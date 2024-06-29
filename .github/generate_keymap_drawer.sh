#!/bin/bash

generate_keymap_svg() {
    if [ "$#" -ne 3 ]; then
        echo "Usage: $0 <qmk_keymap_json> <output_file_name>"
        return 1
    fi

    local THEME=$1
    local QMK_KEYMAP_JSON=$2
    local OUTPUT_FILE_NAME=$3

    local DARK_CONFIG=$(
        cat <<EOF
draw_config:
    dark_mode: true
EOF
    )

    local LIGHT_CONFIG=$(
        cat <<EOF
draw_config:
    dark_mode: false
EOF
    )

    # Choose the appropriate configuration content based on the theme
    local CONFIG_CONTENT
    if [ "$THEME" = "dark" ]; then
        CONFIG_CONTENT="$DARK_CONFIG"
    elif [ "$THEME" = "light" ]; then
        CONFIG_CONTENT="$LIGHT_CONFIG"
    fi

    keymap parse -c 10 -q "$QMK_KEYMAP_JSON" | keymap -c <(echo "$CONFIG_CONTENT") draw - >"${OUTPUT_FILE_NAME}_${THEME}.svg"
}

for theme in "dark" "light"; do
    generate_keymap_svg "${theme}" "$1" "$2"
done
