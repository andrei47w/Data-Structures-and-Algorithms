#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>

using namespace std;

Bag::Bag() {
    this->hashTable = new Node *[INITIAL_HASH_TABLE_SIZE];

    for (int i = 0; i < INITIAL_HASH_TABLE_SIZE; i++) {
        this->hashTable[i] = nullptr;
    }

    this->numberOfPairs = 0;
    this->numberOfElem = 0;
    this->numberOfPositions = INITIAL_HASH_TABLE_SIZE;
    this->hashConstant = INITIAL_HASH_TABLE_SIZE;
}

int Bag::hashFunction(TElem originalKey) const {
    if (originalKey < 0) {
        originalKey = -originalKey;
    }
    return originalKey % this->hashConstant;
}

void Bag::addToLinkedList(Node *&linkedListHead, TElem elementKey, TFreq elementFreq) {
    Node *newNode = new Node;
    newNode->keyValuePair = std::make_pair(elementKey, elementFreq);
    newNode->nextNode = linkedListHead;
    linkedListHead = newNode;
}

bool Bag::checkIfOverloaded() {
    return (double) (this->numberOfPairs / this->numberOfPositions) >= HASH_LOAD_FACTOR;
}

void Bag::deleteLinkedList(Node *&linkedListHead) {
    Node *temporaryNode;
    while (linkedListHead != nullptr) {
        temporaryNode = linkedListHead->nextNode;
        delete linkedListHead;
        linkedListHead = temporaryNode;
    }
}

void Bag::deleteHashTable(Node **&hashTable, int numberOfPositions) {
    // in the copy constructor, this part is called before actually allocating memory for the hash table
    // so it crashed when it got here;
    // we now ensure against that -> if the list isn't even allocated, we don't need to delete it
    if (hashTable == nullptr) {
        return;
    }

    for (int i = 0; i < numberOfPositions; i++) {
        this->deleteLinkedList(hashTable[i]);
    }
    delete[] hashTable;
}

void Bag::resizeHashTable() {
    Node **auxiliaryHashTable = new Node *[this->numberOfPositions * MULTIPLYING_FACTOR];
    Node *currentNode;
    int newPairKey;

    this->hashConstant *= MULTIPLYING_FACTOR; // this will change the hash function
    for (int i = 0; i < this->numberOfPositions * MULTIPLYING_FACTOR; i++) {
        auxiliaryHashTable[i] = NULL;
    }
    for (int i = 0; i < this->numberOfPositions; i++) {
        currentNode = this->hashTable[i];
        while (currentNode != NULL) {
            newPairKey = this->hashFunction(currentNode->keyValuePair.first);
            this->addToLinkedList(auxiliaryHashTable[newPairKey], currentNode->keyValuePair.first,
                                  currentNode->keyValuePair.second);
            currentNode = currentNode->nextNode;
        }
    }

    deleteHashTable(this->hashTable, this->numberOfPositions);
    this->numberOfPositions *= MULTIPLYING_FACTOR;
    this->hashTable = auxiliaryHashTable;
}

Node *Bag::searchInLinkedList(int positionInHashTable, TElem searchedKey) const {
    Node *currentNode = this->hashTable[positionInHashTable];

    while (currentNode != NULL) {
        if (currentNode->keyValuePair.first == searchedKey) {
            return currentNode;
        }
        currentNode = currentNode->nextNode;
    }

    return NULL;
}

void Bag::add(TElem c) {
    int positionInHashTable = this->hashFunction(c);

    if (this->hashTable[positionInHashTable] == NULL) {
        this->addToLinkedList(this->hashTable[positionInHashTable], c, 1);
        this->numberOfElem++;
        this->numberOfPairs++;
        if (checkIfOverloaded()) this->resizeHashTable();
    } else {
        Node *positionInLinkedList = this->searchInLinkedList(positionInHashTable, c);
        if (positionInLinkedList == NULL) {
            this->addToLinkedList(this->hashTable[positionInHashTable], c, 1);
            this->numberOfElem++;
            this->numberOfPairs++;
            if (checkIfOverloaded()) this->resizeHashTable();
            return;
        } else {
            positionInLinkedList->keyValuePair = std::make_pair(c, positionInLinkedList->keyValuePair.second +
                                                                   1); // update
            this->numberOfElem++;
        }
    }

    if (checkIfOverloaded()) this->resizeHashTable();
}

void Bag::removeLinkedListHead(int positionInHashTable) {
    Node *nextNodeCopy = this->hashTable[positionInHashTable]->nextNode;
    delete this->hashTable[positionInHashTable];
    this->hashTable[positionInHashTable] = nextNodeCopy;
}

Node *Bag::getNodeBeforeKey(int positionInHashTable, TElem searchedKey) const {
    Node *currentNode = this->hashTable[positionInHashTable];

    while (currentNode->nextNode != NULL) {
        if (currentNode->nextNode->keyValuePair.first == searchedKey) {
            return currentNode;
        }
        currentNode = currentNode->nextNode;
    }

    return NULL;
}

void Bag::removeFromLinkedList(Node *positionBeforeKey) {
    // next will always be != NULL
    Node *nextNextNodeCopy = positionBeforeKey->nextNode->nextNode;
    delete positionBeforeKey->nextNode;
    positionBeforeKey->nextNode = nextNextNodeCopy;
}

bool Bag::remove(TElem c) {
    int positionInHashTable = this->hashFunction(c);

    if (this->hashTable[positionInHashTable] == NULL) {
        return false;
    }

    if (this->hashTable[positionInHashTable]->keyValuePair.first == c) {
        if (this->hashTable[positionInHashTable]->keyValuePair.second - 1 > 0) {
            this->hashTable[positionInHashTable]->keyValuePair.second--;
            this->numberOfElem--;
            return true;
        } else {
            this->removeLinkedListHead(positionInHashTable);
            this->numberOfPairs--;
            this->numberOfElem--;
            return true;
        }
    }

    Node *positionBeforeKey = this->getNodeBeforeKey(positionInHashTable, c);
    if (positionBeforeKey == NULL) {
        return false;
    }

    if (positionBeforeKey->nextNode->keyValuePair.second - 1 > 0) {
        positionBeforeKey->nextNode->keyValuePair.second--;
        this->numberOfElem--;
    } else {
        this->removeFromLinkedList(positionBeforeKey);
        this->numberOfPairs--;
        this->numberOfElem--;
    }
    return true;
}


bool Bag::search(TElem c) const {
    int positionInHashTable = this->hashFunction(c);

    if (this->hashTable[positionInHashTable] == NULL) {
        return false;
    }

    Node *positionInLinkedList = this->searchInLinkedList(positionInHashTable, c);
    if (positionInLinkedList == NULL) {
        return false;
    }
    return true;
}

int Bag::nrOccurrences(TElem c) const {
    int positionInHashTable = this->hashFunction(c);

    if (this->hashTable[positionInHashTable] == NULL) {
        return 0;
    }

    Node *positionInLinkedList = this->searchInLinkedList(positionInHashTable, c);
    if (positionInLinkedList == NULL) {
        return 0;
    }
    return positionInLinkedList->keyValuePair.second;
}


int Bag::size() const {
    return this->numberOfElem;
}


bool Bag::isEmpty() const {
    return this->numberOfPairs == 0;
}

BagIterator Bag::iterator() const {
    return BagIterator(*this);
}


Bag::~Bag() {
    this->deleteHashTable(this->hashTable, this->numberOfPositions);
}

