#include <WiFi.h>
#include <ArduinoOTA.h>

#include "config.h"
#include "ota.h"

bool Ota::init() {
	/* Configure WiFi for static IP */
	if (!WiFi.config(OWN_IP_ADDRESS, INADDR_NONE, SUBNET)) {
#ifdef SERIAL_PRINT
		Serial.println("Failed to configure own IP address");
#endif
		return false;
	}

	/* Initiate WiFi connection*/
	WiFi.begin(SSID, WIFI_PSK);
#ifdef SERIAL_PRINT
	Serial.printf("Initiating Wifi connection to %s", SSID);
#endif

	/* Configure OTA */
	ArduinoOTA.setPort(OTA_PORT);
	ArduinoOTA.setPassword(OTA_PW);

	ArduinoOTA.onStart([]() {
		String type;
		if (ArduinoOTA.getCommand() == U_FLASH) {
			type = "sketch";
		} else { /* U_SPIFFS */
			type = "filesystem";
		}

		// NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
#ifdef SERIAL_PRINT
		Serial.println("OTA: Start updating " + type);
#endif
	}).onEnd([]() {
#ifdef SERIAL_PRINT
		Serial.println("\nOTA: End");
#endif
	}).onProgress([](unsigned int progress, unsigned int total) {
#ifdef SERIAL_PRINT
		Serial.printf("OTA: Progress: %u%%\r", (progress / (total / 100)));
#endif
	}).onError([](ota_error_t error) {
#ifdef SERIAL_PRINT
		Serial.printf("OTA: Error[%u]: ", error);
		if (error == OTA_AUTH_ERROR) Serial.println("OTA: Auth Failed");
		else if (error == OTA_BEGIN_ERROR) Serial.println("OTA: Begin Failed");
		else if (error == OTA_CONNECT_ERROR) Serial.println("OTA: Connect Failed");
		else if (error == OTA_RECEIVE_ERROR) Serial.println("OTA: Receive Failed");
		else if (error == OTA_END_ERROR) Serial.println("OTA: End Failed");
#endif
	});

	ArduinoOTA.begin();

#ifdef SERIAL_PRINT
	Serial.println("OTA: Ready for updates");
#endif
	return true;
}

void Ota::handleOta() {
	if (!connected) {
		if (WiFi.status() != WL_CONNECTED) {
			return;
		}
		connected = true;
#ifdef SERIAL_PRINT
		Serial.printf("Connected to %s: ", SSID);
		Serial.println(WiFi.localIP());
#endif

#ifdef CONF_PARTYRAUM
        /* indicate WiFi connection */
        digitalWrite(STATUS_LED_1, HIGH);
#endif
	}

	ArduinoOTA.handle();
}
