// mechmind_connect.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
// c++
#include <iostream>
#include <stdlib.h>
#include <fstream>
// mmind
#include <MechEyeApi.h>
#include <SampleUtil.h>

int main(int argc, char*argv[])
{
	std::cout << "Find Mech-Eye device..." << std::endl;
	std::vector<mmind::api::MechEyeDeviceInfo> deviceInfoList =
		mmind::api::MechEyeDevice::enumerateMechEyeDeviceList();

	if (deviceInfoList.empty()) {
		std::cout << "No Mech-Eye device found." << std::endl;
		exit(1);
	}

	printDeviceInfo(deviceInfoList[0]);

	std::fstream out("device_info.txt", std::ios::out);
	if (out.fail()) {
		std::cout << "fail to write device_info.txt." << std::endl;
		exit(2);
	}
	out
		<< deviceInfoList[0].model << std::endl
		<< deviceInfoList[0].id << std::endl
		<< deviceInfoList[0].hardwareVersion << std::endl
		<< deviceInfoList[0].firmwareVersion << std::endl
		<< deviceInfoList[0].ipAddress << std::endl
		<< deviceInfoList[0].port << std::endl;
	out.close();

	mmind::api::MechEyeDevice device;
	mmind::api::ErrorStatus status;
	status = device.connect(deviceInfoList[0]);
	if (status.isOK()) {
		std::cout << "Mech-Eye camera has been connected." << std::endl;
	}
	else {
		std::cout << "Mech-Eye camera is unable to connect." << std::endl;
		exit(3);
	}

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
