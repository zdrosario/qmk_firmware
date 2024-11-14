// Copyright 2022 Sergey Vlasov (@sigprof)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// clang-format off

#define LAYOUT_via(             \
      k17,     k15,    k16,     \
    k23,k22, k19,k18, k21,k20,  \
     k00, k01, k02, k03, k04,   \
     k05, k06, k07, k08, k09,   \
     k10, k11, k12, k13, k14    \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k20, k21, k22, k23 } \
}

#define U_LTESC LT(1, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_via(
            MO(1),           MO(1),           MO(1),
        KC_PGUP, KC_PGDN,  KC_VOLD, KC_VOLU,  KC_MPRV, KC_MNXT,
             RGB_TOG,    KC_2,    KC_3,    KC_4,    KC_5,
             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
             U_LTESC, KC_TAB,  KC_SPC,  KC_BSPC, KC_ENT
    ),
    [1] = LAYOUT_via(
            _______,           _______,           _______,
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
             RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,
             RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,
             _______, RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R
    ),
    [2 ... 7] = LAYOUT_via(
            _______,           _______,           _______,
        _______, _______,  _______, _______,  _______, _______,
             _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case RGB_TOG:
    if (record->event.pressed) {
      led_flags_t flags = rgb_matrix_get_flags();
      rgb_matrix_set_flags(flags ^ LED_FLAG_ALL);
    }
    return false;
  }

  return true;
}


// clang-format on
