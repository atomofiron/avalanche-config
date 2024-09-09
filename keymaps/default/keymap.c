#include QMK_KEYBOARD_H

enum layer {
    LAYER_0,
    LAYER_1,
};
enum {
    TD_SHFT_CAPS,
};

#define FN_1 MO(LAYER_1)

tap_dance_action_t tap_dance_actions[] = {
    [TD_SHFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_0] = LAYOUT(
                 KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC,
                 KC_EQL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC,
        KC_TAB,  KC_MINS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_RGHT, KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, FN_1,
        TD(TD_SHFT_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LEFT, KC_UP,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                                   UG_NEXT, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  KC_ENT,  KC_DOWN, TD(TD_SHFT_CAPS), KC_TAB,  KC_MUTE
    ),
    [LAYER_1] = LAYOUT(
                 KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
                 UG_TOGG, UG_NEXT, UG_HUEU, UG_SATU, UG_VALU, KC_BRIU,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12,
        KC_CAPS, XXXXXXX, UG_PREV, UG_HUED, UG_SATD, UG_VALD, KC_BRID, KC_HOME, KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                 KC_APP,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_END,  KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, _______, _______, _______, KC_MCTL, KC_LPAD, KC_PGDN, KC_MPLY, KC_MUTE, XXXXXXX
    ),
};

