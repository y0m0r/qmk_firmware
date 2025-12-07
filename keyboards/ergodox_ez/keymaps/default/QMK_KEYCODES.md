# QMK キーコード一覧（ErgoDox EZ 対応）

## 特殊キー

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `KC_NO` | `XXXXXXX` | 何もしない |
| `KC_TRANSPARENT` | `KC_TRNS`, `_______` | 下のレイヤーを透過 |

---

## 基本キー（アルファベット・数字）

| キーコード | 説明 |
|-----------|------|
| `KC_A` 〜 `KC_Z` | A〜Z |
| `KC_1` 〜 `KC_0` | 1〜0 |

---

## 記号・句読点

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `KC_MINUS` | `KC_MINS` | `-` |
| `KC_EQUAL` | `KC_EQL` | `=` |
| `KC_LEFT_BRACKET` | `KC_LBRC` | `[` |
| `KC_RIGHT_BRACKET` | `KC_RBRC` | `]` |
| `KC_BACKSLASH` | `KC_BSLS` | `\` |
| `KC_SEMICOLON` | `KC_SCLN` | `;` |
| `KC_QUOTE` | `KC_QUOT` | `'` |
| `KC_GRAVE` | `KC_GRV` | `` ` `` |
| `KC_COMMA` | `KC_COMM` | `,` |
| `KC_DOT` | | `.` |
| `KC_SLASH` | `KC_SLSH` | `/` |

### Shift + 記号

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `KC_TILDE` | `KC_TILD` | `~` |
| `KC_EXCLAIM` | `KC_EXLM` | `!` |
| `KC_AT` | | `@` |
| `KC_HASH` | | `#` |
| `KC_DOLLAR` | `KC_DLR` | `$` |
| `KC_PERCENT` | `KC_PERC` | `%` |
| `KC_CIRCUMFLEX` | `KC_CIRC` | `^` |
| `KC_AMPERSAND` | `KC_AMPR` | `&` |
| `KC_ASTERISK` | `KC_ASTR` | `*` |
| `KC_LEFT_PAREN` | `KC_LPRN` | `(` |
| `KC_RIGHT_PAREN` | `KC_RPRN` | `)` |
| `KC_UNDERSCORE` | `KC_UNDS` | `_` |
| `KC_PLUS` | | `+` |
| `KC_LEFT_CURLY_BRACE` | `KC_LCBR` | `{` |
| `KC_RIGHT_CURLY_BRACE` | `KC_RCBR` | `}` |
| `KC_PIPE` | | `\|` |

---

## 機能キー

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `KC_ENTER` | `KC_ENT` | Enter |
| `KC_ESCAPE` | `KC_ESC` | Escape |
| `KC_BACKSPACE` | `KC_BSPC` | Backspace |
| `KC_TAB` | | Tab |
| `KC_SPACE` | `KC_SPC` | Space |
| `KC_CAPS_LOCK` | `KC_CAPS` | Caps Lock |
| `KC_DELETE` | `KC_DEL` | Delete |
| `KC_INSERT` | `KC_INS` | Insert |
| `KC_HOME` | | Home |
| `KC_END` | | End |
| `KC_PAGE_UP` | `KC_PGUP` | Page Up |
| `KC_PAGE_DOWN` | `KC_PGDN` | Page Down |
| `KC_PRINT_SCREEN` | `KC_PSCR` | Print Screen |

---

## 矢印キー

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `KC_UP` | | ↑ |
| `KC_DOWN` | | ↓ |
| `KC_LEFT` | | ← |
| `KC_RIGHT` | `KC_RGHT` | → |

---

## ファンクションキー

| キーコード | 説明 |
|-----------|------|
| `KC_F1` 〜 `KC_F12` | F1〜F12 |
| `KC_F13` 〜 `KC_F24` | F13〜F24 |

---

