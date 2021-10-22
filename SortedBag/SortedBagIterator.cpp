#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	this->first();
}

TComp SortedBagIterator::getCurrent() {
	if (this->valid() == false) {
		throw exception();
	}

	return this->bag.elements[this->position].info;
}

bool SortedBagIterator::valid() {
	return this->position >= 0 and this->position < this->bag.arrayCapacity and this->bag.elements[this->position].info != NULL_TELEM;
}

void SortedBagIterator::next() {

	if (this->valid() == false) {
		throw exception();
	}

	// it has a right-child
	if (this->bag.elements[this->position].right != NONEXISTENT_POSITION) {
		// the minimum from the right sub-tree (the first element larger than the current one)
		this->position = this->bag.getPositionOfMinimum(this->bag.elements[this->position].right);
	}

		// if it doesn't have a right-child, we need to go up the tree:
		//	- if the current node is a left-child => its parent is the next position
		//	- otherwise, we find the first value larger than the current one
	else {
		if (this->bag.isLeftChild(this->position) == true) {
			this->position = this->bag.elements[this->position].parent;
		}

		else {
			int auxPosition = this->bag.elements[this->position].parent;

			while (auxPosition >= 0 and this->bag.relation(this->bag.elements[auxPosition].info, this->bag.elements[this->position].info) == true) {
				if (auxPosition == 0) { // it's the 'maximum' element
					this->position = this->bag.arrayCapacity; // make the position invalid
					return;
				}
				auxPosition = this->bag.elements[auxPosition].parent;
			}
			this->position = auxPosition;
		}
	}
}

void SortedBagIterator::first() {
	this->position = this->bag.rootPosition;

	if (this->position == NONEXISTENT_POSITION) { // if the set is empty => no sense in having an iterator
		this->position = this->bag.arrayCapacity; // makes the position invalid
		return;
	}

	// the first position is the one of the minimum of the set
	this->position = this->bag.getPositionOfMinimum(this->position);
}

