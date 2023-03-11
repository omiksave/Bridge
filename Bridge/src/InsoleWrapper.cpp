#pragma once
#include "InsoleWrapper.h"

InsoleWrapper::InsoleWrapper(int IDx)
{
	ID = IDx;
	SetupInsole();//Initialize object
}

void InsoleWrapper::SetupInsole()
{
	std::cout << "Connecting Sensor " << ID <<std::endl;
	tx->connect(true);//Connect to Insole with true calibration
	pprivate = tx->matrix();//Point private pointer to matrix
	std::cout << "Insole "<< ID <<" Connected" << std::endl;
}

void InsoleWrapper::UpdateInsole()
{
	//shareblock.lock();//Add lock to avoid memory corruption
	tx->scan();//Refresh new frame from Insole API
	memcpy(p, pprivate, 128 * 4);//Copy matrix for Task Manager access
	//shareblock.unlock();//Release lock
}

void InsoleWrapper::ThreadFunc()
{
	std::cout << "Insole " << ID << " is running" << std::endl;
	while (runstat) {
		ThreadTimer timex;//Create thread time management
		//std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
		UpdateInsole();//Run Insole Update in infinite while loop
		//std::this_thread::sleep_for(std::chrono::milliseconds(1));
		//std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		//std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
	}
	std::cout << "Insole "<< ID<<" has stopped" << std::endl;
}

void InsoleWrapper::StartThread()
{
	runstat = true;//Start thread
	threadrunner = std::thread(&InsoleWrapper::ThreadFunc, this);//Create object specific thread for constant update of insole
}

void InsoleWrapper::StopThread()
{
	runstat = false;//Exit infinite while loop
	threadrunner.join();//Kill thread
}

InsoleWrapper::~InsoleWrapper(void)
{
	delete tx;//Delete API Instance
	std::cout << "Closing Insole " << ID << std::endl;
}


