//
// Manager.h
//

#ifndef __MANAGER_H__
#define __MANAGER_H__

// System includes
#include <string>

namespace df {

class Manager {
private:
	std::string type;
	bool is_started;

protected:
	// Set type identifier of Manager
	void setType(std::string type);

public:
	Manager();
	virtual ~Manager();

	// Get type identifier of Manager
	std::string getType() const;

	// Startup Manager
	// Return 0 if okay, else negative number
	virtual int startUp();

	// Shutdown Manager
	virtual void shutDown();

	// Return true when startUp() was executed okay, else false
	bool isStarted() const;
};

} // End of namespace df
#endif // __MANAGER_H__
