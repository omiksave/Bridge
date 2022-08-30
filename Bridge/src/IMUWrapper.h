#pragma once
#include<iostream>
#include<thread>
#include<chrono>
#include"yei_threespace_api.h"
#include<mutex>
#include<atomic>

class IMUWrapper
{
private:
	TSS_Device_Id* device = new TSS_Device_Id;//Create unique device ID
	TSS_ComPort* comport = new TSS_ComPort;//Create COM PORT object 
public:
	IMUWrapper(int offsetx);
	void initSensors(int offsetx);
};

