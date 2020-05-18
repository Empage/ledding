#ifndef EFFECT_H
#define EFFECT_H

#include <FastLED.h>

class Effect {
public:
	virtual bool calcStep();

	bool running = false;
};

class EffectBolt : public Effect {
public:

	/*! \brief Create a bolt
	 *
	 * \param speed Speed and direction of the bolt (num of leds per round)
	 */
//	EffectBolt();

	void configure(uint16_t startled, int8_t speed, CRGB color, uint16_t delay);

	/*! \brief Calculate next step of the effect
	 *
	 * \return True if effect is done, false if function needs to be called again
	 */
	bool calcStep();

private:
	int idx;
	int8_t speed;
	uint16_t delay;
	CRGB color;
};


class EffectStatic : public Effect {
public:
	void configure(CRGB color);

	/*! \brief Calculate next step of the effect
	 *
	 * \return True if effect is done, false if function needs to be called again
	 */
	bool calcStep();

	void nextColor();

	void prevColor();

private:
	CRGB color;

	int coloridx = 0;

	bool is_new_color;
};

#endif /* end of include guard: EFFECT_H */
