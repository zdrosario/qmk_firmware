#pragma once
#include QMK_KEYBOARD_H

enum layers {
  _BL = 0,
  _F1,
  _F2,
  _F3,
};

enum cust_keycodes {
  CW_UP = SAFE_RANGE,
  CW_DOWN,
  CW_LEFT,
  CW_RGHT,
  BL_TOG,
  UG_TOG,
};

#undef _______
#define _______ KC_NO

#define ENT_F1 LT(_F1, KC_ENT)
#define BSP_F2 LT(_F2, KC_BSPC)

#define SS_LCTL_LGUI(string) SS_LCTL(SS_LGUI(string))
