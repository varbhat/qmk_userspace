// OLED
// #define OLED_ENABLE
#ifdef OLED_ENABLE

static const char PROGMEM font_logo[16] = {0x80, 0x81, 0x82, 0x83, 0x84, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P((modifiers & MOD_MASK_SHIFT) ? PSTR("Shift\n") : PSTR("     \n"), false);
    oled_write_P((modifiers & MOD_MASK_CTRL) ? PSTR("Ctrl\n") : PSTR("    \n"), false);
    oled_write_P((modifiers & MOD_MASK_ALT) ? PSTR("Alt \n") : PSTR("    \n"), false);
    oled_write_P((modifiers & MOD_MASK_GUI) ? PSTR("Super\n") : PSTR("     \n"), false);
}

void render_lock_status(led_t led_state) {
    oled_write_P(led_state.caps_lock ? PSTR("CAPS\n") : PSTR("    \n"), false);
}

void render_layer_status(void) {
    switch (get_highest_layer(layer_state)) {
        case _DVORAK:
            oled_write("DVK", false);
            break;
        case _NUM:
            oled_write("NUM", false);
            break;
        case _SYM:
            oled_write("SYM", false);
            break;
        case _NAV:
            oled_write("NAV", false);
            break;
        case _QWERTY:
            oled_write("QWR", false);
            break;
        default:
            oled_write("UNK", false);
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_lock_status(host_keyboard_led_state());
        render_mod_status(get_mods() | get_oneshot_mods());
        oled_set_cursor(0, 15);
        render_layer_status();
    } else {
        oled_write_P(font_logo, false);
        oled_write("corne", false);
        oled_set_cursor(0, 14);
        oled_write("crkbd", false);
        oled_set_cursor(0, 15);
        oled_write("vbt", false);
    }
    return false;
}

#endif
