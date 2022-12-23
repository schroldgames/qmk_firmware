 /*
 Copyright 2020 Garret Gartner

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// Defining layer names.
#define _BASE 0
#define _NUM 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_staggered(
        KC_P7, KC_P8, KC_P9,           KC_ESC,         KC_TAB,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,   KC_BSLS, KC_BSPC,
        KC_P4, KC_P5, KC_P6,           KC_NO,          KC_CAPS,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN,   KC_NO,KC_ENT,
        KC_P1, KC_P2, KC_P3,           KC_UP,          KC_LSFT,KC_NO,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,
        KC_P0, KC_PDOT,        KC_LEFT, KC_DOWN, KC_RGHT,      KC_LCTL,KC_LGUI,KC_LALT,   KC_NO,MO(_NUM),  KC_NO,KC_SPC,  KC_NO,MO(_LOWER),    KC_RALT,KC_RGUI,KC_RCTL
    ),


    // numbers + shifted numbers, grave/tilde, minus, equals, quotes
    [_NUM] = LAYOUT_staggered(
        KC_P7, KC_P8, KC_P9,           KC_TILD,         KC_GRV,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,   KC_0,   KC_MINS, KC_EQL,
        KC_P4, KC_P5, KC_P6,           KC_NO,          KC_NLCK,   KC_EXLM,   KC_AT,   KC_HASH,   KC_DLR,   KC_PERC,   KC_CIRC,   KC_AMPR,   KC_ASTR,    KC_LPRN,   KC_RPRN,   KC_NO,KC_QUOT,
        KC_P1, KC_P2, KC_P3,           KC_UP,          KC_LSFT,KC_NO,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,
        KC_P0, KC_PDOT,        KC_LEFT, KC_DOWN, KC_RGHT,      KC_LCTL,KC_LGUI,KC_LALT,   KC_NO,MO(_NUM),  KC_NO,KC_SPC,  KC_NO,MO(_LOWER),    KC_RALT,KC_RGUI,KC_RCTL
    ),


    // media keys, home, end, pgup, pgdn, delete
    [_LOWER] = LAYOUT_staggered(
        KC_P7, KC_P8, KC_P9,           KC_ESC,         KC_GRV,    KC_Q,   KC_PGUP,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,   KC_LBRC,   KC_RBRC, KC_DEL,
        KC_P4, KC_P5, KC_P6,           KC_NO,          KC_CAPS,   KC_HOME,   KC_PGDN,   KC_END,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN,   KC_NO,KC_ENT,
        KC_P1, KC_P2, KC_P3,           KC_UP,          KC_LSFT,KC_NO,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,
        KC_P0, KC_PDOT,        KC_LEFT, KC_DOWN, KC_RGHT,      KC_MPRV,KC_MPLY,KC_MNXT,   KC_NO,MO(_NUM),  KC_NO,KC_SPC,  KC_NO,MO(_LOWER),    KC_RALT,KC_RGUI,KC_RCTL
    ),

    [_RAISE] = LAYOUT_staggered(
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
    )
  

};

// Configure default LED color after boot
void keyboard_post_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    rgblight_set_effect_range(0, 1);
    rgblight_setrgb(0,0,0);
    rgblight_set();
  #endif // RGBLIGHT_ENABLE
}

// Main function to update LED colors
void update_led(void) {
  #ifdef RGBLIGHT_ENABLE
    rgblight_set_effect_range(0, 1);
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    // LED color dependent on layer
    switch (biton32(layer_state)) {
      case _BASE:
      rgblight_setrgb(0,0,0);
      break;
      case _NUM:
      rgblight_setrgb(0,0,0);
      break;
      case _LOWER:
      rgblight_setrgb(0,0,0);
      break;
      default:
      rgblight_setrgb(0,0,0);
      break;
    }

    // Override color if capslock is on
    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
      rgblight_setrgb(RGB_RED);
      rgblight_mode(RGBLIGHT_MODE_BREATHING+1);
    }

    rgblight_set();
  #endif // RGBLIGHT_ENABLE
}

void led_set_user(uint8_t usb_led) {
  // must be trigger to
  // - activate capslock color
  // - go back to the proper layer color if needed when quitting capslock
  update_led();
}

// RGB Indicator Customization: (cont.)
//layer_state_t layer_state_set_user(layer_state_t state){
uint32_t layer_state_set_user(uint32_t state) {
  #ifdef RGBLIGHT_ENABLE
    update_led();
  #endif //RGBLIGHT_ENABLE
  return state;
}
