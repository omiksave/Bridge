#pragma once
#include "IMUWrapper.h"

IMUWrapper::IMUWrapper(int offsetx)
{
	offset = offsetx;//Set offset
	initSensors();//Initialize Sensor
}

void IMUWrapper::initSensors()
{
	tss_getComPorts(comport,1,offset,TSS_FIND_ALL_KNOWN);//Get current device COM PORT
	*device = tss_createTSDeviceStr(comport->com_port, TSS_TIMESTAMP_SENSOR);//Assign device to COM PORT
	*(color+offset) = 1;//Set unique color
	*error = tss_setLEDColor(*device, color, timestamp);//Set LED Color to identify
}

void IMUWrapper::updateIMU()
{
	//blockIMU.lock();//Lock IMU
	*error = tss_getTaredOrientationAsEulerAngles(*device, _euler, timestamp);//Get new value of IMU
	memcpy(euler,_euler,12);//Make copy of Euler
	//blockIMU.unlock();//Unlock IMU
}

void IMUWrapper::threadIMUFunc()
{
	std::cout << "IMU " << offset << " is running" << std::endl;
	while (runIMU) {
		//std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
		ThreadTimer timex;//Create thread time management
		updateIMU();//Run Insole Update in infinite while loop
		//std::this_thread::sleep_for(std::chrono::milliseconds(2));
		//std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		//std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
	}
	std::cout << "IMU " << offset << " has stopped" << std::endl;
}

void IMUWrapper::startIMUThread()
{
	runIMU = true;//Start thread
	threadIMU = std::thread(&IMUWrapper::threadIMUFunc, this);//Create object specific thread for constant update of insole
}

void IMUWrapper::stopIMUThread()
{
	runIMU = false;//Exit infinite while loop
	threadIMU.join();//Kill thread
	color = new float[3]{ 0,0,1 };
	*error = tss_setLEDColor(*device, color, timestamp);//Set LED Color to identify
}

IMUWrapper::~IMUWrapper(void)
{
	delete device;//Delete API Instance
	delete comport;//Delete COM PORT object
	delete error;//Delete error instance
	std::cout << "Closing IMU " << offset << std::endl;
}
