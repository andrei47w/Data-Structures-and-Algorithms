#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
    this->first();
}

TComp SortedBagIterator::getCurrent() {
    if (this->current == nullptr)
        throw exception();
    return this->current->info;
}

bool SortedBagIterator::valid() {
	if (this->current == nullptr)
        return false;
    return true;
}

void SortedBagIterator::next() {
    if (this->current == nullptr)
        throw exception();

    Node *n = this->stack.top();
    this->stack.pop();
    if (n->right != nullptr){
        n = n->right;
        while (n != nullptr) {
            this->stack.push(n);
            n = n->left;
        }
    }
    if (this->stack.empty())
        this->current = nullptr;
    else
        this->current = this->stack.top();

}

void SortedBagIterator::first() {
    while (!this->stack.empty())
        this->stack.pop();

    Node *n = bag.root;
    while (n != nullptr) {
        this->stack.push(n);
        n = n->left;
    }
    if (this->stack.empty())
        this->current = nullptr;
    else
        this->current = this->stack.top();
}

