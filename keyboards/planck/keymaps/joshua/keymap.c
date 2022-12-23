#include QMK_KEYBOARD_H

// Defining layer names.
#define _BASE 0
#define _NUM 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4

// Defining custom keycodes for _ADJUST layer.
enum my_keycodes {
	J_ESC = SAFE_RANGE,
	J_DEL,
	J_SP,
	J_LEFT,
	J_RIGHT,
	J_DOWN,
	J_UP,
	J_CTRL,
	J_WIN,
	J_ALT,
	J_1,
	J_2,
	J_3,
	J_4,
	J_5,
	J_6,
	J_7,
	J_8,
	J_9,
	J_0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT_planck_1x2uC(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_LCTL, KC_LGUI, KC_LALT, MO(1), MO(2), KC_SPC, MO(3), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
	[_NUM] = LAYOUT_planck_1x2uC(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(2), KC_TRNS, MO(3), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[_LOWER] = LAYOUT_planck_1x2uC(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_NO, KC_NO, KC_MINS, KC_EQL, KC_TRNS, KC_TILD, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(1), KC_TRNS, KC_TRNS, MO(3), KC_HOME, KC_PGDN, KC_PGUP, KC_END),
	[_RAISE] = LAYOUT_planck_1x2uC(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS, KC_CAPS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_SAD, RGB_SAI, RGB_HUD, RGB_HUI, KC_MPRV, KC_MPLY, KC_MNXT, MO(1), MO(2), RGB_TOG, KC_TRNS, RGB_RMOD, RGB_VAD, RGB_VAI, RGB_MOD),
	[_ADJUST] = LAYOUT_planck_1x2uC(J_ESC, J_1, J_2, J_3, J_4, J_5, J_6, J_7, J_8, J_9, J_0, J_DEL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, EE_CLR, J_WIN, J_ALT, MO(1), MO(2), J_SP, MO(3), J_LEFT, J_DOWN, J_UP, J_RIGHT)
};

// Persistent settings stored in EEPROM
typedef union {
	uint32_t raw;
	struct {
		// Flag to determine if encoder should beep or not.
		bool	beep :1;
	};
} user_config_t;
user_config_t user_config;

// Custom song to play
#ifdef AUDIO_ENABLE
float my_song[][2] = SONG(NUMBER_ONE);
float start_song[][2] = SONG(ONE_UP_SOUND);
float toggle_on_song[][2] = SONG(SONIC_RING);
float toggle_off_song[][2] = SONG(COIN_SOUND);
float song1[][2] = SONG(ALL_STAR);
float song2[][2] = SONG(PLATINUM_DISCO);
float song3[][2] = SONG(RENAI_CIRCULATION);
float song4[][2] = SONG(ISABELLAS_LULLABY);
float song5[][2] = SONG(MARIO_MUSHROOM);
float song6[][2] = SONG(MEGALOVANIA);
float song7[][2] = SONG(DISNEY_SONG);
float song8[][2] = SONG(NUMBER_ONE);
float song9[][2] = SONG(RICK_ROLL);
float song0[][2] = SONG(FF_PRELUDE);
//float sleep_song[][2] = SONG(MARIO_GAMEOVER);
#endif	// AUDIO_ENABLE

/*
 * Loops to perform encoder functions.
 */
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
		switch (get_highest_layer(layer_state)) {
			case _BASE:
				clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
				break;
			case _NUM:
				clockwise ? tap_code(KC_WH_D) : tap_code(KC_WH_U);
				break;
			case _LOWER:
				clockwise ? tap_code(KC_L) : tap_code(KC_J);
				break;
			case _RAISE:
				clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
				break;
			case _ADJUST:
				#ifdef AUDIO_ENABLE
				clockwise ? increase_tempo(10) : decrease_tempo(10);
				#endif	// AUDIO_ENABLE
				break;
			default:
				clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
				break;
		}
		#ifdef AUDIO_CLICKY
		if (user_config.beep) {
			clicky_on();
			clockwise ? clicky_freq_up() : clicky_freq_down();
			clicky_play();
			clicky_off();
		}
		#endif	// AUDIO_CLICKY
	}
    return true;
}
#endif  // ENCODER_ENABLE

