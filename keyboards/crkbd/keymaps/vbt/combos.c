const uint16_t PROGMEM del_combo[]     = {KC_ESC, KC_BSPC, COMBO_END};
const uint16_t PROGMEM spc_ent_combo[] = {KC_SPC, KC_ENT, COMBO_END};

// clang-format off
combo_t key_combos[] = {
    COMBO(del_combo, KC_DEL),
    COMBO(spc_ent_combo, TO(_DVORAK)),
};
// clang-format on
