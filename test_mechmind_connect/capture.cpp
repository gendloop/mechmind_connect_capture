// mmind
#include "MechEyeApi.h"
#include "SampleUtil.h"
#include "PclUtil.h"
// .h
#include "capture.h"

int capture() {
	mmind::api::MechEyeDevice device;
	// 查找相机并连接
	if (!findAndConnect(device))
		return -1;

	// 拍照,获取mmid点云
	mmind::api::PointXYZMap pointXYZMap;
	showError(device.capturePointXYZMap(pointXYZMap)); // 显示点云错误
	
	// 转化为pcl点云
	pcl::PointCloud<pcl::PointXYZ> pointCloud(pointXYZMap.width(), pointXYZMap.height());
	toPCL(pointCloud, pointXYZMap);
	viewPCL(pointCloud); // 显示pcl点云

	// 输入点云保存路径
	std::string pointCloudPath;
	std::cout << "input save path: ";
	std::cin >> pointCloudPath;
	
	// 保存点云
	savePLY(pointXYZMap, pointCloudPath);

	// 断开相机连接
	device.disconnect();
	std::cout << "Disconnected from the Mech-Eye device successfully." << std::endl;

	return 0;
}