#include "ThreadTimer.h"

ThreadTimer::~ThreadTimer()
{
	_end = std::chrono::high_resolution_clock::now();
	_elapsed = (_end - _start).count();
	if (_elapsed < _delay) {
		std::this_thread::sleep_for(std::chrono::nanoseconds(_delay - _elapsed));
	}
}
