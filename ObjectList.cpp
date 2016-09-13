//
// ObjectList.cpp
//

// Engine include
#include "ObjectList.h"

namespace df {

ObjectList::ObjectList() {
	count = 0;
}

int ObjectList::insert(Object *p_o) {
	if (isFull()) {
		return false;
	}
	p_obj[count] = p_o;
	count++;
	return true;
}

int ObjectList::remove(Object *p_o) {
	for (int i = 0; i < count; i++) {
		if (p_obj[i] == p_o) {
			for (int j = i; j < count - 1; j++) {
				p_obj[j] = p_obj[j + 1];
			}
			count--;
			return true;
		}
	}
	return false;
}

void ObjectList::clear() {
	count = 0;
}

int ObjectList::getCount() const {
	return count;
}

bool ObjectList::isEmpty() const {
	if (count == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool ObjectList::isFull() const {
	if (count == MAX_OBJECTS) {
		return true;
	}
	else {
		return false;
	}
}

} // end namespace df