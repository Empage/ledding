#include "config.h"

/************************/
/* secret configuration */
/************************/

const char* SSID = "musicstation";
const char* WIFI_PSK = "testtesttest";
const char* OTA_PW = "secretpw0";


/************************/
/* static configuration */
/************************/

#ifdef MAITE
const IPAddress OWN_IP_ADDRESS(192, 168, 2, 12);
#else /* partyraum */
const IPAddress OWN_IP_ADDRESS(192, 168, 5, 11);
#endif
const IPAddress SUBNET(255, 255, 255, 0);

const uint16_t OTA_PORT = 3232;

const CRGB::HTMLColorCode COLOR_PALETTE[] = {
	CRGB::DeepPink,
	CRGB::Blue,
	CRGB::Red,
	CRGB::Green,
	CRGB::Yellow,
	CRGB::White,
};

const int COLOR_PALETTE_SIZE = sizeof(COLOR_PALETTE) / sizeof(CRGB::HTMLColorCode);
