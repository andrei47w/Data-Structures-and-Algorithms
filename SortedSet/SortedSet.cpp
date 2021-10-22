#include <iostream>
#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r) {
    head = nullptr;
    tail = nullptr;
    currentRelation = r;
    listLength = 0;
}

void SortedSet::insertBeforeNode(Node *rightNode, TComp info) {
    Node *newNode = new Node;
    newNode->info = info;
    newNode->nextNode = rightNode;

    if (rightNode == head) {
        rightNode->prevNode = newNode;
        newNode->prevNode = nullptr;
        head = newNode;
        return;
    }

    if (rightNode == nullptr) {
        newNode->prevNode = tail;
        tail->nextNode = newNode;
        tail = newNode;
        return;
    }

    newNode->prevNode = rightNode->prevNode;
    rightNode->prevNode->nextNode = newNode;
    rightNode->prevNode = newNode;
}

Node *SortedSet::getNodeWithInfo(TComp info) const {
    for (Node *listIterator = head; listIterator != nullptr; listIterator = listIterator->nextNode) {
        if (!currentRelation(listIterator->info, info) || listIterator->info == info) {
            return listIterator;
        }
    }

    return nullptr;
}

bool SortedSet::foundExactElement(Node *possiblePosition, TComp info) {
    return (possiblePosition != nullptr && possiblePosition->info == info);
}

bool SortedSet::removeFromListWithOneElement(TComp e) {
    if (head->info == e) {
        listLength--;
        delete head;
        head = tail = nullptr;
        return true;
    }
    return false;
}

void SortedSet::deleteNode(Node *elementPosition) {
    Node *nextNode = elementPosition->nextNode;
    Node *prevNode = elementPosition->prevNode;

    if (nextNode == nullptr) { // last element
        prevNode->nextNode = nullptr;
        tail = prevNode;
    } else if (prevNode == nullptr) { // first element
        nextNode->prevNode = nullptr;
        head = nextNode;
    } else {
        prevNode->nextNode = nextNode;
        nextNode->prevNode = prevNode;
    }

    delete elementPosition;
    listLength--;
}

bool SortedSet::add(TComp elem) {
    if (listLength == 0) { // empty list
        Node *newNode = new Node;
        newNode->info = elem;
        newNode->nextNode = nullptr;
        newNode->prevNode = nullptr;
        head = tail = newNode;

        listLength++;
        return true;
    }

    Node *positionOfElement;
    positionOfElement = getNodeWithInfo(elem);

    if (foundExactElement(positionOfElement, elem)) { // element already exists
        return false;
    } else { // normal add
        insertBeforeNode(positionOfElement, elem);
        listLength++;
        return true;
    }
}

bool SortedSet::remove(TComp elem) {
    if (listLength == 0) { // already empty
        return false;
    }

    if (listLength == 1) { // 1 element
        return removeFromListWithOneElement(elem);
    }

    // 2 >= elements
    auto elementPosition = getNodeWithInfo(elem);
    if (!foundExactElement(elementPosition, elem)) {
        return false;
    }
    deleteNode(elementPosition);
    return true;
}

bool SortedSet::search(TComp elem) const {
    return (foundExactElement(getNodeWithInfo(elem), elem));
}

int SortedSet::size() const {
    return listLength;
}

bool SortedSet::isEmpty() const {
    return listLength == 0;
}

SortedSetIterator SortedSet::iterator() const {
    return SortedSetIterator(*this);
}

SortedSet::~SortedSet() {
    Node *temporaryNode;
    while (head != nullptr) {
        temporaryNode = head->nextNode;
        delete head;
        head = temporaryNode;
    }
}

// Theta(n^2)
// best case is when there is no element which needs to be removed since it only parses through the nodes once -> n complexity
// worst case is when all elements need to be removed -> n^2 complexity
void SortedSet::filter(Condition cond) {
    int *list = new int[this->listLength];
    int pos = 0;
    for (Node *listIterator = head; listIterator != nullptr; listIterator = listIterator->nextNode) {
        if (!cond(listIterator->info)) list[pos++] = listIterator->info;
    }
    for (int i = 0; i < pos; i++) remove(list[i]);
    delete[] list;
}


