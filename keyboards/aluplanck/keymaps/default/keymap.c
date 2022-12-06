#include QMK_KEYBOARD_H

#define WINMC MAGIC_TOGGLE_CTL_GUI

// Defines names for use in layer keycodes and the keymap
enum planck_layers {
    _BASE,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum planck_keycodes {
  BASE = SAFE_RANGE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NUMPAD MO(_NUMPAD)
#define COLEMAK MO(_COLEMAK)

#define WINMC MAGIC_TOGGLE_CTL_GUI
#define L2_SPC LT(_LOWER,KC_SPC)
#define L3_ENT LT(_RAISE,KC_ENT)
#define L4_SPC LT(_ADJUST,KC_SPC)
#define L4_ENT LT(_ADJUST,KC_ENT)

enum custom_keycodes {
    PIN = SAFE_RANGE,
    CF,
    MAIL,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case PIN:
        if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING("221208"SS_TAP(X_ENT));
        } else {
        }
        break;

    case CF:
        if (record->event.pressed) {
           SEND_STRING("DSNBNN86T15F839Y");
        }
        break;

    case MAIL:
        if (record->event.pressed) {
           SEND_STRING("desantisb@gmail.com");
        }
        break;

    }
    return true;
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
[_BASE] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI, _______, LOWER,   L2_SPC,  L3_ENT,  RAISE,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
),

[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI, _______, LOWER,   L2_SPC,  L3_ENT,  RAISE,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
),

[_LOWER] = LAYOUT_planck_grid(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______,  L4_ENT, _______, _______,  _______, _______, _______
),

[_RAISE] = LAYOUT_planck_grid(
    _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,   KC_DEL,
    _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_BSLS, KC_LBRC, KC_RBRC,   KC_GRV,
    _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_PIPE, KC_LCBR, KC_RCBR,  _______,
    _______, _______, _______, _______, _______, L4_SPC, _______, _______, _______,  _______, _______,  _______
),

[_ADJUST] = LAYOUT_planck_grid(
    RESET,   _______, _______, MAIL,    CF,      PIN,     _______, _______, _______, _______, _______, TG(_COLEMAK),
    _______, OUT_USB, OUT_BT,  _______, _______, _______, _______, KC__VOLUP,KC_BRMU,_______, _______, _______,
    WINMC,   _______, _______, _______, _______, _______, KC_MPLY, KC__VOLDOWN,KC_BRMD,KC_MNXT,_______,_______,
    KC_POWER,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
