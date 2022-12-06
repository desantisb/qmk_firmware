#include QMK_KEYBOARD_H

#define WINMC MAGIC_TOGGLE_CTL_GUI
#define L2_SPC LT(2,KC_SPC)
#define L3_ENT LT(3,KC_ENT)
#define L4_SPC LT(4,KC_SPC)
#define L4_ENT LT(4,KC_ENT)
#define MTA MT(MOD_LCTL,KC_A)
#define MTS MT(MOD_LALT,KC_S)
#define MTD MT(MOD_LGUI,KC_D)
#define MTZ MT(MOD_LSFT,KC_Z)
#define MTF MT(MOD_LSFT,KC_F)
#define MTSCLN MT(MOD_LCTL,KC_SCLN)
#define MTL MT(MOD_LALT,KC_L)
#define MTK MT(MOD_LGUI,KC_K)
#define MTSLSH MT(MOD_LSFT,KC_SLSH)
#define MTJ MT(MOD_LSFT,KC_J)

enum custom_keycodes {
    PIN = SAFE_RANGE,
    CF,
    MAIL,
    PW,
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

    case PW:
        if (record->event.pressed) {
           SEND_STRING("@Pwam:HP2@");
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,     MTA,     MTS,     MTD,     MTF,    KC_G,                         KC_H,     MTJ,     MTK,     MTL,  MTSCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,     MTZ,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT,  MTSLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TAB, KC_BSPC,  L2_SPC,     L3_ENT,  KC_GRV, KC_QUOT
                                      //`--------------------------'  `--------------------------'
  ),
/*
  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, KC_LGUI,  L2_SPC,     L3_ENT,  KC_GRV, KC_HYPR
                                      //`--------------------------'  `--------------------------'
  ),*/

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,  KC_ESC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     L4_ENT, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_BSLS, KC_LBRC, KC_RBRC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_PIPE, KC_LCBR, KC_RCBR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, KC_DEL,  L4_SPC,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX,      PW,    MAIL,      CF,     PIN,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   TG(1),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        WINMC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,KC__VOLUP,KC_BRMU, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MPLY,KC__VOLDOWN,KC_BRMD,KC_MNXT,XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};
