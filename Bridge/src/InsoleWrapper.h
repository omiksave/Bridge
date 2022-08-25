#pragma once
#include<iostream>
#include<thread>
#include<chrono>
#include"Tactilus.h"
class InsoleWrapper
{	private:
		Tactilus* tx = new Tactilus();//Create new insole object from Tactilus API
		float* pprivate;//Pointer communicating with API
		std::thread updater;
	public:
		InsoleWrapper();
		unsigned char* p = new unsigned char[128*4];//Pointer communicating with Task Manager
		
		void SetupInsole();//Connect to Insole via API
		void UpdateInsole();//Update Sensor Matrix


};

