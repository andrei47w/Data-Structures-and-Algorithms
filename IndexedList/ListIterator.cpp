#include "ListIterator.h"
#include <exception>
#include <iostream>

ListIterator::ListIterator(const IndexedList& list) : list(list){
    first();
}

void ListIterator::first(){
    this->pos = list.head;
}

void ListIterator::next(){
    if(this->pos == NULL)
        throw std::exception("\nInvalid node!\n");
    this->pos = list.next[this->pos];
}

bool ListIterator::valid() const{
    if(this->pos != NULL)
        return true;
    return false;
}

TElem ListIterator::getCurrent() const{
    if (this->pos == NULL)
        throw std::exception("\nInvalid node!\n");
    return list.elem[this->pos];
}