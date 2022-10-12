#pragma once
#include<iostream>
#include<thread>
#include<chrono>
#include"yei_threespace_api.h"
#include<mutex>
#include<atomic>
#include"ThreadTimer.h"

class IMUWrapper
{
private:
	TSS_Device_Id* device = new TSS_Device_Id;//Create unique device ID
	TSS_ComPort* comport = new TSS_ComPort;//Create COM PORT object 
	int offset = 0;//Default offset
	TSS_Error* error = new TSS_Error;//Create error instance
	float* _euler = new float[3]{0,0,0};//Create Euler Angle Buffer
	float* color = new float[3]{ 0,0,0 };//Create Unique color identifier
	unsigned int* timestamp = new unsigned int[1]();//Create timestamp variable
	/********************************************Client Multithreading Member Variables*****************************************/
	std::mutex blockIMU;//Create lock for pointer when copying data from API
	std::thread threadIMU;//Create pointer for thread
public:
	unsigned char* euler = new unsigned char[12]();//Public Euler copy for communication
	std::atomic<bool> runIMU{ false };//Default dont run thread
	IMUWrapper(int offsetx);//Default constructor
	void initSensors();//Initialize IMU
	void updateIMU();//Update Euler Angles
	void threadIMUFunc();//Loop Update until asked to stop
	void startIMUThread();//Start Thread
	void stopIMUThread();//Stop Thread
	~IMUWrapper(void);//Class destructor
};

