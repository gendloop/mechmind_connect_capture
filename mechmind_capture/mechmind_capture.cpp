// mechmind_capture.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include "common.h"
// mmind
#include <MechEyeApi.h>
#include <SampleUtil.h>
#include <PclUtil.h>

#include <Windows.h>

int main(int argc, char* argv[])
{
	commandLineArgs args(argc, argv);
	if(args.ParsedArgc() == 0 || args.CheckCmdLineFlag("help"))
	{
		printf("\n%s --help \n"
			"\n\t[--file=<file to save, absolute path> \n"
			"\n\t[--view=<whether to view cloud, true or false> \n"
			, argv[0]);
		printf("\n\nexamples:\n");
		printf("\n\t mechmind_capture.exe --file=\"cloud.txt\" \n");
		printf("\n\t mechmind_capture.exe --file=\"C:\\Users\\admin\\Desktop\\cloud.txt\" --view=true \n");
		fflush(stdout);
		system("pause");
		exit(0);
	}
	
	// connect device
	mmind::api::MechEyeDevice device;
	mmind::api::MechEyeDeviceInfo device_info;
	std::fstream in("device_info.txt", std::ios::in);
	if (in.fail()) {
		std::cout << "fail to read device_info.txt." << std::endl;
		exit(-2);
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
	if (!status.isOK()) {
		printf("Unable to connect. \n");
		exit(-3);
	}

	// capture
	mmind::api::PointXYZMap pointXYZMap;
	device.capturePointXYZMap(pointXYZMap);
	
	// save
	std::string file = "cloud.ply";
	if (args.CheckCmdLineFlag("file")) {
		args.GetCmdLineArgument("file", file);
	}
	saveTXT(pointXYZMap, file);

	// view
	if (args.CheckCmdLineFlag("view")) {
		std::string str_view = "false";
		args.GetCmdLineArgument("view", str_view);
		if (str_view == "true") {
			pcl::PointCloud<pcl::PointXYZ> pointCloud(pointXYZMap.width(), pointXYZMap.height());
			toPCL(pointCloud, pointXYZMap);
			viewPCL(pointCloud);
		}
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
