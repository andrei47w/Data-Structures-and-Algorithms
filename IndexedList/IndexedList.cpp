#include <exception>
#include <iostream>

#include "IndexedList.h"
#include "ListIterator.h"

void IndexedList::posValidator(int pos) const {
    if (isEmpty())
        throw std::exception("\nEmpty list!\n");

    if (pos < 0)
        throw std::exception("\nInvalid position!\n");

    if (pos >= this->length)
        throw std::exception("\nInvalid position!\n");
}


IndexedList::IndexedList() {
    this->length = 0;
}

int IndexedList::size() const {
    return length;
}


bool IndexedList::isEmpty() const {
    return this->head == NULL;
}

TElem IndexedList::getElement(int pos) const {
    posValidator(pos);

    auto current = this->head;
    int p = 0;

    while (current != NULL && p < pos) {
        current = next[current];
        p++;
    }

    return current;
}

TElem IndexedList::setElement(int pos, TElem e) {
    posValidator(pos);

    auto current = this->head;
    int p = 0;

    while (current != NULL && p < pos) {
        current = next[current];
        p++;
    }
    TElem old_info = current;
    current = e;

    return old_info;
}

void IndexedList::addToEnd(TElem e) {
    if (isEmpty()) {
        this->head = e;
    } else {
        auto current = this->head;
        int p = 0;
        while (p < this->length - 1) {
            current = next[current];
            p++;
        }
        next[current] = e;
    }
    this->length++;
}


void IndexedList::addToPosition(int pos, TElem e) {
    posValidator(pos);

    if (isEmpty()) {
        this->head = e;
        this->length++;
    } else {
        auto current = this->head;
        int p = 0;
        while (p < pos - 1) {
            current = next[current];
            p++;
        }
        if (pos == 0) {
            this->next[e] = current;
            this->head = e;
        } else {
            next[e] = next[current];
            next[current] = e;
        }
            this->length++;
    }
}


TElem IndexedList::remove(int pos) {
    posValidator(pos);

    if (pos == 0) {
        int nr = this->head;
        int prev = next[this->head];
        this->head = prev;
        this->length--;
        return nr;
    }

    auto current = this->head;
    int p = 0;

    while (current != NULL && p < pos - 1) {
        current = next[current];
        p++;
    }

    if (next[next[current]] == NULL) {
        int nr = next[current];
        next[current] = NULL;
        this->length--;
        return nr;
    }

    int nr = next[current];
    int prev = next[next[current]];
    next[current] = prev;
    this->length--;
    return nr;
}

int IndexedList::search(TElem e) const {
    auto current = this->head;
    int p = 0;
    while (current != NULL) {
        if (current == e)
            return p;
        current = next[current];
        p++;
    }
    return -1;
}

ListIterator IndexedList::iterator() {
    return ListIterator(*this);
}

IndexedList::~IndexedList() {
    auto current = this->head;
}

