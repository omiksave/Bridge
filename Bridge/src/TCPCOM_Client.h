#pragma once
#include"InsoleWrapper.h"
#include<boost/asio.hpp>
#include<string>

class TCPCOM_Client
{
private:
	/******************************************Communication Member Variables********************************************/
	std::unique_ptr<boost::asio::ip::tcp::socket> sock;//Create unique pointer for TCP Socket
	std::unique_ptr<boost::asio::io_service> io_service;//Create unique pointer for IO SERVICE
	std::unique_ptr<boost::system::error_code> error;//Create unique pointer for ERROR CODE
	std::string address;//Store COM Address
	int port;//Store COM Port
	/*******************************************Sensor Specific Member Variables*******************************************/
	InsoleWrapper* I1;//Create new instance for Insole #104
	InsoleWrapper* I2;//Create new instance for Insole #105
	/********************************************Client Multithreading Member Variables******************************************/
	std::mutex	blockClient;//Create lock for pointer when copying data from API
	std::thread threadClient;//Create pointer for thread
public:
	TCPCOM_Client(std::string add,int portx);//Intialize Class Instance
	void Connect();//Connect to Socket
	void getSensor();//Intialize Insoles from Client Instance
	void runSensor();//Start Individual Threads on Each Sensors to update data
	void stopSensor();//Stop all threads on all sensors
};

