#include QMK_KEYBOARD_H

// Layers keycodes and definitions
enum planck_layers {
    _COLEMAK,
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MACRO_LAY
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
//Advanced Tap Dance
/*
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    X_CTL,
    X_SFTCAPS
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void x_finished(qk_tap_dance_state_t *state, void *user_data);
void x_reset(qk_tap_dance_state_t *state, void *user_data);
*/
//END OF ADVANCED TAP DANCE

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
    [_COLEMAK] = LAYOUT_ortho_4x12(
        TD(TD_ESC_GRV), KC_Q,       KC_W,         KC_F,         KC_P,         KC_G,         KC_J,         KC_L,         KC_U,         KC_Y,         KC_SCLN,      KC_BSPC,
        KC_TAB,       KC_A,         KC_R,         KC_S,         KC_T,         KC_D,         KC_H,         KC_N,         KC_E,         KC_I,         KC_O,         TD(TD_QUOT_DQUO),
        KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_K,         KC_M,         KC_COMM,      KC_DOT,       KC_UP,        KC_RSFT,
        KC_LCTL,      KC_LALT,      KC_LGUI,      MO(_MACRO_LAY),MO(_LOWER),  KC_SPC,       KC_ENT,       MO(_RAISE),   KC_SLSH,      KC_LEFT,      KC_DOWN,      KC_RGHT
    ),
    [_QWERTY] = LAYOUT_ortho_4x12(
        _______,      KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,         _______,
        _______,      KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,         KC_J,         KC_K,         KC_L,         KC_SCLN,      _______,
        _______,      KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,         KC_M,         _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    ),
    [_LOWER] = LAYOUT_ortho_4x12(
        KC_TILD,      KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC,      KC_CIRC,      KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_RPRN,      KC_BSPC,
        KC_DEL,       KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,        KC_F6,        KC_UNDS,      KC_PLUS,      KC_LCBR,      KC_RCBR,      KC_PIPE,
        KC_CAPS,      KC_F7,        KC_F8,        KC_F9,        KC_F10,       KC_F11,       KC_F12,       S(KC_NUHS),   S(KC_NUBS),   _______,      KC__VOLUP,    _______,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      KC_MNXT,      KC__VOLDOWN,  KC_MPLY
    ),
    [_RAISE] = LAYOUT_ortho_4x12(
        KC_ESC,       KC_1,         KC_2,         KC_3,         KC_4,         KC_5,         KC_6,         KC_7,         KC_8,         KC_9,         KC_0,         KC_BSPC,
        KC_DEL,       KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,        KC_F6,        KC_MINS,      KC_EQL,       KC_LBRC,      KC_RBRC,      KC_BSLS,
        KC_CAPS,      KC_F7,        KC_F8,        KC_F9,        KC_F10,       KC_F11,       KC_F12,       KC_NUHS,      KC_NUBS,      _______,      KC_PGUP,      _______,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      KC_HOME,      KC_PGDN,      KC_END
    ),
    [_ADJUST] = LAYOUT_ortho_4x12(
        _______,      RESET,        _______,      _______,      _______,      _______,      TG(_QWERTY), _______,      _______,      _______,      _______,      _______,
        _______,      OUT_USB,      OUT_BT,       _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      KC_BRMU,      _______,
        KC_POWER,     KC_SLEP,      KC_WAKE,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      KC_BRMD,      _______
    ),
    [_MACRO_LAY] = LAYOUT_ortho_4x12(
        DM_REC1,      DM_REC2,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      MA_PIN,       _______ ,
        DM_PLY1,      DM_PLY2,      DM_RSTP,      _______,      _______,      _______,      _______,      _______,      _______,      KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2 ,
        _______,      _______,      _______,      MA_CF,        _______,      MA_NAME,      _______,      MA_MAIL,      _______,      KC_MS_BTN1,   KC_MS_UP,     KC_MS_BTN2 ,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      KC_MS_LEFT,   KC_MS_DOWN,   KC_MS_RIGHT
    )
};

//Tri layer state
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
