//
// Object.cpp
//

// Engine includes
#include "Object.h"
#include "WorldManager.h"

namespace df {

Object::Object() {
	static int id_count = 0;
	id = id_count;
	id_count++;
	type = "Object";
	position = Vector();
	WorldManager &world_manager = WorldManager::getInstance();
	world_manager.insertObject(this);
}

Object::~Object() {
	WorldManager &world_manager = WorldManager::getInstance();
	world_manager.removeObject(this);
}

void Object::setId(int new_id) {
	id = new_id;
}

int Object::getId() const {
	return id;
}

void Object::setType(std::string new_type) {
	type = new_type;
}

std::string Object::getType() const {
	return type;
}

void Object::setPosition(Vector new_pos) {
	position = new_pos;
}

Vector Object::getPosition() const {
	return position;
}

int Object::eventHandler(const Event * p_e) {
	return 0;
}

}