## モディファイアキー

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `KC_LEFT_CTRL` | `KC_LCTL` | 左 Control |
| `KC_LEFT_SHIFT` | `KC_LSFT` | 左 Shift |
| `KC_LEFT_ALT` | `KC_LALT`, `KC_LOPT` | 左 Alt / Option |
| `KC_LEFT_GUI` | `KC_LGUI`, `KC_LCMD`, `KC_LWIN` | 左 GUI / Command / Win |
| `KC_RIGHT_CTRL` | `KC_RCTL` | 右 Control |
| `KC_RIGHT_SHIFT` | `KC_RSFT` | 右 Shift |
| `KC_RIGHT_ALT` | `KC_RALT`, `KC_ROPT`, `KC_ALGR` | 右 Alt / Option |
| `KC_RIGHT_GUI` | `KC_RGUI`, `KC_RCMD`, `KC_RWIN` | 右 GUI / Command / Win |

---

## テンキー

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `KC_KP_1` 〜 `KC_KP_0` | `KC_P1` 〜 `KC_P0` | テンキー 1〜0 |
| `KC_KP_SLASH` | `KC_PSLS` | テンキー `/` |
| `KC_KP_ASTERISK` | `KC_PAST` | テンキー `*` |
| `KC_KP_MINUS` | `KC_PMNS` | テンキー `-` |
| `KC_KP_PLUS` | `KC_PPLS` | テンキー `+` |
| `KC_KP_ENTER` | `KC_PENT` | テンキー Enter |
| `KC_KP_DOT` | `KC_PDOT` | テンキー `.` |
| `KC_NUM_LOCK` | `KC_NUM` | Num Lock |

---

## メディアキー

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `KC_AUDIO_MUTE` | `KC_MUTE` | ミュート |
| `KC_AUDIO_VOL_UP` | `KC_VOLU` | 音量 UP |
| `KC_AUDIO_VOL_DOWN` | `KC_VOLD` | 音量 DOWN |
| `KC_MEDIA_PLAY_PAUSE` | `KC_MPLY` | 再生/一時停止 |
| `KC_MEDIA_NEXT_TRACK` | `KC_MNXT` | 次のトラック |
| `KC_MEDIA_PREV_TRACK` | `KC_MPRV` | 前のトラック |
| `KC_MEDIA_STOP` | `KC_MSTP` | 停止 |
| `KC_MEDIA_FAST_FORWARD` | `KC_MFFD` | 早送り |
| `KC_MEDIA_REWIND` | `KC_MRWD` | 巻き戻し |
| `KC_BRIGHTNESS_UP` | `KC_BRIU` | 画面輝度 UP |
| `KC_BRIGHTNESS_DOWN` | `KC_BRID` | 画面輝度 DOWN |

---

## ブラウザ/アプリキー

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `KC_WWW_BACK` | `KC_WBAK` | ブラウザ戻る |
| `KC_WWW_FORWARD` | `KC_WFWD` | ブラウザ進む |
| `KC_WWW_REFRESH` | `KC_WREF` | ブラウザ更新 |
| `KC_WWW_STOP` | `KC_WSTP` | ブラウザ停止 |
| `KC_WWW_HOME` | `KC_WHOM` | ブラウザホーム |
| `KC_WWW_SEARCH` | `KC_WSCH` | ブラウザ検索 |
| `KC_WWW_FAVORITES` | `KC_WFAV` | ブラウザお気に入り |
| `KC_CALCULATOR` | `KC_CALC` | 電卓起動 |
| `KC_MAIL` | | メール起動 |
| `KC_MY_COMPUTER` | `KC_MYCM` | マイコンピュータ |
| `KC_MEDIA_SELECT` | `KC_MSEL` | メディアプレイヤー起動 |

---

## マウスキー

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `KC_MS_UP` | `KC_MS_U`, `MS_UP` | カーソル上 |
| `KC_MS_DOWN` | `KC_MS_D`, `MS_DOWN` | カーソル下 |
| `KC_MS_LEFT` | `KC_MS_L`, `MS_LEFT` | カーソル左 |
| `KC_MS_RIGHT` | `KC_MS_R`, `MS_RGHT` | カーソル右 |
| `KC_MS_BTN1` | `KC_BTN1`, `MS_BTN1` | 左クリック |
| `KC_MS_BTN2` | `KC_BTN2`, `MS_BTN2` | 右クリック |
| `KC_MS_BTN3` | `KC_BTN3`, `MS_BTN3` | 中クリック |
| `KC_MS_BTN4` | `KC_BTN4`, `MS_BTN4` | ボタン4 |
| `KC_MS_BTN5` | `KC_BTN5`, `MS_BTN5` | ボタン5 |
| `KC_MS_WH_UP` | `KC_WH_U` | ホイール上 |
| `KC_MS_WH_DOWN` | `KC_WH_D` | ホイール下 |
| `KC_MS_WH_LEFT` | `KC_WH_L` | ホイール左 |
| `KC_MS_WH_RIGHT` | `KC_WH_R` | ホイール右 |
| `KC_MS_ACCEL0` | `KC_ACL0` | マウス速度0（遅い） |
| `KC_MS_ACCEL1` | `KC_ACL1` | マウス速度1（中） |
| `KC_MS_ACCEL2` | `KC_ACL2` | マウス速度2（速い） |

