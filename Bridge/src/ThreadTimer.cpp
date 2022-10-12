#include "ThreadTimer.h"

ThreadTimer::~ThreadTimer()
{
	_end = std::chrono::high_resolution_clock::now();// Note end loop execution time
	_elapsed = (_end - _start).count();// Calculate elapsed time
	if (_elapsed < _delay) {// Criteria for pause
		std::this_thread::sleep_for(std::chrono::nanoseconds(_delay - _elapsed));// Pause thread for recommended delay
	}
}
