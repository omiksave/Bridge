#pragma once
#include<iostream>
#include"Tactilus.h"
class InsoleWrapper
{	private:
		Tactilus* tx = new Tactilus();//Create new insole object from Tactilus API
		float* pprivate;//Pointer communicating with API
	public:
		float* p;//Pointer communicating with Task Manager
		
		void SetupInsole();//Connect to Insole via API
		float* UpdateInsole();//Update Sensor Matrix

};

