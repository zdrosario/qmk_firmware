#include QMK_KEYBOARD_H
#include "keymap.h"

/*
 * ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
 * |        |        |        |        |        |        |                          |        |        |        |        |        |        |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |        |        |        |        |        |        |                          |        |        |        |        |        |        |
 * ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
 * |        |        |        |        |        |        |                          |        |        |        |        |        |        |
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
 *                                |        |        |        |                 |        |        |        |
 *                                └────────┴────────┴────────┘                 └────────┴────────┴────────┘
 */

//
// LAYOUT
//

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BL] = LAYOUT(

  /*
   * ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   * |   ESC  |   1!   |   2@   |   3#   |   4$   |   5%   |                          |   6^   |   7&   |   8*   |   9(   |   0)   |  Bspc  |
   * ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   * |   Tab  |    Q   |    W   |    E   |    R   |    T   |                          |    Y   |    U   |    I   |    O   |    P   |  Enter |
   * ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   * |  Caps  |    A   |    S   |    D   |    F   |    G   |                          |    H   |    J   |    K   |    L   |   ;:   |   '"   |
   * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   * | LShift |    Z   |    X   |    C   |    V   |    B   |  LGui  |        |  LGui  |    N   |    M   |   ,<   |   .>   |   /?   | RShift |
   * └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
   *                                |  LCtl  |  Space | LShift |                 |Bspc/_F2| Ent/_F1|  LAlt  |
   *                                └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   */

    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI,          KC_LGUI, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                   KC_LCTL, KC_SPC,  KC_LSFT,                   BSP_F2, ENT_F1,  KC_LALT
  ),

  [_F1] = LAYOUT(

  /*
   * ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   * |   `~   |        |        |        |        |        |                          |        |        |        |   -_   |   =+   |   Del  |
   * ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   * |        |        |        |        |        |        |                          |        |        |   Up   |   [{   |   ]}   |   \|   |
   * ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   * |  Caps  |        |        |        |        |        |                          |        |  Left  |  Down  |  Right |        |        |
   * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   * | Transp |        |        |        |        |        | Transp |        | Transp |        |        |        |        |        | Transp |
   * └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
   *                                | Transp |        | Transp |                 | Transp | Transp | Transp |
   *                                └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   */


    KC_GRV,  _______, _______, _______, _______, _______,                            _______, _______, _______, KC_MINS, KC_EQL,  KC_DEL,
    _______, _______, _______, _______, _______, _______,                            _______, _______, KC_UP,   KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CAPS, _______, _______, _______, _______, _______,                            _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    KC_TRNS, _______, _______, _______, _______, _______, KC_TRNS,          KC_TRNS, _______, _______, _______, _______, _______, KC_TRNS,
                                   KC_TRNS, _______, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_F2] = LAYOUT(

  /*
   * ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   * |   F12  |   F1   |   F2   |   F3   |   F4   |   F5   |                          |   F6   |   F7   |   F8   |   F9   |   F10  |   F11  |
   * ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   * |        |        | CtWnUp |        |        |        |                          |        | PrtScr | Insert | Delete | PageUp |  Home  |
   * ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   * |        | CtWnLt | CtWnDn | CtWnRt |        |        |                          |        | Media< |  Media | Media> | PageDn |   End  |
   * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   * | Transp |        |        |        |        |        | Transp |        | MO _F3 |        |  Mute  |  Vol-  |  Vol+  |        | Transp |
   * └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
   *                                | Transp |        | Transp |                 | Transp | Transp | Transp |
   *                                └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   */

    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______, CW_UP,   _______, _______, _______,                            _______, KC_PSCR, KC_INS,  KC_DEL,  KC_PGUP, KC_HOME,
    _______, CW_LEFT, CW_DOWN, CW_RGHT, _______, _______,                            _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_PGDN, KC_END,
    KC_TRNS, _______, _______, _______, _______, _______, KC_TRNS,          MO(_F3), _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_TRNS,
                                   KC_TRNS, _______, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_F3] = LAYOUT(

  /*
   * ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   * |        |        |        |        |        |        |                          |        |        |        |        |        |        |
   * ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   * |  Boot  |        |        |        |        |        |                          |        |        |        |        |        |        |
   * ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   * |        |        | RGB V+ | RGBSa+ | RGBHu+ | RGBMod |                          |        |        |        |        |        |        |
   * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   * | Transp |        | UG Tog | BL Tog | RGBSp+ | RGB Pl |        |        | Transp |        |        |        |        |        | Transp |
   * └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
   *                                |        |        | Transp |                 | Transp | Transp |        |
   *                                └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   */

    _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    QK_BOOT, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    _______, _______, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,                            _______, _______, _______, _______, _______, _______,
    KC_TRNS, _______, UG_TOG,  BL_TOG,  RGB_SPI, RGB_M_P, _______,          KC_TRNS, _______, _______, _______, _______, _______, KC_TRNS,
                                   _______, _______, KC_TRNS,                   KC_TRNS, KC_TRNS, _______
  )
};

