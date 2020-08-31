#!/bin/bash

# use the partyraum environment as default
if [ "$1" = "build_flags" ]; then
	# we need to pass as strings, that is why we need the `\\\"` to actually have the `"` in the C source code
	echo \
		-D${LEDDING_CONFIGURATION:-CONF_PARTYRAUM} \
		-DWLAN_SSID="\\\"${LEDDING_WLAN_SSID:-musicstation}\\\"" \
		-DWLAN_PSK="\\\"${LEDDING_WLAN_PSK:-testtesttest}\\\"" \
		-DESP_IP="${LEDDING_ESP_IP:-192,168,5,11}"

elif [ "$1" = "ota_port" ]; then
	echo ${LEDDING_OTA_PORT:-192.168.5.11}

elif [ "$1" = "cable_port" ]; then
	echo ${LEDDING_CABLE_PORT:-/dev/ttyUSB0}

else
	echo "INVALID"
	exit 1
fi

