#include "config.h"
#include "globals.h"

#include "effect.h"

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

	if (delay) {
		delay--;
		return false;
	}

	if (speed > 0) {
		for (int j = idx; j < idx + speed && j < NUM_LEDS; j++) {
			leds[j] += color;
		}
	} else {
		for (int j = idx + speed; j < idx && j >= 0; j++) {
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

void EffectStatic::configure(CRGB color) {
	this->color = color;

	running = true;
	is_new_color = true;
}

bool EffectStatic::calcStep() {
	for (int i = 0; i < NUM_LEDS; i++) {
		leds[i] = color;
	}

	if (is_new_color) {
		is_new_color = false;
		return true;
	}

	return false;
}

void EffectStatic::nextColor() {
	if (++coloridx >= COLOR_PALETTE_SIZE) {
		coloridx = 0;
	}
	color = COLOR_PALETTE[coloridx];
	is_new_color = true;
	Serial.printf("Next color: %d\n", coloridx);
}

void EffectStatic::prevColor() {
	if (--coloridx <= 0) {
		coloridx = COLOR_PALETTE_SIZE - 1;
	}
	color = COLOR_PALETTE[coloridx];
	is_new_color = true;
	Serial.printf("Prev color: %d\n", coloridx);
}
