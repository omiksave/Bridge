#pragma once
#include<iostream>
#include<thread>
#include<chrono>
#include"Tactilus.h"
#include<mutex>

class InsoleWrapper
{	private:
		Tactilus* tx = new Tactilus();//Create new insole object from Tactilus API
		float* pprivate = new float[128];//Pointer communicating with API
		std::thread updater;//Create object specific thread for constant update of insole
		std::mutex	shareblock;//Create lock for pointer when copying data from API
	public:
		InsoleWrapper();
		unsigned char* p = new unsigned char[128*4];//Pointer communicating with Task Manager
		
		void SetupInsole();//Connect to Insole via API
		void UpdateInsole();//Update Sensor Matrix


};

