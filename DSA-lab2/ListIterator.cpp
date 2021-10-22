#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

ListIterator::ListIterator(const SortedIndexedList& list) : list(list) {
	this->pos = list.head;
}

void ListIterator::first(){
	this->pos = list.head;
}

void ListIterator::next(){
	if(this->pos == NULL)
        throw exception("\nInvalid node!\n");
	this->pos = this->pos->next;
}

bool ListIterator::valid() const{
    if(this->pos != NULL)
        return true;
	return false;
}

TComp ListIterator::getCurrent() const{
	if (this->pos == NULL)
        throw exception("\nInvalid node!\n");
	return this->pos->info;
}


