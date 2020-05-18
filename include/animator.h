#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "effect.h"

/*! \brief This class handles the animations on the LED stripes
 *
 * It is responsible for the maintaining the currently active mode and forwards
 * button pressed events to the active effect
 */
class Animator {
public:
	enum AnimatorMode {
		ANIMATOR_CONSTANT,
		ANIMATOR_FADE,
		ANIMATOR_SOUND,
	};
	static const int ANIMATOR_MODE_SIZE = 3;

	explicit Animator();

	void runStateMachine();

	void addEffect(AnimatorMode mode, Effect* effect);

	/* currently active mode */
	AnimatorMode mode = ANIMATOR_CONSTANT;

private:
	Effect* effects[ANIMATOR_MODE_SIZE];
	uint16_t idx = 0;

	bool runEffects(bool fade);

	void runSoundEffect();
};

#endif /* end of include guard: ANIMATOR_H */
