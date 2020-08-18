/* Ledding - a fancy LED project */

#include <Arduino.h>
#include <FastLED.h>
#include <config.h>

/* include global instances of leds, animator, buttons, ota and effects */
#include "globals.h"

void setupMaite() {
	animator.mode = Animator::ANIMATOR_CONSTANT;
}

void setupPartyraum() {
	/* setup connection to RPi */
    Serial2.begin(115200, SERIAL_8N1, SERIAL_TO_RPI_RXD2, SERIAL_TO_RPI_TXD2);

	/* setup partyraum specifc effects */
	arcEffect.configure(CRGB::Blue, CRGB::Green);
	animator.addEffect(Animator::ANIMATOR_ARC, &arcEffect);
	soundEffect.configure(CRGB::Red);
	animator.addEffect(Animator::ANIMATOR_SOUND, &soundEffect);

	animator.mode = Animator::ANIMATOR_SOUND;
}

void setup() {
	FastLED.addLeds<WS2812B, LED_DATA_PIN, GRB>(leds, NUM_LEDS);
	FastLED.setBrightness(DEF_GLOBAL_BRIGHTNESS);
	FastLED.setDither();
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();

	pinMode(BUILTIN_LED, OUTPUT);

#ifdef SERIAL_PRINT
	Serial.begin(115200);
#endif

	/* setup common effects */
	staticEffect.configure(CRGB::DeepPink);
	animator.addEffect(Animator::ANIMATOR_CONSTANT, &staticEffect);
	boltEffect.configure(0, 2, CRGB::Red, 10);
	animator.addEffect(Animator::ANIMATOR_BOLT, &boltEffect);
	strobeEffect.configure(CRGB::White);//, 3, 50, 1000);
	animator.addEffect(Animator::ANIMATOR_STROBE, &strobeEffect);
	sparkleEffect.configure(CRGB::White);
	animator.addEffect(Animator::ANIMATOR_SPARKLE, &sparkleEffect);
	
    animator.mode = Animator::ANIMATOR_STROBE;

	/* setup specifics for individual installation */
#ifdef MAITE
	setupMaite();
#else
	setupPartyraum();
#endif

#ifdef DEV_MODE
	/* turn on builtin LED */
	digitalWrite(BUILTIN_LED, HIGH);
#endif

	ota.init();
}


void loop() {
	ota.handleOta();

	EVERY_N_MILLISECONDS(REDRAW_RESOLUTION) {
		animator.redraw();
	}

	EVERY_N_MILLISECONDS(BUTTON_CHECK_RES) {
		buttons.handleButtons();
	}
}

void blur() {

	uint8_t blurAmount = dim8_raw( beatsin8(3,64, 192) );
	blur1d( leds, NUM_LEDS, blurAmount);

	uint8_t  i = beatsin8(  9, 0, NUM_LEDS);
	uint8_t  j = beatsin8( 7, 0, NUM_LEDS);
	uint8_t  k = beatsin8(  5, 0, NUM_LEDS);

	// The color of each point shifts over time, each at a different speed.
	uint16_t ms = millis();
	leds[(i+j)/2] = CHSV( ms / 29, 200, 255);
	leds[(j+k)/2] = CHSV( ms / 41, 200, 255);
	leds[(k+i)/2] = CHSV( ms / 73, 200, 255);
	leds[(k+i+j)/3] = CHSV( ms / 53, 200, 255);
	FastLED.show();
}
