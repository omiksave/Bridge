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
}
