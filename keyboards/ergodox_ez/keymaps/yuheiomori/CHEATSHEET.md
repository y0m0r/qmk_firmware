# ErgoDox EZ Keymap チートシート

## コンボ (同時押し)

| コンボ | 出力 | 用途 |
|--------|------|------|
| J + K | SUPER (Ctrl+Alt+Cmd) | 修飾キー |
| F + D | SUPER (Ctrl+Alt+Cmd) | 修飾キー |
| K + L | Hyper (Ctrl+Alt+Cmd+Shift) | 修飾キー |
| D + S | Hyper (Ctrl+Alt+Cmd+Shift) | 修飾キー |

## ダイナミックマクロ (Fn + )

| キー | 機能 |
|------|------|
| Fn + S | 録画開始 (DM_REC1) |
| Fn + D | 録画停止 (DM_RSTP) |
| Fn + F | 再生 (DM_PLY1) |

**使い方:**
1. `Fn + S` で録画開始
2. 記録したいキー操作を入力
3. `Fn + D` で録画停止
4. `Fn + F` で再生

## その他の便利キー (Fn + )

| キー | 機能 |
|------|------|
| Fn + A | コンボ ON/OFF (CM_TOGG) |
| Fn + Z | EEPROM クリア (EE_CLR) |

## マウス操作 (Fn + )

| キー | 機能 |
|------|------|
| Fn + H/J/K/L | カーソル移動 (左/下/上/右) |
| Fn + Y | ドラッグロック (範囲選択用) |
| Fn + U | 左クリック |
| Fn + I | 右クリック |
| Fn + N/M/,/. | ホイール (左/上/下/右) |
| Fn + C/V/B | 速度 (遅/中/速) |

## LED表示

| LED | レイヤー |
|-----|----------|
| LED1 | MAC (通常) |
| LED2 | MACFN (Fn押下中) |

## ビルド方法

```bash
make ergodox_ez/shine:yuheiomori
```
