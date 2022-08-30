#include"InsoleWrapper.h"//Insole Wrapper Function
#include"TCPCOM_Client.h"//TCP Client Function
#include<timeapi.h>//Access system granularity
#include"yei_threespace_api.h"
#include<stdio.h>

int main() {
	/*TSS_Device_Id* device = new TSS_Device_Id;
	TSS_ComPort* comport = new TSS_ComPort;

	int numero = tss_getComPorts(comport, 1, 0, TSS_FIND_ALL_KNOWN);

	*device = tss_createTSDeviceStr(comport->com_port,TSS_TIMESTAMP_SENSOR);
	TSS_Error* error = new TSS_Error;
	float* euler = new float[3]{};
	unsigned int* timestamp = new unsigned int[1]();
	*error = tss_getTaredOrientationAsEulerAngles(*device, euler, timestamp);
	*error = tss_getTaredOrientationAsEulerAngles(*device, euler, timestamp);
	float* color = new float[3]{ 0,0,1 };
	*error = tss_setLEDColor(*device,color , timestamp);
	TSS_Device_Id* device1 = new TSS_Device_Id;
	TSS_ComPort* comport1 = new TSS_ComPort;
	*color = 1;
	numero = tss_getComPorts(comport1, 1, 1, TSS_FIND_ALL_KNOWN^TSS_FIND_DNG);

	*device1 = tss_createTSDeviceStr(comport1->com_port, TSS_TIMESTAMP_SENSOR);

	*error = tss_setLEDColor(*device1, color, timestamp);*/
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