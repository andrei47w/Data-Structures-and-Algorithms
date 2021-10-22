#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

#include <exception>

SortedIndexedList::SortedIndexedList(Relation r) {
    this->rel = r;
    this->length = 0;
}

int SortedIndexedList::size() const {

    return this->length;
}

bool SortedIndexedList::isEmpty() const {
    if (this->head == NULL)
        return true;
    return false;
}

TComp SortedIndexedList::getElement(int i) const {

    if (isEmpty())
        throw exception("\nEmpty list!\n");

    if (i < 0)
        throw exception("\nInvalid position!\n");

    if (i >= this->length)
        throw exception("\nInvalid position!\n");

    auto current = this->head;
    int p = 0;

    while (current != NULL && p < i) {
        current = current->next;
        p++;
    }

    return current->info;
}

TComp SortedIndexedList::remove(int i) {

    if (isEmpty())
        throw exception("\nEmpty list!\n");

    if (i < 0)
        throw exception("\nInvalid position!\n");

    if (i >= this->length)
        throw exception("\nInvalid position!\n");

    Node* prev = NULL;

    if (i == 0) {
        TComp nr = this->head->info;
        prev = this->head->next;
        delete this->head;
        this->head = prev;
        this->length--;
        return nr;
    }


    auto current = this->head;
    int p = 0;

    while (current != NULL && p < i - 1) {
        current = current->next;
        p++;
    }

    if (current->next->next == NULL) {
        TComp nr = current->next->info;
        delete current->next;
        current->next = NULL;
        this->length--;
        return nr;
    }

    TComp nr = current->next->info;
    prev = current->next->next;
    delete current->next;
    current->next = prev;
    this->length--;
    return nr;
}

int SortedIndexedList::search(TComp e) const {
    auto current = this->head;
    int p = 0;
    while (current != NULL) {
        if (current->info == e)
            return p;
        current = current->next;
        p++;
    }
    return -1;
}

void SortedIndexedList::add(TComp e) {
    Node *node = new Node;
    node->info = e;
    node->next = NULL;

    if (isEmpty()) {
        this->head = node;
        this->length++;
    } else {
        if (this->rel(e, this->head->info)) {
            node->next = this->head;
            this->head = node;
            this->length++;
        } else {
            auto current = this->head;
            while (current->next != NULL && !this->rel(e, current->next->info)) {
                current = current->next;
            }
            node->next = current->next;
            current->next = node;
            this->length++;
        }
    }

}

void SortedIndexedList::filter(Condition cond) {
//because we go through the full list we don't have a baste/worst case case, meaning that the overall complexity is theta(n)
    if (isEmpty())
        throw exception("\nEmpty list!\n");

    Node* copy = NULL;

    while (this->head!=NULL && !cond(this->head->info)){
        copy = this->head->next;
        delete this->head ;
        this->head = copy;
        this->length--;
    }

    auto current = this->head;
    Node *prev = NULL;

    while (current != NULL) {
            if (!cond(current->info)) {
                copy = current->next;
                delete prev->next;
                prev->next = copy;
                current = copy;
                this->length--;
            } else {
                prev = current;
                current = current->next;
            }
        }
}

ListIterator SortedIndexedList::iterator() {
    return ListIterator(*this);
}

//destructor
SortedIndexedList::~SortedIndexedList() {
    auto current = this->head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
}
