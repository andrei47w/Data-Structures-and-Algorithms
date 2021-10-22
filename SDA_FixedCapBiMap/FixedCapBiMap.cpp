#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"
#include <exception>

using namespace std;

FixedCapBiMap::FixedCapBiMap(int capacity) {
    if (capacity <= 0) throw exception();
    this->capacity = capacity;
    this->nr_elements = 0;
    this->elements = new TElem[capacity];
}

FixedCapBiMap::~FixedCapBiMap() {
    delete[] this->elements;
}

bool FixedCapBiMap::add(TKey c, TValue v) {
    if (this->capacity == this->nr_elements)
        throw exception();

    int index = 0;
    int count = 0;
    while (count < 2 && index < this->nr_elements) {
        if (this->elements[index].first == c)
            count++;
        index++;
    }
    if (count == 2)
        return false;
    else {
        this->elements[this->nr_elements].first = c;
        this->elements[this->nr_elements].second = v;
        this->nr_elements++;
        return true;
    }
}

ValuePair FixedCapBiMap::search(TKey c) const {
    ValuePair returnvalue;
    returnvalue.first = NULL_TVALUE;
    returnvalue.second = NULL_TVALUE;

    int count = 0;
    int index = 0;
    while (count < 2 && index < this->nr_elements) {
        if (this->elements[index].first == c) {
            if (count == 0) {
                returnvalue.first = this->elements[index].second;
            } else {
                returnvalue.second = this->elements[index].first;
            }
            count++;
        }
        index++;
    }

    return returnvalue;
}

bool FixedCapBiMap::remove(TKey c, TValue v) {
    int index = 0;
    bool found = false;
    while (index < this->nr_elements && !found) {
        if (this->elements[index].first == c && this->elements[index].second == v) found = true;
        else index++;
    }
    if (!found) return false;
    this->elements[index] = this->elements[this->nr_elements - 1];
    this->nr_elements--;
    return true;
}


int FixedCapBiMap::size() const {
    return this->nr_elements;
}

bool FixedCapBiMap::isEmpty() const {
    if (this->nr_elements == 0) return true;
    return false;
}

bool FixedCapBiMap::isFull() const {
    if (this->nr_elements == this->capacity) return true;
    return false;
}

FixedCapBiMapIterator FixedCapBiMap::iterator() const {
    return FixedCapBiMapIterator(*this);
}



