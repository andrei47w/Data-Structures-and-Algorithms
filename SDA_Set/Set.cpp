#include "Set.h"
#include "SetITerator.h"
#include <exception>

using namespace std;

Set::Set() {
    this->nr_elements = 0;
    this->elements = new TElem[0];
}
/// Theta(1)

bool Set::add(TElem elem) {
    for (int i = 0; i < this->nr_elements; i++)
        if (this->elements[i] == elem)
            return false;
    TElem *new_elements = new TElem[nr_elements+1];
    for (int i = 0; i < this->nr_elements; i++)
        new_elements[i] = this->elements[i];
    delete[] this->elements;
    this->elements = new_elements;

    this->elements[this->nr_elements] = elem;
    this->nr_elements++;
    return true;
}
/// Theta(n)

bool Set::remove(TElem elem) {
    for (int i = 0; i < this->nr_elements; i++)
        if (this->elements[i] == elem) {
            this->elements[i] = this->elements[nr_elements - 1];
            this->nr_elements--;
            return true;
        }
    return false;
}
/// Theta(n)

bool Set::search(TElem elem) const {
    for (int i = 0; i < this->nr_elements; i++)
        if (this->elements[i] == elem)
            return true;
    return false;
}
/// Theta(n)


int Set::size() const {
    return this->nr_elements;
}
/// Theta(1)


bool Set::isEmpty() const {
    if (this->nr_elements == 0) return true;
    return false;
}
/// Theta(1)


Set::~Set() {
    delete[] this->elements;
}
/// Theta(1)


SetIterator Set::iterator() const {
    return SetIterator(*this);
}


