#include QMK_KEYBOARD_H

#define MAC 0   // default layer
#define MACFN 1 // function layer
#define FKEY 2  // F1-F12 / メディア layer (内側の下段キーで保持)

// SUPER = Ctrl + Alt + Cmd (コンボの出力に使う)
#define SUPER(kc) LCAG(kc)

// 内側の大きなキー4つは全てレイヤー保持キーにしている。
// 上段が MACFN、下段が FKEY で、どちらも左右両方にある。
// 「保持する手」と「操作する手」を必ず分けられるようにするため。
//   例: 左手で FKEY を保持 -> 右手で音量・メディア操作
//       右手で FKEY を保持 -> 左手で F1-F12
// 修飾キー(Hyper/SUPER)は専用キーを廃止し、コンボに一本化した。

// カスタムキーコード
enum custom_keycodes {
    MS_LOCK = SAFE_RANGE,   // マウス左クリック ロック/解除
};

// クリックロック状態
static bool mouse_lock = false;

// コンボの定義
const uint16_t PROGMEM combo_super_jk[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_super_fd[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM combo_hyper_kl[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_hyper_ds[] = {KC_D, KC_S, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_super_jk, SUPER(KC_NO)),   // J + K = SUPER (Ctrl+Alt+Cmd)
    COMBO(combo_super_fd, SUPER(KC_NO)),   // F + D = SUPER (Ctrl+Alt+Cmd)
    COMBO(combo_hyper_kl, KC_HYPR),        // K + L = Hyper (Ctrl+Alt+Cmd+Shift)
    COMBO(combo_hyper_ds, KC_HYPR),        // D + S = Hyper (Ctrl+Alt+Cmd+Shift)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Mac
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |  1   |   2  |   3  |   4  |   5  | `~   |           | `~   |   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |  Q   |   W  |   E  |   R  |   T  |MACFN |           |MACFN |   Y  |   U  |   I  |   O  |   P  |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CTRL   |  A   |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |  K   |   L  |   ;  | '"     |
 * |--------+------+------+------+------+------| FKEY |           | FKEY |------+------+------+------+------+--------|
 * | LShift |  Z   |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   |  \     |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | cut  | paste| copy | Alt  | LGUI |                                       | RGUI | RCTL | [    | ]    |      |
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
    KC_TAB,       KC_Q,       KC_W,       KC_E,    KC_R,    KC_T,    MO(MACFN),         MO(MACFN),       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_LCTL,      KC_A,       KC_S,       KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,      KC_Z,       KC_X,       KC_C,    KC_V,    KC_B,    MO(FKEY),          MO(FKEY),        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
    LGUI(KC_X),   LGUI(KC_V), LGUI(KC_C), KC_LALT, KC_LGUI,                                              KC_RGUI, KC_RCTL, KC_LBRC, KC_RBRC, KC_NO,
                                                            MS_ACL1, MO(MACFN),           KC_LEFT, KC_RGHT,
                                                                     KC_PGUP,           KC_UP,
                                                   KC_SPC,  KC_BSPC, KC_PGDN,           KC_DOWN, MS_BTN2, KC_ENT
),
/* Keymap 1: Mac function Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |           | F7   |  F8  |  F9  | F10  |  F11 |  F12 |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |RGBTOG|RGBMOD|RGBHUI|RGBSAI|RGBVAI|(保持)|           |(保持)|DrgLck|LClick|RClick|      |      |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CTRL   |CMBTOG|DMREC1|DMPLY1|DMRSTP|      |------|           |------| M-L  | M-Dn | M-U  | M-R  |      |  '"    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |      |DMREC2|DMPLY2|      |      |      |           |      | WH-L | WH-U | WH_D | WH_R |      |  \     |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | cut  | paste| copy | Alt  | LGUI |                                       | RGUI |      |      |      |      |
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
    KC_TRNS,      KC_NO,      DM_REC2,    DM_PLY2, KC_NO,   KC_NO,   KC_NO,        KC_NO,        MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR, KC_NO,   KC_TRNS,
    KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                               KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                                            KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS,
                                                                     KC_TRNS,      KC_TRNS,
                                                   KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: F key Layer (内側の下段キーを押している間だけ有効。左右どちらでも)
 *
 * 左手をホームポジションから動かさずに F1-F12 を打つためのレイヤー。
 * 最上段まで手を伸ばす必要をなくすのが目的。
 * 右手側は音量・輝度・メディア操作に使っている。
 *
 * QK_BOOT はここに置いている。このレイヤーは MO だけでトグルがないため、
 * 内側キーを意図的に押さえていない限り発火しない。
 *
 * ブートローダ起動: 内側の下段キー + ESC
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | BOOT   |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | F11  | F12  |      |      |      |      |           |      | 輝度-| 輝度+| 音量-| 音量+| ミュト|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |------|           |------| 前曲 | 再生 | 次曲 |      |      |        |
 * |--------+------+------+------+------+------|      |           | FKEY |------+------+------+------+------+--------|
 * |        |  F6  |  F7  |  F8  |  F9  | F10  |      |           |(保持)|      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[FKEY] = LAYOUT_ergodox_pretty(
    // left hand                                                                   // right hand
    QK_BOOT,      KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,      KC_F11,     KC_F12,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,      KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS,
    KC_TRNS,      KC_F1,      KC_F2,      KC_F3,   KC_F4,   KC_F5,                               KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,      KC_F6,      KC_F7,      KC_F8,   KC_F9,   KC_F10,  KC_TRNS,      KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                            KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS,
                                                                     KC_TRNS,      KC_TRNS,
                                                   KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
),

};

// カスタムキーコードの処理
// ドラッグロックを解除する。既に解除済みなら何もしない。
static void mouse_lock_release(void) {
    if (!mouse_lock) {
        return;
    }
    mouse_lock = false;
    unregister_code16(MS_BTN1);
    unregister_code(KC_LSFT);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MS_LOCK:
            if (record->event.pressed) {
                // ドラッグロックのトグル (Shift+クリック押しっぱなし)
                if (mouse_lock) {
                    mouse_lock_release();
                } else {
                    mouse_lock = true;
                    register_code(KC_LSFT);
                    register_code16(MS_BTN1);
                }
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

    // 通常レイヤーに戻ったらドラッグロックを解除する。
    // 解除は MACFN の Y を押すしかないため、ロックしたままレイヤーを
    // 抜けると Shift が押されっぱなしのまま気づけない。
    // マウスキーは MACFN 上にあるので、レイヤーを抜けた時点で
    // ドラッグは終わっているとみなしてよい。
    if (layer == MAC) {
        mouse_lock_release();
    }

    switch (layer) {
        case MAC:
            ergodox_right_led_1_on();
            break;
        case MACFN:
            ergodox_right_led_2_on();
            break;
        case FKEY:
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

    return state;
}
