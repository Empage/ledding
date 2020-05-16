/* Ledding - a fancy LED project */

#include <Arduino.h>
#include <FastLED.h>

#include "config.h"
#include "animator.h"

// Define the array of leds
CRGB leds[NUM_LEDS];

Animator animator;
EffectBolt bolts[100];

uint8_t brightness = DEF_GLOBAL_BRIGHTNESS;
int button_state = 0;

void simpleLEDTest();
void runningLightTest();
void crazyLightTest();
void startBolts();

void setup() {
	FastLED.addLeds<WS2812B, LED_DATA_PIN, GRB>(leds, NUM_LEDS);
	FastLED.setBrightness(brightness);
	FastLED.setDither();

	pinMode(BUTTON_PIN, INPUT_PULLUP);

#ifdef SERIAL_PRINT
	Serial.begin(115200);

	Serial.printf("Hello World!\n");
#endif

	for (int i = 0; i < 100; i++) {
		animator.addEffect(bolts + i);
	}

	startBolts();
}


void loop() {
//	runningLightTest();
	simpleLEDTest();
//	crazyLightTest();


#if 0
	animator.runStateMachine();

	EVERY_N_MILLISECONDS(200) {
		button_state = digitalRead(BUTTON_PIN);
		if (button_state == LOW) {
//			brightness += 16;
//			FastLED.setBrightness(brightness);
//			Serial.printf("Brightness: %d\n", brightness);

			uint16_t start = random(NUM_LEDS);
			int8_t dir = random(2);
			int8_t speed = random(3) + 2;
			uint8_t color = random(256);

			if ((dir && start > 10) || start > NUM_LEDS - 10) {
				speed *= -1;
			}

			bolts[99].configure(start, speed, CHSV(color, 255, 255), 0);
		}
	}
#endif
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
	EVERY_N_MILLISECONDS(200) {
		button_state = digitalRead(BUTTON_PIN);
		if (button_state == LOW) {
			brightness += 16;
			FastLED.setBrightness(brightness);
			Serial.printf("Brightness: %d\n", brightness);
		}
	}
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

void startBolts() {
	for (int i = 0; i < 99; i++) {
		uint16_t start = random(NUM_LEDS);
		int8_t dir = random(2);
		int8_t speed = random(3) + 2;
		uint16_t delay = random(300);
		uint8_t color = random(256);

		if (dir) {
			speed *= -1;
		}

		bolts[i].configure(start, speed, CHSV(color, 255, 255), delay);
	}
}
