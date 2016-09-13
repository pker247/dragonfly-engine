//
// GameManager.cpp
//

// System includes
#include <Windows.h>

// Engine includes
#include "GameManager.h"
#include "LogManager.h"
#include "Clock.h"
#include "WorldManager.h"
#include "EventStep.h"

namespace df {

GameManager::GameManager() {
	setType("GameManager");

	game_over = false;
	frame_time = FRAME_TIME_DEFAULT;
}

void GameManager::operator=(GameManager const&) {

}

GameManager & GameManager::getInstance() {
	static GameManager game_manager;
	return game_manager;
}

int GameManager::startUp() {
	// Start up all other managers
	LogManager &log_manager = LogManager::getInstance();
	log_manager.startUp();
	WorldManager &world_manager = WorldManager::getInstance();
	world_manager.startUp();

	Manager::startUp();

	timeBeginPeriod(1);

	return 0;
}

void GameManager::shutDown() {
	// Shut down all other managers
	WorldManager &world_manager = WorldManager::getInstance();
	world_manager.shutDown();
	LogManager &log_manager = LogManager::getInstance();
	log_manager.shutDown();

	Manager::shutDown();

	// Tell game objects the game is over
	setGameOver();

	timeEndPeriod(1);
}

void GameManager::run() {
	Clock clock;
	int loop_time;
	int loop_num = 1;
	WorldManager &world_manager = WorldManager::getInstance();

	// Run game loop
	while (!game_over) {
		clock.delta();
		// Get input
		// Update world state
		world_manager.update();
		// Send each object a Step Event
		ObjectList allObjects = world_manager.getAllObjects();
		EventStep s(loop_num);
		ObjectListIterator iterator(&allObjects);
		while (!iterator.isDone()) {
			iterator.currentObject() -> eventHandler(&s);
			iterator.next();
		}
		// Draw current scene to back buffer
		// Swap back buffer to current buffer
		if (loop_num = 165) {
			setGameOver();
		}
		loop_num++;
		loop_time = clock.split();
		Sleep(FRAME_TIME_DEFAULT - loop_time);
	}
	
}

void GameManager::setGameOver(bool new_game_over) {
	game_over = new_game_over;
}

bool GameManager::getGameOver() const {
	return game_over;
}

int GameManager::getFrameTime() const {
	return FRAME_TIME_DEFAULT;
}

} // end namespace df