---

## レイヤー操作

| 関数 | 説明 |
|------|------|
| `MO(layer)` | 押している間だけレイヤー有効（Momentary） |
| `TG(layer)` | レイヤーをトグル（Toggle） |
| `TO(layer)` | 指定レイヤーに切り替え（他はオフ） |
| `TT(layer)` | タップでトグル、ホールドで一時有効（Tap-Toggle） |
| `DF(layer)` | デフォルトレイヤーを変更 |
| `LT(layer, kc)` | ホールドでレイヤー、タップでキー（Layer-Tap） |
| `OSL(layer)` | 次の1キーだけレイヤー有効（One-Shot Layer） |
| `LM(layer, mod)` | モディファイア付きレイヤー |

### 使用例

```c
MO(1)           // 押している間だけレイヤー1
TG(2)           // レイヤー2をオン/オフ切り替え
LT(1, KC_SPC)   // ホールドでレイヤー1、タップでスペース
TT(SYMB)        // タップでトグル、ホールドで一時有効
```

---

## Mod-Tap（ホールドでモディファイア、タップでキー）

| 関数 | エイリアス | 説明 |
|------|-----------|------|
| `MT(mod, kc)` | | 汎用 Mod-Tap |
| `LCTL_T(kc)` | `CTL_T(kc)` | ホールド: Ctrl, タップ: kc |
| `LSFT_T(kc)` | `SFT_T(kc)` | ホールド: Shift, タップ: kc |
| `LALT_T(kc)` | `ALT_T(kc)` | ホールド: Alt, タップ: kc |
| `LGUI_T(kc)` | `GUI_T(kc)` | ホールド: GUI/Cmd, タップ: kc |
| `RCTL_T(kc)` | | ホールド: 右 Ctrl, タップ: kc |
| `RSFT_T(kc)` | | ホールド: 右 Shift, タップ: kc |
| `RALT_T(kc)` | | ホールド: 右 Alt, タップ: kc |
| `RGUI_T(kc)` | | ホールド: 右 GUI, タップ: kc |
| `MEH_T(kc)` | | ホールド: Ctrl+Shift+Alt, タップ: kc |
| `HYPR_T(kc)` | | ホールド: Ctrl+Shift+Alt+GUI, タップ: kc |

### 使用例

```c
CTL_T(KC_Z)     // ホールドでCtrl、タップでZ
GUI_T(KC_QUOT)  // ホールドでCommand、タップで'
HYPR_T(KC_NO)   // Hyperキー（単独では何もしない）
```

---

## One-Shot キー

| 関数/キーコード | エイリアス | 説明 |
|----------------|-----------|------|
| `OSM(mod)` | | 次のキーにだけモディファイア適用 |
| `OSL(layer)` | | 次のキーにだけレイヤー適用 |
| `QK_ONE_SHOT_ON` | `OS_ON` | One-Shot 有効化 |
| `QK_ONE_SHOT_OFF` | `OS_OFF` | One-Shot 無効化 |
| `QK_ONE_SHOT_TOGGLE` | `OS_TOGG` | One-Shot トグル |

### モディファイア定数

```c
MOD_LCTL  // 左 Control
MOD_LSFT  // 左 Shift
MOD_LALT  // 左 Alt
MOD_LGUI  // 左 GUI
MOD_RCTL  // 右 Control
MOD_RSFT  // 右 Shift
MOD_RALT  // 右 Alt
MOD_RGUI  // 右 GUI
MOD_MEH   // Ctrl + Shift + Alt
MOD_HYPR  // Ctrl + Shift + Alt + GUI
```

