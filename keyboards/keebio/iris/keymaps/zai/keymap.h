#pragma once
#include QMK_KEYBOARD_H

#define LED_FLAG_KEYS (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR)

#define CAPS_INDICATOR_KEY 61
#define OH_LAYER_INDICATOR_KEY 27
#define KB_LAYER_INDICATOR_KEY 52
#define SP_LAYER_INDICATOR_KEY 26

#define RGB_INDICATOR 0x7f, 0x3f, 0x00


enum layers {
  _BL = 0,
  _OH,
  _F1,
  _F2,
  _KP,
  _SY,
  _SP,
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

#define X_____X KC_TRNS

#define BSP_F1 LT(_F1, KC_BSPC)
#define ENT_SY LT(_SY, KC_ENT)
#define SP_F2 LT(_F2, KC_SPC)
#define MO_SF1 LM(_F1, MOD_LSFT)

#define ENT_LAYER ENT_SY
#define BSP_LAYER BSP_F1

#define SS_LCTL_LGUI(string) SS_LCTL(SS_LGUI(string))
