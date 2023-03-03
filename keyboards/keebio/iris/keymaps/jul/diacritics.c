#include "diacritics.h"

const uint16_t diacritic_map[][26][2] = {
  [D_ACUTE] = {
    { 225, 193 },
    NO_CODE,
    { 263, 262 },
    NO_CODE,
    { 233, 201 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    { 237, 205 },
    NO_CODE,
    NO_CODE,
    { 314, 313 },
    NO_CODE,
    { 324, 323 },
    { 243, 211 },
    NO_CODE,
    NO_CODE,
    { 341, 340 },
    { 347, 346 },
    NO_CODE,
    { 250, 218 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    { 253, 221 },
    { 378, 377 },
  },

 [D_CIRCUMFLEX] = {
    { 226, 194 },
    NO_CODE,
    { 265, 264 },
    NO_CODE,
    { 234, 202 },
    NO_CODE,
    { 285, 284 },
    { 293, 292 },
    { 238, 206 },
    { 309, 308 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
    { 244, 212 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    { 349, 348 },
    NO_CODE,
    { 251, 219 },
    NO_CODE,
    { 373, 372 },
    NO_CODE,
    { 375, 374 },
    NO_CODE,
  },

  [D_DIAERESIS] = {
    { 228, 196 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    { 235, 203 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    { 239, 207 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
    { 246, 214 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
    { 252, 220 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    { 255, 376 },
    NO_CODE,
  },

  [D_GRAVE] = {
    { 224, 192 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    { 232, 200 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    { 236, 204 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
    { 242, 210 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
    { 249, 217 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
  },

  [D_TILDE] = {
    { 227, 195 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
    { 297, 296 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
    { 241, 209 },
    { 245, 213 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
    { 361, 360 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
  },

  [D_CEDILLA] = {
    NO_CODE,
    NO_CODE,
    { 231, 199 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    { 291, 290 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    { 311, 310 },
    { 316, 315 },
    NO_CODE,
    { 326, 325 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    { 343, 342 },
    { 351, 350 },
    { 355, 354 },
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
    NO_CODE,
  },
};

const uint16_t kc_map[10] = {
  KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4,
  KC_KP_5, KC_KP_6, KC_KP_7, KC_KP_8, KC_KP_9,
};

void tap_alt_code(uint16_t code) {
  uint8_t mod_state = get_mods();
  bool numlock_on = host_keyboard_led_state().num_lock;

  del_mods(MOD_MASK_SHIFT);
  if (!numlock_on) tap_code(KC_NUM);

  uint16_t a = kc_map[(code / 100) % 10];
  uint16_t b = kc_map[(code / 10) % 10];
  uint16_t c = kc_map[code % 10];

  register_code(KC_LALT);
  tap_code(KC_KP_0);
  tap_code(a);
  tap_code(b);
  tap_code(c);
  unregister_code(KC_LALT);

  if (!numlock_on) tap_code(KC_NUM);
  set_mods(mod_state);
}

void tap_diacritic(enum diacritic d, uint16_t kc) {
  bool shifted = get_mods() & MOD_MASK_SHIFT;
  bool caps = host_keyboard_led_state().caps_lock;

  uint16_t code = diacritic_map[d][kc - KC_A][shifted || (caps && !shifted)];
  if (code == 0) return;

  tap_alt_code(code);
}
