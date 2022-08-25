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
	shareblock.lock();//Add lock to avoid memory corruption
	memcpy(p, pprivate, 128 * 4);//Copy matrix for Task Manager access
	shareblock.unlock();//Release lock
}

void InsoleWrapper::StartThread()
{
	while (runstat) {
		UpdateInsole();
		std::this_thread::sleep_for(std::chrono::milliseconds(1));//Pause the loop for sensor to update
	}
}


