/*
Copyright 2021 Salicylic_Acid

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
このコードは Salicylic_Acid 氏が作成したものを yamanyon が fork し独自カスタマイズしたものです。
2026.11.07 ver.1.00 リリース
*/

#include QMK_KEYBOARD_H

// KVM 切替操作のキー入力待ち ms
#define KVM_COMMAND_DELAY 50

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _QWERTJ,
    _FN,
    _FNJ,
    _NUM,
};

enum my_keycodes {
    FN_BSPC = LT(_FN, KC_BSPC),
    FN_HE   = LT(_FN, KC_LNG2), // 長押しで _FN にレイヤー切り替え、タップで IME を半角英数に切り替え
    FNJ_HE  = LT(_FNJ, KC_LNG2), // 長押しで _FNJ にレイヤー切り替え、タップで IME を半角英数に切り替え
    DF_EN   = DF(_QWERTY),
    DF_JP   = DF(_QWERTJ),
};

enum custom_keycodes {
    KM_GRVJ = SAFE_RANGE,
    KM_EQL,
    KM_QUOT,
    KM_KVM1,
    KM_KVM2,
    KM_KVM3,
    KM_KVM4,
    RGB_RST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_ESC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_PGUP,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT, FN_HE,            KC_SPC,           MO(_FN),          KC_LNG1, KC_PSCR, TG(_NUM),         KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_QWERTJ] = LAYOUT(
        KM_GRVJ, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KM_EQL,  KC_BSPC, KC_ESC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC, KC_NUHS, KC_INT3, KC_DEL,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KM_QUOT, KC_ENT,           KC_PGUP,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT, FNJ_HE,           KC_SPC,           MO(_FNJ),         KC_LNG1, KC_PSCR, TG(_NUM),         KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_FN] = LAYOUT(
        KC_ESC , KC_NO,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_INS,
        DF_JP,   _______, _______, KC_LCBR, KC_RCBR, _______,          _______, KC_PGUP, KC_HOME, KC_PGDN, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_LPRN, KC_RPRN, KC_COLN,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,  _______, _______,          KC_HOME,
        _______, _______, _______, _______, _______, _______,          KM_KVM1, KM_KVM2, KM_KVM3, KM_KVM4, _______, _______,          _______, KC_END,
        _______, _______, _______, KC_BSPC,          _______,          _______,          _______, KC_SCRL, RGB_RST,          _______, _______, _______
    ),
    [_FNJ] = LAYOUT(
        KC_ESC , KC_NO,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_INS,
        DF_EN,   _______, _______, KC_LCBR, KC_RCBR, _______,          _______, KC_PGUP, KC_HOME, KC_PGDN, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_LPRN, KC_RPRN, KC_COLN,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,  _______, _______,          KC_HOME,
        _______, _______, _______, _______, _______, _______,          KM_KVM1, KM_KVM2, KM_KVM3, KM_KVM4, _______, _______,          _______, KC_END,
        _______, _______, _______, KC_BSPC,          _______,          _______,          _______, KC_SCRL, RGB_RST,          _______, _______, _______
    ),
    [_NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,          KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, _______, _______, _______, _______, KC_NUM,
        _______, _______, _______, KC_LCBR, KC_RCBR, _______,          KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, _______, _______, KC_SCRL,
        _______, _______, _______, KC_LPRN, KC_RPRN, KC_COLN,          KC_P4,   KC_P5,   KC_P6,   _______, _______, _______, _______,          RGB_SAI,
        _______, _______, _______, _______, _______, _______,          KC_P1,   KC_P2,   KC_P3,   _______, _______, _______,          RGB_VAI, RGB_SAD,
        _______, _______, _______, _______,          _______,          KC_P0,            KC_PDOT, _______, _______,          RGB_HUD, RGB_VAD, RGB_HUI
    )
};

