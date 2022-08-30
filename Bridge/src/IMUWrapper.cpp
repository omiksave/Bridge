#include "IMUWrapper.h"

IMUWrapper::IMUWrapper(int offsetx)
{
	initSensors(offsetx);
}

void IMUWrapper::initSensors(int offsetx)
{
	tss_getComPorts(comport,1,offsetx,TSS_FIND_ALL_KNOWN);
}
