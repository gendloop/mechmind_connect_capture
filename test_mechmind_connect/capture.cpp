// mmind
#include "MechEyeApi.h"
#include "SampleUtil.h"
#include "PclUtil.h"
// .h
#include "capture.h"

int capture() {
	mmind::api::MechEyeDevice device;
	// �������������
	if (!findAndConnect(device))
		return -1;

	// ����,��ȡmmid����
	mmind::api::PointXYZMap pointXYZMap;
	showError(device.capturePointXYZMap(pointXYZMap)); // ��ʾ���ƴ���
	
	// ת��Ϊpcl����
	pcl::PointCloud<pcl::PointXYZ> pointCloud(pointXYZMap.width(), pointXYZMap.height());
	toPCL(pointCloud, pointXYZMap);
	viewPCL(pointCloud); // ��ʾpcl����

	// ������Ʊ���·��
	std::string pointCloudPath;
	std::cout << "input save path: ";
	std::cin >> pointCloudPath;
	
	// �������
	savePLY(pointXYZMap, pointCloudPath);

	// �Ͽ��������
	device.disconnect();
	std::cout << "Disconnected from the Mech-Eye device successfully." << std::endl;

	return 0;
}