// レイヤーに合わせて LED ライトを変化させる
const rgblight_segment_t PROGMEM rgb_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0,  1,  HSV_RED },        // 左側キーボードの左上 LED を赤くする
//    { 1,  8,  HSV_RED },      // 左側キーボードのその他の LED はそのままにする (変更する場合はコメントアウトしカラーを設定)
//    { 9,  11, HSV_RED },      // 右側キーボードのその他の LED はそのままにする (変更する場合はコメントアウトしカラーを設定)
    { 20, 1,  HSV_RED }         // 右側キーボードの右上 LED を赤くする
);

const rgblight_segment_t PROGMEM rgb_qwertj_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0,  1,  HSV_RED },        // 左側キーボードの左上 LED を赤くする
//    { 1,  8,  HSV_WHITE },    // 左側キーボードのその他の LED はそのままにする (変更する場合はコメントアウトしカラーを設定)
//    { 9,  11, HSV_WHITE },    // 右側キーボードのその他の LED はそのままにする (変更する場合はコメントアウトしカラーを設定)
    { 20, 1,  HSV_RED }         // 右側キーボードの右上 LED を赤くする
);

const rgblight_segment_t PROGMEM rgb_fn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0,  1,  HSV_WHITE },      // 左側キーボードの左上 LED を白くする
//    { 1,  8,  HSV_RED },      // 左側キーボードのその他の LED はそのままにする (変更する場合はコメントアウトしカラーを設定)
//    { 9,  11, HSV_RED },      // 右側キーボードのその他の LED はそのままにする (変更する場合はコメントアウトしカラーを設定)
    { 20, 1,  HSV_WHITE }       // 右側キーボードの右上 LED を白くする
);

const rgblight_segment_t PROGMEM rgb_fnj_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0,  1,  HSV_WHITE },      // 左側キーボードの左上 LED を白くする
//    { 1,  8,  HSV_WHITE },    // 左側キーボードのその他の LED はそのままにする (変更する場合はコメントアウトしカラーを設定)
//    { 9,  11, HSV_WHITE },    // 右側キーボードのその他の LED はそのままにする (変更する場合はコメントアウトしカラーを設定)
    { 20, 1,  HSV_WHITE }       // 右側キーボードの右上 LED を白くする
);

const rgblight_segment_t PROGMEM rgb_num_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0,  1,  HSV_BLUE },       // 左側キーボードの左上 LED を青くする
//    { 1,  8,  HSV_RED },      // 左側キーボードのその他の LED はそのままにする (変更する場合はコメントアウトしカラーを設定)
//    { 9,  11, HSV_RED },      // 右側キーボードのその他の LED はそのままにする (変更する場合はコメントアウトしカラーを設定)
    { 20, 1,  HSV_BLUE }        // 右側キーボードの右上 LED を青くする
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_qwerty_layer,
    rgb_qwertj_layer,
    rgb_fn_layer,
    rgb_fnj_layer,
    rgb_num_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTJ));
    rgblight_set_layer_state(2, layer_state_cmp(state, _FN));
    rgblight_set_layer_state(3, layer_state_cmp(state, _FNJ));
    rgblight_set_layer_state(4, layer_state_cmp(state, _NUM));
    rgblight_set_effect_range( 1, RGBLIGHT_LIMIT_VAL-2);
    return state;
}

// KVM スイッチを動作させる
static void switch_kvm_port(uint8_t num) {
    // 1～4 の数字キー配列を定義しておき、キー入力を配列番号で管理できるようにする
    static const uint16_t kvm_keys[] = {
        KC_NO,
        KC_1,
        KC_2,
        KC_3,
        KC_4
    };

    // num に 1～4 以外の数字が指定されたら強制終了する
    if (num < 1 || num > 4) {
        return;
    }

    // Scroll Lock + Scroll Lock + 数字キー + Enter でスイッチする
    tap_code(KC_SCRL);
    tap_code(KC_SCRL);
    tap_code(kvm_keys[num]);
    // Enter キーが即押下だと反応しないのでスリープ
    wait_ms(KVM_COMMAND_DELAY);
    tap_code(KC_ENT);

    // キーマップをそれぞれに合わせる
    switch (num) {
        case 1:
        case 2: { default_layer_set(1UL<<_QWERTY); break; }
        case 3:
        case 4: { default_layer_set(1UL<<_QWERTJ); break; }
    }

    return;
}

