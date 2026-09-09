# Virtual Function Mocking: How It Works Behind the Scenes

## Background

BonoboMock patches functions at runtime by overwriting the first few bytes of a
target function with a jump instruction that redirects execution to a mock
trampoline. For non-virtual functions, finding the address to patch is
straightforward: the function pointer IS the address. For virtual functions,
the address depends on the vtable, and getting it requires understanding how
each compiler's ABI represents pointers-to-member-functions (PMFs).

Bloomberg compiles on two platforms:

| | **amd64 + RHEL** | **SPARC + Solaris** |
|---|---|---|
| Compiler | GCC / Clang | SunPro |
| ABI | Itanium | SunPro (proprietary) |

The `BONOBO_MOCK_VIRTUAL(&Class::func)` macro works on both platforms, but the
mechanism for resolving the actual function address is completely different.

---

## The Problem: Where Does a Virtual Function Live?

Given a class:

```cpp
class Animal {
public:
    virtual int speak(int volume) { return 0; }
    virtual int eat() const { return 1; }
};
```

When you write `&Animal::speak`, the compiler gives you a
pointer-to-member-function (PMF). But a PMF to a virtual function doesn't
point directly at the function's code -- it encodes information about _which
slot in the vtable_ to look up at call time. The encoding differs by ABI.

To mock `Animal::speak`, BonoboMock needs to find the address of the actual
machine code so it can overwrite it with a jump. The PMF alone isn't enough;
we need to decode it.

---

## Itanium ABI (GCC / Clang)

### PMF Layout

Under the Itanium ABI, a PMF is a struct with two pointer-sized words:

```
word[0]: function pointer or vtable offset
word[1]: this-pointer adjustment (for multiple inheritance)
```

For a **non-virtual** function, `word[0]` is the actual function address.
For a **virtual** function, `word[0]` is the vtable byte offset with the low
bit set to 1 (to distinguish it from a real address):

```
word[0] = (vtable_slot_index * sizeof(void*)) + 1
```

### How BonoboMock Resolves It

```
BONOBO_MOCK_VIRTUAL(&Animal::speak)
       |
       v
  Read word[0] from the PMF
       |
       v
  word[0] is small (< page size) and odd? --> virtual
       |
       v
  vtable_index = word[0] / sizeof(void*)
       |
       v
  Construct a temporary Animal object (or use a provided instance)
       |
       v
  Read the vptr from the object (first pointer-sized word at offset 0)
       |
       v
  target_address = vptr[vtable_index]
       |
       v
  Overwrite target_address with a jump to the mock trampoline
```

### Example: Step by Step

```cpp
auto mock = BONOBO_MOCK_VIRTUAL(&Animal::speak);
```

1. `&Animal::speak` produces a PMF. On a 64-bit system, `word[0] = 0x11`
   (vtable offset 16 + 1 for the virtual flag). This means `speak` is at
   byte offset 16 in the vtable (slot index 2, since 16 / 8 = 2).

2. BonoboMock constructs a temporary `Animal` object and reads its vptr:
   ```
   Animal tmp;
   void** vtable = *(void***)&tmp;
   ```

3. It indexes the vtable:
   ```
   void* target = vtable[2];   // 0x11 / 8 = 2
   ```
   This is the address of `Animal::speak`'s machine code.

4. BonoboMock overwrites the first bytes of `target` with an x86-64 jump:
   ```
   48 b8 XX XX XX XX XX XX XX XX   movabs rax, <mock_trampoline>
   ff e0                           jmp rax
   ```

5. Any call to `speak()` -- on any `Animal` instance -- now jumps to the
   mock trampoline, which forwards to gMock's expectation matching.

6. When the mock is destroyed (or `mock->restore()` is called), the original
   bytes are written back.

---

## SunPro ABI (SPARC)

### PMF Layout

SunPro does **not** follow the Itanium ABI. A PMF is still two words:

```
word[0]: function address (non-virtual) or thunk address (virtual)
word[1]: this-pointer adjustment
```

