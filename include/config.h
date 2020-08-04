#ifndef CONFIG_H
#define CONFIG_H

#include <IPAddress.h>
#include <FastLED.h>

/*! Configuration of the project
 *
 * All config parameters which are defined extern are located in `config.cpp`
 */

/*************************/
/* dynamic configuration */
/*************************/
/*! \brief Print all actions on serial */
#define SERIAL_PRINT

/*! \brief Activate developing mode, currently
 * - extra button on dev board
 */
#define DEV_MODE


extern const char* SSID;
extern const char* WIFI_PSK;
extern const char* OTA_PW;


/************************/
/* static configuration */
/************************/
/*! \brief Total number of LEDs */
#define NUM_LEDS 150

/* for pin configuration, please check doc/pinout_maite.ods */
/*! \brief GPIO on which the data signal of the WS2812B is connected */
#define LED_DATA_PIN 23


/*! \brief GPIO for the built-in LED */
#define BUILTIN_LED 2

/*! \brief Touch button definitions
 *
 * Layout on Maites version:
 * BRT_INC   MODE_NEXT   COLOR_NEXT   INTENSITY_INC
 * BRT_DEC   MODE_NEXT   COLOR_PREV   INTENSITY_DEC
 *
 * If using JTAG, one cannot use the GPIOs linked to that for touch (12 - 15).
 * This will be handled in the Buttons class, here we only need to change the button count
 */
#ifdef DEBUG_JTAG
	#define TOUCH_BUTTON_COUNT    4
#else
	#define TOUCH_BUTTON_COUNT    8
#endif

#define BUTTON_BRT_INC       14
#define BUTTON_BRT_DEC       27
#define BUTTON_MODE_NEXT     15
#define BUTTON_MODE_PREV      4
#define BUTTON_COLOR_NEXT    33 /* this should be GPIO32 */
#define BUTTON_COLOR_PREV    32 /* this should be GPIO33, dont know where the mixup is */
#define BUTTON_INTENSITY_INC 13
#define BUTTON_INTENSITY_DEC 12

/*! \brief Threshold value of the touch button
 *
 * This is highly depenend on the concrete realization and should be tested in each device
 * If the actual value which was read was below this twice in a row, the button is considered pressed.
 * Twice because there a some occasional bogus reads below the threshold although it was not pressed.
 */
#define TOUCH_BUTTON_THRESHOLD 20

/*! \brief How often are the button states polled in ms */
#define BUTTON_CHECK_RES 100

/*! \brief Resolution of the state machine (i.e. the delay each round) in ms */
#define STATE_MACHINE_RES 1

/*! \brief Default global brightness to start with */
#define DEF_GLOBAL_BRIGHTNESS 200


extern const IPAddress OWN_IP_ADDRESS;
extern const IPAddress SUBNET;

extern const uint16_t OTA_PORT;

/*! \brief These colors are choseable by button */
extern const CRGB::HTMLColorCode COLOR_PALETTE[];
extern const int COLOR_PALETTE_SIZE;

#ifdef DEV_MODE
/*! \brief GPIO on which the button (which pulls to GND when pressed) is connected */
/* on dev sample, not Maites build */
#define DEV_BUTTON_PIN 18
#endif /* DEV_MODE */

/* tmp */
#define MIC_PIN 13
#define DC_OFFSET 0
#define SQUELCH 0


#endif /* end of include guard: CONFIG_H */