### 使用例

```c
OSM(MOD_LSFT)           // 次のキーだけShift
OSM(MOD_LCTL | MOD_LSFT) // 次のキーだけCtrl+Shift
OSL(1)                  // 次のキーだけレイヤー1
```

---

## RGB / バックライト

### RGB Lighting

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `RGB_TOG` | `UG_TOGG` | RGB オン/オフ |
| `RGB_MODE_FORWARD` | `RGB_MOD`, `UG_NEXT` | 次のモード |
| `RGB_MODE_REVERSE` | `RGB_RMOD`, `UG_PREV` | 前のモード |
| `RGB_HUI` | `UG_HUEU` | 色相 UP |
| `RGB_HUD` | `UG_HUED` | 色相 DOWN |
| `RGB_SAI` | `UG_SATU` | 彩度 UP |
| `RGB_SAD` | `UG_SATD` | 彩度 DOWN |
| `RGB_VAI` | `UG_VALU` | 明度 UP |
| `RGB_VAD` | `UG_VALD` | 明度 DOWN |
| `RGB_SPI` | | 速度 UP |
| `RGB_SPD` | | 速度 DOWN |

### RGB モード

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `RGB_MODE_PLAIN` | `RGB_M_P` | 単色 |
| `RGB_MODE_BREATHE` | `RGB_M_B` | ブリーズ（呼吸） |
| `RGB_MODE_RAINBOW` | `RGB_M_R` | レインボー |
| `RGB_MODE_SWIRL` | `RGB_M_SW` | スワール |
| `RGB_MODE_SNAKE` | `RGB_M_SN` | スネーク |
| `RGB_MODE_KNIGHT` | `RGB_M_K` | ナイトライダー |
| `RGB_MODE_XMAS` | `RGB_M_X` | クリスマス |
| `RGB_MODE_GRADIENT` | `RGB_M_G` | グラデーション |
| `RGB_MODE_TWINKLE` | `RGB_M_TW` | トゥインクル |

### バックライト

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `QK_BACKLIGHT_ON` | `BL_ON` | バックライト ON |
| `QK_BACKLIGHT_OFF` | `BL_OFF` | バックライト OFF |
| `QK_BACKLIGHT_TOGGLE` | `BL_TOGG` | バックライト切替 |
| `QK_BACKLIGHT_UP` | `BL_UP` | 明るく |
| `QK_BACKLIGHT_DOWN` | `BL_DOWN` | 暗く |
| `QK_BACKLIGHT_STEP` | `BL_STEP` | 段階切替 |
| `QK_BACKLIGHT_TOGGLE_BREATHING` | `BL_BRTG` | ブリーズ切替 |

---

## システム/QMK 特殊キー

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `QK_BOOTLOADER` | `QK_BOOT` | ブートローダーモード（ファームウェア書き込み） |
| `QK_REBOOT` | `QK_RBT` | キーボード再起動 |
| `QK_CLEAR_EEPROM` | `EE_CLR` | EEPROM クリア（設定リセット） |
| `QK_DEBUG_TOGGLE` | `DB_TOGG` | デバッグモード切替 |
| `QK_MAKE` | | ファームウェアビルド |
| `QK_GRAVE_ESCAPE` | `QK_GESC` | Shift/GUI押下時は `~`、通常は Esc |
| `QK_LEADER` | `QK_LEAD` | リーダーキー開始 |
| `QK_LOCK` | | キーロック |

### システム電源

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `KC_SYSTEM_POWER` | `KC_PWR` | 電源オフ |
| `KC_SYSTEM_SLEEP` | `KC_SLEP` | スリープ |
| `KC_SYSTEM_WAKE` | `KC_WAKE` | ウェイク |

---

## ダイナミックマクロ

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `QK_DYNAMIC_MACRO_RECORD_START_1` | `DM_REC1` | マクロ1 録画開始 |
| `QK_DYNAMIC_MACRO_RECORD_START_2` | `DM_REC2` | マクロ2 録画開始 |
| `QK_DYNAMIC_MACRO_RECORD_STOP` | `DM_RSTP` | 録画停止 |
| `QK_DYNAMIC_MACRO_PLAY_1` | `DM_PLY1` | マクロ1 再生 |
| `QK_DYNAMIC_MACRO_PLAY_2` | `DM_PLY2` | マクロ2 再生 |

