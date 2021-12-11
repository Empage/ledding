#ifndef GLOBALS_H
#define GLOBALS_H

#include <FastLED.h>

#include "config.h"

#include "animator.h"
#include "buttons.h"
#include "ota.h"
#include "effect.h"

/*! \brief FastLED array for the current stripe values */
extern CRGB leds[NUM_LEDS * 2];

extern Animator animator;
extern Buttons buttons;
extern Ota ota;
extern EffectStatic staticEffect;
extern EffectBolt boltEffect;
extern EffectArc arcEffect;
extern EffectSound soundEffect;
extern EffectStrobe strobeEffect;
extern EffectSparkle sparkleEffect;
extern EffectMeteor meteorEffect;

/*! \brief Increase global LED brightness */
void increaseBrightness();

/*! \brief Decrease global LED brightness */
void decreaseBrightness();

/*! \brief Calculate the modulo of `a mod b`
 *
 * This is different from the remainder `a % b` if the divisor `a` is negative:
 * `-1 % 5 = -1`
 * `-1 mod 5 = 4`
 *
 * This function is helpful for array access in the functions which decrease the array index
 */
int modulo(int a, int b);

extern uint8_t LIN_EYE[];


#endif /* end of include guard: GLOBALS_H */
