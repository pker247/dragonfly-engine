//
// WorldManager.h
//

#ifndef __WORLDMANAGER_H__
#define __WORLDMANAGER_H__

// Engine includes
#include "Manager.h"
#include "ObjectList.h"

namespace df {

class WorldManager : public Manager {
private:
	WorldManager();							// Private (singleton)
	WorldManager(WorldManager const&);		// Don't allow copy
	void operator=(WorldManager const&);	// Don't allow assignment
	ObjectList updates;						// All Objects in world to update
	ObjectList deletions;					// All Objects in world to delete

public:
	// Get the one and only instance of the WorldManager
	static WorldManager &getInstance();

	// Start up game world (initialize everything to empty)
	// Return 0
	int startUp();

	// Shut down game world (delete all game world Objects)
	void shutDown();

	// Add Object to world
	// Return 0 if okay, else -1
	int insertObject(Object *p_o);

	// Remove Object from world
	// Return 0 if okay, else -1
	int removeObject(Object *p_o);

	// Return list of all Objects in world
	ObjectList getAllObjects() const;

	// Return list of all Objects in world matching type
	ObjectList objectsOfType(std::string type) const;

	// Update world
	// Delete obects marked for deletion
	void update();

	// Indicate Object is to be deleted at the end of current game loop
	// Return 0 if okay, else -1
	int markForDelete(Object *p_o);
};

} // end namespace df
#endif // __WORLDMANAGER_H__