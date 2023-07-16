/* Copyright 2020 yushakobo
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
#include "keymap_japanese.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  ADJUST,
  RGBRST,
  USER,
  PASS
};


#define LOWER TL_LOWR
#define RAISE TL_UPPR

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |  ￥  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  @   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | CAPS |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |MY_Scr|      |   N  |   M  |   ,  |   .  |   /  |  \   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | BTN1 | WIN  | LAlt  | GUI | LAlt | MHEN |Space |Space | HENK | KANA | RAlt |      |  App |Lower |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    JP_YEN,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JP_AT,
      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, JP_BSLS,
      KC_BTN1, KC_LWIN, KC_LALT, KC_LGUI, KC_LALT, JP_MHEN, KC_SPC,  KC_SPC,  JP_HENK, JP_KANA, KC_RALT, _______, KC_APP,  LOWER
    ),
  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      | Pass | User |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |Enter | Bksp | Del  |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, PASS,    USER,
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT,  KC_BSPC, KC_DEL,  _______, _______, _______
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   -  |   =  |   [  |   ]  |  \   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | CAPS |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |  F12 |      |      |PageDn|PageUp|      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_BSPC,
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
      KC_CAPS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, _______, KC_F12,  _______, _______, KC_PGDN, KC_PGUP, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
      ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | Reset|RGBRST|      |      |      |             |      |      |      |      |      |  Del |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      | Mac  |             | Win  |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | MODE | HUE- | SAT- | VAL- |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  LAYOUT(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
      _______, QK_BOOT,   RGBRST,  _______, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL,
      _______, _______, _______, _______, _______, AG_NORM,                   AG_SWAP, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD
      )

};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* Left side encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) { /* Right side encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
    return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;

    case USER:
      if (record->event.pressed) {
        SEND_STRING("USERNAME");
      } 
      break;

    case PASS:
      if (record->event.pressed) {
        SEND_STRING("PASSWORD");
      }
      break;
    
  }
  return true;
}

/*
 * Setting for Pointing Device az1uball
 *
 * documents for PIM477 options
 * https://github.com/qmk/qmk_firmware/blob/master/docs/feature_pointing_device.md#pimoroni-trackball
 */

int16_t accum_x = 0;
int16_t accum_y = 0;

bool is_moving = false;
int16_t moving_frame_thresold = 50;
int16_t moving_frame = 0;

int16_t sign(int16_t num){
  if (num < 0) {
    return -1;
  }
  return 1;
}

int16_t abs(int16_t num){
  if (num < 0) {
    num=-num;
  }
  return num;
}

#include <math.h>
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report){
  if (!is_moving) {
    if (mouse_report.x != 0 || mouse_report.y != 0) {
      is_moving = true;
      moving_frame = 0;
      accum_x = mouse_report.x;
      accum_y = mouse_report.y;
    }
  }
  
  if (is_moving) {
    moving_frame += 1;
    
    if (mouse_report.x == 0 && mouse_report.y == 0) {
      if (moving_frame > moving_frame_thresold) {
        is_moving = false;
        moving_frame = 0;
        accum_x = 0;
        accum_y = 0;
      }
    } else {
      accum_x += mouse_report.x;
      accum_y += mouse_report.y;
      mouse_report.x = sign(accum_x) * pow(abs(accum_x), 1.5);
      mouse_report.y = sign(accum_y) * pow(abs(accum_y), 1.5);
    }
  }
  return mouse_report;
}