#pragma once
#include<iostream>
#include<thread>
#include<chrono>
#include"Tactilus.h"
#include"ThreadTimer.h"
#include<mutex>
#include<atomic>

class InsoleWrapper
{	
private:
	Tactilus* tx = new Tactilus();//Create new insole object from Tactilus API
	float* pprivate = new float[128]();//Pointer communicating with API
	std::mutex shareblock;//Create lock for pointer when copying data from API
	std::thread threadrunner;//Create pointer for thread
public:
	int ID;//Insole ID
	unsigned char* p = new unsigned char[128 * 4]();//Pointer communicating with Task Manager
	std::atomic<bool> runstat {false};//Default dont run thread
/************************************************************************/
	InsoleWrapper(int IDx);//Default Constructor
	void SetupInsole();//Connect to Insole via API
	void UpdateInsole();//Update Sensor Matrix
	void ThreadFunc();//Loop Update until asked to stop
	void StartThread();//Start Thread
	void StopThread();//Stop Thread
	~InsoleWrapper(void);//Class destructor
};

