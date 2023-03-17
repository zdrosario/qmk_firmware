RGB_MATRIX_EFFECT(CUSTOM_REACTIVE)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV CUSTOM_REACTIVE_math(HSV hsv, uint16_t offset) {
    hsv.s = (offset < hsv.s) ? offset : hsv.s;
    return hsv;
}

bool CUSTOM_REACTIVE(effect_params_t* params) {
    return effect_runner_reactive(params, &CUSTOM_REACTIVE_math);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
