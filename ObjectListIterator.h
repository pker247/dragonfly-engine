//
// ObjectListIterator.h
//

#ifndef __OBJECTLISTITERATOR_H__
#define __OBJECTLISTITERATOR_H__

// Engine includes
#include "Object.h"
#include "ObjectList.h"

namespace df {

class ObjectList;

class ObjectListIterator {
private:
	ObjectListIterator();			// Must be given list when created
	int index;						// Index into list
	const ObjectList *p_list;		// List iterating over

public:
	// Create iterator, over indicated list
	ObjectListIterator(const ObjectList *p_l);

	// Set iterator to first item in the list
	void first();

	// Set iterator to next item in the list
	void next();

	// Return true if at end of the list
	bool isDone() const;

	// Return pointer to current Object, NULL if done/empty
	Object *currentObject() const;
};

} // end namespace df
#endif // __OBJECTLISTITERATOR_H__