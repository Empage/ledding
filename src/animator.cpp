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


void Animator::runSoundEffect() {
	for (int i = 0; i < NUM_LEDS; i++) {
		leds[i] = i % 2 ? CRGB::Green : CRGB::Blue;
	}
}
