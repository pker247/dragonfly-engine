//
// LogManager.cpp
//

// System includes
#include <stdio.h>
#include <stdarg.h>
#include <iostream>
#include <fstream>

// Engine includes
#include "LogManager.h"

namespace df {

LogManager::LogManager() {
	setType("LogManager");

	// Initialize attributes
	p_f = NULL;
	do_flush = false;
	file_open = false;
}

LogManager::~LogManager() {
	if (file_open) {
		fclose(p_f);
	}
}

void LogManager::operator=(LogManager const &) {

}

LogManager & LogManager::getInstance() {
	static LogManager log_manager;
	return log_manager;
}

int LogManager::startUp() {
	Manager::startUp();

	const char* cstr = LOGFILE_NAME.c_str();

	// Open logfile
	p_f = fopen(cstr, "w");

	// Check that file successfully opened
	if (p_f == NULL) {
		file_open = true;
		return 1;
	}
	else {
		return 0;
	}
}

void LogManager::shutDown() {
	Manager::shutDown();

	// Close logfile
	fclose(p_f);
	file_open = false;
}

void LogManager::setFlush(bool do_flush) {

}

int LogManager::writeLog(const char *fmt, ...) const {
	int chars_written;

	// Writes to logfile using variable number of arguments
	va_list args;
	va_start(args, fmt);
	chars_written = vfprintf(p_f, fmt, args);
	va_end(args);

	// Add newline after writing to log
	fputs("\n", p_f);

	// If game programmer wants to flush after each writeLog, then flush
	if (do_flush == true) {
		fflush(p_f);
	}

	// If vfprintf failed, change return value to -1 to indicate error
	if (chars_written < 0) {
		chars_written = -1;
	}

	// Return number of bytes written to log
	return chars_written;
}

} // End df namespace