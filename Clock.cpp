//
// Clock.cpp
//

// System includes
#include <Windows.h>

// Engine includes
#include "Clock.h"

namespace df {

	Clock::Clock() {
		// Set previous time to current time in microseconds
		SYSTEMTIME now;
		GetSystemTime(&now);
		previous_time = (now.wMinute * 60 * 1000000)
			+ (now.wSecond * 1000000)
			+ (now.wMilliseconds * 1000);
	}

	long int Clock::delta() {
		// Start timer, set previous_time to start time in microseconds
		SYSTEMTIME before;
		GetSystemTime(&before);
		previous_time = (before.wMinute * 60 * 1000000)
			+ (before.wSecond * 1000000)
			+ (before.wMilliseconds * 1000);

		return previous_time;
	}

	long int Clock::split() const {
		// End timer
		SYSTEMTIME after;
		long int after_time;
		GetSystemTime(&after);
		after_time = (after.wMinute * 60 * 1000000)
			+ (after.wSecond * 1000000)
			+ (after.wMilliseconds * 1000);

		// Calculate time
		return after_time - previous_time;
	}
} // end namespace df