// ここからは QWERTJ マップで使用するヘルパー群
// 左右で同じ機能を持つファンクション キーの状態やイベントを管理する変数
typedef struct {
    bool pressed;       // キーの押下状態
    bool registered;    // OS に送信しているイベントの状態
} mod_state_t;

typedef struct {
    mod_state_t left;   // 左
    mod_state_t right;  // 右
} left_right_key_state_t;

static left_right_key_state_t shift = {0};  // Shift キーのフラグ
static left_right_key_state_t alt   = {0};  // ALT キーのフラグ

// 各キー操作の状態を記録するフラグ
static bool KE_GRVJ     = false;    // `
static bool KE_S_GRVJ   = false;    // ~
static bool KE_ZKHK     = false;    // 全角/半角
static bool KE_S_2      = false;    // @
static bool KE_S_6      = false;    // ^
static bool KE_S_7      = false;    // &
static bool KE_S_8      = false;    // *
static bool KE_S_9      = false;    // (
static bool KE_S_0      = false;    // )
static bool KE_S_MINS   = false;    // _
static bool KE_EQL      = false;    // =
static bool KE_S_EQL    = false;    // +
static bool KE_S_SCLN   = false;    // :
static bool KE_QUOT     = false;    // '
static bool KE_S_QUOT   = false;    // "

// キー入力の代替操作用ヘルパー
static void key_press_handler(bool pressed, uint16_t keycode)
{
    if (pressed) {
        register_code(keycode);
    } else {
        unregister_code(keycode);
    }
}

// Shift の押下状態を判定するヘルパー
// キー イベントの上書きのために Shift の状態を強制的に変更してしまっているので、それを修正する役割を担っている
// register_code の重複 (unregister せずに register を再送する行為) が Pro Micro だと問題なかったが BLE Micro Pro だと動かない
// そのあたりのケアも含め registered フラグの制御を追加している
static bool sync_shift_state(void) {
    // 左 Shift が押されている / 左 Shift の押下イベントを送信していない
    if ( shift.left.pressed && !shift.left.registered ) {
        register_code(KC_LSFT);
        shift.left.registered = true;
    }
    // 左 Shift が押されていない / 左 Shift の押下イベントを送信している
    if ( !shift.left.pressed && shift.left.registered ) {
        unregister_code(KC_LSFT);
        shift.left.registered = false;
    }
    // 右 Shift が押されている / 右 Shift の押下イベントを送信していない
    if ( shift.right.pressed && !shift.right.registered ) {
        register_code(KC_RSFT);
        shift.right.registered = true;
    }
    // 右 Shift が押されていない / 右 Shift の押下イベントを送信している
    if ( !shift.right.pressed && shift.right.registered ) {
        unregister_code(KC_RSFT);
        shift.right.registered = false;
    }

    return shift.left.pressed || shift.right.pressed;
}

// Shift 押下状態を強制解除するヘルパー
static void suspend_shift(void)
{
    if (shift.left.pressed) {
        unregister_code(KC_LSFT);
        shift.left.registered = false;
    }

    if (shift.right.pressed) {
        unregister_code(KC_RSFT);
        shift.right.registered = false;
    }
}

// Shift イベントを送信するヘルパー
static void force_shift(void)
{
    shift.left.registered = true;
    register_code(KC_LSFT);
}

