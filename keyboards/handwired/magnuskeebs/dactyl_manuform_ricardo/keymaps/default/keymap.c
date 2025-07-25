/*
Copyright 2022 fgoodwin <fgoodwin@north-tech.net>

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
#include "print.h" // Add at the top of your keymap.c for uprintf

#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY (Dactyl Manuform 5x6+6)
 *
 *     |-----------------------------------------|                                  |-----------------------------------------|
 *     | Esc  |  1   +  2   |  3   |  4   |  5   |                                  |  6   |  7   |  8   |  9   |  0   |  `   |
 *     |------+------|------+------+------+------|                                  |------+------+------+------+------+------|
 *     | Tab  |  Q   +  W   |  E   |  R   |  T   |                                  |  Y   |  U   |  I   |  O   |  P   |  -   |
 *     |------+------|------+------+------+------|   	                            |------+------+------+------+------+------|
 *     | Ctrl |  A   +  S   |  D   |  F   |  G   |                                  |  H   |  J   |  K   |  L   |  ;   |  '   |
 *     |------+------|------+------+------+------|                                  |------+------+------+------+------+------|
 *     | Shft |  Z   +  X   |  C   |  V   |  B   |                                  |  N   |  M   |  ,   |  .   |  /   | Shft |
 *     |-------------|------+------+-------------|		                            |------+------+------+------+-------------|
 *                   |  [   |  ]   |                                                              |  +   |  =   |
*                    |-----------------------------------------|	         |-----------------------------------
 *                                        | Spc  | Tab  | Home |	         | End  | Del  | Enter|
 *                                        |------+------+------|	         |------+------+------|
 *                                        | MO1  | Bksp | Grv  |	         | GUI  | Alt  | MO2  |
 *          				              |--------------------|	         |--------------------|
 */
    [_QWERTY] = LAYOUT_split_5x6_6(
        KC_ESC,   KC_1,  KC_2,     KC_3,     KC_4,    KC_5,             KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_GRV,
        KC_TAB,   KC_Q,   KC_W,     KC_E,     KC_R,    KC_T,            KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_MINS,
        KC_LCTL,  KC_A,   KC_S,     KC_D,     KC_F,    KC_G,            KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
        KC_LSFT,  KC_Z,   KC_X,     KC_C,     KC_V,    KC_B,            KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
        KC_NO,    KC_NO,  KC_SPC,   KC_TAB,   KC_LBRC,  KC_RBRC,        KC_PPLS,  KC_EQL,   KC_SLSH,  KC_RSFT,  KC_NO,    KC_NO,
        KC_NO,    KC_NO,  KC_HOME, MO(1),    KC_BSPC, KC_GRV,           KC_ENT,   KC_DEL,   MO(2),   KC_RGUI,  KC_NO,    KC_NO
    ),

/* LOWER (Dactyl Manuform 5x6+6)
 *
 *                   |---------------------------|                                  |---------------------------|
 *     |-------------+      |      |      |      |                                  |      |      |      |      |-------------|
 *     |      |      |------+------+------+------|                                  |------+------+------+------+      |      |
 *     |------+------+  F3  |  F4  |  F5  |  F6  |                                  |  F7  |  F8  |  F9  | F10  |------+------|
 *     |  F1  |  F2  |------+------+------+------|   	                            |------+------+------+------+ F11  | F12  |
 *     |------+------+  @   |  #   |  $   |  %   |                                  |  ^   |  &   |  *   |  (   |------+------|
 *     |  `   |  !   |------+------+------+------|                                  |------+------+------+------+  )   |  ~   |
 *     |------+------+      |      |      |      |                                  |      |  _   |  +   |  {   |------+------|
 *     |      |      |------+------+-------------|		                            |------+------+------+------+  }   |  |   |
 *     |-------------|      |      |                                                              |      |      |-------------|
 *                   |-----------------------------------------|	         |-----------------------------------
 *                                        |      |      |      |	         |      |      |      |
 *                                        |------+------+------|	         |------+------+------|
 *                                        | MO1  |      |      |	         |      |      | MO2  |
 *          				              |--------------------|	         |--------------------|
 */
    [_LOWER] = LAYOUT_split_5x6_6(
        KC_NO,		KC_NO,		_______,	_______,	_______,	_______,		_______,	_______,	_______,	_______,	KC_NO,		KC_NO,
        _______,	_______,	KC_F3,		KC_F4,		KC_F5,		KC_F6,			KC_F7,		KC_F8,		KC_F9,		KC_F10,		_______,	_______,
        KC_F1,    	KC_F2,		KC_AT,		KC_HASH,	KC_DLR,		KC_PERC,		KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_F11,		KC_F12,
        KC_GRV,		KC_EXLM,	_______,	_______,	_______,	_______,		_______,	_______,	_______,	_______,	KC_RPRN,	KC_TILD,
        _______,  	_______,	_______,	_______,	KC_NO,		KC_NO,			KC_NO,		KC_NO,		_______,	_______,	_______,	_______,
        KC_NO, 	  	KC_NO,		KC_NO,		MO(1),	    _______,	_______,		_______,	_______,	MO(2),	    KC_NO,		KC_NO,		KC_NO
    ),

