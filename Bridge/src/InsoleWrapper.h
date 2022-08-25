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
		float* p;//Pointer communicating with Task Manager
		
		float* SetupInsole();//Connect to Insole via API
		void UpdateInsole();//Update Sensor Matrix


};

