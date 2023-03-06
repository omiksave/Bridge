
#include"TCPCOM_Client.h"//TCP Client Function
#include<timeapi.h>//Access system granularity
#include<vector>
#include"DongleWrapper.h"

int main() {
	timeBeginPeriod(1);//Change system granularity to 1 ms, default 10ms
	TCPCOM_Client MyClient("192.168.85.5", 5001);//Initialize communication with Speedgoat
	std::cout << "Finished Setup" << std::endl;
	std::cin.get();
	MyClient.startClientThread();//Start Client thread
	std::cin.get();//Press Enter to safely interrupt
	MyClient.stopClientThread();//Stop Client Thread
	timeEndPeriod(1);//Return system granularity to default
	std::cin.get();
	return 0;
}

//int main() {
//	std::vector<TSS_Device_Id> sensors;
//	TSS_Device_Id wsensor;
//	TSS_Device_Id dongle;
//	TSS_ComPort com;
//	TSS_Error error = TSS_NO_ERROR;
//
//	auto get_dongle = tss_getComPorts(&com, 10, 0, TSS_FIND_ALL_KNOWN);
//	if (com.sensor_type == 3) {
//		dongle = tss_createTSDeviceStr(com.com_port, TSS_TIMESTAMP_SENSOR);
//	}
//	int logic_id = 0;
//	tss_getSensorFromDongle(dongle, logic_id, &wsensor);
//	while (wsensor != TSS_NO_DEVICE_ID) {
//		sensors.push_back(wsensor);
//		logic_id++;
//		error = tss_getSensorFromDongle(dongle, logic_id, &wsensor);
//	}
//	float euler[3];
//	unsigned int timestamp;
//	error = tss_getTaredOrientationAsEulerAngles(sensors[0], euler, &timestamp);
//	TSS_Stream_Command slots[8] = { TSS_GET_TARED_ORIENTATION_AS_EULER_ANGLES,TSS_NULL,TSS_NULL,TSS_NULL ,TSS_NULL ,TSS_NULL ,TSS_NULL ,TSS_NULL };
//	tss_setStreamingTiming(sensors[0], 0, TSS_INFINITE_DURATION, 0, NULL);
//	tss_setStreamingSlots(sensors[0], slots, NULL);
//	tss_startStreaming(sensors[0], NULL);
//	error = tss_getLastStreamData(sensors[0], (char*) & euler,sizeof(euler), & timestamp);
//	tss_stopStreaming(sensors[0], NULL);
//	std::cin.get();
//	return 0;
//
//}