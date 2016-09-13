//
// Clock.h
//

#ifndef __CLOCK_H__
#define __CLOCK_H__

namespace df {

class Clock {
private:
	long int previous_time;		// Previous time delta() called (in microseconds)

public:
	// Sets previous time to current time
	Clock();

	// Return time elapsed since delta() was last called (in microseconds), -1 if error
	long int delta();

	//Return time elapsed since delta() was called (in microseconds), -1 if error
	long int split() const;
};

} // end namespace df
#endif // __CLOCK_H__
