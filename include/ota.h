#ifndef OTA_H_MOXGSAH3
#define OTA_H_MOXGSAH3

/*! \brief Handle WiFi connection and over-the-air firmware update */
class Ota {
public:
	bool init();

	void handleOta();

private:
	bool connected = false;
};

#endif /* end of include guard: OTA_H_MOXGSAH3 */
