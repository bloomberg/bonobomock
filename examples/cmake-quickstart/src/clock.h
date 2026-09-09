// SPDX-License-Identifier: Apache-2.0
//
// Copyright 2026 Bloomberg Finance LP
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef INCLUDED_CLOCK
#define INCLUDED_CLOCK

/// Wall-clock source used to stamp valuations.
class Clock {
public:
    /// Return the current time as seconds since the UNIX epoch, UTC.
    ///
    /// A static member function: the other shape of dependency that cannot be
    /// injected without changing the code that calls it.
    static long long nowUtcSeconds();
};

#endif
