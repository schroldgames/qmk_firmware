#include QMK_KEYBOARD_H

static uint8_t caps_state = 0;
//static uint8_t defaultmode;
//static HSV defaulthsv;
static uint8_t changed = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_planck_mit(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_LCTL, KC_LGUI, KC_LALT, MO(1), MO(2), KC_SPC, MO(3), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
	[1] = LAYOUT_planck_mit(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT_planck_mit(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_NO, KC_NO, KC_MINS, KC_EQL, KC_TRNS, KC_TILD, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END),
	[3] = LAYOUT_planck_mit(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS, KC_CAPS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_SAD, RGB_SAI, RGB_HUD, RGB_HUI, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_NO, RGB_TOG, KC_NO, RGB_RMOD, RGB_VAD, RGB_VAI, RGB_MOD)
};

// loops, overrides any leds currently set from rgb lighting
bool rgb_matrix_indicators_user(void) {
	// disable the six underglow LEDs on the back of the PCB
	for (int i = 47; i < 53; i++) {
		rgb_matrix_set_color(i, RGB_OFF);
	}
	
	// if caps lock is on, change led color to red
	if (caps_state) {
		rgb_matrix_set_color(24, 255, 0, 0);
	}
	
	// depending on layer, change colors
	uint8_t layer = biton32(layer_state);
	switch (layer) {
		case 0:
			if (changed){
				//rgb_matrix_mode(defaultmode);
				//rgb_matrix_sethsv(defaulthsv.h, defaulthsv.s, defaulthsv.v);
				changed = 0;
			}
			break;
		case 1:
			my_layer_change_led();
			break;
		case 2:
			my_layer_change_led();
			break;
		case 3:
			my_layer_change_led();
			break;
	}

	return true;
}

// my custom layer change led function
void my_layer_change_led(void) {
	// set color of spacebar
	rgb_matrix_set_color(41, 255, 255, 255);
	if (!changed) {
		// store the original RGB mode and color
		//defaultmode = rgb_matrix_get_mode();
		//defaulthsv = rgb_matrix_get_hsv();
		// temporarily change mode
		//rgb_matrix_mode((uint8_t) RGB_MATRIX_BREATHING);
		// mark as changed
		changed = 1;
	}
}

// loops to see what the led_state is
// see
// https://beta.docs.qmk.fm/using-qmk/hardware-features/feature_led_indicators
bool led_update_user(led_t led_state) {
    caps_state = 0;
    if (led_state.caps_lock) {
        caps_state = 1;
    }
    return false;	// dont run led_update_kb
}
