#include QMK_KEYBOARD_H
#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_F1), KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_F1] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_INS,
        QK_BOOT, _______, RGB_VAD, RGB_SAD, RGB_HUD, RGB_SPD, _______, U_T_AUTO,U_T_AGCR,_______, KC_PSCR, KC_SCRL, KC_PAUS, _______, KC_END,
        _______, _______, RGB_VAI, RGB_SAI, RGB_HUI, RGB_SPI, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,          _______, KC_VOLU,
        KC_TRNS, _______, UG_TOG,  BL_TOG,  RGB_MOD, RGB_M_P, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,          _______, KC_VOLD,
        KC_TRNS, KC_TRNS, KC_TRNS,                            _______,                            KC_TRNS, KC_TRNS, _______, _______, _______
    ),

    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______
    ),
    */
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    //
    // Custom keycodes
    //

    case BL_TOG:
        if (record->event.pressed) {
            led_flags_t flags = rgb_matrix_get_flags();
            rgb_matrix_set_flags(flags ^ LED_FLAG_KEYS);
        }
        return false;

    case UG_TOG:
        if (record->event.pressed) {
            led_flags_t flags = rgb_matrix_get_flags();
            rgb_matrix_set_flags(flags ^ LED_FLAG_UNDERGLOW);
        }
        return false;

    //
    // Alt keycodes
    //

    case U_T_AUTO:
        if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
            TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
        }
        return false;

    case U_T_AGCR:
        if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
            TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
        }
        return false;


    default:
        return true;
    }
}
