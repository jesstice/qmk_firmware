//
// Render left OLED display
//
static void render_oled(void) {
    
    // WPM
    oled_write_P(PSTR("      "), false);
    sprintf(wpm_str, "%03d", get_current_wpm());
    oled_write(wpm_str, false);
    oled_write_P(PSTR("   WPM"), false);

    // GUI keys indicator
    if (gui_on) oled_write_P(PSTR("\n       "), false);
    else oled_write_P(PSTR("\n      GUI   OFF"), false);
    
    // Caps lock indicator
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("\n      CAPS LOCK") : PSTR("\n       "), false);

    // Layer indicator
    oled_write_P(PSTR("\n      LAYER "), false);

    switch (get_highest_layer(layer_state)) {
        // Layer 1
        case 1:
            oled_write_P(PSTR("  1"), false);
            break;
        // Layer 0
        default:
            oled_write_P(PSTR("  0"), false);
            break;
    }

    // Caps lock indicator on RGB underglow
    uint16_t underglow_brightness = rgblight_get_val();

    if (led_state.caps_lock) rgblight_sethsv(213, 255, underglow_brightness);
    else if (layer_state == 0) rgblight_sethsv(128, 255, underglow_brightness);
}
