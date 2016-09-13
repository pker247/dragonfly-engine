#include "Saucer.h"
#include "EventStep.h"
#include "LogManager.h"
#include "Event.h"

Saucer::Saucer() {
	setType("Saucer");
}

Saucer::~Saucer() {

}

int Saucer::eventHandler(const df::Event *p_e) {
	df::LogManager &log_manager = df::LogManager::getInstance();
	if (p_e -> getType() == STEP_EVENT) {
		log_manager.writeLog("Step Event seen by Saucer\n");
		return 1;
	}
	return 0;
}