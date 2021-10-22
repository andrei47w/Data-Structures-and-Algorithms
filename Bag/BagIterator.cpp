#include <exception>
#include <iostream>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag &c) : bag(c) {
    this->first();
}

void BagIterator::first() {
    for (int i = 0; i < bag.numberOfPositions; i++) {
        if (bag.hashTable[i] != nullptr) {
            this->positionInHashTable = i;
            break;
        }
    }

    this->positionInLinkedList = bag.hashTable[this->positionInHashTable];
    if (valid()) {
        this->tempFreq = bag.hashTable[this->positionInHashTable]->keyValuePair.second;
    }
}


void BagIterator::next() {
    if (!valid()) {
        throw exception("Invalid position");
    }

    if(this->tempFreq > 1) {
        this->tempFreq--;
        return;
    }

    if (this->positionInLinkedList->nextNode != nullptr) {
        this->positionInLinkedList = this->positionInLinkedList->nextNode;
        this->tempFreq = this->positionInLinkedList->keyValuePair.second;
    } else {
        this->positionInHashTable++;
        while (this->positionInHashTable < bag.numberOfPositions &&
               bag.hashTable[this->positionInHashTable] == nullptr) {
            this->positionInHashTable++;
        }

        if (this->positionInHashTable == bag.numberOfPositions) {
            this->positionInLinkedList = nullptr; // the iterator becomes invalid
        } else {
            this->positionInLinkedList = bag.hashTable[this->positionInHashTable];
            this->tempFreq = this->positionInLinkedList->keyValuePair.second;
        }
    }
}


bool BagIterator::valid() const {
    return this->positionInHashTable < bag.numberOfPositions && this->positionInLinkedList != nullptr;
}


TElem BagIterator::getCurrent() const {
    if (!valid()) {
        throw std::exception("Invalid position");
    }
    return this->positionInLinkedList->keyValuePair.first;
}
