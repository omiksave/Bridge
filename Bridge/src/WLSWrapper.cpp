#include "WLSWrapper.h"

WLSWrapper::WLSWrapper(TSS_Device_Id sensor)
{
	_sensor_id = sensor;
	//*dbuf_loc = *copy_loc;
	tss_setStreamingTiming(_sensor_id, 2, TSS_INFINITE_DURATION, 0, NULL);
	tss_setStreamingSlots(_sensor_id, _slots, NULL);
	tss_startStreaming(_sensor_id, NULL);
	//startThreadWLS();


}

void WLSWrapper::updateWLS()
{
	//blockWLS.lock();
	_error = tss_getLastStreamData(_sensor_id, (char*)&_euler, sizeof(_euler), _timestamp);
	memcpy(euler, _euler, 12);
	//blockWLS.unlock();
}

void WLSWrapper::threadWLSFunc()
{
	std::cout << "WLS " << _sensor_id << " is running" << std::endl;
	while (runWLS) {
		//std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
		ThreadTimer timex;//Create thread time management
		updateWLS();//Run Insole Update in infinite while loop
		//std::this_thread::sleep_for(std::chrono::milliseconds(2));
		//std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		//std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
	}
	std::cout << "WLS " << _sensor_id << " has stopped" << std::endl;
}

void WLSWrapper::startThreadWLS()
{
		runWLS = true;//Start thread
		threadWLS = std::thread(&WLSWrapper::threadWLSFunc, this);//Create object specific thread for constant update of insole
}

void WLSWrapper::stopThreadWLS()
{
	runWLS = false;//Exit infinite while loop
	threadWLS.join();//Kill thread
}


WLSWrapper::~WLSWrapper()
{
	tss_stopStreaming(_sensor_id, NULL);
	stopThreadWLS();
}
