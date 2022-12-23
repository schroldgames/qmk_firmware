#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 5

#ifdef AUDIO_ENABLE
    #define AUDIO_CLICKY
    #define AUDIO_CLICKY_OFF
    #define AUDIO_CLICKY_FREQ_MAX 2200.0f
    #define AUDIO_CLICKY_FREQ_MIN 250.0f
    #define AUDIO_CLICKY_FREQ_RANDOMNESS 0.05f
    #define AUDIO_CLICKY_FREQ_DEFAULT 880.0f
#endif

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4
#define ENCODERS_PAD_A { B12 }
#define ENCODERS_PAD_B { B13 }
#define ENCODER_DIRECTION_FLIP
#define TAP_CODE_DELAY 10	// Needed for volume adjustment to work
