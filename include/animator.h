#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "effect.h"

class Animator {
public:
	explicit Animator();

	bool runStateMachine();

	bool addEffect(EffectBolt* effect);

private:
	EffectBolt* effects[100];
	uint16_t idx = 0;
};

#endif /* end of include guard: ANIMATOR_H */