---

## Caps Word / Auto Shift

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `QK_CAPS_WORD_TOGGLE` | `CW_TOGG` | Caps Word トグル |
| `QK_AUTO_SHIFT_ON` | `AS_ON` | Auto Shift 有効 |
| `QK_AUTO_SHIFT_OFF` | `AS_OFF` | Auto Shift 無効 |
| `QK_AUTO_SHIFT_TOGGLE` | `AS_TOGG` | Auto Shift トグル |

---

## コンボ

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `QK_COMBO_ON` | `CM_ON` | コンボ有効 |
| `QK_COMBO_OFF` | `CM_OFF` | コンボ無効 |
| `QK_COMBO_TOGGLE` | `CM_TOGG` | コンボトグル |

---

## 日本語入力（Mac/JIS）

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `KC_LANGUAGE_1` | `KC_LNG1` | 英数（Mac）/ ハングル（韓国語） |
| `KC_LANGUAGE_2` | `KC_LNG2` | かな（Mac）/ 漢字（韓国語） |
| `KC_INTERNATIONAL_1` | `KC_INT1` | ろ（JISキーボード） |
| `KC_INTERNATIONAL_2` | `KC_INT2` | カタカナ/ひらがな |
| `KC_INTERNATIONAL_3` | `KC_INT3` | ¥（JISキーボード） |
| `KC_INTERNATIONAL_4` | `KC_INT4` | 変換 |
| `KC_INTERNATIONAL_5` | `KC_INT5` | 無変換 |

---

## Space Cadet

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `QK_SPACE_CADET_LEFT_SHIFT_PARENTHESIS_OPEN` | `SC_LSPO` | 左Shift タップで `(` |
| `QK_SPACE_CADET_RIGHT_SHIFT_PARENTHESIS_CLOSE` | `SC_RSPC` | 右Shift タップで `)` |
| `QK_SPACE_CADET_LEFT_CTRL_PARENTHESIS_OPEN` | `SC_LCPO` | 左Ctrl タップで `(` |
| `QK_SPACE_CADET_RIGHT_CTRL_PARENTHESIS_CLOSE` | `SC_RCPC` | 右Ctrl タップで `)` |
| `QK_SPACE_CADET_RIGHT_SHIFT_ENTER` | `SC_SENT` | 右Shift タップで Enter |

---

## Unicode

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `QK_UNICODE_MODE_NEXT` | `UC_NEXT` | 次の Unicode モード |
| `QK_UNICODE_MODE_PREVIOUS` | `UC_PREV` | 前の Unicode モード |
| `QK_UNICODE_MODE_MACOS` | `UC_MAC` | macOS モード |
| `QK_UNICODE_MODE_LINUX` | `UC_LINX` | Linux モード |
| `QK_UNICODE_MODE_WINDOWS` | `UC_WIN` | Windows モード |
| `QK_UNICODE_MODE_WINCOMPOSE` | `UC_WINC` | WinCompose モード |

---

## Haptic（振動フィードバック）

| キーコード | エイリアス | 説明 |
|-----------|-----------|------|
| `QK_HAPTIC_ON` | `HF_ON` | Haptic 有効 |
| `QK_HAPTIC_OFF` | `HF_OFF` | Haptic 無効 |
| `QK_HAPTIC_TOGGLE` | `HF_TOGG` | Haptic トグル |
| `QK_HAPTIC_MODE_NEXT` | `HF_NEXT` | 次のモード |
| `QK_HAPTIC_MODE_PREVIOUS` | `HF_PREV` | 前のモード |

---

## 参考リンク

- [QMK 公式ドキュメント](https://docs.qmk.fm/)
- [Keycodes Overview](https://docs.qmk.fm/#/keycodes)
- [Mod-Tap](https://docs.qmk.fm/#/mod_tap)
- [Layers](https://docs.qmk.fm/#/feature_layers)
- [RGB Lighting](https://docs.qmk.fm/#/feature_rgblight)
