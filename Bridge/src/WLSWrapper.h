#pragma once
#include<iostream>
#include<chrono>
#include<mutex>
#include<thread>
#include"ThreadTimer.h"
#include"yei_threespace_api.h"

class WLSWrapper
{
private:
	float* _euler[3]{ 0,0,0 };
	unsigned int* _timestamp;
	TSS_Error _error = TSS_NO_ERROR;
	TSS_Device_Id _sensor_id;
	TSS_Stream_Command _slots[8] = { TSS_GET_TARED_ORIENTATION_AS_EULER_ANGLES,TSS_NULL,TSS_NULL,TSS_NULL ,TSS_NULL ,TSS_NULL ,TSS_NULL ,TSS_NULL };
	std::mutex blockWLS;//Create lock for pointer when copying data from API
	std::thread threadWLS;//Create pointer for thread
public:
	unsigned char* euler = new unsigned char[12]();
	std::atomic<bool> runWLS{ false };//Default dont run thread
	WLSWrapper(TSS_Device_Id sensor);
	void updateWLS();
	void threadWLSFunc();
	void startThreadWLS();
	void stopThreadWLS();
	~WLSWrapper();
};

