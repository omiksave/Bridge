#pragma once
#include "InsoleWrapper.h"

InsoleWrapper::InsoleWrapper()
{
	SetupInsole();
}

void InsoleWrapper::SetupInsole()
{
	std::cout << "Connecting Sensor" << std::endl;
	tx->connect(true);//Connect to Insole with true calibration
	std::cout << "Insole Connected" << std::endl;
}

void InsoleWrapper::UpdateInsole()
{
	tx->scan();//Refresh new frame from Insole API
	pprivate = tx->matrix();//Update Matrix
	shareblock.lock();
	memcpy(p, pprivate, 128 * 4);//Copy matrix for Task Manager access
	shareblock.unlock();
}


