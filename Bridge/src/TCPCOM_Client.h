#pragma once
#include<boost/asio.hpp>
#include<boost/array.hpp>
#include"InsoleWrapper.h"
#include"IMUWrapper.h"
#include"ThreadTimer.h"
#include"DongleWrapper.h"
#include<string>

typedef boost::array<boost::asio::const_buffer, 2> sensorPacket;//Define Buffer Array

class TCPCOM_Client
{
private:
	/******************************************Communication Member Variables********************************************/
	std::unique_ptr<boost::asio::ip::tcp::socket> sock;//Create unique pointer for TCP Socket
	std::unique_ptr<boost::asio::io_service> io_service;//Create unique pointer for IO SERVICE
	std::unique_ptr<boost::system::error_code> error;//Create unique pointer for ERROR CODE
	std::string address;//Store COM Address
	int port;//Store COM Port
	/*******************************************Sensor Specific Member Variables************************************************/
	//InsoleWrapper* I1;//Create new instance for Insole #104
	//InsoleWrapper* I2;//Create new instance for Insole #105
	DongleWrapper* dongle;
	//DongleWrapper* dongle1;
	//IMUWrapper* IMU1;//Create new instance for IMU 0
	//IMUWrapper* IMU2;//Create new instance for IMU 1
	sensorPacket packet;//Create variable for storing buffer of all sensors
	/********************************************Client Multithreading Member Variables*****************************************/
	std::mutex blockClient;//Create lock for pointer when copying data from API
	std::thread threadClient;//Create pointer for thread
public:
	std::atomic<bool> runClient{ false };//Default dont run thread
	/***************************************************************************************************************************/
	TCPCOM_Client(std::string add,int portx);//Intialize Class Instance
	void Connect();//Connect to Socket
	void getSensor();//Intialize Insoles from Client Instance
	void runSensor();//Start Individual Threads on Each Sensors to update data
	void stopSensor();//Stop all threads on all sensors
	void sendPacket();//Send Packet Function
	void threadClientFunc();//Loop send until stopped
	void startClientThread();//Start seperate thread to control buffer send
	void stopClientThread();//Stop buffer send thread
	~TCPCOM_Client(void);//Class destructor
};

