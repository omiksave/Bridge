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
	pprivate = tx->matrix();//Point private pointer to matrix
	std::cout << "Insole Connected" << std::endl;
}

void InsoleWrapper::UpdateInsole()
{
	tx->scan();//Refresh new frame from Insole API
	shareblock.lock();//Add lock to avoid memory corruption
	memcpy(p, pprivate, 128 * 4);//Copy matrix for Task Manager access
	shareblock.unlock();//Release lock
}

void InsoleWrapper::ThreadFunc()
{

	std::cout << "Thread is running" << std::endl;
	while (runstat) {
		UpdateInsole();
		std::this_thread::sleep_for(std::chrono::milliseconds(1));//Pause the loop for sensor to update
	}
	std::cout << "This thread has stopped" << std::endl;

}

void InsoleWrapper::StartThread()
{
	runstat = true;//Start thread
	threadrunner = new std::thread(&InsoleWrapper::ThreadFunc, this);//Create object specific thread for constant update of insole
}

void InsoleWrapper::StopThread()
{
	runstat = false;
	threadrunner->join();
	delete threadrunner;
}


