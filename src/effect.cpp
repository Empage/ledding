#include "config.h"
#include "globals.h"

#include "effect.h"

EffectBolt::EffectBolt() :
	running(false)
{
}

void EffectBolt::configure(uint16_t startled, int8_t speed, CRGB color, uint16_t delay = 0) {
	this->idx = startled;
	this->speed = speed;
	this->color = color;
	this->delay = delay;

	running = true;

	Serial.printf("Configure led: %d, speed: %d, delay: %d\n", idx, this->speed, this->delay);
	calcStep();
}

bool EffectBolt::calcStep() {
//	Serial.printf("idx: %d\n", this->idx);

	if (delay) {
		delay--;
		return false;
	}

	if (speed > 0) {
		for (int j = idx; j < idx + speed && j < NUM_LEDS; j++) {
//			Serial.printf("HERE1: j: %d\n", j);
			leds[j] += color;
		}
	} else {
		for (int j = idx + speed; j < idx && j >= 0; j++) {
//			Serial.printf("HERE2: j: %d\n", j);
			leds[j] += color;
		}
	}

	idx += speed;

	if ((speed > 0 && idx >= NUM_LEDS) || (speed < 0 && idx <= 0)) {
		/* bolt reached end of strip, effect done */
		Serial.printf("Effect done!\n");
		running = false;
		return true;
	}

	return false;
}
