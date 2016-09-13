//
// ObjectList.h
//

#ifndef __OBJECTLIST_H__
#define __OBJECTLIST_H__

const int MAX_OBJECTS = 3;

// Engine includes
#include "Object.h"
#include "ObjectListIterator.h"

namespace df {

class ObjectListIterator;

class ObjectList {
private:
	int count;						// Count of objects in list
	Object *p_obj[MAX_OBJECTS];		// Array of pointers to objects

public:
	friend class ObjectListIterator;

	// Default constructor
	ObjectList();

	// Insert object pointer in list
	// Return 0 if okay, else -1
	int insert(Object *p_o);

	// Remove object pointer from list
	// Return 0 if found, else -1
	int remove(Object *p_o);

	// Clear list (setting count to 0)
	void clear();

	// Return count of number of objects in list
	int getCount() const;

	// Return true if list is empty, else false
	bool isEmpty() const;

	// Return true if list is full, else false
	bool isFull() const;
};

} // end namespace df
#endif // __OBJECTLIST_H__
