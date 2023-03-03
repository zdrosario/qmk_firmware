#pragma once
#include QMK_KEYBOARD_H

#define NO_CODE { 0, 0 }

enum diacritic {
  D_ACUTE = 0,
  D_CIRCUMFLEX,
  D_DIAERESIS,
  D_GRAVE,
  D_TILDE,
  D_CEDILLA,
};

void tap_diacritic(enum diacritic d, uint16_t keycode);

void tap_alt_code(uint16_t code);
