#include "animator.h"

#include "config.h"
#include "globals.h"

Animator::Animator() {
}

bool Animator::runStateMachine() {
	bool stillEffecting = false;
	fadeToBlackBy(leds, NUM_LEDS, 30);

	for (int i = 0; i < idx; i++) {
		if (effects[i]->running) {
//			Serial.printf("CalcStep on %d\n", i);
			effects[i]->calcStep();
			stillEffecting = true;
		}
	}

	FastLED.show();
	FastLED.delay(STATE_MACHINE_RES);

	return stillEffecting;
}

bool Animator::addEffect(EffectBolt* effect) {
	if (idx >= 100) {
		return false;
	}

	Serial.printf("Add effect %d\n", idx);
	effects[idx++] = effect;
	return true;
}
