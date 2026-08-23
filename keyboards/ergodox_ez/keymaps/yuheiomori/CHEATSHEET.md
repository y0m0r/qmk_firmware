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

## F キー (右手内側の下段キーを押しながら)

`N` の左隣にある大きなキーを右手人差し指で押さえている間だけ有効。
左手はホームポジションから動かさずに F1-F12 が打てる。

左手が F キー、右手が音量・輝度・メディア操作。

| キー | F キー |
|------|--------|
| A / S / D / F / G | F1 / F2 / F3 / F4 / F5 |
| Z / X / C / V / B | F6 / F7 / F8 / F9 / F10 |
| Q / W | F11 / F12 |

| キー | 機能 |
|------|------|
| Y / U | 画面輝度 下 / 上 |
| I / O | 音量 下 / 上 |
| P | ミュート |
| H / J / K | 前の曲 / 再生・停止 / 次の曲 |
| ESC | ブートローダ起動 (書き込み時) |

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
| LED3 | FKEY (右手内側の下段キー押下中) |

## 内側の大きなキー

| 位置 | 左手 | 右手 |
|------|------|------|
| 上段 (T / Y の隣) | Hyper | SUPER |
| 下段 (B / N の隣) | SUPER | **FKEY レイヤー保持** |

右手の Hyper は FKEY レイヤーに譲ったため専用キーがない。
Hyper が要るときは K+L か D+S のコンボを使う。

## ビルド方法

実機は **shine**（単色バックライト）。base / glow ではないので注意。

```bash
make ergodox_ez/shine:yuheiomori
# qmk CLI で書くと同じ意味
qmk compile -kb ergodox_ez/shine -km yuheiomori
```

生成物はリポジトリ直下の `ergodox_ez_shine_yuheiomori.hex`。

2026-08-22 時点のサイズは 26058 / 32256 バイト（80%、空き 6198 バイト）。
atmega32u4 の容量が 32256 バイトなので、機能を足していく余地はあまり大きくない。

## 書き込み (flash)

普段は **Teensy Loader の GUI**（`/Applications/Teensy.app`）を使っている。

1. 先に上のビルドコマンドで `ergodox_ez_shine_yuheiomori.hex` を作る
2. Teensy.app を起動する
3. File > Open HEX File でリポジトリ直下の `ergodox_ez_shine_yuheiomori.hex` を選ぶ
4. キーボードで **内側の下段キー(N の隣) + ESC** を押してブートローダに入る
   （FKEY レイヤーの ESC の位置に `QK_BOOT` を割り当て済み）
5. Teensy.app の Program ボタン（下向き矢印）で書き込み、Reboot で再起動

ブートローダは HalfKay（Teensy 2.0 系）。詳細は `docs/flashing.md` の HalfKay の節。

### コマンドラインで焼く場合

`make ... :flash` や `qmk flash` でも焼けるが、これらは `teensy_loader_cli` を呼ぶ。
**2026-08-22 時点でこのマシンには未インストール**なので、使うなら先に入れること。
GUI で困っていないなら無理に入れる必要はない。

```bash
brew install teensy_loader_cli
make ergodox_ez/shine:yuheiomori:flash
# qmk CLI で書くと同じ意味
qmk flash -kb ergodox_ez/shine -km yuheiomori
```

コマンド実行後に `Waiting for bootloader...` が出たら
内側の下段キー + ESC を押す。
ブートローダに入ってから **7秒以内** に書き込みが始まる必要がある。

## 本家 (qmk/qmk_firmware) との同期

このリポジトリは qmk/qmk_firmware のフォーク。本家の更新を取り込む手順:

```bash
git fetch upstream
git merge upstream/master
git push origin master
git submodule update --init --recursive
```

GitHub の画面にある `Sync fork` ボタンでも同じことができるが、隣の
`Discard N commits` を押すと自分のキーマップ変更が消えるので、
ローカルでやるほうが安全。

`Contribute` ボタンは本家への PR 作成用なので、このリポジトリでは使わない。
