//
// GameManager.h
//

#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

// Engine includes
#include "Manager.h"

namespace df {

// Default frame rate (game loop time)
const int FRAME_TIME_DEFAULT = 33;

class GameManager : public Manager {
private:
	GameManager();							// Private since singleton
	GameManager(GameManager const&);		// Don't allow copy
	void operator=(GameManager const&);		// Don't allow assignment
	bool game_over;							// True, then game loop should stop
	int frame_time;							// Target time per game loop, in milliseconds

public:
	// Get the singleton instance of the GameManager
	static GameManager &getInstance();

	// Startup all GameManager services
	int startUp();

	// Shut down GameManager services
	void shutDown();

	// Run game loop
	void run();

	// Set game over status to indicated value
	// If true (default), will stop game loop
	void setGameOver(bool new_game_over = true);

	// Get game over status
	bool getGameOver() const;

	// Return frame time
	// Frame time is target time for game loop, in milliseconds
	int getFrameTime() const;
};

} // end namespace df
#endif // __GAMEMANAGER_H__