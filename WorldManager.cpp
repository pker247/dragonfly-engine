//
// WorldManager.cpp
//

// Engine includes
#include "WorldManager.h"
#include "LogManager.h"

namespace df {

WorldManager::WorldManager() {
	setType("WorldManager");
	updates = ObjectList();
	deletions = ObjectList();
}

void WorldManager::operator=(WorldManager const&) {

}

WorldManager & WorldManager::getInstance() {
	static WorldManager world_manager;
	return world_manager;
}

int WorldManager::startUp() {
	Manager::startUp();
	return 0;
}

void WorldManager::shutDown() {
	ObjectList list = updates;
	ObjectListIterator iterator(&list);

	// Delete all objects from list
	for (iterator.first(); !iterator.isDone(); iterator.next()) {
		delete iterator.currentObject();
	}
	
	Manager::shutDown();
}

int WorldManager::insertObject(Object *p_o) {
	// Add object to game world
	updates.insert(p_o);
	LogManager &log_manager = LogManager::getInstance();
	log_manager.writeLog("Object inserted into WorldManager");
	return 0;
}

int WorldManager::removeObject(Object *p_o) {
	// Remove object from game world
	updates.remove(p_o);
	LogManager &log_manager = LogManager::getInstance();
	log_manager.writeLog("Object removed from WorldManager");
	return 0;
}

ObjectList WorldManager::getAllObjects() const {
	return updates;
}

ObjectList WorldManager::objectsOfType(std::string type) const {
	ObjectList list;
	ObjectListIterator iterator(&updates);

	// Find objects of specified type, add to list
	for (iterator.first(); !iterator.isDone(); iterator.next()) {
		Object o = *iterator.currentObject();
		if (o.getType() == type) {
			list.insert(iterator.currentObject());
		}
	}
	return list;
}

void WorldManager::update() {
	// Delete all objects marked for deletion
	ObjectListIterator iterator(&deletions);
	while (!iterator.isDone()) {
		delete iterator.currentObject();
		iterator.next();
	}

	// Clear list for next game loop
	deletions.clear();
}

int WorldManager::markForDelete(Object *p_o) {
	// Make sure object is not already marked for deletion
	ObjectListIterator iterator(&deletions);
	while (!iterator.isDone()) {
		if (iterator.currentObject() == p_o) {
			return 0;
		}
		iterator.next();
	}

	// Mark object for deletion since it wasn't already marked
	deletions.insert(p_o);
	return 0;
}

} // end namespace df