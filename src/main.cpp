/* Ledding - a fancy LED project */

#include <Arduino.h>
#include <FastLED.h>

/* include global instances of leds, animator, buttons, ota and effects */
#include "globals.h"

void setup() {
	FastLED.addLeds<WS2812B, LED_DATA_PIN, GRB>(leds, NUM_LEDS);
	FastLED.setBrightness(DEF_GLOBAL_BRIGHTNESS);
	FastLED.setDither();

	pinMode(BUILTIN_LED, OUTPUT);

#ifdef SERIAL_PRINT
	Serial.begin(115200);
#endif

	/* setup the effects */
	staticEffect.configure(CRGB::DeepPink);
	animator.addEffect(Animator::ANIMATOR_CONSTANT, &staticEffect);

	/* turn on builtin LED */
//	digitalWrite(BUILTIN_LED, HIGH);

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
