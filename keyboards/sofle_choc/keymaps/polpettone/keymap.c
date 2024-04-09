/* Copyright 2023 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |kaputt|   9  |  0   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;: |  " ' |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * | CTL  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |  /?  | \|   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |  CTL |  CMD |  CMD | TG(1)| /Space  /       \Enter \  | = + |  -_  |  [{  |  ]}  |
 *            |      |      |      |      |/       /         \      \ |     |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[0] = LAYOUT(
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,     KC_7,     KC_8,    KC_0,    KC_9,    KC_0,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,   KC_MPLY, KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                      KC_LCTL, KC_LGUI,KC_LALT,  TG(1),   KC_SPC,    KC_ENT , KC_EQL,   KC_MINS,  KC_LBRC, KC_RBRC
),

/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |kaputt|   9  |  0   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |  = + | - _  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  " ' |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * | CTL  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |  /?  | \|   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | RALT |  CMD |  CMD | LALT | /Space  /       \Enter \  | RALT | RCMD |  [{  |  ]}  |
 *            |      |      |      |      |/       /         \      \ |     |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[1] = LAYOUT(
    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,     KC_7,     KC_8,    KC_0,     KC_9,    KC_0,
    KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,     KC_U,     KC_I,    KC_O,     KC_EQL,  KC_MINS,
    KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_LEFT,  KC_DOWN,  KC_UP,   KC_RIGHT, KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,  KC_MPLY, KC_N,     KC_M,     KC_COMM, KC_DOT,   KC_SLSH, KC_TRNS,
                   KC_RALT, KC_LGUI, KC_LCMD, TG(1),   KC_SPC,   KC_ENT,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS
)

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) }
};
#endif


enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

static void print_status_narrow(void) {
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
}

bool oled_task_user(void) {
    print_status_narrow();
    return true;
}

