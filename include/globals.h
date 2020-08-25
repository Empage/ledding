#ifndef GLOBALS_H
#define GLOBALS_H

#include <FastLED.h>

#include "config.h"

#include "animator.h"
#include "buttons.h"
#include "ota.h"
#include "effect.h"

/*! \brief FastLED array for the current stripe values */
extern CRGB leds[NUM_LEDS];

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

void increaseBrightness();
void decreaseBrightness();


#endif /* end of include guard: GLOBALS_H */
