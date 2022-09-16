#include "connect_to_camera.h"	

int connect_to_camera()
{
	std::cout << "Find Mech-Eye devices..." << std::endl;
	std::vector<mmind::api::MechEyeDeviceInfo> deviceInfoList =
		mmind::api::MechEyeDevice::enumerateMechEyeDeviceList();

	if (deviceInfoList.empty()) {
		std::cout << "No Mech-Eye device found." << std::endl;
		return -1;
	}

	for (int i = 0; i < deviceInfoList.size(); i++) {
		std::cout << "Mech-Eye device index : " << i << std::endl;
		printDeviceInfo(deviceInfoList[i]);
	}

	std::cout << "Please enter the device index you want to connect: ";
	unsigned inputIndex;

	while (1) {
		std::string str;
		std::cin >> str;
		if (isNumber(str) && atoi(str.c_str()) < deviceInfoList.size()) {
			inputIndex = atoi(str.c_str());
			break;
		}
		std::cout << "Input invalid! Please enter the device index you want to connect: ";
	}

	mmind::api::ErrorStatus status;
	mmind::api::MechEyeDevice device;
	status = device.connect(deviceInfoList[inputIndex]);

	if (!status.isOK()) {
		showError(status);
		return -1;
	}

	std::cout << "Connected to the Mech-Eye device successfully." << std::endl;

	device.disconnect();
	std::cout << "Disconnected from the Mech-Eye device successfully." << std::endl;
	return 0;
}