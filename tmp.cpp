#if 0 /* webserver approach */
	/*return index page which is stored in serverIndex */
	server.on("/", HTTP_GET, []() {
		server.sendHeader("Connection", "close");
		server.send(200, "text/html", loginIndex);
	});
	server.on("/serverIndex", HTTP_GET, []() {
		server.sendHeader("Connection", "close");
		server.send(200, "text/html", serverIndex);
	});
	/*handling uploading firmware file */
	server.on("/update", HTTP_POST, []() {
		server.sendHeader("Connection", "close");
		server.send(200, "text/plain", (Update.hasError()) ? "FAIL" : "OK");
		ESP.restart();
	}, []() {
		HTTPUpload& upload = server.upload();
		if (upload.status == UPLOAD_FILE_START) {
			Serial.printf("Update: %s\n", upload.filename.c_str());
			if (!Update.begin(UPDATE_SIZE_UNKNOWN)) { //start with max available size
				Update.printError(Serial);
			}
		} else if (upload.status == UPLOAD_FILE_WRITE) {
			/* flashing firmware to ESP*/
			if (Update.write(upload.buf, upload.currentSize) != upload.currentSize) {
				Update.printError(Serial);
			}
		} else if (upload.status == UPLOAD_FILE_END) {
			if (Update.end(true)) { //true to set the size to the current progress
				Serial.printf("Update Success: %u\nRebooting...\n", upload.totalSize);
			} else {
				Update.printError(Serial);
			}
		}
	});
	server.begin();
#endif


void simpleLEDTest() {
#if 0
  leds[0] = CRGB::Red;
  leds[1] = CRGB::Green;
  leds[2] = CRGB::Blue;
  leds[3] = CRGB::Yellow;
  leds[4] = CRGB::White;
  FastLED.show();
  delay(500);
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[4] = CRGB::Black;
  FastLED.show();
  delay(500);
#endif
	delay(10);
	EVERY_N_MILLISECONDS(200) {
		button_state = touchRead(BUTTON_BRT_INC);
		if (button_state <= 20) {
			brightness += 16;
			FastLED.setBrightness(brightness);
			Serial.printf("Brightness: %d\n", brightness);
		}

		button_state = touchRead(BUTTON_COLOR_NEXT);
		if (button_state <= 20) {
//			FastLED.showColor(CHSV(HUE_BLUE, 255, random(256)));
			FastLED.showColor(CRGB(random(256), random(256), random(256)));
			Serial.printf("New color\n");
		}

//		Serial.printf("Touch 32: %d\n", touchRead(32));
//		Serial.printf("Touch 33: %d\n", touchRead(33));
//		Serial.printf("Touch 27: %d\n", touchRead(27));
//		Serial.printf("Touch 14: %d\n", touchRead(14));
//		Serial.printf("Touch 13: %d\n", touchRead(13));
//		Serial.printf("Touch 15: %d\n", touchRead(15));
//		Serial.printf("Touch 02: %d\n", touchRead(2));
//		Serial.printf("Touch 04: %d\n", touchRead(4));

		Serial.printf(
			"%02d %02d %02d %02d\n%02d %02d %02d %02d\n\n",
			touchRead(BUTTON_BRT_INC), touchRead(BUTTON_SPEED_INC),
			touchRead(BUTTON_COLOR_NEXT), touchRead(BUTTON_MODE_NEXT),
			touchRead(BUTTON_BRT_DEC), touchRead(BUTTON_SPEED_DEC),
			touchRead(BUTTON_COLOR_PREV), touchRead(BUTTON_MODE_PREV)
		);
	}
}

uint16_t i = 0;
int8_t speed = 2;
void runningLightTest() {
	fadeToBlackBy(leds, NUM_LEDS, 20);

//	Serial.printf("i: %d", i);
	if (speed > 0 && i >= NUM_LEDS) {
		speed *= -1;
	} else if (speed < 0 && i == 0) {
		speed *= -1;
	}

	if (speed > 0) {
//		fadeToBlackBy(leds, i, 10);
		for (int j = i; j < i + speed; j++) {
			leds[j] += CRGB::Yellow;
		}
	} else {
//		Serial.printf("i: %d, other: %d\n", i, NUM_LEDS - i);
//		fadeToBlackBy(leds + i, NUM_LEDS - i , 10);
		for (int j = i + speed; j < i; j++) {
			leds[j] += CRGB::BlueViolet;
		}
	}

	i += speed;

	FastLED.show();
	FastLED.delay(1);
}

/* blocking */
uint8_t hue;
/* 16 is quarter note */
uint8_t timeouts[] {
	32, 16, 16, 32, 16
};
int speed_scaler = 12;
uint8_t colors[] {
	HUE_RED, HUE_GREEN, HUE_RED, HUE_RED, HUE_GREEN
};
void crazyLightTest() {
	for (int j = 0; j < 1000; j++) {
		for (int k = 0; k < NUM_LEDS; k++) {
			uint8_t value = random(256);
			if (k % 2 == j % 2) {
				leds[k] = CHSV( HUE_BLUE, 255, value);
			} else {
				leds[k] = CRGB::Black;
			}
		}

//		timeout = random(200, 400);
		FastLED.delay(timeouts[j % 5] * speed_scaler);
	}
}

void startBolts() {
	for (int i = 0; i < 99; i++) {
		uint16_t start = random(NUM_LEDS);
		int8_t dir = random(2);
		int8_t speed = random(3) + 2;
		uint16_t delay = random(300);
		uint8_t color = random(256);

		if (dir) {
			speed *= -1;
		}

		bolts[i].configure(start, speed, CHSV(color, 255, 255), delay);
	}
}

bool Animator::runEffects(bool fade) {
	bool stillEffecting = false;
	if (fade) {
		fadeToBlackBy(leds, NUM_LEDS, 64);
	}

	for (int i = 0; i < idx; i++) {
		if (effects[i]->running) {
			effects[i]->calcStep();
			stillEffecting = true;
		}
	}

	FastLED.show();

	return stillEffecting;
}

void Animator::runSoundEffect() {
	for (int i = 0; i < NUM_LEDS; i++) {
		leds[i] = i % 2 ? CRGB::Green : CRGB::Blue;
	}
}
