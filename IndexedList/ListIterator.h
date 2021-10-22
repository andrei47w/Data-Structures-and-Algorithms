#pragma once
#include "IndexedList.h"
#include "Node.h"

class IndexedList;

class ListIterator{
    //DO NOT CHANGE THIS PART
	friend class IndexedList;
private:
    const IndexedList& list;
    int pos;
    ListIterator(const IndexedList& lista);
public:
    void first();
    void next();
    bool valid() const;
    TElem getCurrent() const;

};

