/* Ledding - a fancy LED project */

#include <Arduino.h>
#include <FastLED.h>

#include "config.h"

// Define the array of leds
CRGB leds[NUM_LEDS];

uint8_t brightness = 150;
int button_state = 0;

void simpleLEDTest();
void runningLightTest();

void setup() {
	FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
	FastLED.setBrightness(brightness);

	pinMode(BUTTON_PIN, INPUT_PULLUP);

#ifdef SERIAL_PRINT
	Serial.begin(115200);

	Serial.printf("Hello World!\n");
#endif
}

void loop() {
	runningLightTest();
//	simpleLEDTest();

	EVERY_N_MILLISECONDS(200) {
		button_state = digitalRead(BUTTON_PIN);
		if (button_state == LOW) {
			brightness += 16;
			FastLED.setBrightness(brightness);
			Serial.printf("Brightness: %d\n", brightness);
		}
	}
}

void simpleLEDTest() {
#if 0
  leds[0] = CRGB::Red;
  leds[1] = CRGB::Green;
  leds[2] = CRGB::Blue;
  leds[3] = CRGB::Yellow;
  leds[4] = CRGB::White;
  FastLED.show();
  delay(500);
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[4] = CRGB::Black;
  FastLED.show();
  delay(500);
#endif
  FastLED.showColor(CRGB::White);
  delay(10);

}

uint16_t i = 0;
int8_t speed = 1;
void runningLightTest() {
	fadeToBlackBy(leds, NUM_LEDS, 10);
	if (speed > 0) {
//		fadeToBlackBy(leds, i, 10);
		leds[i] += CRGB::Red;
	} else {
//		Serial.printf("i: %d, other: %d\n", i, NUM_LEDS - i);
//		fadeToBlackBy(leds + i, NUM_LEDS - i , 10);
		leds[i] += CRGB::Blue;
	}
	i += speed;
	if (i >= 148) {
		speed = -1;
	} else if (i == 1 && speed < 0) {
		speed = 1;
	}

	FastLED.show();
	delayMicroseconds(100);
}

void energyTest() {
}
