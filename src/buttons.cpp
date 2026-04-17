#include <Arduino.h>
#include <FastLED.h>

#include "globals.h"
#include "buttons.h"

Buttons::Buttons() {
#ifdef DEV_MODE
	pinMode(DEV_BUTTON_PIN, INPUT_PULLUP);
#endif
#ifdef HAS_PD_BUTTONS
	pinMode(BUTTON_BRT_INC, INPUT_PULLUP);
	pinMode(BUTTON_MODE_NEXT, INPUT_PULLUP);
	pinMode(BUTTON_INTENSITY_INC, INPUT_PULLUP);
	pinMode(BUTTON_COLOR_NEXT, INPUT_PULLUP);
#endif
}

void Buttons::handleButtons() {
#ifdef HAS_TOUCHBUTTONS
	handleButtonsTouch();
#endif

#ifdef HAS_PD_BUTTONS
	handleButtonsPullDown();
#endif
}

#ifdef HAS_TOUCHBUTTONS
void Buttons::handleButtonsTouch() {
#ifdef SERIAL_PRINT
	Serial.printf("Touch button readings:\n");
#endif

	for (int i = 0; i < TOUCH_BUTTON_COUNT; i++) {
		uint16_t value = touchRead(buttons[i]);
#ifdef SERIAL_PRINT
	Serial.printf("%02d ", value);
#endif

		/* Reset if value is above TOUCH_BUTTON_THRESHOLD */
		if (value > TOUCH_BUTTON_THRESHOLD) {
			button_states[i] = UNPRESSED;
			continue;
		}

		/* otherwise toggle through the states */
		switch (button_states[i]) {
			case UNPRESSED:
				button_states[i] = PREPRESSED;
				break;
			case PREPRESSED:
				button_states[i] = PRESSED_0;
				activateTouch(buttons[i]);
				break;
			case PRESSED_0:
				button_states[i] = PRESSED_1;
				break;
			case PRESSED_1:
				button_states[i] = PRESSED_2;
				break;
			case PRESSED_2:
				button_states[i] = UNPRESSED;
				break;
		}
	}

#ifdef SERIAL_PRINT
	Serial.printf("\n");
#endif

#ifdef DEV_MODE
	if (digitalRead(DEV_BUTTON_PIN) == LOW) {
		if (dev_button_state == 0) {
			Serial.printf("Activate dev button\n");
			activateTouch(DEV_BUTTON_PIN);
			dev_button_state++;
		} else if (dev_button_state >= 5) {
			dev_button_state = 0;
		} else {
			dev_button_state++;
		}
	} else {
		dev_button_state = 0;
	}
#endif
}
#endif  /* HAS_TOUCHBUTTONS */

#ifdef HAS_PD_BUTTONS
void Buttons::handleButtonsPullDown() {

	for (int i = 0; i < PD_BUTTON_COUNT; i++) {
		int value = digitalRead(buttons[i]);

		/* Reset if button  is unpressed */
		if (value == HIGH) {
			button_states[i] = UNPRESSED;
			continue;
		}

		/* otherwise toggle through the states */
		switch (button_states[i]) {
			case UNPRESSED:
				button_states[i] = PREPRESSED;
				break;
			case PREPRESSED:
				button_states[i] = PRESSED_0;
				activatePullDown(buttons[i]);
				break;
			case PRESSED_0:
				button_states[i] = PRESSED_1;
				break;
			case PRESSED_1:
				button_states[i] = PRESSED_2;
				break;
			case PRESSED_2:
				button_states[i] = UNPRESSED;
				break;
		}
	}

#ifdef DEV_MODE
	if (digitalRead(DEV_BUTTON_PIN) == LOW) {
		if (dev_button_state == 0) {
			Serial.printf("Activate dev button\n");
			activatePullDown(DEV_BUTTON_PIN);
			dev_button_state++;
		} else if (dev_button_state >= 5) {
			dev_button_state = 0;
		} else {
			dev_button_state++;
		}
	} else {
		dev_button_state = 0;
	}
#endif
}
#endif  /* HAS_PD_BUTTONS */

#ifdef HAS_TOUCHBUTTONS
void Buttons::activateTouch(uint8_t button_pin) {
	/* for now, simply define action here in a switch */
#ifdef SERIAL_PRINT
	Serial.printf("%lu: Button active: %d\n", millis(), button_pin);
#endif

	switch (button_pin) {
		case BUTTON_BRT_INC:
			increaseBrightness();
			break;


		case BUTTON_BRT_DEC:
			decreaseBrightness();
			break;


		case BUTTON_INTENSITY_INC:
			animator.incIntensity();
			break;

		case BUTTON_INTENSITY_DEC:
			animator.decIntensity();
			break;

		case BUTTON_COLOR_NEXT:
			animator.nextColor();
			break;

		case BUTTON_COLOR_PREV:
			animator.prevColor();
			break;

		case BUTTON_MODE_NEXT:
			animator.nextMode();
			break;

		case BUTTON_MODE_PREV:
			animator.prevMode();
			break;

#ifdef DEV_MODE
		/* use the dev button when there is not enough tough buttons available on dev board */
		case DEV_BUTTON_PIN:
			animator.nextMode();
			break;
#endif

		default:
			break;
	}
}
#endif /* HAS_TOUCHBUTTONS */

#ifdef HAS_PD_BUTTONS
void Buttons::activatePullDown(uint8_t button_pin) {
	/* for now, simply define action here in a switch */
#ifdef SERIAL_PRINT
			Serial.printf("%lu: Button active: %d\n", millis(), button_pin);
#endif

	switch (button_pin) {
		case BUTTON_BRT_INC:
			increaseBrightness();
			break;

		case BUTTON_INTENSITY_INC:
			animator.incIntensity();
			break;

		case BUTTON_COLOR_NEXT:
			animator.nextColor();
			break;

		case BUTTON_MODE_NEXT:
			animator.nextMode();
			break;

#ifdef DEV_MODE
		/* use the dev button when there is not enough tough buttons available on dev board */
		case DEV_BUTTON_PIN:
			animator.nextMode();
			break;
#endif

		default:
			break;
	}
}
#endif  /* HAS_PD_BUTTONS */