/*
 * Handles switching to _ADJUST layer, as well as custom keycodes.
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case MO(2):
			if (record->event.pressed) {
				layer_on(_LOWER);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			} else {
				layer_off(_LOWER);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			return false;
		case MO(3):
			if (record->event.pressed) {
				layer_on(_RAISE);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			} else {
				layer_off(_RAISE);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			return false;
		case J_ESC:
			if (record->event.pressed) {
				user_config.beep ^= 1;	// Enable/disable beeping of encoder
				eeconfig_update_user(user_config.raw); // Writes the new status to EEPROM
				#ifdef AUDIO_ENABLE
				if (user_config.beep) {
					PLAY_SONG(toggle_on_song);
				} else {
					PLAY_SONG(toggle_off_song);
				}
				#endif	// AUDIO_ENABLE
			}
			return false;
		case J_SP:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
				PLAY_SONG(my_song);
				#endif	// AUDIO_ENABLE
			}
			return false;
		case J_DEL:
			if (record->event.pressed) {
				set_tempo(120);	// Reset audio tempo to 120
			}
			return false;
		case J_CTRL:
			if (record->event.pressed) {
				tap_code16(EE_CLR);	// Reset EEPROM
			}
			return false;
		case J_1:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
				PLAY_SONG(song1);
				#endif	// AUDIO_ENABLE
			}
			return false;
		case J_2:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
				PLAY_SONG(song2);
				#endif	// AUDIO_ENABLE
			}
			return false;
		case J_3:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
				PLAY_SONG(song3);
				#endif	// AUDIO_ENABLE
			}
			return false;
		case J_4:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
				PLAY_SONG(song4);
				#endif	// AUDIO_ENABLE
			}
			return false;
		case J_5:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
				PLAY_SONG(song5);
				#endif	// AUDIO_ENABLE
			}
			return false;
		case J_6:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
				PLAY_SONG(song6);
				#endif	// AUDIO_ENABLE
			}
			return false;
		case J_7:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
				PLAY_SONG(song7);
				#endif	// AUDIO_ENABLE
			}
			return false;
		case J_8:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
				PLAY_SONG(song8);
				#endif	// AUDIO_ENABLE
			}
			return false;
		case J_9:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
				PLAY_SONG(song9);
				#endif	// AUDIO_ENABLE
			}
			return false;
		case J_0:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
				PLAY_SONG(song0);
				#endif	// AUDIO_ENABLE
			}
			return false;
		default:
			return true; // Process all other keycodes normally
	}
}

/*
 * Runs after keyboard has been initialized.
 */
void keyboard_post_init_user(void) {
	// Read the user config from EEPROM
	user_config.raw = eeconfig_read_user();
	
	// Play startup sound
	#ifdef AUDIO_ENABLE
	PLAY_SONG(start_song);
	#endif	// AUDIO_ENABLE
}

/* 
 * Default EEPROM settings when reset
 */
void eeconfig_init_user(void) {  // EEPROM is getting reset!
 	user_config.raw = 0;
	user_config.beep = true; // We want this enabled by default
	eeconfig_update_user(user_config.raw); // Write default value to EEPROM now
}

/*
 * Code to execute when powering down.
 */
void suspend_power_down_user(void) {
    //rgb_matrix_set_suspend_state(true);
}

/*
 * Code to execute when waking up.
 */
void suspend_wakeup_init_user(void) {
    //rgb_matrix_set_suspend_state(false);
    // Play startup sound
	#ifdef AUDIO_ENABLE
	PLAY_SONG(start_song);
	#endif	// AUDIO_ENABLE
}