For a **non-virtual** function, `word[0]` is the actual function address
(same as Itanium). But for a **virtual** function, `word[0]` is the address
of a compiler-generated **thunk** -- a small trampoline that loads the vtable
and jumps to the correct entry.

### The Thunk

SunPro generates a different thunk shape depending on the optimization level.

**Optimized thunk (-O1 and above):** a compact leaf function (no stack frame):

```
__SLIP.MFPTR__U:                       ; 64-bit example
    ldx   [%o0], %g5           ; load vptr from object (this is in %o0)
    ldx   [%g5 + 0x10], %g4   ; load function ptr from vtable at offset 0x10
    jmp   %g4                  ; jump to the real function
    nop                        ; delay slot
```

**Unoptimized thunk (-O0):** a non-leaf function with `save`/`restore`
(SPARC register window):

```
__SLIP.MFPTR__U:                       ; 32-bit -O0 example
    save  %sp, -0x60, %sp     ; create stack frame + new register window
    mov   %i0, %o0             ; this: input reg (%i0) -> output reg (%o0)
    st    %o0, [%fp + 0x44]    ; spill this to stack
    ld    [%fp + 0x44], %o0    ; reload this
    ld    [%o0 + 0x0], %o1     ; load vptr from object
    ld    [%o1 + 0x10], %o1    ; load function ptr from vtable at offset 0x10
    mov   %o0, %i0             ; pass this back to callee's input regs
    jmp   %o1                  ; jump to the real function
    restore                    ; destroy stack frame (delay slot)
```

In both cases, the vtable byte offset (0x10 in these examples) is hardcoded
in the `ld`/`ldx` instruction's `simm13` immediate field. Each virtual function
gets its own thunk with a different offset.

The key difference is that the -O0 thunk has a `mov` instruction between
the vtable load and the `jmp` -- the instruction immediately before `jmp` is
**not** the vtable load.

### How BonoboMock Resolves It

```
BONOBO_MOCK_VIRTUAL(&Animal::speak)
       |
       v
  Read word[0] from the PMF --> this is the thunk address
       |
       v
  Parse the thunk's SPARC machine code:
    1. Scan forward for a JMPL (jmp) instruction
    2. From the JMPL, extract rs1: the register holding the jump target
    3. Scan backwards from the JMPL for the ld/ldx instruction
       whose destination register (rd) matches rs1
    4. Extract the simm13 field (low 13 bits) = vtable byte offset
       |
       v
  Construct a temporary Animal object (or use a provided instance)
       |
       v
  Read the vptr from the object
       |
       v
  target_address = *(void**)((char*)vptr + vtable_byte_offset)
       |
       v
  Overwrite target_address with a jump to the mock trampoline
```

The backward scan (step 3) is necessary because the compiler may insert
instructions between the vtable load and the jump at lower optimization levels.
By matching the load's destination register against the jump's source register,
BonoboMock finds the correct vtable load regardless of the thunk shape.

### Example: Optimized Build (Step by Step)

```cpp
bsl::shared_ptr<GMock<int(void*, int)> > mock =
    BONOBO_MOCK_VIRTUAL(&Animal::speak);
```

1. `&Animal::speak` produces a PMF. `word[0] = 0x1003d4e80` -- this is the
   address of a thunk, not `speak` itself.

2. BonoboMock reads the thunk's machine code at that address:
   ```
   0x1003d4e80: ca 5a 20 00   ldx [%o0], %g5         // load vptr
   0x1003d4e84: c8 59 60 10   ldx [%g5 + 0x10], %g4  // load func ptr
   0x1003d4e88: 81 c1 00 00   jmp %g4                // jump
   0x1003d4e8c: 01 00 00 00   nop
   ```

3. BonoboMock scans for the `jmp` instruction. SPARC `jmpl` to `%g0` (which
   discards the return address, making it a plain jump) has the bit pattern:
   ```
   op=10, rd=00000, op3=111000 --> mask 0xFFF80000, value 0x81C00000
   ```
   It finds `0x81c10000` at offset +8. From this, it extracts `rs1 = %g4`
   (the register being jumped to).