/* RAISE (Dactyl Manuform 5x6+6)
 *
 *                   |---------------------------|                                  |---------------------------|
 *     |-------------+      |      |      |      |                                  |      |      |      |      |-------------|
 *     |      |      |------+------+------+------|                                  |------+------+------+------+      |      |
 *     |------+------+  2   |  3   |  4   |  5   |                                  |  6   |  7   |  8   |  9   |------+------|
 *     |  `   |  1   |------+------+------+------|   	                            |------+------+------+------+  0   |      |
 *     |------+------+  F3  |  F4  |  F5  |  F6  |                                  |      | Left | Down |  Up  |------+------|
 *     |  F1  |  F2  |------+------+------+------|                                  |------+------+------+------+Right |      |
 *     |------+------+  F9  | F10  | F11  | F12  |                                  |   +  |   -  |   =  |  [   |------+------|
 *     |  F7  |  F8  |------+------+-------------|		                            |------+------+------+------+  ]  |   \   |
 *     |-------------|      |      |                                                              |      |      |-------------|
 *                   |-----------------------------------------|	         |-----------------------------------
 *                                        |      |      |      |	         |      |      |      |
 *                                        |------+------+------|	         |------+------+------|
 *                                        | MO1  |      |      |	         |      |      | MO2  |
 *          				              |--------------------|	         |--------------------|
 */
    [_RAISE] = LAYOUT_split_5x6_6(
        KC_NO,		KC_NO,		_______,	_______,	_______,	_______,             _______,     _______,     _______,     _______,     KC_NO,    KC_NO,
        _______,	_______,	KC_2,       KC_3,		KC_4,		KC_5,             KC_6,     KC_7,     KC_8,     KC_9,     _______,     _______,
        KC_GRV,		KC_1,       KC_F3,      KC_F4,		KC_F5,		KC_F6,            _______,     KC_LEFT,  KC_DOWN,  KC_UP,    KC_0,     _______,
        KC_F1,      KC_F2,      KC_F9,      KC_F10,		KC_F11,		KC_F12,           KC_PLUS,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RGHT,  _______,
        KC_F7,      KC_F8,      _______,	_______,	KC_NO,		KC_NO,            KC_NO,    KC_NO,    _______,     _______,     KC_RBRC,  KC_BSLS,
        KC_NO, 	  	KC_NO,		KC_NO,		MO(1),	    _______,	_______,		_______,	_______,	MO(2),	    KC_NO,		KC_NO,		KC_NO
    ),

/* ADJUST (Dactyl Manuform 5x6+6)
 *
 * (all keys currently transparent)
 */
    [_ADJUST] = LAYOUT_split_5x6_6(
        KC_NO, 	  KC_NO,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_NO,    KC_NO,
        XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  KC_NO,    KC_NO,            KC_NO,    KC_NO,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_NO, 	  KC_NO,   KC_NO, 	 MO(1),    XXXXXXX,  XXXXXXX,          XXXXXXX,  XXXXXXX,  MO(2),    KC_NO,    KC_NO,    KC_NO
    ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        uprintf("Row: %d, Col: %d\n", record->event.key.row, record->event.key.col);
    }
    return true;
}
