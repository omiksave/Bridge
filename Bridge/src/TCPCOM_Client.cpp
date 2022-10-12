#pragma once
#include "TCPCOM_Client.h"

TCPCOM_Client::TCPCOM_Client(std::string add,int portx)
{
	address = add;//Assign address to class instance from main
	port = portx;//Assign port to class instance from main
	Connect();//Initialize socket
}

void TCPCOM_Client::Connect()
{
	io_service = std::make_unique<boost::asio::io_service>();//Create unique IO SERVICE
	sock = std::make_unique<boost::asio::ip::tcp::socket>(*io_service);//Create socket using IO SERVICE
	error = std::make_unique<boost::system::error_code>();//Generate error code
	std::cout << "Connecting to Client...." << std::endl;
	sock->connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(address), port));//Connect to socket
	std::cout << "Connected to Client!" << std::endl;
}

void TCPCOM_Client::getSensor()
{
	I1 = new InsoleWrapper(104);//Create new instance of Insole 104
	I2 = new InsoleWrapper(105);//Create new instance of Insole 105
	IMU1 = new IMUWrapper(0);//Create new instance of IMU 0
	IMU2 = new IMUWrapper(1);//Create new instance of IMU 1
	packet = { boost::asio::buffer(I1->p,128 * 4),
			   boost::asio::buffer(I2->p,128 * 4),
			   boost::asio::buffer(IMU1->euler,3 * 4),
			   boost::asio::buffer(IMU2->euler,3 * 4) };//Create packet from all sensor buffers
}

void TCPCOM_Client::runSensor()
{
	I1->StartThread();//Start Insole 1 thread
	I2->StartThread();//Start Insole 2 thread
	IMU1->startIMUThread();//Start IMU 0 thread
	IMU2->startIMUThread();//Start IMU 1 thread
}

void TCPCOM_Client::stopSensor()
{
	I1->StopThread();//Stop Insole 1 thread
	I2->StopThread();//Stop Insole 2 thread
	IMU1->stopIMUThread();//Stop IMU 0 thread
	IMU2->stopIMUThread();//Stop IMU 1 thread
}

void TCPCOM_Client::sendPacket()
{
	blockClient.lock();//Lock packet until safe
	boost::asio::write(*sock, packet, * error);//Write data to packet
	blockClient.unlock();//Unlock packet
}

void TCPCOM_Client::threadClientFunc()
{
	std::cout << "Actively Sending Packets..." << std::endl;
	while (runClient) {
		std::chrono::steady_clock::time_point begin = std::chrono::high_resolution_clock::now();
		ThreadTimer timex;//Create thread time management
		sendPacket();//Send Packet
		//std::this_thread::sleep_for(std::chrono::milliseconds(3));//Pause Client for external computer to catch up
		std::chrono::steady_clock::time_point end = std::chrono::high_resolution_clock::now();
		//std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
		printf("Packet sent in %I64d [ns]\n", std::chrono::duration_cast<std::chrono::nanoseconds>(begin - end).count());
	}
	std::cout << "No Longer Sending Packets" << std::endl;
}

void TCPCOM_Client::startClientThread()
{
	getSensor();//Initialize all sensors
	runSensor();//Start all sensor threads
	std::this_thread::sleep_for(std::chrono::seconds(1));//Pause execution momentarily
	runClient = true;//Start thread
	threadClient = std::thread(&TCPCOM_Client::threadClientFunc, this);//Create object specific thread for sending data to external computer
}

void TCPCOM_Client::stopClientThread()
{
	stopSensor();//Stop all sensor threads
	runClient = false;//Exit infinite while loop
	threadClient.join();//Kill thread
}

TCPCOM_Client::~TCPCOM_Client(void)
{
	delete I1;//Delete Insole 104 instance
	delete I2;//Delete Insole 105 instance
	delete IMU1;//Delete IMU 0 instance
	delete IMU2;//Delete IMU 1 instance
	delete sock.release();//Delete Socket
	delete io_service.release();//Delete IO Service
	std::cout << "Closing Client!" << std::endl;
}
