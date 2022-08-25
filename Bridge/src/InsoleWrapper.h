#pragma once
#include<iostream>
#include<thread>
#include<chrono>
#include"Tactilus.h"
#include<mutex>
#include<atomic>

class InsoleWrapper
{	private:
		Tactilus* tx = new Tactilus();//Create new insole object from Tactilus API
		float* pprivate = new float[128];//Pointer communicating with API
		std::thread updater;//Create object specific thread for constant update of insole
		std::mutex	shareblock;//Create lock for pointer when copying data from API
	public:
		unsigned char* p = new unsigned char[128 * 4];//Pointer communicating with Task Manager
		std::atomic<bool> runstat {false};
		
		InsoleWrapper();//Default Constructor
		void SetupInsole();//Connect to Insole via API
		void UpdateInsole();//Update Sensor Matrix
		void StartThread();//Run Update Thread until asked to stop

};

