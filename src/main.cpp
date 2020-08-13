/* Ledding - a fancy LED project */

#include <Arduino.h>
#include <FastLED.h>
#include <config.h>
#include <ArduinoJson.h>
#include <StreamUtils.h>
#include <sstream>

#define RXD2 17
#define TXD2 16

CRGB leds[NUM_LEDS];
uint8_t brightness = 150;

void runningLightTest();
void musicReactive();
void blur();

void setup() { 
	FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
	FastLED.setBrightness(brightness);
    Serial.begin(115200);
    Serial.printf("Hello World!\n");
    // Serial2.begin(115200, SERIAL_8N1, RXD2); //, TXD2);
    Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
    Serial.println("Serial Rxd is on pin: "+String(RXD2));
    Serial.println("Serial Txd is on pin: "+String(TXD2));
    fill_solid( leds, NUM_LEDS, CRGB::Black );
    FastLED.show();
      
}

void loop() {
    // EVERY_N_MILLISECONDS(10) {
        // blur();
    musicReactive();
		// runningLightTest();
    // }
}


int i = 0;
void musicReactive() {
    while (Serial2.available()) {
        uint8_t value = Serial2.read();
        Serial.println(value);
        if ( value == 255 || i >= NUM_LEDS) {
            i = 0;
            Serial2.write(84);
            FastLED.show();
            delayMicroseconds(20);
            continue;
        } else {
            i++;
        }
        leds[i].setRGB(value, 0, 0);
        // leds[i] = CHSV(random8(), 255, value);
    }
}


void runningLightTest() {
    for ( i = 0; i < NUM_LEDS; i++ ) {
        if ( i % 10 == 0 ) {
            leds[i] = CRGB::Red;
        } else {
            leds[i] = CRGB::Green;
        }
    }
	FastLED.show();
	delayMicroseconds(100);
}

void blur() {

    uint8_t blurAmount = dim8_raw( beatsin8(3,64, 192) );
    blur1d( leds, NUM_LEDS, blurAmount);
    
    uint8_t  i = beatsin8(  9, 0, NUM_LEDS);
    uint8_t  j = beatsin8( 7, 0, NUM_LEDS);
    uint8_t  k = beatsin8(  5, 0, NUM_LEDS);
    
    // The color of each point shifts over time, each at a different speed.
    uint16_t ms = millis();  
    leds[(i+j)/2] = CHSV( ms / 29, 200, 255);
    leds[(j+k)/2] = CHSV( ms / 41, 200, 255);
    leds[(k+i)/2] = CHSV( ms / 73, 200, 255);
    leds[(k+i+j)/3] = CHSV( ms / 53, 200, 255);
    FastLED.show();
  
} // loop()
