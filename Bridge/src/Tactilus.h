#pragma once
#define DLL_API __declspec(dllimport)


 class DLL_API Tactilus
 {
 public:
	Tactilus();
 	virtual ~Tactilus(void);

	/*tries to connect a tactilus mat via USB connection.Returns true if there is a succesfull connection , false if connection to the device fails.
	Send calibrated as true for hardware calibrated readings desired true for raw data.
	This function should be called before using any other function in the API.
	*/
	bool connect(bool calibrated=true);

	/*
	Scans the Sensor matrix and store values in a float array.Returns false if device fails to scan sensors.
	*/
	bool scan();

	/*
	returns the sensor values in a float array [column X row]
	*/
	float* matrix();

	/*
		returns maximum pressure
	*/
	float maximum();

	/*
		returns minimum pressure
	*/
	float minimum();

	/*
		returns number colum count of sensor matrix
	*/
	int columnCount();

	/*
		returns number row count of sensor matrix
	*/
	int rowCount();

	/*
		returns width of a single sensor in mm
	*/
	float sensorWidth();

	/*
		returns height of a single sensor in mm
	*/
	float sensorHeight();

	/*
		returns width of the connected mat
	*/
	float padwidth();

	/*
		returns height of the connected mat
	*/
	float padHeight();

	/*
		returns the pressure unit
	*/
	char* unitName();

	/*
		tells if mat is used in calibrated mode
	*/
	bool calibrated();
 
 protected:
	bool _calibrated;
 private:
	void* _device;
	float* _matrix;
	int _columnCount;
	int _rowCount;
	float _sensorWidth;
	float _sensorHeight;
	float _padWidth;
	float _padHeight;
	float _maximumPressure;
	float _minimumPressure;
	char* _unitName;

 };

