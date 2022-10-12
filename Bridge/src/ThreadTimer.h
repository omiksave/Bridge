#pragma once
#include<iostream>
#include<chrono>
#include<thread>

class ThreadTimer
{
private:
	std::chrono::high_resolution_clock::time_point _start = std::chrono::high_resolution_clock::now();
	std::chrono::high_resolution_clock::time_point _end;
	long long _elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(_end - _start).count();
	long long _delay = 500000;
public:
	ThreadTimer(long long delay) { _delay = delay; };
	~ThreadTimer();
};