4. BonoboMock scans backwards for an `ld`/`ldx` with immediate mode whose
   destination register is `%g4`. It finds `ldx [%g5 + 0x10], %g4` at
   offset +4. It extracts the `simm13` field (low 13 bits): `0x10` =
   16 decimal. This is the vtable byte offset for `speak`.

5. BonoboMock constructs a temporary `Animal` object and reads its vptr:
   ```
   Animal tmp;
   void** vtable = *(void***)&tmp;
   ```

6. It indexes the vtable at byte offset 16:
   ```
   void* target = *(void**)((char*)vtable + 16);
   ```

7. BonoboMock overwrites the first bytes of `target` with a SPARC jump sequence
   (7 instructions / 28 bytes on 64-bit SPARC):
   ```
   sethi  hi(mock_addr >> 32), %g1
   sethi  hi(mock_addr & 0xFFFFFFFF), %g5
   or     %g1, lo(mock_addr >> 32), %g1
   or     %g5, lo(mock_addr & 0xFFFFFFFF), %g5
   sllx   %g1, 32, %g1
   jmp    %g1 + %g5
   nop
   ```

8. All calls to `speak()` now route through the mock.

### Example: Unoptimized Build

In a debug build (-O0), step 2 would show a longer thunk with register
window management:

```
0x0012960: 9d e3 bf a0   save %sp, -96, %sp     // stack frame
0x0012964: 90 10 00 18   mov  %i0, %o0           // this -> output reg
0x0012968: d0 27 a0 44   st   %o0, [%fp + 0x44]  // spill
0x001296c: d0 07 a0 44   ld   [%fp + 0x44], %o0  // reload
0x0012970: d2 02 20 00   ld   [%o0], %o1          // load vptr
0x0012974: d2 02 60 10   ld   [%o1 + 0x10], %o1  // load func ptr
0x0012978: b0 10 00 08   mov  %o0, %i0            // pass this to callee
0x001297c: 81 c2 40 00   jmp  %o1                 // jump
0x0012980: 81 e8 00 00   restore
```

BonoboMock finds `jmp %o1` at offset +0x1c, extracts `rs1 = %o1`, then scans
backwards. It skips the `mov` at offset +0x18 (not a load) and finds
`ld [%o1 + 0x10], %o1` at offset +0x14 -- its `rd` (`%o1`) matches the
jump's `rs1`. The vtable byte offset is `0x10`, the same as in the
optimized case.

---

## BONOBO_MOCK_VIRTUAL_ON: Classes Without Default Constructors

Both resolution paths need an object instance to read the vptr from. By
default, `BONOBO_MOCK_VIRTUAL` constructs a temporary. If the class has no
default constructor, use `BONOBO_MOCK_VIRTUAL_ON`:

```cpp
class DatabaseConnection {
public:
    DatabaseConnection(const std::string& connStr);  // no default ctor
    virtual int query(int id);
};

DatabaseConnection conn("localhost:5432");
auto mock = BONOBO_MOCK_VIRTUAL_ON(conn, &DatabaseConnection::query);
```

This uses `conn`'s vptr instead of trying to default-construct a
`DatabaseConnection`.

---

## Limitations

- **Single inheritance only**: All three resolution paths (Itanium, SunPro,
  MSVC) assume a single vptr at offset 0 in the object layout. Classes using
  multiple or virtual inheritance have multiple vtables and require
  this-pointer adjustments that the resolvers do not handle. Mocking virtual
  functions on such classes may patch the wrong address or fail entirely.

- **SPARC V9 only**: The thunk parser assumes SPARC instruction encoding.
  The vtable offset must fit in a 13-bit signed immediate (-4096 to +4095
  bytes), covering classes with up to ~512 virtual functions on 64-bit.

- **Single inheritance only**: BonoboMock's vtable resolution assumes a single
  vtable per object. Classes using multiple inheritance may have multiple
  vtables with adjusted object pointers, which BonoboMock does not account for.
