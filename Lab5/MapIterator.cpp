#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;

MapIterator::MapIterator(const Map& d) : map(d){
	this->first();
}

void MapIterator::first() {
	for (int i = 0; i < map.numberOfPositions; i++) {
		if (map.hashTable[i] != nullptr) {
			this->positionInHashTable = i;
			break;
		}
	}

	this->positionInLinkedList = map.hashTable[this->positionInHashTable];
}

void MapIterator::next() {
	if (!valid()) {
		throw exception("Invalid position");
	}

	if (this->positionInLinkedList->nextNode != nullptr) {
		this->positionInLinkedList = this->positionInLinkedList->nextNode;
	}
	else {
		this->positionInHashTable++;
		while (this->positionInHashTable < map.numberOfPositions && map.hashTable[this->positionInHashTable] == nullptr) {
			this->positionInHashTable++;
		}

		if (this->positionInHashTable == map.numberOfPositions) {
			this->positionInLinkedList = nullptr; // the iterator becomes invalid
		}
		else {
			this->positionInLinkedList = map.hashTable[this->positionInHashTable];
		}
	}
}

TElem MapIterator::getCurrent(){
	if (!valid()) {
		throw std::exception("Invalid position");
	}
	return this->positionInLinkedList->keyValuePair;
}

bool MapIterator::valid() const {
	return this->positionInHashTable < map.numberOfPositions && this->positionInLinkedList != nullptr;
}



