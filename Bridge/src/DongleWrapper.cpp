#include "DongleWrapper.h"

DongleWrapper::DongleWrapper()
{
	int num = tss_getComPorts(_com, 1, 0, TSS_FIND_ALL_KNOWN);
	if (num > 0) {
		*_dongle = tss_createTSDeviceStr(_com->com_port, TSS_TIMESTAMP_SENSOR);
		printf("Successfully created (default) dongle\n");
	}
	else {
		printf("Failed to create (default) dongle\n");
	}
}

DongleWrapper::DongleWrapper(int offset)
{
	int num = tss_getComPorts(_com, 1, offset, TSS_FIND_ALL_KNOWN);
	if (num > 0) {
		*_dongle = tss_createTSDeviceStr(_com->com_port, TSS_TIMESTAMP_SENSOR);
		printf("Successfully created %i dongle\n",offset);
	}
	else {
		printf("Failed to create %i dongle\n", offset);
	}
}

void DongleWrapper::CreateWLSensors()
{
	int logic_id = 0;
	TSS_Device_Id* sensor = new TSS_Device_Id;
	*sensor = 0;
	
	while (*sensor != TSS_NO_DEVICE_ID) {
		tss_getSensorFromDongle(*_dongle, logic_id, sensor);
		sensor_list.push_back(*sensor);
		_temp = new WLSWrapper(sensor_list[logic_id]);
		sensor_id.push_back(_temp);
		logic_id++;
	}
}

DongleWrapper::~DongleWrapper()
{
	delete _dongle;
	delete _com;
}
