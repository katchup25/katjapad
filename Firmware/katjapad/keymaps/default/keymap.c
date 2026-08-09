// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    POMODORO = SAFE_RANGE,
    TODO,
    STUDYMUS
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case POMODORO:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(" "));
                wait_ms(500);
                SEND_STRING("https://www.youtube.com/watch?v=WIt8cNOMkwc\n");
            }
            return false;
        case TODO:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(" "));
                wait_ms(500);
                SEND_STRING("https://docs.google.com/document/d/1rvRnc8ZrVPfEkS0OX7QDdP5j68V8ydcS357zTP5Jklo/edit?tab=t.0\n");
            }
            return false;
        case STUDYMUS:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(" "));
                wait_ms(500);
                SEND_STRING("https://www.youtube.com/watch?v=lTRiuFIWV54\n");
            }
            return false;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        POMODORO,    TODO,        STUDYMUS,
        LGUI(KC_C),  LGUI(KC_V),  LGUI(KC_T),
        KC_MPRV,     KC_MPLY,     KC_MNXT
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return false;
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_write_P(PSTR("katjapad\n"), false);
    oled_write_P(PSTR("----------------\n"), false);
    oled_write_P(PSTR("productivity\n"), false);
    oled_write_P(PSTR("+ media\n"), false);
    return false;
}
#endif
