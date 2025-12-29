#pragma once

// RGB Light デフォルト設定
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_KNIGHT  // ナイトライダーモード
#define RGBLIGHT_DEFAULT_HUE 0                       // 赤 (0 = 赤, 85 = 緑, 170 = 青)
#define RGBLIGHT_DEFAULT_SAT 255                     // 彩度 MAX
#define RGBLIGHT_DEFAULT_VAL 255                     // 明度 MAX

// マウスキー設定
#define MK_3_SPEED                    // 3段階速度モード（加速なし）
#define MK_MOMENTARY_ACCEL            // ACLキーを押している間だけ速度変更

// ホイールスクロール速度
#define MK_W_OFFSET_UNMOD 1           // 通常時: 1行ずつスクロール
#define MK_W_INTERVAL_UNMOD 40        // 通常時: スクロール間隔(ms) 小さいほど速い

#define MK_W_OFFSET_0 1               // ACL0時: 1行ずつ
#define MK_W_INTERVAL_0 80            // ACL0時: ゆっくり

#define MK_W_OFFSET_1 2               // ACL1時: 2行ずつ
#define MK_W_INTERVAL_1 40            // ACL1時: 中速

#define MK_W_OFFSET_2 4               // ACL2時: 4行ずつ
#define MK_W_INTERVAL_2 20            // ACL2時: 高速
