#pragma once
#include QMK_KEYBOARD_H

#define LED_FLAG_KEYS (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR)

enum layers {
  _BL = 0,
  _FN,
  _KP,
  _SY,
  _KB,
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

#define ENT_FN LT(_FN, KC_ENT)
#define BSP_SY LT(_SY, KC_BSPC)
#define SP_ALT LALT_T(KC_SPC)
#define MO_SF1 LM(_FN, MOD_LSFT)

#define ENT_LAYER ENT_SY
#define BSP_LAYER BSP_FN

#define SS_LCTL_LGUI(string) SS_LCTL(SS_LGUI(string))
