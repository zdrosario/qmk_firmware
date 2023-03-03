#pragma once
#include QMK_KEYBOARD_H

enum layers {
  _BL = 0,
  _FN,
  _DC,
};

enum cust_keycodes {
  SNIP = SAFE_RANGE,
  DC_ACUT,
  DC_CIRC,
  DC_DIAE,
  DC_GRAV,
  DC_TILD,
  DC_CEDL,
  IV_EXLM,
  IV_QUES,
};

enum dc_mode {
  MD_REG = 0,
  MD_ACUTE,
  MD_CIRCUMFLEX,
  MD_DIAERESIS,
  MD_GRAVE,
  MD_TILDE,
  MD_CEDILLA,
};
