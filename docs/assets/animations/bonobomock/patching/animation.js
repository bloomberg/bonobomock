(function () {
  'use strict';

  var SCENE_OFFSETS = [0, 0, 0, 0, 0];
  var timeline = null;

  function buildTimeline() {
    timeline = anime.timeline({
      easing: 'easeInOutQuad',
      autoplay: false,
      update: function (anim) {
        var fill = document.getElementById('progress-fill');
        fill.setAttribute('width', (anim.progress / 100) * 1000);

        var dots = document.querySelectorAll('.scene-dot');
        var t = anim.currentTime;
        var active = 0;
        for (var i = SCENE_OFFSETS.length - 1; i >= 0; i--) {
          if (t >= SCENE_OFFSETS[i]) { active = i; break; }
        }
        dots.forEach(function (d, idx) {
          d.classList.toggle('active', idx === active);
        });
      },
      complete: function () {
        updatePlayBtn('Replay');
      }
    });

    SCENE_OFFSETS[0] = timeline.duration;
    addScene1(timeline);
    SCENE_OFFSETS[1] = timeline.duration;
    addScene2(timeline);
    SCENE_OFFSETS[2] = timeline.duration;
    addScene3(timeline);
    SCENE_OFFSETS[3] = timeline.duration;
    addScene4(timeline);
    SCENE_OFFSETS[4] = timeline.duration;
    addScene5(timeline);

    return timeline;
  }

  // ============================================================
  // SCENE 1: The Problem
  // ============================================================
  function addScene1(tl) {
    tl
      .add({
        targets: '#scene1-group',
        opacity: [0, 1],
        duration: 100
      })
      .add({
        targets: '#scene1-title',
        opacity: [0, 1],
        translateY: [-15, 0],
        duration: 500
      })
      .add({
        targets: '#scene1-function-box',
        opacity: [0, 1],
        translateY: [20, 0],
        duration: 600
      }, '-=200')
      .add({
        targets: '#scene1-gmock',
        opacity: [0, 1],
        translateX: [40, 0],
        duration: 500
      }, '-=200')
      .add({
        targets: '#scene1-red-x',
        opacity: [0, 1],
        scale: [0, 1],
        duration: 400,
        easing: 'easeOutBack'
      })
      .add({
        targets: '#scene1-fail-text',
        opacity: [0, 1],
        duration: 400
      })
      .add({
        targets: '#scene1-solution',
        opacity: [0, 1],
        translateY: [15, 0],
        duration: 500
      }, '+=300')
      .add({
        targets: '#scene1-group',
        opacity: 1,
        duration: 1800
      })
      .add({
        targets: '#scene1-group',
        opacity: [1, 0],
        duration: 400
      });
  }

  // ============================================================
  // SCENE 2: BONOBO_MOCK Setup
  // ============================================================
  function addScene2(tl) {
    tl
      .add({
        targets: '#scene2-group',
        opacity: [0, 1],
        duration: 100
      })
      .add({
        targets: '#scene2-title',
        opacity: [0, 1],
        translateY: [-15, 0],
        duration: 500
      })
      .add({
        targets: '#scene2-code',
        opacity: [0, 1],
        translateX: [-20, 0],
        duration: 600
      }, '-=200')
      .add({
        targets: '#scene2-monkey',
        opacity: [0, 1],
        translateX: [200, 0],
        duration: 800,
        easing: 'easeOutBack'
      })
      .add({
        targets: '#scene2-flow',
        opacity: [0, 1],
        duration: 500
      }, '-=200')
      .add({
        targets: '#scene2-group',
        opacity: 1,
        duration: 1800
      })
      .add({
        targets: '#scene2-group',
        opacity: [1, 0],
        duration: 400
      });
  }

  // ============================================================
  // SCENE 3: The Patch (key scene)
  // ============================================================
  function addScene3(tl) {
    tl
      .add({
        targets: '#scene3-group',
        opacity: [0, 1],
        duration: 100
      })
      .add({
        targets: '#scene3-title',
        opacity: [0, 1],
        translateY: [-15, 0],
        duration: 500
      })
      .add({
        targets: '#scene3-func-label',
        opacity: [0, 1],
        duration: 400
      }, '-=200')
      .add({
        targets: '#scene3-page',
        opacity: [0, 1],
        duration: 400
      })
      .add({
        targets: '#scene3-page-label',
        opacity: [0, 1],
        duration: 300
      }, '-=300')
      // Byte cells appear
      .add({
        targets: '.scene3-cell',
        opacity: [0, 1],
        translateY: [10, 0],
        delay: anime.stagger(80),
        duration: 300
      })
      // Original byte values appear
      .add({
        targets: '.scene3-original-byte',
        opacity: [0, 1],
        delay: anime.stagger(60),
        duration: 250
      }, '-=100')
      // Lock appears
      .add({
        targets: '#scene3-lock',
        opacity: [0, 1],
        duration: 300
      })
      // Hold to let viewer read the bytes
      .add({
        targets: '#scene3-group',
        opacity: 1,
        duration: 1000
      })

      // === UNLOCK ===
      .add({
        targets: '#scene3-mprotect-unlock',
        opacity: [0, 1],
        duration: 300
      })
      .add({
        targets: '#scene3-lock-shackle',
        translateY: [0, -10],
        duration: 400,
        easing: 'easeOutBack'
      })
      .add({
        targets: '#scene3-lock-body',
        fill: ['#e74c3c', '#4caf50'],
        duration: 300
      }, '-=200')

      // Backup container appears
      .add({
        targets: '#scene3-backup-box, #scene3-backup-label',
        opacity: [0, 1],
        duration: 400
      })

      // Original bytes slide down and fade
      .add({
        targets: '.scene3-original-byte',
        translateY: [0, 240],
        opacity: [1, 0],
        delay: anime.stagger(60),
        duration: 700,
        easing: 'easeInQuad'
      })
      // Backup bytes appear
      .add({
        targets: '.scene3-backup-byte',
        opacity: [0, 1],
        delay: anime.stagger(60),
        duration: 300
      }, '-=300')

      // JMP bytes stamp in
      .add({
        targets: '.scene3-jmp-byte',
        opacity: [0, 1],
        scale: [1.4, 1],
        delay: anime.stagger(80),
        duration: 400,
        easing: 'easeOutBack'
      })
      // Cell highlight flash
      .add({
        targets: '.scene3-cell-highlight',
        opacity: [0, 0.3, 0],
        duration: 600
      }, '-=200')
      // JMP label
      .add({
        targets: '#scene3-jmp-label',
        opacity: [0, 1],
        translateY: [10, 0],
        duration: 400
      })

      // === RE-LOCK ===
      .add({
        targets: '#scene3-mprotect-unlock',
        opacity: [1, 0],
        duration: 200
      })
      .add({
        targets: '#scene3-mprotect-lock',
        opacity: [0, 1],
        duration: 200
      })
      .add({
        targets: '#scene3-lock-shackle',
        translateY: [-10, 0],
        duration: 400,
        easing: 'easeInBack'
      })
      .add({
        targets: '#scene3-lock-body',
        fill: ['#4caf50', '#e74c3c'],
        duration: 300
      }, '-=200')
      .add({
        targets: '#scene3-mprotect-lock',
        opacity: [1, 0],
        duration: 300
      }, '+=200')

      // Step label and footnote
      .add({
        targets: '#scene3-step1',
        opacity: [0, 1],
        duration: 400
      })
      .add({
        targets: '#scene3-footnote',
        opacity: [0, 1],
        duration: 300
      }, '-=200')

      // Hold before trampoline
      .add({
        targets: '#scene3-group',
        opacity: 1,
        duration: 1500
      })

      // === TRAMPOLINE SUB-SCENE ===
      // Fade out near-jump elements
      .add({
        targets: '#scene3-step1, #scene3-footnote, #scene3-jmp-label, #scene3-backup-box, #scene3-backup-label, .scene3-backup-byte',
        opacity: [1, 0],
        duration: 400
      })
      // Show trampoline group
      .add({
        targets: '#scene3-trampoline-group',
        opacity: [0, 1],
        duration: 100
      })
      // Question
      .add({
        targets: '#scene3-trampoline-title',
        opacity: [0, 1],
        duration: 500
      })
      .add({
        targets: '#scene3-trampoline-title',
        opacity: 1,
        duration: 800
      })
      // Source box
      .add({
        targets: '#scene3-tramp-src',
        opacity: [0, 1],
        translateX: [-20, 0],
        duration: 400,
        easing: 'easeOutQuad'
      })
      // Arrow 1
      .add({
        targets: '#scene3-tramp-arrow1',
        opacity: [0, 1],
        duration: 300
      })
      // Trampoline box
      .add({
        targets: '#scene3-tramp-mid',
        opacity: [0, 1],
        translateY: [15, 0],
        duration: 400,
        easing: 'easeOutBack'
      })
      // Arrow 2
      .add({
        targets: '#scene3-tramp-arrow2',
        opacity: [0, 1],
        duration: 300
      })
      // Mock box
      .add({
        targets: '#scene3-tramp-dst',
        opacity: [0, 1],
        translateX: [20, 0],
        duration: 400,
        easing: 'easeOutQuad'
      })
      // Range labels
      .add({
        targets: '#scene3-tramp-range1, #scene3-tramp-range2',
        opacity: [0, 1],
        duration: 300
      })
      // Explanation
      .add({
        targets: '#scene3-tramp-explain',
        opacity: [0, 1],
        duration: 400
      })

      // Hold trampoline view
      .add({
        targets: '#scene3-group',
        opacity: 1,
        duration: 2500
      })
      .add({
        targets: '#scene3-group',
        opacity: [1, 0],
        duration: 400
      });
  }

  // ============================================================
  // SCENE 4: Call Interception
  // ============================================================
  function addScene4(tl) {
    // Pre-calculate dash offsets for arrows
    var arrowIds = ['scene4-arrow1', 'scene4-arrow2', 'scene4-arrow3', 'scene4-arrow4', 'scene4-arrow-return'];
    var arrowLens = {};
    arrowIds.forEach(function (id) {
      var el = document.getElementById(id);
      if (el) {
        var len = el.getTotalLength();
        arrowLens[id] = len;
        el.style.strokeDasharray = len;
        el.style.strokeDashoffset = len;
      }
    });

    tl
      .add({
        targets: '#scene4-group',
        opacity: [0, 1],
        duration: 100
      })
      .add({
        targets: '#scene4-title',
        opacity: [0, 1],
        translateY: [-15, 0],
        duration: 500
      })

      // Box 1: Caller
      .add({
        targets: '#scene4-caller',
        opacity: [0, 1],
        translateY: [-10, 0],
        duration: 400
      })
      // Arrow 1
      .add({
        targets: '#scene4-arrow1',
        opacity: [0, 1],
        strokeDashoffset: [arrowLens['scene4-arrow1'] || 20, 0],
        duration: 300,
        easing: 'easeInOutSine'
      })

      // Box 2: Patched function
      .add({
        targets: '#scene4-function',
        opacity: [0, 1],
        translateY: [-10, 0],
        duration: 400
      })
      // Arrow 2
      .add({
        targets: '#scene4-arrow2',
        opacity: [0, 1],
        strokeDashoffset: [arrowLens['scene4-arrow2'] || 20, 0],
        duration: 300,
        easing: 'easeInOutSine'
      })

      // Box 3: mockFunction
      .add({
        targets: '#scene4-mock-fn',
        opacity: [0, 1],
        translateY: [-10, 0],
        duration: 400
      })
      // Arrow 3
      .add({
        targets: '#scene4-arrow3',
        opacity: [0, 1],
        strokeDashoffset: [arrowLens['scene4-arrow3'] || 20, 0],
        duration: 300,
        easing: 'easeInOutSine'
      })

      // Box 4: MockManager
      .add({
        targets: '#scene4-manager',
        opacity: [0, 1],
        translateY: [-10, 0],
        duration: 400
      })
      // Arrow 4
      .add({
        targets: '#scene4-arrow4',
        opacity: [0, 1],
        strokeDashoffset: [arrowLens['scene4-arrow4'] || 20, 0],
        duration: 300,
        easing: 'easeInOutSine'
      })

      // Box 5: GMock dispatch
      .add({
        targets: '#scene4-gmock',
        opacity: [0, 1],
        translateY: [-10, 0],
        duration: 400
      })

      // Green check
      .add({
        targets: '#scene4-check',
        opacity: [0, 1],
        scale: [0, 1],
        duration: 400,
        easing: 'easeOutBack'
      })

      // Return arrow draws back up
      .add({
        targets: '#scene4-arrow-return',
        opacity: [0, 1],
        strokeDashoffset: [arrowLens['scene4-arrow-return'] || 400, 0],
        duration: 800,
        easing: 'easeInOutSine'
      })
      // Return value
      .add({
        targets: '#scene4-return-value',
        opacity: [0, 1],
        scale: [0.8, 1],
        duration: 400,
        easing: 'easeOutBack'
      }, '-=300')

      // Explanation
      .add({
        targets: '#scene4-explanation',
        opacity: [0, 1],
        duration: 400
      })

      // Hold
      .add({
        targets: '#scene4-group',
        opacity: 1,
        duration: 2000
      })
      .add({
        targets: '#scene4-group',
        opacity: [1, 0],
        duration: 400
      });
  }

  // ============================================================
  // SCENE 5: Restoration
  // ============================================================
  function addScene5(tl) {
    tl
      .add({
        targets: '#scene5-group',
        opacity: [0, 1],
        duration: 100
      })
      .add({
        targets: '#scene5-title',
        opacity: [0, 1],
        translateY: [-15, 0],
        duration: 500
      })
      // Destructor label
      .add({
        targets: '#scene5-destructor',
        opacity: [0, 1],
        duration: 400
      })
      // Show cells with JMP bytes
      .add({
        targets: '.scene5-cell',
        opacity: [0, 1],
        delay: anime.stagger(60),
        duration: 250
      })
      .add({
        targets: '.scene5-jmp-byte',
        opacity: [0, 1],
        delay: anime.stagger(60),
        duration: 200
      }, '-=100')
      // Show backup container
      .add({
        targets: '.scene5-backup',
        opacity: [0, 1],
        duration: 300
      })
      .add({
        targets: '.scene5-backup-byte',
        opacity: [0, 1],
        delay: anime.stagger(60),
        duration: 200
      }, '-=100')

      // Hold briefly
      .add({
        targets: '#scene5-group',
        opacity: 1,
        duration: 800
      })

      // JMP bytes fade out
      .add({
        targets: '.scene5-jmp-byte',
        opacity: [1, 0],
        delay: anime.stagger(40),
        duration: 300
      })
      // Backup bytes slide up
      .add({
        targets: '.scene5-backup-byte',
        translateY: [0, -240],
        opacity: [1, 0],
        delay: anime.stagger(60),
        duration: 600,
        easing: 'easeInQuad'
      }, '-=200')
      // Restored bytes appear
      .add({
        targets: '.scene5-restored-byte',
        opacity: [0, 1],
        scale: [1.2, 1],
        delay: anime.stagger(60),
        duration: 400,
        easing: 'easeOutBack'
      }, '-=200')
      // Cell borders change from orange to normal
      .add({
        targets: '.scene5-cell-restored',
        opacity: [0, 1],
        duration: 300
      })
      // Backup container fades
      .add({
        targets: '.scene5-backup',
        opacity: [1, 0.3],
        duration: 300
      }, '-=200')

      // Restored label
      .add({
        targets: '#scene5-restored-label',
        opacity: [0, 1],
        translateY: [10, 0],
        duration: 400,
        easing: 'easeOutBack'
      })

      // Monkey slides in
      .add({
        targets: '#scene5-monkey',
        opacity: [0, 1],
        translateX: [150, 0],
        duration: 700,
        easing: 'easeOutBack'
      })

      // Explanation
      .add({
        targets: '#scene5-explanation',
        opacity: [0, 1],
        duration: 400
      }, '-=600')

      // Final hold
      .add({
        targets: '#scene5-group',
        opacity: 1,
        duration: 2000
      });
  }

  // ============================================================
  // Controls
  // ============================================================
  var playBtn = document.getElementById('play-btn');
  var playing = false;

  function updatePlayBtn(label) {
    playBtn.textContent = label;
    playing = (label === 'Pause');
  }

  playBtn.addEventListener('click', function () {
    if (!timeline) {
      timeline = buildTimeline();
    }
    if (timeline.completed) {
      timeline.restart();
      updatePlayBtn('Pause');
    } else if (playing) {
      timeline.pause();
      updatePlayBtn('Play');
    } else {
      timeline.play();
      updatePlayBtn('Pause');
    }
  });

  // Scene dot navigation
  document.querySelectorAll('.scene-dot').forEach(function (dot, idx) {
    dot.addEventListener('click', function () {
      if (!timeline) {
        timeline = buildTimeline();
      }
      timeline.pause();
      timeline.seek(SCENE_OFFSETS[idx]);
      updatePlayBtn('Play');
    });
  });

  // Progress bar scrubbing
  var progressTrack = document.getElementById('progress-track');
  var progressFill = document.getElementById('progress-fill');
  [progressTrack, progressFill].forEach(function (el) {
    el.style.cursor = 'pointer';
    el.addEventListener('click', function (e) {
      if (!timeline) {
        timeline = buildTimeline();
      }
      var rect = progressTrack.getBoundingClientRect();
      var pct = (e.clientX - rect.left) / rect.width;
      pct = Math.max(0, Math.min(1, pct));
      timeline.pause();
      timeline.seek(timeline.duration * pct);
      updatePlayBtn('Play');
    });
  });

  // Auto-play when the page loads
  setTimeout(function() {
    anime.speed = 1 / 1.5;
    timeline = buildTimeline();
    timeline.play();
    updatePlayBtn('Pause');
  }, 500);
})();
