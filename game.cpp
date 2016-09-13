#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "LogManager.h"
#include "Clock.h"
#include "GameManager.h"
#include "Vector.h"
#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "Event.h"
#include "EventStep.h"
#include "WorldManager.h"
#include "Saucer.h"

void generalTests();
void gameManagerTests();

// TESTS FOR GAME ENGINE CODE
// ONLY RUN ONE FUNCTION AT A TIME, OTHERWISE IT WILL PROBABLY CRASH
// (COMMENT ONE FUNCTION OUT FROM main() EACH TIME YOU RUN THE ENGINE)
int main()
{
	generalTests();

	//gameManagerTests();
}

void generalTests(){
	// Tests for LogManager (writeLog)
	df::LogManager &log_manager = df::LogManager::getInstance();
	log_manager.startUp();
	int bytes;
	log_manager.writeLog("LogManager Tests:");
	bytes = log_manager.writeLog("Hello");
	bytes += log_manager.writeLog("%s", "Hello again");
	bytes += log_manager.writeLog("%d", 12345);
	bytes += log_manager.writeLog("%s %d", "IMGD", 3000);
	log_manager.writeLog("Bytes Written: %d\n", bytes);

	// Tests for Clock
	log_manager.writeLog("Clock Tests:");
	df::Clock clock;
	Sleep(1000);
	long int time = clock.split();
	log_manager.writeLog("Clock slept for: %d milliseconds\n", time/1000);

	// Tests for Vector
	log_manager.writeLog("Vector Tests:");
	df::Vector vector;
	// Set x/y, get x/y
	vector.setX(5);
	log_manager.writeLog("Vector x: %f", vector.getX());
	vector.setY(10);
	log_manager.writeLog("Vector y: %f", vector.getY());
	vector.setXY(20, 30);
	log_manager.writeLog("Vector (x, y) : (%f, %f)", vector.getX(), vector.getY());
	// Magnitude
	log_manager.writeLog("Vector magnitude: %f\n", vector.getMagnitude());

	// Tests for Object
	log_manager.writeLog("Object Tests:");
	df::Object object;
	// Id
	log_manager.writeLog("Object id: %d", object.getId());
	object.setId(15);
	log_manager.writeLog("Object new id: %d", object.getId());
	// Type
	log_manager.writeLog("Object type: %s", object.getType().c_str());
	object.setType("New Object");
	log_manager.writeLog("Object new type: %s", object.getType().c_str());
	// Position
	log_manager.writeLog("Object position: (%f, %f)", object.getPosition().getX(), object.getPosition().getY());
	object.setPosition(vector);
	log_manager.writeLog("Object new position: (%f, %f)\n", object.getPosition().getX(), object.getPosition().getY());

	// Tests for ObjectList
	log_manager.writeLog("ObjectList Tests:");
	df::ObjectList object_list;
	// isEmpty (should be true (1))
	log_manager.writeLog("ObjectList isEmpty: %d", object_list.isEmpty());
	// isFull (should be false (0))
	log_manager.writeLog("ObjectList isFull: %d", object_list.isFull());
	// Insert (***MAX set to 3 Objects for testing purposes)
	df::Object o1;
	object_list.insert(&o1);
	df::Object o2;
	object_list.insert(&o2);
	df::Object o3;
	object_list.insert(&o3);
	// getCount (should be 3)
	log_manager.writeLog("ObjectList count: %d", object_list.getCount());
	// isEmpty (should be false (0))
	log_manager.writeLog("ObjectList isEmpty: %d", object_list.isEmpty());
	// isFull (should be true (1))
	log_manager.writeLog("ObjectList isFull: %d", object_list.isFull());
	// Remove
	object_list.remove(&o2);
	// getCount (should be 2)
	log_manager.writeLog("ObjectList count: %d", object_list.getCount());
	// Remove
	object_list.remove(&o1);
	object_list.remove(&o3);
	// isEmpty (should be true (1))
	log_manager.writeLog("ObjectList isEmpty: %d\n", object_list.isEmpty());
	object_list.clear();

	// Tests for ObjectListIterator
	log_manager.writeLog("ObjectListIterator Tests:");
	df::Object o4;
	df::Object o5;
	df::Object o6;
	object_list.insert(&o4);
	object_list.insert(&o5);
	object_list.insert(&o6);
	df::ObjectListIterator iterator(&object_list);
	int count = 0;
	for (iterator.first(); !iterator.isDone(); iterator.next()) {
		df::Object o = *iterator.currentObject();
		log_manager.writeLog("Object id: %d", o.getId());
		count++;
	}
	log_manager.writeLog("Number of Objects interated through: %d\n", count);

	// Tests for Event
	log_manager.writeLog("Event Tests:");
	df::Event event;
	// Set/get type
	log_manager.writeLog("Event type: %s", event.getType().c_str());
	event.setType("New Event");
	log_manager.writeLog("Event new type: %s\n", event.getType().c_str());

	// Tests for EventStep
	log_manager.writeLog("EventStep Tests:");
	df::EventStep event_step;
	// getType
	log_manager.writeLog("EventStep type: %s", event_step.getType().c_str());
	// getStepCount
	log_manager.writeLog("EventStep step count: %d", event_step.getStepCount());
	// setStepCount
	event_step.setStepCount(10);
	log_manager.writeLog("EventStep new step count: %d", event_step.getStepCount());
	// Passing STEP_EVENT to Object (should print to dragonfly.log)
	df::EventStep es;
	df::Event ev;
	Saucer *s = new Saucer;
	s -> eventHandler(&es);
	// Should not print anything to dragonfly.log
	s -> eventHandler(&ev);
}

void gameManagerTests() {
	df::GameManager &game_manager = df::GameManager::getInstance();
	game_manager.startUp();
	df::LogManager &log_manager = df::LogManager::getInstance();
	log_manager.setFlush();
	df::WorldManager &world_manager = df::WorldManager::getInstance();

	// Tests for GameManager/WorldManager
	// getFrameTime
	log_manager.writeLog("GameManager/WorldManager Tests:");
	log_manager.writeLog("Frame time: %d\n", game_manager.getFrameTime());
	// Creating derived object adds it to the WorldManager
	new Saucer;
	new Saucer;
	new Saucer;
	// Shutting down WorldManager deletes objects in updates
	world_manager.shutDown();
	// Restart WorldManager for further tests
	world_manager.startUp();
	Saucer *s1 = new Saucer;
	Saucer *s2 = new Saucer;
	Saucer *s3 = new Saucer;
	world_manager.markForDelete(s1);
	// Should print to dragonfly.log that one object was deleted
	log_manager.writeLog("After update call:");
	world_manager.update();
	// Should print to dragonfly.log that two more objects were deleted
	log_manager.writeLog("After shutdown:");

	game_manager.shutDown();
}
