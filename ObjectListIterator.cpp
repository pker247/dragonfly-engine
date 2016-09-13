//
// ObjectListIterator.cpp
//

// Engine includes
#include "ObjectList.h"
#include "ObjectListIterator.h"

namespace df {

ObjectListIterator::ObjectListIterator() {

}

ObjectListIterator::ObjectListIterator(const ObjectList * p_l) {
	p_list = p_l;
	first();
}

void ObjectListIterator::first() {
	index = 0;
}

void ObjectListIterator::next() {
	if (index < (p_list -> count)) {
		index++;
	}
}

bool ObjectListIterator::isDone() const {
	return (index == (p_list -> count));
}

Object* ObjectListIterator::currentObject() const {
	return p_list -> p_obj[index];
}

} // end namespace df
