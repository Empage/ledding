#ifndef EFFECT_H
#define EFFECT_H

#include <FastLED.h>

/*! \brief General Effect class of switch concreate effect realizations can be derived */
class Effect {
public:
	/*! \brief Calculate the next LED frame for this effect
	 *
	 * \return true if frame changed (so should be redrawn), false if nothing changed
	 */
	virtual bool calcStep();

	/*! \brief Switch to the next color for this effect */
	virtual void nextColor();
	/*! \brief Switch to the previous color for this effect */
	virtual void prevColor();

	/*! \brief Increase the intensity of this effect */
	virtual void incIntensity();
	/*! \brief Decrease the intensity of this effect */
	virtual void decIntensity();
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

	int counter = 0;
	int coloridx = 0;
};


/*! \brief Effect having a static, constant color on all LEDs */
class EffectStatic : public Effect {
public:
	void configure(CRGB color);

	bool calcStep() override;
	void nextColor() override;
	void prevColor() override;

private:
	/*! \brief current color */
	CRGB color;

	/*! \brief Keep track of the current color in the COLOR_PALETTE for the next and prev buttons */
	int coloridx = 0;

	/*! \brief Update LEDs in next `calcStep()` when a new color was selected */
	bool is_new_color;
};


/*! \brief Effect having a static, constant color per arc in the partyraum */
class EffectArc : public Effect {
public:
	void configure(CRGB color1, CRGB color2);

	bool calcStep() override;
//	void nextColor() override;
//	void prevColor() override;

private:
	uint16_t delay;

	CRGB color1;
	CRGB color2;

	/*! \brief Update LEDs in next `calcStep()` when a new color was selected */
	bool switchColor = false;
};

/*! \brief Effect for sound visualization */
class EffectSound : public Effect {
public:
	void configure(CRGB color);

	bool calcStep() override;

private:
	int currentLED = 0;

	CRGB color;

	/*! \brief Update LEDs in next `calcStep()` when a new color was selected */
	bool is_new_color;
};

#endif /* end of include guard: EFFECT_H */