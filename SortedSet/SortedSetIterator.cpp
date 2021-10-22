#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet &m) : multime(m) {
    first();
}

// Theta(1)
void SortedSetIterator::first() {
    currentNode = multime.head;
}

// Theta(1)
void SortedSetIterator::next() {
    if (!valid()) {
        throw exception("Invalid position");
    }
    currentNode = currentNode->nextNode;
}

// Theta(1)
TElem SortedSetIterator::getCurrent() {
    if (valid()) {
        return currentNode->info;
    }
    throw exception("Invalid position");
}

// Theta(1)
bool SortedSetIterator::valid() const {
    return (currentNode != nullptr);
}