// キー イベントを検出する
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // 戻り値を True にすると、コード実行後にキー イベントをそのまま返す。
    // 戻り値を False にすると、コード実行後はキー イベントを送らない。
    // カスタム キー イベント処理時は基本的に False を返すが、それ以外は True にする。
    // とりあえず何事も True を返させるため、True をセットしておく。
    bool retcode = true;

    // 押されたキー イベントでスイッチする
    switch (keycode) {

        case KM_KVM1:
            if ( record->event.pressed ) {
                switch_kvm_port(1);
                retcode = false;
            }
            break;

        case KM_KVM2:
            if ( record->event.pressed ) {
                switch_kvm_port(2);
                retcode = false;
            }
            break;

        case KM_KVM3:
            if ( record->event.pressed ) {
                switch_kvm_port(3);
                retcode = false;
            }
            break;

        case KM_KVM4:
            if ( record->event.pressed ) {
                switch_kvm_port(4);
                retcode = false;
            }
            break;
    }

    // _QWERTJ キーマップの時の動作を記述する
    // Shift ペアのキーだけ変更する場合は標準キー イベント (KC_xxxx) の動作を上書きする
    // Shift なし、Shift ペアの両方を変更する場合は専用のキー イベント (KM_xxxx) を作成し動作を記述する
    if ( biton32(default_layer_state) == _QWERTJ ) {

        // Shift と ALT の状態を検出する
        switch (keycode) {
            // Shift が押されたらその状態を反映する
            // Shift キー押下と OS イベント送信が一致していないケースがあるので、それぞれの状態をリセットする
            case KC_LSFT:   shift.left.pressed  = record->event.pressed;    shift.left.registered  = record->event.pressed;  return true;
            case KC_RSFT:   shift.right.pressed = record->event.pressed;    shift.right.registered = record->event.pressed;  return true;
            // ALT が押されたらその状態を反映する
            // ALT キー押下と OS イベント送信は一致しているので、OS イベント送信側は制御しない
            case KC_LALT:   alt.left.pressed    = record->event.pressed;    return true;
            case KC_RALT:   alt.right.pressed   = record->event.pressed;    return true;
        }

        // Shift と ALT の状態を更新する
        // 左右どちらかのキーが押されているかどうかを判定し、その結果として 押されていたら True、そうでなければ False を返す
        // コードの流用ができるように左右両方のキーがある前提で記述しているため、そうでないキーボードでは省略できる部分もあるが、汎用性のために維持する
        bool KE_SFT = sync_shift_state();
        bool KE_ALT = alt.left.pressed || alt.right.pressed;

        // 押されたキー イベントでスイッチする
        switch (keycode) {

            case KM_GRVJ:
                // ` キー イベント
                if ( ( !KE_SFT && !KE_ALT ) || KE_GRVJ ) {
                    KE_GRVJ = record->event.pressed;
                    if ( KE_GRVJ ) {
                        force_shift();
                        register_code(KC_LBRC);
                    } else {
                        unregister_code(KC_LBRC);
                    }
                    retcode = false;
                }
                // ~ キー イベント
                if ( ( KE_SFT && !KE_ALT ) || KE_S_GRVJ ) {
                    KE_S_GRVJ = record->event.pressed;
                    key_press_handler(KE_S_GRVJ, KC_EQL);
                    retcode = false;
                }
                // 日本語入力 ON/OFF イベント
                if ( ( !KE_SFT && KE_ALT ) || KE_ZKHK ) {
                    KE_ZKHK = record->event.pressed;
                    key_press_handler(KE_ZKHK, KC_GRV);
                    retcode = false;
                }
                break;

            case KC_2:
                // @ キー イベント
                if ( ( KE_SFT && !KE_ALT ) || KE_S_2 ) {
                    KE_S_2 = record->event.pressed;
                    if ( KE_S_2 ) {
                        suspend_shift();
                        register_code(KC_LBRC);
                    } else {
                        unregister_code(KC_LBRC);
                    }
                    retcode = false;
                }
                break;

            case KC_6:
                // ^ キー イベント
                if ( ( KE_SFT && !KE_ALT ) || KE_S_6 ) {
                    KE_S_6 = record->event.pressed;
                    if ( KE_S_6 ) {
                        suspend_shift();
                        register_code(KC_EQL);
                    } else {
                        unregister_code(KC_EQL);
                    }
                    retcode = false;
                }
                break;

            case KC_7:
                // & キー イベント
                if ( ( KE_SFT && !KE_ALT ) || KE_S_7 ) {
                    KE_S_7 = record->event.pressed;
                    key_press_handler(KE_S_7, KC_6);
                    retcode = false;
                }
                break;

            case KC_8:
                // * キー イベント
                if ( ( KE_SFT && !KE_ALT ) || KE_S_8 ) {
                    KE_S_8 = record->event.pressed;
                    key_press_handler(KE_S_8, KC_QUOT);
                    retcode = false;
                }
                break;

            case KC_9:
                // ( キー イベント
                if ( ( KE_SFT && !KE_ALT ) || KE_S_9 ) {
                    KE_S_9 = record->event.pressed;
                    key_press_handler(KE_S_9, KC_8);
                    retcode = false;
                }
                break;

            case KC_0:
                // ) キー イベント
                if ( ( KE_SFT && !KE_ALT ) || KE_S_0 ) {
                    KE_S_0 = record->event.pressed;
                    key_press_handler(KE_S_0, KC_9);
                    retcode = false;
                }
                break;

            case KC_MINS:
                // _ キー イベント
                if ( ( KE_SFT && !KE_ALT ) || KE_S_MINS ) {
                    KE_S_MINS = record->event.pressed;
                    key_press_handler(KE_S_MINS, KC_INT1);
                    retcode = false;
                }
                break;

            case KM_EQL:
                // = キー イベント
                if ( ( !KE_SFT && !KE_ALT ) || KE_EQL ) {
                    KE_EQL = record->event.pressed;
                    if ( KE_EQL ) {
                        force_shift();
                        register_code(KC_MINS);
                    } else {
                        unregister_code(KC_MINS);
                    }
                    retcode = false;
                }
                // + キー イベント
                if ( ( KE_SFT && !KE_ALT ) || KE_S_EQL ) {
                    KE_S_EQL = record->event.pressed;
                    if ( KE_S_EQL ) {
                        force_shift();
                        register_code(KC_SCLN);
                    } else {
                        unregister_code(KC_SCLN);
                    }
                    retcode = false;
                }
                break;

            case KC_SCLN:
                // : キー イベント
                if ( ( KE_SFT && !KE_ALT ) || KE_S_SCLN ) {
                    KE_S_SCLN = record->event.pressed;
                    if ( KE_S_SCLN ) {
                        suspend_shift();
                        register_code(KC_QUOT);
                    } else {
                        unregister_code(KC_QUOT);
                    }
                    retcode = false;
                }
                break;

            case KM_QUOT:
                // ' キー イベント
                if ( ( !KE_SFT && !KE_ALT ) || KE_QUOT ) {
                    KE_QUOT = record->event.pressed;
                    if ( KE_QUOT ) {
                        force_shift();
                        register_code(KC_7);
                    } else {
                        unregister_code(KC_7);
                    }
                    retcode = false;
                }
                // " キー イベント
                if ( ( KE_SFT && !KE_ALT ) || KE_S_QUOT ) {
                    KE_S_QUOT = record->event.pressed;
                    key_press_handler(KE_S_QUOT, KC_2);
                    retcode = false;
                }
                break;

            default:
                break;
        }
    }

    // RGB に関する追加のアクションを記述する
    switch (keycode) {
        // RGB の状態をリセットする
        case RGB_RST:
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
                // RGB_current_mode = rgblight_get_mode();
            }
            retcode = false;
            break;
    }

    return retcode;
}
