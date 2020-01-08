#ifndef CONFIG_H
#define CONFIG_H

/* "dynamic" defines */
#define SERIAL_PRINT


/* "static" configuration */

/*! \brief Total number of LEDs */
#define NUM_LEDS 150

/*! \brief GPIO on which the data signal of the WS2812B is connected */
#define LED_DATA_PIN 2
/*! \brief GPIO on which the button (which pulls to GND when pressed) is connected */
#define BUTTON_PIN 18
/*! \brief Resolution of the state machine (i.e. the delay each round) in ms */
#define STATE_MACHINE_RES 10


/* tmp */
#define MIC_PIN 13
#define DC_OFFSET 0
#define SQUELCH 0


#endif /* end of include guard: CONFIG_H */
