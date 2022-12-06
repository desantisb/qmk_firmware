#include QMK_KEYBOARD_H

// Layers keycodes and definitions
enum planck_layers {
    _MIRYOKU,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MACRO_LAY,
    _NUMPAD
};

enum planck_keycodes { BASE = SAFE_RANGE, MA_PIN, MA_MAIL, MA_NAME, MA_CF};

// Tap Dance definitions
enum {
    TD_ESC_GRV,
    TD_QUOT_DQUO,
    TD_SFTCAPS,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_ESC),
    [TD_QUOT_DQUO] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
    [TD_SFTCAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT,KC_CAPS),
//    [] = ACTION_TAP_DANCE_DOUBLE(,),
};

// Macros definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MA_PIN:
        if (record->event.pressed) {
            SEND_STRING("221208"SS_TAP(X_ENTER));
        } else {
        }
        break;

    case MA_MAIL:
        if (record->event.pressed) {
            SEND_STRING("desantisb@gmail.com");
        } else {
        }
        break;

    case MA_CF:
        if (record->event.pressed) {
            SEND_STRING("DSNBNN86T15F839Y");
        } else {
        }
        break;

    case MA_NAME:
        if (record->event.pressed) {
            SEND_STRING("Bruno Antonio De Santis");
        } else {
        }
        break;
    }
    return true;
};



//Layouts definitions
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MIRYOKU] = LAYOUT_ortho_4x12(
        KC_Q,         KC_W,         KC_F,         KC_P,         KC_G,         XXXXXXX,      XXXXXXX,      KC_J,         KC_L,         KC_U,         KC_Y,         KC_SCLN,
        MT(MOD_LCTL,KC_A),MT(MOD_LALT,KC_R),MT(MOD_LGUI,KC_S),MT(MOD_LSFT,KC_T),KC_D,XXXXXXX,XXXXXXX,     KC_H, MT(MOD_RSFT,KC_N),MT(MOD_RGUI,KC_E),MT(MOD_RALT,KC_I),MT(MOD_RCTL,KC_O),
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         XXXXXXX,      XXXXXXX,      KC_K,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
        XXXXXXX,XXXXXXX,LT(_NUMPAD,KC_ESC),LT(_MACRO_LAY,KC_TAB),LT(_LOWER,KC_SPC), XXXXXXX,XXXXXXX,LT(_RAISE,KC_ENT),KC_BSPC,KC_DEL,               XXXXXXX,      XXXXXXX
    ),
    [_LOWER] = LAYOUT_ortho_4x12(
        KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC,      XXXXXXX,      XXXXXXX,      KC_CIRC,      KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_RPRN,
        KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,        XXXXXXX,      XXXXXXX,      KC_F6,        KC_UNDS,      KC_PLUS,      KC_LBRC,      KC_RBRC,
        KC_F7,        KC_F8,        KC_F9,        KC_F10,       KC_F11,       XXXXXXX,      XXXXXXX,      KC_F12,       S(KC_NUHS),   S(KC_NUBS),   KC_LCBR,      KC_RCBR,
        XXXXXXX,      XXXXXXX,      _______,      _______,      _______,      XXXXXXX,      XXXXXXX,      _______,      _______,      _______,      XXXXXXX,      XXXXXXX
    ),
    [_RAISE] = LAYOUT_ortho_4x12(
        KC_1,         KC_2,         KC_3,         KC_4,         KC_5,         XXXXXXX,      XXXXXXX,      KC_6,         KC_7,         KC_8,         KC_9,         KC_0,
        KC_GRAVE,     XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_MINS,      KC_EQL,       XXXXXXX,      KC_QUOTE,
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_NUHS,      KC_NUBS,      XXXXXXX,      XXXXXXX,
        XXXXXXX,      XXXXXXX,      _______,      _______,      _______,      XXXXXXX,      XXXXXXX,      _______,      _______,      _______,      XXXXXXX,      XXXXXXX
    ),
    [_ADJUST] = LAYOUT_ortho_4x12(
        RESET,        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        OUT_USB,      OUT_BT,       XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      MA_PIN,       XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        XXXXXXX,      XXXXXXX,      _______,      _______,      _______,      XXXXXXX,      XXXXXXX,      _______,      _______,      _______,      XXXXXXX,      XXXXXXX
    ),
    [_NUMPAD] = LAYOUT_ortho_4x12(
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_PPLS,      KC_PMNS,      KC_P7,        KC_P8,        KC_P9,        XXXXXXX,      XXXXXXX,
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_PAST,      KC_PSLS,      KC_P4,        KC_P5,        KC_P6,        XXXXXXX,      XXXXXXX,
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_PEQL,      KC_P1,        KC_P2,        KC_P3,        XXXXXXX,      XXXXXXX,
        XXXXXXX,      XXXXXXX,      _______,      _______,      _______,      XXXXXXX,      XXXXXXX,      KC_PDOT,      KC_P0,        XXXXXXX,      XXXXXXX,      XXXXXXX
    ),
    [_MACRO_LAY] = LAYOUT_ortho_4x12(
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      DM_REC1,      DM_REC2,      XXXXXXX,      XXXXXXX,      KC_UP,        XXXXXXX,      XXXXXXX,
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      DM_PLY1,      DM_PLY2,      XXXXXXX,      KC_LEFT,      KC_DOWN,      KC_RIGHT,     XXXXXXX,
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      DM_RSTP,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        XXXXXXX,      XXXXXXX,      _______,      _______,      _______,      XXXXXXX,      XXXXXXX,      _______,      _______,      _______,      XXXXXXX,      XXXXXXX
    )
};

//Tri layer state
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
