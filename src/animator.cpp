#include "animator.h"

#include "config.h"
#include "globals.h"

Animator::Animator() {
}

void Animator::runStateMachine() {
	if (effects[mode]->calcStep()) {
		FastLED.show();
	}
}

void Animator::addEffect(AnimatorMode mode, Effect* effect) {
	effects[mode] = effect;
}

void Animator::nextMode() {
	//TODO [MPH] debug it
	/* iterate through all modes beginning with the next one to look for a configured mode */
	for (int i = mode; i < ANIMATOR_MODE_SIZE + mode; i++) {
		if (effects[(i + 1) % ANIMATOR_MODE_SIZE] == nullptr) {
			continue;
		}

		mode = static_cast<AnimatorMode>((i + 1) % ANIMATOR_MODE_SIZE);
		return;
	}

#ifdef SERIAL_PRINT
	Serial.println("No other mode configured");
#endif
}

void Animator::prevMode() {
	//TODO [MPH] still wrong
	/* iterate through all modes beginning with the previous one to look for a configured mode */
	for (int i = mode; i < ANIMATOR_MODE_SIZE + mode; i++) {
		if (effects[(i + 1) % ANIMATOR_MODE_SIZE] == nullptr) {
			continue;
		}

		mode = static_cast<AnimatorMode>((i + 1) % ANIMATOR_MODE_SIZE);
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
