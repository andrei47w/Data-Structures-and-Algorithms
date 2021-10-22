#include "SetIterator.h"
#include "Set.h"
#include <exception>
#include <iostream>

using namespace std;


SetIterator::SetIterator(const Set &m) : set(m) {
    this->current = 0;
}
/// Theta(1)

void SetIterator::first() {
    this->current = 0;
}
/// Theta(1)


void SetIterator::next() {
    if (this->current >= this->set.nr_elements) throw exception();
    else this->current++;
}
/// Theta(1)


TElem SetIterator::getCurrent() {
    if (this->current >= this->set.nr_elements) throw exception();
    return this->set.elements[this->current];
}
/// Theta(1)


bool SetIterator::valid() const {
    if(this->current < this->set.nr_elements) return true;
    return false;
}
/// Theta(1)

//moves the current element from the iterator k steps forward, or makes the iterator invalid if there are less than k elements left in the Set.
//throws an exception if the iterator is invalid or if k is negative or zero
void SetIterator::jumpForward(int k) {
    if(k >= this->set.nr_elements - this->current || k <= 0) {
//        this->current = this->set.nr_elements;
        throw exception();
    }
    else this->current += k;
}
/// Theta(1)
/// Both worst and best cases have constant complexities


