#include QMK_KEYBOARD_H

enum keycodes {
    DYNAMIC_MACRO_RANGE = SAFE_RANGE
};

#include "dynamic_macro.h"

void matrix_init_user(void) {
    set_unicode_input_mode(UC_MAC);
};

#define M_PLAY1 DYN_MACRO_PLAY1
#define M_START1 DYN_REC_START1
#define M_STOP DYN_REC_STOP

#define _WIN 0
#define _S_WIN 1
#define _LINUX 2
#define _MAC   3
#define _S_UNIX 4
#define _MEDIA 5
#define _KBD 6
#define _QWERTY 7

#define W_UML_A RALT(KC_Q)
#define W_UML_SA RALT(S(KC_Q))
#define W_UML_O RALT(KC_P)
#define W_UML_SO RALT(S(KC_P))

#define U_UML_A UC(0x00E4)
#define U_UML_SA UC(0x00C4)
#define U_UML_O UC(0x00F6)
#define U_UML_SO UC(0x00D6)
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_WIN] = LAYOUT_all(
		KC_DLR,    KC_AMPR,    KC_LBRC,  KC_LCBR, KC_RCBR,    KC_LPRN,     KC_EQL,  KC_ASTR, KC_RPRN,    KC_PLUS,    KC_RBRC,     KC_EXLM,  KC_HASH,    TO(_QWERTY), TO(_LINUX),
		KC_TAB,    KC_SCLN,    KC_COMM,  KC_DOT,  KC_P,       KC_Y,        KC_F,    KC_G,    KC_C,       KC_R,       KC_L,        KC_SLSH,  KC_AT,      KC_BSLS,
		KC_BSPC,   KC_A,       KC_O,     KC_E,    KC_U,       KC_I,        KC_D,    KC_H,    KC_T,       KC_N,       KC_S,        KC_MINS,  KC_ENT,
        W_UML_O,   W_UML_A,    KC_QUOT,  KC_Q,    KC_J,       KC_K,        KC_X,    KC_B,    KC_M,       KC_W,       KC_V,        KC_Z,     KC_HOME,    KC_UP,       KC_END,
		KC_LCTL,   KC_LGUI,    KC_LALT,  KC_SPC,  MO(_MEDIA), MO(_S_WIN),  KC_RALT, KC_ESC,  KC_LEFT,    KC_DOWN,    KC_RGHT),

	[_S_WIN] = LAYOUT_all(
		KC_TILDE,  KC_PERCENT, KC_7,     KC_5,    KC_3,       KC_1,        KC_9,    KC_0,    KC_2,       KC_4,       KC_6,        KC_8,     KC_GRAVE,   KC_TRNS,     KC_TRNS,
		S(KC_TAB), KC_COLON,   KC_LT,    KC_GT,   S(KC_P),    S(KC_Y),     S(KC_F), S(KC_G), S(KC_C),    S(KC_R),    S(KC_L),     KC_QUES,  KC_CIRC,    KC_PIPE,
		KC_TRNS,   S(KC_A),    S(KC_O),  S(KC_E), S(KC_U),    S(KC_I),     S(KC_D), S(KC_H), S(KC_T),    S(KC_N),    S(KC_S),     KC_UNDS,  KC_TRNS,
        W_UML_SO,  W_UML_SA,   KC_DQUO,  S(KC_Q), S(KC_J),    S(KC_K),     S(KC_X), S(KC_B), S(KC_M),    S(KC_W),    S(KC_V),     S(KC_Z),  S(KC_HOME), S(KC_UP),    S(KC_END),
		KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS, MO(_KBD),   KC_TRNS,     KC_TRNS, KC_TRNS, S(KC_LEFT), S(KC_DOWN), S(KC_RGHT)),

	[_LINUX] = LAYOUT_all(
		KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_TRNS,    KC_TRNS,     TO(_MAC),
		KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_TRNS,    KC_TRNS,
		KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_TRNS,
		U_UML_O,   U_UML_A,    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_TRNS,
		KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,    MO(_S_UNIX), KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS),

	[_MAC] = LAYOUT_all(
		KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_TRNS,    KC_TRNS,     TO(_WIN),
		KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_TRNS,    KC_TRNS,
		KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_TRNS,
		U_UML_O,   U_UML_A,    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_TRNS,
		KC_TRNS,   KC_LALT,    KC_LGUI,  KC_TRNS, KC_TRNS,    MO(_S_UNIX), KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS),

	[_S_UNIX] = LAYOUT_all(
		KC_TILDE,  KC_PERCENT, KC_7,     KC_5,    KC_3,       KC_1,        KC_9,    KC_0,    KC_2,       KC_4,       KC_6,        KC_8,     KC_GRAVE,   KC_TRNS,     KC_TRNS,
		S(KC_TAB), KC_COLON,   KC_LT,    KC_GT,   S(KC_P),    S(KC_Y),     S(KC_F), S(KC_G), S(KC_C),    S(KC_R),    S(KC_L),     KC_QUES,  KC_CIRC,    KC_PIPE,
		KC_TRNS,   S(KC_A),    S(KC_O),  S(KC_E), S(KC_U),    S(KC_I),     S(KC_D), S(KC_H), S(KC_T),    S(KC_N),    S(KC_S),     KC_UNDS,  KC_TRNS,
        U_UML_SO,  U_UML_SA,   KC_DQUO,  S(KC_Q), S(KC_J),    S(KC_K),     S(KC_X), S(KC_B), S(KC_M),    S(KC_W),    S(KC_V),     S(KC_Z),  S(KC_HOME), S(KC_UP),    S(KC_END),
		KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS, MO(_KBD),   KC_TRNS,     KC_TRNS, KC_TRNS, S(KC_LEFT), S(KC_DOWN), S(KC_RGHT)),

	[_MEDIA] = LAYOUT_all(
		KC_GRV,    KC_F1,      KC_F2,    KC_F3,   KC_F4,      KC_F5,       KC_F6,   KC_F7,   KC_F8,      KC_F9,      KC_F10,      KC_F11,   KC_F12,     KC_TRNS,     KC_TRNS,
		KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS, KC_7,    KC_8,       KC_9,       KC_ASTR,     KC_TRNS,  KC_TRNS,    KC_TRNS,
		KC_TRNS,   KC_TRNS,    M_START1, M_STOP,  M_PLAY1,    KC_TRNS,     KC_TRNS, KC_4,    KC_5,       KC_6,       KC_MINS,     KC_TRNS,  KC_TRNS,
		KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS, KC_0,    KC_1,       KC_2,       KC_3,        KC_PLUS,  KC_PGUP,    KC_TRNS,     KC_PGDN,
		KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,     KC_DEL,  KC_TRNS, KC_MPRV,    KC_MPLY,    KC_MNXT),

	[_KBD] = LAYOUT_all(
		KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_SLSH,  KC_TRNS,    KC_TRNS,     KC_TRNS,
		KC_TRNS,   RGB_TOG,    RGB_MOD,  RGB_HUI, RGB_HUD,    RGB_SAI,     RGB_SAD, RGB_VAI, RGB_VAD,    KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_TRNS,    RESET,
		KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_TRNS,
		KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS, BL_DEC,     BL_TOGG,     BL_INC,  BL_STEP, KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_TRNS,
		KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS),

    [_QWERTY] = LAYOUT_all(
        KC_ESC,    KC_1,       KC_2,     KC_3,    KC_4,       KC_5,        KC_6,    KC_7,    KC_8,       KC_9,       KC_0,        KC_MINS,  KC_EQL,     TO(_WIN),    KC_GRV,
        KC_TAB,    KC_Q,       KC_W,     KC_E,    KC_R,       KC_T,        KC_Y,    KC_U,    KC_I,       KC_O,       KC_P,        KC_LBRC,  KC_RBRC,    KC_DEL,
        KC_BSPC,   KC_A,       KC_S,     KC_D,    KC_F,       KC_G,        KC_H,    KC_J,    KC_K,       KC_L,       KC_SCLN,     KC_QUOT,  KC_ENT,
        KC_LSPO,   KC_NO,      KC_Z,     KC_X,    KC_C,       KC_V,        KC_B,    KC_N,    KC_M,       KC_COMM,    KC_DOT,      KC_SLSH,  KC_RSPC,    KC_UP,       KC_NO,
        KC_LCTL,   KC_LGUI,    KC_LALT,  KC_SPC,  KC_TRNS,    KC_SPC,      KC_RALT, KC_APP,  KC_LEFT,    KC_DOWN,    KC_RGHT),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }

    return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_ON_STATE(state, _LINUX)){
        set_unicode_input_mode(UC_LNX);
    }
    else if (IS_LAYER_ON_STATE(state, _MAC)){
        set_unicode_input_mode(UC_MAC);
    }
    return state;
};
