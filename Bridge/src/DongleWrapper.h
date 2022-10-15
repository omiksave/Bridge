#pragma once
#include"yei_threespace_api.h"
#include<iostream>
#include<vector>

class DongleWrapper
{
private:
	TSS_Device_Id* _dongle = new TSS_Device_Id;
	TSS_ComPort* _com = new TSS_ComPort;
	TSS_Error _error = TSS_NO_ERROR;
public:
	DongleWrapper();// Default constructor
	DongleWrapper(int offset);// Constructor with Offset
	void CreateWLSensors();
	~DongleWrapper();// Destructor
};

