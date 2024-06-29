#pragma once

// #define USE_MATRIX_I2C

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// #define QUICK_TAP_TERM 0
// #define TAPPING_TERM 100

#define OLED_FONT_H "keyboards/crkbd/keymaps/vbt/glcdfont.c"

#undef SPLIT_USB_DETECT
#define USB_VBUS_PIN 19U

#define OLED_BRIGHTNESS 10
#define SPLIT_OLED_ENABLE

#define TAPPING_TOGGLE 2
