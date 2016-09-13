//
// LogManager.h
//

#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__

// System includes
#include <stdio.h>

// Engine includes
#include "Manager.h"

namespace df {

const std::string LOGFILE_NAME = "dragonfly.log";

class LogManager : public Manager {
private:
	LogManager();							// Private since singleton
	LogManager(LogManager const&);			// Don't allow copy
	void operator = (LogManager const&);	// Don't allow assignment
	bool do_flush;							// True if flush to disk after each write
	FILE *p_f;								// Pointer to logfile struct
	bool file_open;							// True if file is open

public:
	// If logfile is open, close it
	~LogManager();

	// Get the one and only instance of the LogManager
	static LogManager &getInstance();

	// Start up the LogManager (open logfile  "dragonfly.log")
	int startUp();

	// Shut down the LogManager (close logfile)
	void shutDown();

	// Set flush of logfile after each write
	void setFlush(bool do_flush = true);

	// Write to logfile
	// Supports printf() formatting of strings
	// Return number of bytes written, -1 if error
	int writeLog(const char *fmt, ...) const;
};

} // End of namespace df
#endif // __LOG_MANAGER_H__