//
// KEY PROCESSING
//

void register_code_no_shift(uint16_t keycode, uint8_t mod_state) {
  del_mods(MOD_MASK_SHIFT);
  register_code(keycode);
  set_mods(mod_state);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static bool delkey_registered = false;
  static bool tabkey_registered = false;

  uint8_t mod_state = get_mods();

  switch (keycode) {

  //
  // NEW KEYCODES
  //

  case CW_UP:
    if (record->event.pressed) {
      send_string(SS_LCTL_LGUI(SS_TAP(X_UP)));
    }
    return false;

  case CW_DOWN:
    if (record->event.pressed) {
      send_string(SS_LCTL_LGUI(SS_TAP(X_DOWN)));
    }
    return false;

  case CW_LEFT:
    if (record->event.pressed) {
      send_string(SS_LCTL_LGUI(SS_TAP(X_LEFT)));
    }
    return false;

  case CW_RGHT:
    if (record->event.pressed) {
      send_string(SS_LCTL_LGUI(SS_TAP(X_RIGHT)));
    }
    return false;

  case BL_TOG:
    if (record->event.pressed) {
      led_flags_t flags = rgb_matrix_get_flags();
      rgb_matrix_set_flags(flags ^ LED_FLAG_KEYLIGHT);
    }

    return false;

  case UG_TOG:
    if (record->event.pressed) {
      led_flags_t flags = rgb_matrix_get_flags();
      rgb_matrix_set_flags(flags ^ LED_FLAG_UNDERGLOW);
    }

    return false;

  //
  // MODIFIED KEYCODES
  //

  // shift + backspace -> KC_DEL
  // shift + space -> KC_TAB

  case KC_BSPC:
    // shift + KC_BSPC: pressed
    if (record->event.pressed && (mod_state & MOD_MASK_SHIFT)) {
      register_code_no_shift(KC_DEL, mod_state);
      delkey_registered = true;
      return false;

    // shift + KC_BSPC: KC_BSPC released
    } else if (!(record->event.pressed) && delkey_registered) {
      unregister_code(KC_DEL);
      delkey_registered = false;
      return false;
    }

    return true;

  case BSP_F2:
    // shift + BSP_F2: pressed
    if (record->event.pressed && (mod_state & MOD_MASK_SHIFT)) {
      // no hold for BSP_F2
      tap_code(KC_DEL);
      return false;
    }

    return true;

  case KC_SPC:
    // shift + KC_SPC: pressed
    if (record->event.pressed && (mod_state & MOD_MASK_SHIFT)) {
      register_code_no_shift(KC_TAB, mod_state);
      tabkey_registered = true;
      return false;

    // shift + KC_SPC: KC_SPC released
    } else if (!(record->event.pressed) && tabkey_registered) {
      unregister_code(KC_TAB);
      tabkey_registered = false;
      return false;
    }

    return true;

  case KC_LSFT:
  case KC_RSFT:
    // shift + KC_BSPC: shift unreleased
    if (!(record->event.pressed) && delkey_registered) {
      unregister_code(KC_DEL);
      delkey_registered = false;
      register_code(KC_BSPC);
    } 
    
    // shift + KC_SPC: shift unreleased
    else if (!(record->event.pressed) && tabkey_registered) {
      unregister_code(KC_TAB);
      delkey_registered = false;
      register_code(KC_SPC);
    }

    // process as usual after
    return true;
  }

  return true;
}
