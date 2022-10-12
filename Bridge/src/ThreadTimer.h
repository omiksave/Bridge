#pragma once
#include<iostream>
#include<chrono>
#include<thread>
/* This is a timer class for thread time management. This class is intended to be used at the begining of an infinite loop (preferably while),
* where when the object goes out of scope the object calculates the loop execution time, compares with the expected delay and pauses execution
* for the exact remainder time in nanoseconds.
*/
class ThreadTimer
{
private:
	std::chrono::high_resolution_clock::time_point _start = std::chrono::high_resolution_clock::now();// Set initial time
	std::chrono::high_resolution_clock::time_point _end;// Initiate end time variable
	long long _elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(_end - _start).count();// Initiate duration variable
	long long _delay = 500000;// Initiate delay variable
public:
	ThreadTimer(long long delay) { _delay = delay; };// Intialize object
	~ThreadTimer();// Destruct object
};

