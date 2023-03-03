#include QMK_KEYBOARD_H
#include "keymap.h"
#include "diacritics.h"

//
// LAYOUT
//

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BL] = LAYOUT(

  /*
   * ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   * |   ESC  |   1!   |   2@   |   3#   |   4$   |   5%   |                          |   6^   |   7&   |   8*   |   9(   |   0)   |  Bspc  |
   * ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   * |   Tab  |    Q   |    W   |    E   |    R   |    T   |                          |    Y   |    U   |    I   |    O   |    P   |   -_   |
   * ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   * |  Caps  |    A   |    S   |    D   |    F   |    G   |                          |    H   |    J   |    K   |    L   |   ;:   |   '"   |
   * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   * |   Del  |    Z   |    X   |    C   |    V   |    B   |  LGui  |        |   Ent  |    N   |    M   |   ,<   |   .>   |   /?   | RShift |
   * └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
   *                                | MO _FN |  LCtl  | LShift |                 |   Spc  |  RCtl  | MO _DC |
   *                                └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   */

    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_DEL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI,          KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                   MO(_FN), KC_LCTL, KC_LSFT,                   KC_SPC,  KC_RCTL, MO(_DC)
  ),

  [_FN] = LAYOUT(

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |                          |   F7   |   F8   |   F9   |   F10  |   F11  |   F12  |
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     * |  Snip  |   `~   |   Up   |        |        |        |                          |        |        |   [{   |   ]}   |   \|   |   =+   |
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     * |  Boot  |  Left  |  Down  |  Right |        |        |                          |        |        |        |        | RgbVa+ |  Vol+  |
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * |        |        |        |        |        |        |        |        |        |        |        |        |        | RgbVa- |  Vol-  |
     * └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
     *                                |        |  LCtl  | LShift |                 | RShift |        |        |
     *                                └────────┴────────┴────────┘                 └────────┴────────┴────────┘
     */


    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    SNIP,    KC_GRV,  KC_UP,   _______, _______, _______,                            _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, KC_EQL,
    QK_BOOT, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                            _______, _______, _______, _______, RGB_VAI, KC_VOLU,
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, RGB_VAD, KC_VOLD,
                                   _______, KC_LCTL, KC_LSFT,                   KC_RSFT, _______, _______
  ),

  [_DC] = LAYOUT(
     DC_GRAV, _______, _______, _______, _______, _______,                            DC_CIRC, _______, _______, _______, _______, _______,
     _______, _______, _______, DC_ACUT, _______, _______,                            _______, DC_DIAE, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     _______, _______, _______, DC_CEDL, _______, _______, _______,         _______, DC_TILD, _______, _______, _______, _______, _______,
                                    _______, _______, _______,                   _______, _______, _______
  ),
};

//
// KEY PROCESSING
//

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static enum dc_mode dc_mode = MD_REG;

  if (dc_mode > MD_REG && keycode >= KC_A && keycode <= KC_Z) {
    if (record->event.pressed) {
      tap_diacritic(dc_mode - MD_ACUTE, keycode);
      dc_mode = MD_REG;
    }
    return false;
  }

  switch (keycode) {
  case SNIP:
    if (record->event.pressed) {
      send_string(SS_LGUI(SS_LSFT("s")));
    }
    return false;

  case DC_ACUT:
    if (record->event.pressed) {
      dc_mode = MD_ACUTE;
    }
    return false;

  case DC_CIRC:
    if (record->event.pressed) {
      dc_mode = MD_CIRCUMFLEX;
    }
    return false;

  case DC_DIAE:
    if (record->event.pressed) {
      dc_mode = MD_DIAERESIS;
    }
    return false;

  case DC_GRAV:
    if (record->event.pressed) {
      dc_mode = MD_GRAVE;
    }
    return false;

  case DC_TILD:
    if (record->event.pressed) {
      dc_mode = MD_TILDE;
    }
    return false;

  case DC_CEDL:
    if (record->event.pressed) {
      dc_mode = MD_CEDILLA;
    }
    return false;

  default:
    return true;
  }
}
