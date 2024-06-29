#include QMK_KEYBOARD_H
#include "layers.h"
#include "combos.c"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_RIGHTHAND] = LAYOUT(KC_BTN4, KC_BTN5, DRAG_SCROLL, KC_BTN2,
                          KC_BTN1,                       KC_BTN3),
     [_LEFTHAND] = LAYOUT(KC_BTN2, DRAG_SCROLL, KC_BTN4, KC_BTN5,
                          KC_BTN3,                       KC_BTN1)
};
// clang-format on
