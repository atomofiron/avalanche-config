#include "quantum.h"
#include "rgblight.h"
#include <stdio.h> 
#include <stdlib.h>


#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) {
        for (int i = 0; i < 2; i++)
            clockwise ? tap_code(MS_WHLU) : tap_code(MS_WHLD);
    } else if (index == 1) {
        clockwise ? tap_code_delay(KC_VOLD, 10) : tap_code_delay(KC_VOLU, 10);
    }
    return true;
}
#endif

#define FPS 20

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void oled_render_boot(bool bootloader) {
    oled_clear();
    oled_set_cursor(0, 1);
    if (bootloader) {
        oled_write_P(PSTR("Awaiting new firmware..."), false);
    } else {
        oled_write_P(PSTR("Rebooting..."), false);
    }

    oled_render_dirty(true);
}

char* int_to_str(long int value) {
    int length = snprintf(NULL, 0, "%ld", value);
    char* str = malloc(length + 1);
    snprintf(str, length + 1, "%ld", value);
    return str;
}

static const char PROGMEM uwu[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x40, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x48, 0x02, 0x90, 0x00, 0x49, 0x00, 0x22, 0x08, 0x80, 0x24, 0x01, 0x90, 0x04, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x02, 0x00, 0x08, 0x02, 0x20, 0x09, 0x00, 0x24, 0x00, 0x12, 0x00, 0x04, 0x81, 0xC0, 0xE0, 0xF0, 0x70, 0x38, 0x38, 0x18, 0x18, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x18, 0x18, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0xFF, 0xFF, 0xC3, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x1E, 0x1C, 0x3C, 0x38, 0x38, 0x78, 0x78, 0x70, 0x70, 0x70, 0x30, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x7C, 0xEE, 0xC6, 0x86, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x3F, 0x73, 0x71, 0xE0, 0xE0, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0x70, 0x70, 0x38, 0x38, 0x18, 0x18, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x18, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0xFF, 0xC7, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x90, 0x00, 0x24, 0x00, 0x48, 0x02, 0x20, 0x84, 0x10, 0x40, 0x08, 0x20, 0x81, 0x03, 0x07, 0x0F, 0x0E, 0x1E, 0x1C, 0x1C, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x18, 0x18,
    0x00, 0x00, 0x00, 0x04, 0x20, 0x89, 0x00, 0x44, 0x11, 0x00, 0x48, 0x02, 0x20, 0x89, 0x00, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

typedef union {
  uint32_t raw;
  struct {
    long int counter :32;
  };
} config_t;

config_t config;

bool debug = false;
int frame_counter = 0;
long int counter = 0;
int idle_counter = 0;

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (idle_counter < FPS * 3) {
        idle_counter++;
    } else {
        return false;
    }

    int offset = (counter > 99999) ? 1 : 0;
    oled_set_cursor(0, offset);
    if (!debug) oled_write_raw_P(uwu, sizeof(uwu));

    bool invert = false;
    frame_counter++;
    if (frame_counter == FPS * 3) {
        frame_counter = 0;
        if (counter != config.counter) {
            config.counter = counter;
            eeconfig_update_user(config.raw);
            invert = true;
        }
    }
    char* str = int_to_str(counter);
    offset = 5 - strlen(str);
    oled_set_cursor((offset < 0) ? 0 : offset, 0);
    oled_write(str, invert);
    free(str);

    if (debug) {
        bool left = is_keyboard_left();
        oled_set_cursor(left ? 1 : 0, 15);
        char* label = left ? "left" : "right";
        oled_write(label, false);
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    idle_counter = 0;
    if (record->event.pressed) {
        counter++;
        frame_counter = 0;
    }
    return true;
}
#endif

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 2, HSV_RED},
    {7, 2, HSV_RED},
    {12, 2, HSV_RED},
    {17, 2, HSV_RED},
    {22, 2, HSV_RED},
    {26, 2, HSV_RED},
    {28, 1, HSV_RED},
    {30, 2, HSV_RED},
    {33, 2, HSV_RED},
    {39, 2, HSV_RED},
    {44, 2, HSV_RED},
    {49, 2, HSV_RED},
    {54, 2, HSV_RED},
    {58, 2, HSV_RED},
    {60, 1, HSV_RED},
    {62, 2, HSV_RED}
);
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
#ifdef OLED_ENABLE
    config.raw = eeconfig_read_user();
    counter = config.counter;
#endif
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}
