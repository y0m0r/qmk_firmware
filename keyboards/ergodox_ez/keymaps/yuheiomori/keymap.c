#include QMK_KEYBOARD_H

#define MAC 0   // default layer
#define MACFN 1 // function layer

// SUPER = Ctrl + Alt + Cmd
#define SUPER(kc)   LCAG(kc)
#define SUPER_T(kc) LCAG_T(kc)

// カスタムキーコード
enum custom_keycodes {
    MS_LOCK = SAFE_RANGE,   // マウス左クリック ロック/解除
    CB_SUPER,               // Ctrl+Alt+Cmd (コンボ用)
    CB_HYPER,               // Ctrl+Alt+Cmd+Shift (コンボ用)
};

// クリックロック状態
static bool mouse_lock = false;

// コンボの定義
const uint16_t PROGMEM combo_super_jk[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_super_fd[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM combo_hyper_kl[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_hyper_ds[] = {KC_D, KC_S, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_super_jk, CB_SUPER),   // J + K = SUPER (Ctrl+Alt+Cmd)
    COMBO(combo_super_fd, CB_SUPER),   // F + D = SUPER (Ctrl+Alt+Cmd)
    COMBO(combo_hyper_kl, CB_HYPER),   // K + L = Hyper (Ctrl+Alt+Cmd+Shift)
    COMBO(combo_hyper_ds, CB_HYPER),   // D + S = Hyper (Ctrl+Alt+Cmd+Shift)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Mac
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |  1   |   2  |   3  |   4  |   5  | `~   |           | `~   |   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |  Q   |   W  |   E  |   R  |   T  | Hypr |           | Hypr |   Y  |   U  |   I  |   O  |   P  |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CTRL   |  A   |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |  K   |   L  |   ;  | '"     |
 * |--------+------+------+------+------+------|SUPER |           |SUPER |------+------+------+------+------+--------|
 * | LShift |  Z   |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   |  \     |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | cut  | paste| copy | Alt  | LGUI |                                       | RGUI | RCTL | [    | ]    |  L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | SP+1 | LFn |       | left |right |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       | Up   |        |      |
 *                                 |Space |Back  |----- |       |----- | RClick |Enter |
 *                                 |      |Space | PgDn |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
[MAC] = LAYOUT_ergodox_pretty(
    // left hand                                                                        // right hand
    KC_ESC,       KC_1,       KC_2,       KC_3,    KC_4,    KC_5,    KC_GRV,            KC_GRV,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
    KC_TAB,       KC_Q,       KC_W,       KC_E,    KC_R,    KC_T,    HYPR_T(KC_NO),     HYPR_T(KC_NO),   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_LCTL,      KC_A,       KC_S,       KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,      KC_Z,       KC_X,       KC_C,    KC_V,    KC_B,    SUPER_T(KC_NO),    SUPER_T(KC_NO),  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
    LGUI(KC_X),   LGUI(KC_V), LGUI(KC_C), KC_LALT, KC_LGUI,                                              KC_RGUI, KC_RCTL, KC_LBRC, KC_RBRC, TO(MACFN),
                                                            MS_ACL1, MO(MACFN),           KC_LEFT, KC_RGHT,
                                                                     KC_PGUP,           KC_UP,
                                                   KC_SPC,  KC_BSPC, KC_PGDN,           KC_DOWN, MS_BTN2, KC_ENT
),
/* Keymap 1: Mac function Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |           | F7   |  F8  |  F9  | F10  |  F11 |  F12 |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |RGBTOG|RGBMOD|RGBHUI|RGBSAI|RGBVAI|Hyper |           |Hyper |DrgLck|LClick|RClick|      |      |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CTRL   |CMBTOG|DMREC1|DMPLY1|DMRSTP|      |------|           |------| M-L  | M-Dn | M-U  | M-R  |      |  '"    |
 * |--------+------+------+------+------+------|SUPER |           |SUPER |------+------+------+------+------+--------|
 * | LShift |BOOT  |DMREC2|DMPLY2|      |      |      |           |      | WH-L | WH-U | WH_D | WH_R |      |  \     |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | cut  | paste| copy | Alt  | LGUI |                                       | RGUI |      |      |      | L0   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | SP+1 | LFn  |       | left |right |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | PgUp |       | Up   |      |      |
 *                                 |Space |Back  |------|       |------|RClick|Enter |
 *                                 |      |Space | PgDn |       | Down |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MACFN] = LAYOUT_ergodox_pretty(
    // left hand                                                                   // right hand
    KC_TRNS,      KC_F1,      KC_F2,      KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_F7,        KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
    KC_TRNS,      UG_TOGG,    UG_NEXT,    UG_HUEU, UG_SATU, UG_VALU, KC_TRNS,      KC_TRNS,      MS_LOCK, MS_BTN1, MS_BTN2, KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS,      CM_TOGG,    DM_REC1,    DM_PLY1, DM_RSTP, KC_NO,                                  MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, KC_NO,   KC_TRNS,
    KC_TRNS,      QK_BOOT,    DM_REC2,    DM_PLY2, KC_NO,   KC_NO,   KC_NO,        KC_NO,        MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR, KC_NO,   KC_TRNS,
    KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                               KC_TRNS, KC_NO,   KC_NO,   KC_NO,   TO(MAC),
                                                            KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS,
                                                                     KC_TRNS,      KC_TRNS,
                                                   KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
),

};

// カスタムキーコードの処理
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MS_LOCK:
            if (record->event.pressed) {
                // ドラッグロックのトグル (Shift+クリック押しっぱなし)
                mouse_lock = !mouse_lock;
                if (mouse_lock) {
                    register_code(KC_LSFT);
                    register_code16(MS_BTN1);
                } else {
                    unregister_code16(MS_BTN1);
                    unregister_code(KC_LSFT);
                }
            }
            return false;
        case CB_SUPER:
            // SUPER = Ctrl+Alt+Cmd
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_LGUI);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
            }
            return false;
        case CB_HYPER:
            // Hyper = Ctrl+Alt+Cmd+Shift
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_LGUI);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LSFT);
                unregister_code(KC_LGUI);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
            }
            return false;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
    ergodox_board_led_off();
    ergodox_right_led_1_on();   // MACレイヤー = LED1のみ点灯
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
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
