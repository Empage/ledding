#ifndef EFFECT_H
#define EFFECT_H

#include <FastLED.h>

class EffectBolt {
public:

	/*! \brief Create a bolt
	 *
	 * \param speed Speed and direction of the bolt (num of leds per round)
	 */
	EffectBolt();

	void configure(uint16_t startled, int8_t speed, CRGB color, uint16_t delay);

	/*! \brief Calculate next step of the effect
	 *
	 * \return True if effect is done, false if function needs to be called again
	 */
	bool calcStep();

	bool running;

private:
	int idx;
	int8_t speed;
	uint16_t delay;
	CRGB color;
};

#endif /* end of include guard: EFFECT_H */
