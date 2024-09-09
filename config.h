#pragma once

#define USE_I2C
#define MASTER_LEFT
#define SPLIT_USB_DETECT
#define EE_HANDS
#define RGBLIGHT_LAYERS
//#define CONSOLE_ENABLE // rules.mk only?
//#define OLED_DRIVER_ENABLE // rules.mk
//#define SPLIT_OLED_ENABLE // rules.mk
//#define RGBLIGHT_EFFECT_TWINKLE // json
//#define RGBLIGHT_EFFECT_TWINKLE_PROBABILITY 32/127

//#define OLED_ENABLE // rules.mk caused by "fatal error: oled_driver.h: No such file or directory"
#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X32
#    define OLED_TIMEOUT 30000
#endif

// qmk flash -kb avalanche/v2 -km default -bl avrdude-split-left
// qmk flash -kb avalanche/v2 -km default -bl avrdude-split-right
// make avalanche/v2:default:avrdude-split-left
// make avalanche/v2:default:avrdude-split-right
