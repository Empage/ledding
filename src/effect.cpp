#include "config.h"
#include "globals.h"

#include "effect.h"

void Effect::nextColor() {
}
void Effect::prevColor() {
}
void Effect::incIntensity() {
}
void Effect::decIntensity() {
}

/*********************** Effect Bolt *************************/
void EffectBolt::configure(uint16_t startled, int8_t speed, CRGB color, uint16_t delay = 0) {

	this->idx = startled;
	this->speed = speed;
	this->color = color;
	this->delay = delay;

	Serial.printf("Configure led: %d, speed: %d, delay: %d\n", idx, this->speed, this->delay);
	calcStep();
}

bool EffectBolt::calcStep() {

	if (delay) {
		fadeToBlackBy(leds, NUM_LEDS, 64);
		delay--;
		return true;
	}

	if (counter < 5) {
		counter++;
		return false;
	}

	counter = 0;

	if (speed > 0) {
		for (int j = idx; j < idx + speed && j < NUM_LEDS; j+=2) {
			leds[j] += color;
		}
	} else {
		for (int j = idx + speed; j < idx && j >= 0; j+=2) {
			leds[j] += color;
		}
	}

	idx += speed;

//	if ((speed > 0 && idx >= NUM_LEDS) || (speed < 0 && idx <= 0)) {
//		speed *= -1;
//	}
	/* send next bolt in same direction */
	if (speed > 0 && idx >= NUM_LEDS - 1) {
		idx = 0;
		if (++coloridx >= COLOR_PALETTE_SIZE) {
			coloridx = 0;
		}
		this->color = COLOR_PALETTE[coloridx];
		delay = 200;
	}

	fadeToBlackBy(leds, NUM_LEDS, 64);
	return true;
}

/*********************** Effect Static *************************/
void EffectStatic::configure(CRGB color) {
	this->color = color;

	is_new_color = true;
}

bool EffectStatic::calcStep() {
	if (!is_new_color) {
		return false;
	}

	for (int i = 0; i < NUM_LEDS; i++) {
		leds[i] = color;
	}

	is_new_color = false;
	return true;
}

void EffectStatic::nextColor() {
	if (++coloridx >= COLOR_PALETTE_SIZE) {
		coloridx = 0;
	}
	color = COLOR_PALETTE[coloridx];
	is_new_color = true;
	Serial.printf("Next color: %d\n", coloridx);
}

void EffectStatic::prevColor() {
	if (--coloridx <= 0) {
		coloridx = COLOR_PALETTE_SIZE - 1;
	}
	color = COLOR_PALETTE[coloridx];
	is_new_color = true;
	Serial.printf("Prev color: %d\n", coloridx);
}

/*********************** Effect Arc *************************/
void EffectArc::configure(CRGB color1, CRGB color2) {
	this->color1 = color1;
	this->color2 = color2;
}

#define ARC_INITIAL_PAUSE 10
#define ARC_NUMBER 50
#define ARC_PAUSE 15
bool EffectArc::calcStep() {
	if (delay) {
		delay--;
		return false;
	}


	for (int i = ARC_INITIAL_PAUSE; i < ARC_NUMBER + ARC_INITIAL_PAUSE; i++) {
		leds[i] = switchColor ? color2 : color1;
	}
	for (int i = ARC_INITIAL_PAUSE + ARC_NUMBER + ARC_PAUSE;
		i < ARC_NUMBER * 2 + ARC_INITIAL_PAUSE + ARC_PAUSE;
		i++
	) {
		leds[i] = switchColor ? color1 : color2;
	}

	switchColor = !switchColor;
	delay = random(100, 1000);
	return true;
}

/*********************** Effect Sound *************************/
void EffectSound::configure(CRGB color) {
	this->color = color;

	is_new_color = true;
}

bool EffectSound::calcStep() {
    int peak = 0;
    uint16_t peak_counter = 0;
	for (int i = 0; i < NUM_LEDS; i++) {
		if (Serial2.available()) {
			uint8_t value = Serial2.read();
			if ( value == 255) {
				currentLED = 0;
                /*  Keep this for Peak Output
                peak = Serial2.read();
                fadeToBlackBy(leds, NUM_LEDS, 192);
                uint8_t counter_peak = 0;
                while ( peak > 0 ) {
                    leds[counter_peak].setRGB(255, 0, 0);
                    counter_peak++;
                    peak--;
                    leds[counter_peak].setRGB(255, 0, 0);
                }
                */
                
				Serial2.write(84);
				return true;
			}
            leds[currentLED].setRGB(value, 0, 0);
			currentLED++;
		}
	}
	return false;
}

/*********************** Effect Strobe *************************/
void EffectStrobe::configure(CRGB color) { //, uint8_t count, uint8_t flashDelay, uint16_t endPause) {
	this->color = color;
	// this->count = count;
	// this->flashDelay = flashDelay;
	// this->endPause = endPause;
}

bool EffectStrobe::calcStep() {
    count++;
    Serial.println(count);
    if ( count >= 200 ) {
        count = 0;
		this->color = COLOR_PALETTE[random(COLOR_PALETTE_SIZE)];
        return false;
    }
    if ( count >= 100 ) {
		fill_solid(leds, NUM_LEDS, CRGB::Black);
        return true;
    }
    if ( count % 6 >= 3) {
		fill_solid(leds, NUM_LEDS, color);
        return true;
    }
    if ( count % 6 <= 3 ) {
		fill_solid(leds, NUM_LEDS, CRGB::Black);
        return true;
    }
    return false;
}

/*********************** Effect Sparkle *************************/
void EffectSparkle::configure(CRGB color) {
    this->color = color;
}

bool EffectSparkle::calcStep() {
    if ( count == 0 ) {
        pixel = random(NUM_LEDS);
        leds[pixel] = color;
        count++;
        return true;
    }
    if ( count >= 1 ) {
        leds[pixel] = CRGB::Black;
        count = 0;
        return true;
    }
}
