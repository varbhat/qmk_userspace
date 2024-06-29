#include QMK_KEYBOARD_H
#include "layers.h"
#include "combos.c"
#include "oled.c"

/* Corne
 * https://github.com/foostan/crkbd
 * Corne keyboard, a split keyboard with 3x6 column staggered keys and 3 thumb keys.
 * ,-----------------------------------------------,       ,-----------------------------------------------,
 * |       |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |       |
 * '-----------------------------------------------'       '-----------------------------------------------'
 *                         ,-----------------------,       ,-----------------------,
 *                         |       |       |       |       |       |       |       |
 *                         '-----------------------'       '-----------------------'
 *
 */

// [_LAYER] = LAYOUT_split_3x6_3(
// KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,  /**/  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS,
// KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,  /**/  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS,
// KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,  /**/  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS,
//                                  KC_TRNS, KC_TRNS,   KC_TRNS,  /**/  KC_TRNS,   KC_TRNS,   KC_TRNS
// ),

// clang-format off
// Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* dvorak
    * ,-----------------------------------------------,       ,-----------------------------------------------,
    * | alt   |  tab  |  , <  |  . >  |   p   |   y   |       |   f   |   g   |   c   |   r   |   l   |  /?   |
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * | esc   |   a   |   o   |   e   |   u   |   i   |       |   d   |   h   |   t   |   n   |   s   | bkspc |
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * | shift |  nav  |   q   |   j   |   k   |   x   |       |   b   |   m   |   w   |   v   |   z   | shift |
    * '-----------------------------------------------'       '-----------------------------------------------'
    *                         ,-----------------------,       ,-----------------------,
    *                         |  gui  | ctrl  | space |       |  ent  |  num  |   sym |
    *                         '-----------------------'       '-----------------------'
    */
    [_DVORAK] = LAYOUT_split_3x6_3(
    KC_LALT,  KC_TAB,   KC_COMM,  KC_DOT,  KC_P,   KC_Y, /**/ KC_F,    KC_G,   KC_C,   KC_R,  KC_L,  KC_SLASH,
    KC_ESC,   KC_A,     KC_O,     KC_E,    KC_U,   KC_I, /**/ KC_D,    KC_H,   KC_T,   KC_N,  KC_S,  KC_BSPC,
    KC_LSFT,  TT(_NAV), KC_Q,     KC_J,    KC_K,   KC_X, /**/ KC_B,    KC_M,   KC_W,   KC_V,  KC_Z,  KC_RSFT,
                               KC_LGUI, KC_LCTL, KC_SPC, /**/ KC_ENT,  TT(_NUM), TT(_SYM)
  ),

    /* qwerty
    * ,-----------------------------------------------,       ,-----------------------------------------------,
    * |  alt  |   q   |   w   |   e   |   r   |   t   |       |   y   |   u   |   i   |   o   |   p   |  /?   |
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * |  esc  |   a   |   s   |   d   |   f   |   g   |       |   h   |   j   |   k   |   l   |  nav  | bkspc |
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * | shift |   z   |   x   |   c   |   v   |   b   |       |   n   |   m   |  , <  |  . >  |  tab  | shift |
    * '-----------------------------------------------'       '-----------------------------------------------'
    */
    [_QWERTY] = LAYOUT_split_3x6_3(
    KC_LALT,  KC_Q,  KC_W,  KC_E,  KC_R,   KC_T, /**/ KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,     KC_SLASH,
    KC_ESC,   KC_A,  KC_S,  KC_D,  KC_F,   KC_G, /**/ KC_H,   KC_J,   KC_K,    KC_L,   TT(_NAV), KC_BSPC,
    KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,   KC_B, /**/ KC_N,   KC_M,   KC_COMM, KC_DOT, KC_TAB,   KC_RSFT,
                      KC_TRNS, KC_TRNS, KC_TRNS, /**/  KC_TRNS,   KC_TRNS,   KC_TRNS
  ),

    /* numbers
    * ,-----------------------------------------------,       ,-----------------------------------------------,
    * | alt   |   !   |   @   |   #   |    %  |   +   |       |   -   |   &   |   *   |   =   |   /   |   .   |
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * | esc   |   1   |   2   |   3   |   4   |   5   |       |   6   |   7   |   8   |   9   |   0   | bkspc |
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * | CAPS  |  F1   |   F2  |   F3  |  F4   |  F5   |       |  F6   |   F7  |   F8  |   F9  |   F10 | shift |
    * '-----------------------------------------------'       '-----------------------------------------------'
    *                         ,-----------------------,       ,-----------------------,
    *                         |  nav  |       |       |       |       |       |       |
    *                         '-----------------------'       '-----------------------'
    */
    [_NUM] = LAYOUT_split_3x6_3(
    KC_LALT,  KC_EXLM, KC_AT,  KC_HASH,  KC_PERC,  KC_PLUS,/**/ KC_MINUS, KC_AMPR, KC_ASTR, KC_EQUAL, KC_SLASH, KC_DOT,
    KC_ESC,   KC_1,    KC_2,   KC_3,     KC_4,     KC_5,   /**/ KC_6,     KC_7,    KC_8,    KC_9,     KC_0,     KC_BSPC,
    KC_CAPS,  KC_F1,   KC_F2,  KC_F3,    KC_F4,    KC_F5,  /**/ KC_F6,    KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_RSFT,
                            TG(_NAV), KC_TRNS,   KC_TRNS,  /**/ KC_TRNS,   KC_TRNS,   KC_TRNS
  ),

    /* symbols
    * ,-----------------------------------------------,       ,-----------------------------------------------,
    * | alt   | find  |   ~   |   ;   |    <  |   /   |       |   -   |   >   |   '   |   "   |   \   |os:ralt|
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * | esc   |   ^   |   [   |   {   |   (   |   $   |       |   _   |   )   |   }   |   ]   |   |   | bkspc |
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * |ctl+sft| undo  | qwerty|   :   |   `   |   ?   |       |   F11 |  F12  |  cut  |  copy | paste | shift |
    * '-----------------------------------------------'       '-----------------------------------------------'
    *                         ,-----------------------,       ,-----------------------,
    *                         |  nav  |       |       |       |       |       |       |
    *                         '-----------------------'       '-----------------------'
    */
    [_SYM] = LAYOUT_split_3x6_3(
    KC_LALT,                                   KC_FIND,   KC_TILD,     KC_SCLN,  KC_LT,   KC_SLASH, /**/  KC_MINUS, KC_GT,   KC_QUOT,  KC_DQT,   KC_BSLS,  OSM(MOD_RALT),
    KC_ESC,                                    KC_CIRC,   KC_LBRC,     KC_LCBR,  KC_LPRN, KC_DLR,   /**/  KC_UNDS,  KC_RPRN, KC_RCBR,  KC_RBRC,  KC_PIPE,  KC_BSPC,
    OSM(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT)),  KC_UNDO,   TG(_QWERTY), KC_COLN,  KC_GRV,  KC_QUES,  /**/  KC_F11,   KC_F12,  KC_CUT,   KC_COPY,  KC_PASTE, KC_RSFT,
                                                                      TT(_NAV),  KC_TRNS, KC_TRNS,  /**/  KC_TRNS,  KC_TRNS, KC_TRNS
  ),

    /* navigation
    * ,-----------------------------------------------,       ,-----------------------------------------------,
    * |  alt  |  F13  |  PAUS |  BRID | BRIU  |  PSCR |       |  home |  pgup |   ↑   | pgdown|  end  | wsch  |
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * |  esc  |  F14  |  MUTE | VOLD  | VOLU  |  ins  |       |   del |   ←   |   ↓   |   →   |  wref | bkspc |
    * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
    * | shift |  nav  |  MSTP | MPRV  | MNXT  | MPLY  |       |  whom |  home |   ↓   |  end  |  wbak | wfwd  |
    * '-----------------------------------------------'       '-----------------------------------------------'
    */
    [_NAV] = LAYOUT_split_3x6_3(
    KC_LALT, KC_F13,  KC_PAUS, KC_BRID, KC_BRIU,   KC_PSCR,  /**/  KC_HOME,   KC_PGUP,   KC_UP,     KC_PGDN,      KC_END,  KC_WSCH,
    KC_ESC,  KC_F14,  KC_MUTE, KC_VOLD, KC_VOLU,   KC_INS,   /**/  KC_DEL,    KC_LEFT,   KC_DOWN,   KC_RIGHT,     KC_WREF, KC_BSPC,
    KC_LSFT, TG(_NAV),KC_MSTP, KC_MPRV, KC_MNXT,   KC_MPLY,  /**/  KC_WHOM,   KC_HOME,   KC_DOWN,   KC_END,       KC_WBAK, KC_WFWD,
                               KC_TRNS, KC_TRNS,   KC_TRNS,  /**/  KC_TRNS,   KC_TRNS,   KC_TRNS
  ),

};
// clang-format on
