#pragma once

#include "SortedSet.h"

//DO NOT CHANGE THIS PART
class SortedSetIterator {
    friend class SortedSet;

private:
    Node *currentNode{}; // the node associated with the current element
    const SortedSet &multime;

    SortedSetIterator(const SortedSet &m);

public:
    void first();

    void next();

    TElem getCurrent();

    bool valid() const;
};

