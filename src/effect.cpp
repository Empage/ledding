#include "config.h"
#include "globals.h"

#include "effect.h"

void Effect::nextColor() {
}
void Effect::prevColor() {
}
void Effect::incIntensity() {
}
void Effect::decIntensity() {
}

/*********************** Effect Bolt *************************/
void EffectBolt::configure(uint16_t startled, int8_t speed, CRGB color, uint16_t delay = 0) {

	this->idx = startled;
	this->speed = speed;
	this->color = color;
	this->delay = delay;

	Serial.printf("Configure led: %d, speed: %d, delay: %d\n", idx, this->speed, this->delay);
	calcStep();
}

bool EffectBolt::calcStep() {

	if (delay) {
		fadeToBlackBy(leds, NUM_LEDS, 64);
		delay--;
		return true;
	}

	if (counter < 5) {
		counter++;
		return false;
	}

	counter = 0;

	if (speed > 0) {
		for (int j = idx; j < idx + speed && j < NUM_LEDS; j+=2) {
			leds[j] += color;
		}
	} else {
		for (int j = idx + speed; j < idx && j >= 0; j+=2) {
			leds[j] += color;
		}
	}

	idx += speed;

//	if ((speed > 0 && idx >= NUM_LEDS) || (speed < 0 && idx <= 0)) {
//		speed *= -1;
//	}
	/* send next bolt in same direction */
	if (speed > 0 && idx >= NUM_LEDS - 1) {
		idx = 0;
		if (++coloridx >= COLOR_PALETTE_SIZE) {
			coloridx = 0;
		}
		this->color = COLOR_PALETTE[coloridx];
		delay = 200;
	}

	fadeToBlackBy(leds, NUM_LEDS, 64);
	return true;
}

/*********************** Effect Static *************************/
void EffectStatic::configure(CRGB color) {
	this->color = color;

	is_new_color = true;
}

bool EffectStatic::calcStep() {
	if (!is_new_color) {
		return false;
	}

	for (int i = 0; i < NUM_LEDS; i++) {
		leds[i] = color;
	}

	is_new_color = false;
	return true;
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

/*********************** Effect Arc *************************/
void EffectArc::configure(CRGB color1, CRGB color2) {
	this->color1 = color1;
	this->color2 = color2;
}

#define ARC_INITIAL_PAUSE 10
#define ARC_NUMBER 50
#define ARC_PAUSE 15
bool EffectArc::calcStep() {
	if (delay) {
		delay--;
		return false;
	}


	for (int i = ARC_INITIAL_PAUSE; i < ARC_NUMBER + ARC_INITIAL_PAUSE; i++) {
		leds[i] = switchColor ? color2 : color1;
	}
	for (int i = ARC_INITIAL_PAUSE + ARC_NUMBER + ARC_PAUSE;
		i < ARC_NUMBER * 2 + ARC_INITIAL_PAUSE + ARC_PAUSE;
		i++
	) {
		leds[i] = switchColor ? color1 : color2;
	}

	switchColor = !switchColor;
	delay = random(100, 1000);
	return true;
}

/*********************** Effect Sound *************************/
void EffectSound::configure(CRGB color) {
	this->color = color;

	is_new_color = true;
}

bool EffectSound::calcStep() {
	for (int i = 0; i < NUM_LEDS; i++) {
		if (Serial2.available()) {
			uint8_t value = Serial2.read();
			if ( value == 255) {
				currentLED = 0;
				Serial2.write(84);
				return true;
			}
			leds[currentLED].setRGB(value, 0, 0);
			currentLED++;
		}
	}
	return false;
}
