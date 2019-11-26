#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _FUNC,
  _FUNC2,

  _VIM,
  _VIM_SHIFT,
  _VIM_CONTROL
};

enum custom_keycodes {
  DYNAMIC_MACRO_RANGE = SAFE_RANGE,
  a_MACRO,
  A_MACRO,
  I_MACRO,
  O_MACRO,
};

#define KC_PREV_WORD LCTL(KC_LEFT)
#define KC_NEXT_WORD LCTL(KC_RIGHT)
#define KC_UNDO LCTL(KC_Z)
#define KC_CUT LCTL(KC_X)
#define KC_COPY LCTL(KC_C)
#define KC_PASTE LCTL(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
 _______, KC_GESC,  KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9,    KC_0,    KC_MINS, KC_EQL, XXXXXXX, KC_BSLS, \
 KC_PGUP, KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, \
 KC_PGDN, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L,    KC_SCLN, KC_QUOT,          KC_ENT, \
          KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_FUNC2), \
          _______,            KC_LALT, KC_SPC, MO(_FUNC),     KC_SPC,       KC_RALT,                   KC_RCTRL \
   ),
[_FUNC] = LAYOUT(
 RGB_TOG, KC_GRAVE,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX, RESET, \
 RGB_MOD, KC_CAPS, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
RGB_RMOD, KC_LCTL, KC_END,  XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX, XXXXXXX, \
/* RGB_RMOD, KC_LCTL, KC_END,  XXXXXXX, KC_PGDN, TO(_VIM), XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX, XXXXXXX, \ */
          KC_LSFT, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, \
          _______,          KC_LALT, _______, _______,          _______,                   KC_RALT,                            _______ \
   ),
[_FUNC2] = LAYOUT(
 RGB_TOG, VLK_TOG,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, RESET, \
 RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, \
          KC_LSFT, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, \
          _______,          KC_LALT, _______, _______,          _______,                   KC_RALT,                            _______ \
   ),

[_VIM] = LAYOUT(
       XXXXXXX, TO(_BASE),   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,  KC_0,  KC_MINS,  KC_EQL, _______, KC_BSLS, \
         XXXXXXX, XXXXXXX, XXXXXXX, KC_NEXT_WORD, KC_NEXT_WORD, XXXXXXX, XXXXXXX, KC_COPY, KC_UNDO, TO(_BASE), KC_ENTER, KC_PASTE, XXXXXXX, XXXXXXX, KC_DEL, \
XXXXXXX, MO(_VIM_CONTROL), a_MACRO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX,   XXXXXXX, KC_ENTER, \
           MO(_VIM_SHIFT), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PREV_WORD, KC_PREV_WORD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,KC_RSFT, TO(_BASE), \
          _______,          KC_LALT, _______, _______,          _______,                   KC_RALT,                            _______ \
   ),

[_VIM_SHIFT] = LAYOUT(
       XXXXXXX, TO(_BASE),   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,  KC_0,  KC_MINS,  KC_EQL, _______, KC_BSLS, \
         XXXXXXX, XXXXXXX, XXXXXXX, KC_NEXT_WORD, KC_NEXT_WORD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, I_MACRO, O_MACRO, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL, \
XXXXXXX, XXXXXXX, A_MACRO, XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX,   XXXXXXX, KC_ENTER, \
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PREV_WORD, KC_PREV_WORD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,KC_RSFT, TO(_BASE), \
          _______,          KC_LALT, _______, _______,          _______,                   KC_RALT,                            _______ \
   ),

[_VIM_CONTROL] = LAYOUT(
       XXXXXXX, TO(_BASE),   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,  KC_0,  KC_MINS,  KC_EQL, _______, KC_BSLS, \
         XXXXXXX, XXXXXXX, XXXXXXX, KC_NEXT_WORD, KC_NEXT_WORD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, I_MACRO, O_MACRO, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL, \
XXXXXXX, XXXXXXX, A_MACRO, XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX,   XXXXXXX, KC_ENTER, \
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PREV_WORD, KC_PREV_WORD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,KC_RSFT, TO(_BASE), \
          _______,          KC_LALT, _______, _______,          _______,                   KC_RALT,                            _______ \
   )
};

#ifdef USE_LEDS_FOR_LAYERS
// example of how to use LEDs as layer indicators
static uint8_t top = 1;
static uint8_t middle = 0;
static uint8_t bottom = 0;

layer_state_t layer_state_set_user(layer_state_t state) {
    top = middle = bottom = 0;
    switch (get_highest_layer(state)) {
    case _BASE:
        top = 1;
        break;
    case _FUNC:
        middle = 1;
        break;
    default: //  for any other layers, or the default layer
        break;
    }
  return state;
}

// override kb level function
bool led_update_user(led_t usb_led) {
    writePin(B1, !top);
    writePin(B2, !middle);
    writePin(B3, !bottom);
    return false; // we are using LEDs for something else override kb
}
#endif
