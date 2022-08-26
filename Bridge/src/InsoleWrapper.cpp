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
	shareblock.lock();//Add lock to avoid memory corruption
	tx->scan();//Refresh new frame from Insole API
	pprivate = tx->matrix();//Update Matrix
	memcpy(p, pprivate, 128 * 4);//Copy matrix for Task Manager access
	shareblock.unlock();//Release lock
}

void InsoleWrapper::ThreadFunc()
{
	float sumx = 0.0;
	int itr = 0;
	while (runstat) {
		UpdateInsole();
		std::cout << "Thread is running" << std::endl;	
		std::this_thread::sleep_for(std::chrono::milliseconds(2));//Pause the loop for sensor to update
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


