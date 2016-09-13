//
// Manager.cpp
//

// System includes
#include <string>

// Engine includes
#include "Manager.h"

namespace df {

Manager::Manager() {

}

Manager::~Manager() {

}

std::string Manager::getType() const {
	return type;
}

void Manager::setType(std::string type) {
	Manager::type = "Manager";
}

int Manager::startUp() {
	is_started = true;
	return 0;
}

void Manager::shutDown() {
	is_started = false;
}

bool Manager::isStarted() const{
	return true;
}

} // End namespace df