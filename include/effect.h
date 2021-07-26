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
	virtual bool calcNextFrame();

	/*! \brief Switch to the next color for this effect */
	virtual void nextColor();
	/*! \brief Switch to the previous color for this effect */
	virtual void prevColor();

	/*! \brief Increase the intensity of this effect */
	virtual void incIntensity();
	/*! \brief Decrease the intensity of this effect */
	virtual void decIntensity();

	/*! \brief Indicate whether to write this frame to the led array or not */
	bool draw = true;
};

class EffectBolt : public Effect {
public:
	/*! \brief Configure the bolt
	 *
	 * \param startled
	 * \param speed speed in 1/32 steps
	 */
	void configure(uint16_t startled, int8_t speed, CRGB color, uint16_t delay);

	bool calcNextFrame() override;
	void incIntensity() override;
	void decIntensity() override;

private:
	int idx;
	int8_t speed;
	uint16_t delay;
	CRGB color;

	int coloridx = 0;
};


/*! \brief Effect having a static, constant color on all LEDs */
class EffectStatic : public Effect {
public:
	void configure(CRGB color);

	bool calcNextFrame() override;
	void nextColor() override;
	void prevColor() override;
	void incIntensity() override;
	void decIntensity() override;

private:
	static const int SUBMODE_COUNT = 3;

	/*! \brief current colors */
	CRGB color[SUBMODE_COUNT];

	/*! \brief Keep track of the current color in the COLOR_PALETTE for the next and prev buttons */
	int coloridx = 0;

	/*! \brief Keep track of the current submode */
	int submodeidx = 0;
};


/*! \brief Effect having a static, constant color per arc in the partyraum */
class EffectArc : public Effect {
public:
	void configure(CRGB color1, CRGB color2);

	bool calcNextFrame() override;
//	void nextColor() override;
//	void prevColor() override;

private:
	uint16_t delay;

	CRGB color1;
	CRGB color2;

	/*! \brief Update LEDs in next `calcNextFrame()` when a new color was selected */
	bool switchColor = false;
};

/*! \brief Effect for sound visualization */
class EffectSound : public Effect {
public:
	void configure(CRGB color);

	bool calcNextFrame() override;

private:
	int currentLED = 0;

	CRGB color;

	/*! \brief Update LEDs in next `calcNextFrame()` when a new color was selected */
	bool is_new_color;
};

/*! \brief Effect for strobes */
class EffectStrobe : public Effect {
public:
	void configure(CRGB color);//, uint8_t count, uint8_t flashDelay, uint16_t endPause);

	bool calcNextFrame() override;

private:
	CRGB color;
    int count = 0;
    int coloridx = 0;
    // int flashDelay = 5;
    // int endPause = 100;

	/*! \brief Update LEDs in next `calcNextFrame()` when a new color was selected */
};

class EffectSparkle : public Effect {
	public:
		void configure(CRGB color, bool soft);
		bool calcNextFrame() override;

	private:
		/*! \brief Number of simultaneous sparkles */
		static const int CNT = 64;

		CRGB color;
		int count[CNT] = {0};
		int pixel[CNT] = {0};

		/*! \brief Softer version of the effect (mainly for Maite) */
		bool soft;
};

/*! \brief Effect for meteors */
class EffectMeteor : public Effect {
    public:
        void configure(CRGB color);
        bool calcNextFrame() override;

    private:
        CRGB color;
        int meteorSize = 20;
        int i = 0;
};

#endif /* end of include guard: EFFECT_H */
