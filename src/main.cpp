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
void crazyLightTest();

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
//	crazyLightTest();

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
int8_t speed = 2;
void runningLightTest() {
	fadeToBlackBy(leds, NUM_LEDS, 20);

	Serial.printf("i: %d", i);
	if (speed > 0 && i >= NUM_LEDS) {
		speed *= -1;
	} else if (speed < 0 && i == 0) {
		speed *= -1;
	}

	if (speed > 0) {
//		fadeToBlackBy(leds, i, 10);
		for (int j = i; j < i + speed; j++) {
			leds[j] += CRGB::Red;
		}
	} else {
//		Serial.printf("i: %d, other: %d\n", i, NUM_LEDS - i);
//		fadeToBlackBy(leds + i, NUM_LEDS - i , 10);
		for (int j = i + speed; j < i; j++) {
			leds[j] += CRGB::Blue;
		}
	}

	i += speed;

	FastLED.show();
	FastLED.delay(1);
}

/* blocking */
uint8_t hue;
/* 16 is quarter note */
uint8_t timeouts[] {
	32, 16, 16, 32, 16
};
int speed_scaler = 12;
uint8_t colors[] {
	HUE_RED, HUE_GREEN, HUE_RED, HUE_RED, HUE_GREEN
};
void crazyLightTest() {
	for (int j = 0; j < 1000; j++) {
		for (int k = 0; k < NUM_LEDS; k++) {
			uint8_t value = random(256);
			if (k % 2 == j % 2) {
				leds[k] = CHSV( HUE_BLUE, 255, value);
			} else {
				leds[k] = CRGB::Black;
			}
		}

//		timeout = random(200, 400);
		FastLED.delay(timeouts[j % 5] * speed_scaler);
	}
}

