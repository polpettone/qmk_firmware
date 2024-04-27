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
#include "debug.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |kaputt|   9  |  0   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -_  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;: |  " ' |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * | CTL  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |  /?  | \|   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |  CTL |  CMD |  CMD | TG(1)| /Space  /       \Enter \  | Bspc|  =+  |  [{  |  ]}  |
 *            |      |      |      |      |/       /         \      \ |     |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[0] = LAYOUT(
    KC_ESC,   KC_1,   KC_2,    KC_3,   KC_4,    KC_5,                           KC_6,      KC_7,     KC_8,    KC_0,    KC_9,    KC_0,
    KC_TAB,   KC_Q,   KC_W,    KC_E,   KC_R,    KC_T,                           KC_Y,      KC_U,     KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_LSFT,  KC_A,   KC_S,    KC_D,   KC_F,    KC_G,                           KC_H,      KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL,  KC_Z,   KC_X,    KC_C,   KC_V,    KC_B,      KC_MUTE,    KC_MPLY, KC_N,      KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                      KC_CAPS, TG(1),  KC_LALT, KC_LGUI,   KC_SPC,     KC_ENT,  KC_BSPC,   KC_EQL,  KC_LBRC, KC_RBRC
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
    KC_TRNS,   KC_TRNS,   KC_2,    KC_3,    KC_4,      KC_5,                          KC_6,     KC_7,     KC_8,    KC_0,     KC_9,    KC_0,
    KC_TRNS,   KC_TRNS,   KC_W,    KC_E,    KC_R,      KC_T,                          KC_Y,     KC_U,     KC_I,    KC_O,     KC_EQL,  KC_MINS,
    KC_TRNS,   KC_TRNS,   KC_S,    KC_D,    KC_F,      KC_G,                          KC_LEFT,  KC_DOWN,  KC_UP,   KC_RIGHT, KC_SCLN, KC_QUOT,
    KC_TRNS,   KC_TRNS,   KC_X,    KC_C,    KC_V,      KC_B,       KC_MUTE,  KC_MPLY, KC_N,     KC_M,     KC_COMM, KC_DOT,   KC_SLSH, KC_TRNS,
                          KC_RALT, TG(1),   KC_TRNS,  KC_TRNS,     KC_SPC,   KC_ENT,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS
)

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) }
};
#endif

bool lightToggle = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TG(0):
            if (record->event.pressed) {
                layer_state_set_user(layer_state);  // Setze den Layer auf 1
                rgblight_sethsv(100, 255, 255);
            }
            break;
        case TG(1):
            if (record->event.pressed) {
                layer_state_set_user(layer_state);
                if(lightToggle) {
                    rgblight_sethsv(150, 255, 255);
                    lightToggle = false;
                } else {
                    rgblight_sethsv(50, 255, 255);
                    lightToggle = true;
                }
            }
            break;
    }
    return true;
}
