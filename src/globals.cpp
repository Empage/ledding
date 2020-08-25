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
