#include "config.h"

/************************/
/* secret configuration */
/************************/

/* WLAN_SSID passed in via platform.ini build_flags from set-environment */
const char* SSID = WLAN_SSID;
/* WLAN_PSK passed in via platform.ini build_flags from set-environment */
const char* WIFI_PSK = WLAN_PSK;

const char* OTA_PW = "secretpw0";


/************************/
/* static configuration */
/************************/

/* ESP_IP passed in via platform.ini build_flags from set-environment */
const IPAddress OWN_IP_ADDRESS(ESP_IP);
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
