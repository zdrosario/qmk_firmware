#pragma once
#include QMK_KEYBOARD_H

enum layers {
  _BL = 0,
  _F1,
};

enum cust_keycodes {
  U_T_AUTO = SAFE_RANGE,
  U_T_AGCR,
  BL_TOG,
  UG_TOG,
};

#undef _______
#define _______ KC_NO

#define LED_FLAG_KEYS (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR)
