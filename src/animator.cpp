#include "animator.h"

#include "config.h"
#include "globals.h"

Animator::Animator() {
}

void Animator::redraw() {
	if (effects[mode]->calcNextFrame()) {
		FastLED.show();
	}
}

void Animator::addEffect(AnimatorMode mode, Effect* effect) {
	effects[mode] = effect;
}

void Animator::nextMode() {
	/* iterate through all modes beginning with the next one to look for a configured mode */
	for (int i = 1; i < ANIMATOR_MODE_SIZE; i++) {
		if (effects[(mode + i) % ANIMATOR_MODE_SIZE] == nullptr) {
			continue;
		}

		mode = static_cast<AnimatorMode>((mode + i) % ANIMATOR_MODE_SIZE);
		/* tell the new effect to redraw */
		effects[mode]->draw = true;
		return;
	}

#ifdef SERIAL_PRINT
	Serial.println("No other mode configured");
#endif
}

void Animator::prevMode() {
	int remainder = 0;
	int new_index = 0;
	/* iterate through all modes beginning with the previous one to look for a configured mode */
	for (int i = 1; i < ANIMATOR_MODE_SIZE; i++) {
		/* negative wrap-around needs special care because e.g. `-1 % 5` is not `4` but rather `-1`,
		 * that is apparently the difference between remainder and modulo */
		remainder = ((int)mode - i) % ANIMATOR_MODE_SIZE;
		if (remainder < 0) {
			new_index = remainder + ANIMATOR_MODE_SIZE;
		} else {
			new_index = remainder;
		}
		if (effects[new_index] == nullptr) {
			continue;
		}

		mode = static_cast<AnimatorMode>(new_index);
		/* tell the new effect to redraw */
		effects[mode]->draw = true;
		return;
	}

#ifdef SERIAL_PRINT
	Serial.println("No other mode configured");
#endif
}

void Animator::nextColor() {
	effects[mode]->nextColor();
}

void Animator::prevColor() {
	effects[mode]->prevColor();
}

void Animator::incIntensity() {
	effects[mode]->incIntensity();
}

void Animator::decIntensity() {
	effects[mode]->decIntensity();
}
