#include "globals.h"

CRGB leds[NUM_LEDS];
Animator animator;
Buttons buttons;
Ota ota;
EffectStatic staticEffect;
EffectBolt boltEffect;
EffectArc arcEffect;
EffectSound soundEffect;
EffectStrobe strobeEffect;
EffectSparkle sparkleEffect;
EffectMeteor meteorEffect;

void increaseBrightness() {
	uint8_t brightness = FastLED.getBrightness();
	if (brightness < 16) {
		brightness += 1;
	} else if (brightness < 32) {
		brightness += 2;
	} else if (brightness < 255 - 16) {
		brightness += 16;
	} else {
		brightness = 255;
	}

	FastLED.setBrightness(brightness);
	FastLED.show();
#ifdef SERIAL_PRINT
	Serial.printf("New brightness: %d\n", brightness);
#endif
}

void decreaseBrightness() {
	uint8_t brightness = FastLED.getBrightness();
	if (brightness >= 32) {
		brightness -= 16;
	} else if (brightness >= 16) {
		brightness -= 2;
	} else if (brightness >= 1) {
		brightness -= 1;
	}

	FastLED.setBrightness(brightness);
	FastLED.show();
#ifdef SERIAL_PRINT
	Serial.printf("New brightness: %d\n", brightness);
#endif
}

int modulo(int a, int b) {
  int m = a % b;
  if (m < 0) {
    m = (b < 0) ? m - b : m + b;
  }
  return m;
}

/*! \brief Linear brightness increase for the eye (with 32 steps) */
uint8_t LIN_EYE[] = {
	  0,   1,   2,   3,   4,   5,   7,   9,
	 12,  15,  18,  22,  27,  32,  38,  44,
	 51,  58,  67,  76,  86,  96, 108, 120,
	134, 148, 163, 180, 197, 216, 235, 255
};
