
#include <exception>
#include "ListIterator.h"
#include "IteratedList.h"

#define INITCAPACITY 1000000

void IteratedList::resize() {
	TElem* new_elements = new TElem[capacity * 2];
	int* new_next = new int[capacity * 2];

	for (size_t i = 0; i < capacity; ++i) {
		new_elements[i] = elem[i];
		new_next[i] = next[i];
	}

	for (size_t i = capacity; i < capacity * 2 - 1; ++i)
		new_next[i] = i + 1;
	new_next[capacity * 2 - 1] = -1;

	delete[] elem;
	delete[] next;

    elem = new_elements;
	next = new_next;
	first_empty = capacity;
	capacity *= 2;
}

IteratedList::IteratedList() {
	capacity = INITCAPACITY;
	head = -1;
    first_empty = 0;
    nr_elem = 0;
    elem = new TElem[capacity];
	next = new int[capacity];

	for (size_t i = 0; i < capacity - 1; ++i)
		next[i] = i + 1;
	next[capacity - 1] = -1;
}

int IteratedList::size() const {
	return nr_elem;
}

bool IteratedList::isEmpty() const {
	return nr_elem == 0;
}

ListIterator IteratedList::first() const {
	return ListIterator(*this);
}

TElem IteratedList::getElement(ListIterator pos) const {
	if (!pos.valid())
		throw std::exception();
	return pos.getCurrent();
}

TElem IteratedList::remove(ListIterator& pos) {
}

ListIterator IteratedList::search(TElem e) const{
	auto iterator = first();

	while (iterator.valid() && iterator.getCurrent() != e)
		iterator.next();
	return iterator;
}

TElem IteratedList::setElement(ListIterator pos, TElem e) {
	if (!pos.valid())
		throw std::exception();

	TElem old_value = pos.getCurrent();
	int i = pos.current;
    elem[i] = e;

	return old_value;
}

void IteratedList::addToPosition(ListIterator& pos, TElem e) {
	if (!pos.valid())
		throw std::exception();
	if (first_empty == -1)
		resize();

	int current = pos.current;
	int new_position = first_empty;
	first_empty = next[first_empty];
    elem[new_position] = e;
	next[new_position] = next[current];
	next[current] = new_position;

	pos.next();
	nr_elem++;
}

void IteratedList::addToEnd(TElem e) {
}

void IteratedList::addToBeginning(TElem e) {
	if (first_empty == -1)
		resize();
	
	int new_position = first_empty;
	first_empty = next[first_empty];
	next[new_position] = head;
	head = new_position;
    elem[new_position] = e;
	nr_elem++;
}

IteratedList::~IteratedList() {
	delete[] elem;
	delete[] next;
}
