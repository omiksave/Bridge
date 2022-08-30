#include"InsoleWrapper.h"//Insole Wrapper Function
#include"TCPCOM_Client.h"//TCP Client Function
#include<timeapi.h>//Access system granularity
#include"yei_threespace_api.h"
#include<stdio.h>

int main() {
	TSS_Device_Id  device;
	TSS_Error tss_error;
	TSS_ComPort comport;

	if (tss_getComPorts(&comport, 1, 0, TSS_FIND_ALL_KNOWN ^ TSS_FIND_DNG)) {
		device = tss_createTSDeviceStr(comport.com_port, TSS_TIMESTAMP_SENSOR);
		if (device == TSS_NO_DEVICE_ID) {
			printf("Failed to create a sensor on %s\n", comport.com_port);
			return 1;
		}
	}
	else {
		printf("No sensors found\n");
		return 1;
	}
	printf("==================================================\n");
	printf("Getting the filtered tared quaternion orientation.(xyzw)\n");
	float eul[3];
	unsigned int timestamp;
	while (true) {
		tss_error = tss_getTaredOrientationAsEulerAngles(device, eul, &timestamp);//tss_getTaredOrientationAsQuaternion(device, quat, &timestamp);
		if (!tss_error) {
			printf("Euler: %f, %f, %f Timestamp=%u\n", eul[0], eul[1], eul[2], timestamp);
		}
		else {
			printf("TSS_Error: %s\n", TSS_Error_String[tss_error]);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	/*printf("==================================================\n");
	printf("Getting the Corrected Component Sensor Data.\n");
	float gyro[3];
	float accel[3];
	float compass[3];
	tss_error = tss_getAllCorrectedComponentSensorData(device, gyro, accel, compass, NULL);
	if (!tss_error) {
		printf("Gyro:  %f, %f, %f\n", gyro[0], gyro[1], gyro[2]);
		printf("Accel: %f, %f, %f\n", accel[0], accel[1], accel[2]);
		printf("Comp:  %f, %f, %f\n", compass[0], compass[1], compass[2]);
	}
	else {
		printf("TSS_Error: %s\n", TSS_Error_String[tss_error]);
	}
	printf("==================================================\n");
	printf("Getting the LED color  of the device.\n");
	float color[3];
	tss_error = tss_getLEDColor(device, color, NULL);
	if (!tss_error) {
		printf("Color: %f, %f, %f\n", color[0], color[1], color[2]);
	}
	else {
		printf("TSS_Error: %s\n", TSS_Error_String[tss_error]);
	}
	printf("==================================================\n");*/
	tss_closeTSDevice(device);

	printf("Finished press Enter to continue");
	getchar();
	return 0;


	//timeBeginPeriod(1);//Change system granularity to 1 ms, default 10ms
	//TCPCOM_Client MyClient("127.0.0.1", 5001);//Initialize communication with Speedgoat
	//MyClient.startClientThread();//Start Client thread
	//std::cin.get();//Press Enter to safely interrupt
	//MyClient.stopClientThread();//Stop Client Thread
	//timeEndPeriod(1);//Return system granularity to default
	//return 0;
}

/***********************************Garbage******************************************/
	//std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	//std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	//std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
	//timeBeginPeriod(1);
	//InsoleWrapper I1;
	//InsoleWrapper I2;
	//I1.StartThread();
	//I2.StartThread();
	//// 
	////I2.UpdateInsole();
	//boost::asio::io_service io_service;
	////socket creation
	//tcp::socket socket(io_service);
	////connection
	////socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("192.168.7.1"), 5001));

	// //request/message from client
	//boost::system::error_code error;

	//std::atomic<bool> runner = true;

	////std::thread tthr(sendPacket, pointrunner, I1, error, socket);
	////std::cin.get();
	//runner = false;
	////while(1) {
	//////	//std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	//////	//I1.UpdateInsole();
	////	boost::asio::write(socket, boost::asio::buffer(I1.p, 128 * 4), error);
	////	//std::this_thread::sleep_for(std::chrono::milliseconds(1));
	//////	//socket.send(boost::asio::buffer(I1.p, 128 * 4));
	//////	//socket.write_some(boost::asio::buffer(I1.p, 128 * 4), error);
	//////	//std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	//////	//std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
	////}
	//timeEndPeriod(1);
	//float* p1 = new float[1]{ 1};
	//float* p2 = new float[1]{ 10};
	//boost::array<boost::asio::const_buffer, 2> b{};
	//boost::asio::io_service io_service;
	//boost::asio::ip::tcp::socket socket(io_service);
	////auto b = boost::asio::buffer(p1, 128);
	//socket.connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("192.168.7.1"), 5001));
	//boost::system::error_code error;
	////socket.send(b);
	//std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	//b =
	//{ boost::asio::buffer(p1, 4),
	//boost::asio::buffer(p2, 4) };
	//socket.send(b);
	//std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	//std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
	//*p1 = 22;
	//*p2 = 1;
	//begin = std::chrono::steady_clock::now();
	//std::this_thread::sleep_for(std::chrono::milliseconds(20));
	//end = std::chrono::steady_clock::now();
	//std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
	//begin = std::chrono::steady_clock::now();
	//socket.send(b);
	//end = std::chrono::steady_clock::now();
	//std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;