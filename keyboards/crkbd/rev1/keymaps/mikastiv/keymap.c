#include QMK_KEYBOARD_H

// enum custom_keycodes {
//   DEFAULT = SAFE_RANGE,
//   LOWER,
//   RAISE,
//   FUNC,
//   GLOWER
// };

enum combos {
  GAME,
  JK_ESC
};


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers {
  DEFAULT,
  LOWER,
  RAISE,
  FUNC,
  GAMING,
  GAMING_LOWER
};

const uint16_t PROGMEM gaming_combo[] = {KC_Y, KC_DEL, COMBO_END};
const uint16_t PROGMEM jk_esc_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [GAME]    = COMBO(gaming_combo, TO(GAMING)),
  [JK_ESC]    = COMBO(jk_esc_combo, KC_ESC),
};

// For DEFAULT layer
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSL_FUN  OSL(FUNC)
#define GUI_ENT  GUI_T(KC_ENT)
#define LOW_TAB  LT(LOWER, KC_TAB)
#define RSE_BSP  LT(RAISE, KC_BSPC)

// For _GAMING layer
#define MO_LOW MO(GAMING_LOWER)
#define TO_DEF TO(DEFAULT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEFAULT] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     OSM_LALT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_UNDS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     OSM_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, OSL_FUN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         OSM_LCTL, LOW_TAB,  KC_SPC,    KC_RSFT, RSE_BSP, GUI_ENT
                                      //`--------------------------'  `--------------------------'
  ),

  [LOWER] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_GRV, KC_TILD, KC_PIPE, KC_LCBR, KC_LBRC,                      KC_RBRC, KC_RCBR, KC_DQUO, KC_QUOT, KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         MOD_LCTL, XXXXXXX, _______,    _______, _______,  KC_ENT
                                      //`--------------------------'  `--------------------------'
    ),

  [RAISE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, KC_PIPE, KC_AMPR, KC_EXLM, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_PLUS, KC_MINS,  KC_EQL, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX,   KC_LT,   KC_GT, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_PSCR, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_ESC, _______, _______,    _______, XXXXXXX, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [FUNC] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, RGB_TOG, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_HUD, RGB_SAD, RGB_VAD,RGB_RMOD, QK_BOOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [GAMING] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_UNDS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  TO_DEF,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL,  MO_LOW,  KC_SPC,    KC_RSFT, KC_BSPC, GUI_ENT
                                      //`--------------------------'  `--------------------------'
  ),

  [GAMING_LOWER] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_GRV, KC_TILD, KC_PIPE, KC_LBRC, KC_LCBR,                      KC_RCBR, KC_RBRC, KC_DQUO, KC_QUOT, KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, XXXXXXX, _______,    _______, _______,  KC_ENT
                                      //`--------------------------'  `--------------------------'
    )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case RSE_BSP:
      case LOW_TAB:
            return TAPPING_TERM_THUMB;
      default:
            return TAPPING_TERM;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSE_BSP:
        case LOW_TAB:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

#define CUSTOM_CYAN        150, 255, RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define CUSTOM_ORANGE       15, 255, RGB_MATRIX_MAXIMUM_BRIGHTNESS

void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(CUSTOM_CYAN);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case GAMING:
        case GAMING_LOWER:
            rgb_matrix_sethsv_noeeprom(CUSTOM_ORANGE);
            break;
        default:
            rgb_matrix_sethsv_noeeprom(CUSTOM_CYAN);
            break;
    }
    return false;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return rotation;
}

static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,192,224, 96, 48, 16,  8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,248,252,254,207,199,135,135,135,  7,  7,  7, 15, 31,254,252,248,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,  7,  7,  7,  7,  7,  7,135,199,231,247,127, 63, 31, 15,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255, 15, 15,  7,  3,  9, 12, 14, 15, 15, 15, 15,143,207,239,255,255,255,127, 63, 31, 15,  7,  3,  9, 12, 14, 15,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 28, 60,124,240,224,224,224,224,224,224,224,240,248,127, 63, 31,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,224,240,248,252,254,239,231,227,225,224,224,224,224,224,224,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,240,112, 48,144,192,224,240,248,252,254,255,255,255,247,243,241,240,240,240,240,112, 48,144,192,224,240,240,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 16,  8, 12,  6,  7,  3,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

static void render_layer_state(void) {
    // Host Keyboard Layer Status
    oled_write_ln_P(PSTR(""), false);
    oled_write_P(PSTR("Layer: "), false);

    const char *msg;
    switch (get_highest_layer(layer_state)) {
        case DEFAULT:
            msg = PSTR("Default");
            break;
        case LOWER:
            msg = PSTR("Lower");
            break;
        case RAISE:
            msg = PSTR("Raise");
            break;
        case FUNC:
            msg = PSTR("Function");
            break;
        case GAMING:
            msg = PSTR("Gaming");
            break;
        case GAMING_LOWER:
            msg = PSTR("Gaming Lower");
            break;
        default:
            msg = PSTR("Undef");
            break;
    }

    oled_write_ln_P(msg, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_layer_state();
    } else {
        render_logo();
        oled_scroll_left();
    }

    return false;
}
#endif

#ifdef RGBLIGHT_SLEEP
static uint32_t key_timer;
static bool is_rgb_timeout = false;

static void refresh_rgb(void) {
    key_timer = timer_read32();
    if (is_rgb_timeout)
    {
        is_rgb_timeout = false;
        rgblight_wakeup();
    }
}

static void check_rgb_timeout(void) {
    if (!is_rgb_timeout && timer_elapsed32(key_timer) > RGBLIGHT_TIMEOUT) {
        rgblight_suspend();
        is_rgb_timeout = true;
    }
}

void housekeeping_task_user(void) {
#ifdef RGBLIGHT_TIMEOUT
    check_rgb_timeout();
#endif
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef RGBLIGHT_TIMEOUT
    if (record->event.pressed)
        refresh_rgb();
#endif
}

void post_encoder_update_user(uint8_t index, bool clockwise) {
#ifdef RGBLIGHT_TIMEOUT
    refresh_rgb();
#endif
}
#endif
