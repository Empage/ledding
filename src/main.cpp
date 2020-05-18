/* Ledding - a fancy LED project */

#include <Arduino.h>
#include <FastLED.h>

/* include global instances of leds, animator, buttons and ota */
#include "globals.h"

void setup() {
	FastLED.addLeds<WS2812B, LED_DATA_PIN, GRB>(leds, NUM_LEDS);
	FastLED.setBrightness(DEF_GLOBAL_BRIGHTNESS);
	FastLED.setDither();

	//TODO [MPH]
	pinMode(2, OUTPUT);

#ifdef SERIAL_PRINT
	Serial.begin(115200);
#endif

	myeffect.configure(CRGB::Blue);
	animator.addEffect(Animator::ANIMATOR_CONSTANT, &myeffect);

	//TODO [MPH]
	/* turn off builtin LED */
	digitalWrite(2, HIGH);
	Serial.printf("COLOR_PALETTE_SIZE: %d\n", COLOR_PALETTE_SIZE);

	ota.init();
}

void loop() {
	ota.handleOta();

	EVERY_N_MILLISECONDS(STATE_MACHINE_RES) {
		animator.runStateMachine();
	}

	EVERY_N_MILLISECONDS(BUTTON_CHECK_RES) {
		buttons.handleButtons();
	}
}
