//
// EventStep.h
//

#ifndef __EVENTSTEP_H__
#define __EVENTSTEP_H__

// Engine includes
#include "Event.h"

const std::string STEP_EVENT = "df::step";

namespace df {

class EventStep : public Event {
private:
	int step_count;		// Iteration number of game loop

public:
	// Default constructor
	EventStep();

	// Constructor with initial step count
	EventStep(int init_step_count);

	// Set step count
	void setStepCount(int new_step_count);

	// Get step count
	int getStepCount() const;
};

} // end namespace df
#endif // __EVENTSTEP_H__