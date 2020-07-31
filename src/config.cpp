#include "config.h"

/************************/
/* secret configuration */
/************************/

const char* SSID = "myssid";
const char* WIFI_PSK = "mypsk";
const char* OTA_PW = "ota_pw";


/************************/
/* static configuration */
/************************/

const IPAddress OWN_IP_ADDRESS(192, 168, 2, 11);
const IPAddress SUBNET(255, 255, 255, 0);

const uint16_t OTA_PORT = 3232;

const CRGB::HTMLColorCode COLOR_PALETTE[] = {
	CRGB::DeepPink,
	CRGB::White,
	CRGB::Blue,
	CRGB::Red,
	CRGB::Green,
	CRGB::Yellow,
};

const int COLOR_PALETTE_SIZE = sizeof(COLOR_PALETTE) / sizeof(CRGB::HTMLColorCode);
