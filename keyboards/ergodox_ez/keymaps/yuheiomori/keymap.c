#include QMK_KEYBOARD_H

#define MAC 0   // default layer
#define MACFN 1 // function layer

// コンボ用カスタムキーコード
enum custom_keycodes {
    CB_PAREN = SAFE_RANGE,  // ()
    CB_BRACK,               // []
    CB_BRACE,               // {}
    CB_UNDER,               // _
    CB_ARROW,               // =>
};

// コンボの定義
const uint16_t PROGMEM combo_backspace[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_enter[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_escape[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_paren[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_bracket[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_brace[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_underscore[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_arrow[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_backspace, KC_BSPC),   // S + D = Backspace
    COMBO(combo_enter, KC_ENT),        // K + L = Enter
    COMBO(combo_escape, KC_ESC),       // J + K = Escape
    COMBO(combo_paren, CB_PAREN),      // U + I = ()
    COMBO(combo_bracket, CB_BRACK),    // I + O = []
    COMBO(combo_brace, CB_BRACE),      // O + P = {}
    COMBO(combo_underscore, CB_UNDER), // M + , = _
    COMBO(combo_arrow, CB_ARROW),      // , + . = =>
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Mac
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |  1   |   2  |   3  |   4  |   5  | `~   |           | `~   |   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |  Q   |   W  |   E  |   R  |   T  | Hypr |           | Hypr |   Y  |   U  |   I  |   O  |   P  |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CTRL   |  A   |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |  K   |   L  |   ;  | '"     |
 * |--------+------+------+------+------+------| LFn  |           | LFn  |------+------+------+------+------+--------|
 * | LShift |  Z   |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   |  \     |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | cut  | paste| copy | Alt  | LGUI |                                       | RGUI | RCTL | [    | ]    |  L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | BTN4 | BTN5 |       | left |right |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       | Up   |        |      |
 *                                 |Space |Back  |----- |       |----- | RClick |Enter |
 *                                 |      |Space | PgDn |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
[MAC] = LAYOUT_ergodox_pretty(
    // left hand                                                                   // right hand
    KC_ESC,       KC_1,       KC_2,       KC_3,    KC_4,    KC_5,    KC_GRV,       KC_GRV,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
    KC_TAB,       KC_Q,       KC_W,       KC_E,    KC_R,    KC_T,    HYPR_T(KC_NO),HYPR_T(KC_NO),KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_LCTL,      KC_A,       KC_S,       KC_D,    KC_F,    KC_G,                                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,      KC_Z,       KC_X,       KC_C,    KC_V,    KC_B,    MO(MACFN),    MO(MACFN),    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
    LGUI(KC_X),   LGUI(KC_V), LGUI(KC_C), KC_LALT, KC_LGUI,                                               KC_RGUI, KC_RCTL, KC_LBRC, KC_RBRC, TO(MACFN),
                                                            MS_BTN4, MS_BTN5,      KC_LEFT, KC_RGHT,
                                                                     KC_PGUP,      KC_UP,
                                                   KC_SPC,  KC_BSPC, KC_PGDN,      KC_DOWN, MS_BTN2, KC_ENT
),

/* Keymap 1: Mac function Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |           | F7   |  F8  |  F9  | F10  |  F11 |  F12 |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |RGBTOG|RGBMOD|RGBHUI|RGBSAI|RGBVAI|Hyper |           |Hyper |      |LClick|RClick|      |      |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CTRL   |      |      |      |      |      |------|           |------| M-L  | M-Dn | M-U  | M-R  |      |  '"    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |EECLR |      | SP+0 | SP+1 | SP+2 |      |           |      | WH-L | WH-U | WH_D | WH_R |      |  \     |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | cut  | paste| copy | Alt  | LGUI |                                       | RGUI |      |      |      | L0   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | BTN4 | BTN5 |       | left |right |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | PgUp |       | Up   |      |      |
 *                                 |Space |Back  |------|       |------|RClick|Enter |
 *                                 |      |Space | PgDn |       | Down |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MACFN] = LAYOUT_ergodox_pretty(
    // left hand                                                                   // right hand
    KC_TRNS,      KC_F1,      KC_F2,      KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_F7,        KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
    KC_TRNS,      UG_TOGG,    UG_NEXT,    UG_HUEU, UG_SATU, UG_VALU, KC_TRNS,      KC_TRNS,      KC_NO,   MS_BTN1, MS_BTN2, KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS,      KC_NO,      KC_NO,      KC_NO,   KC_NO,  KC_NO,                                MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, KC_NO,   KC_TRNS,
    KC_TRNS,      EE_CLR,     KC_NO,      MS_ACL0, MS_ACL1, MS_ACL2, KC_NO,        KC_NO,        MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR, KC_NO,   KC_TRNS,
    KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                               KC_TRNS, KC_NO,   KC_NO,   KC_NO,   TO(MAC),
                                                            KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS,
                                                                     KC_TRNS,      KC_TRNS,
                                                   KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
),

};

// カスタムキーコードの処理（文字列送信）
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case CB_PAREN:
                SEND_STRING("()");
                return false;
            case CB_BRACK:
                SEND_STRING("[]");
                return false;
            case CB_BRACE:
                SEND_STRING("{}");
                return false;
            case CB_UNDER:
                SEND_STRING("_");
                return false;
            case CB_ARROW:
                SEND_STRING("=>");
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
    ergodox_board_led_off();
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
}

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case MAC:
            ergodox_right_led_1_on();
            break;
        case MACFN:
            ergodox_right_led_2_on();
            break;
        default:
            break;
    }

    return state;
}
