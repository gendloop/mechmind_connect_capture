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
	// connect device
	mmind::api::MechEyeDevice device;
	mmind::api::MechEyeDeviceInfo device_info;
	std::fstream in("device_info.txt", std::ios::in);
	if (in.fail()) {
		std::cout << "fail to read device_info.txt." << std::endl;
		exit(2);
	}
	std::string tmp;
	int count = 0;
	while (std::getline(in, tmp)) {
		if (count == 0)
			device_info.model = tmp;
		else if (count == 1)
			device_info.id = tmp;
		else if (count == 2)
			device_info.hardwareVersion = tmp;
		else if (count == 3)
			device_info.firmwareVersion = tmp;
		else if (count == 4)
			device_info.ipAddress = tmp;
		else if (count == 5)
			device_info.port = atoi(tmp.c_str());
		else
			break;
		count++;
	}
	in.close();
	auto status = device.connect(device_info);
	if (status.isOK()) {
		device.disconnect();
		std::cout << "Mech-Eye camera has been disconnected." << std::endl;
	}
	else {
		std::cout << "No Mech-Eye camera connect." << std::endl;
		exit(1);
	}

	system("pause");

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
