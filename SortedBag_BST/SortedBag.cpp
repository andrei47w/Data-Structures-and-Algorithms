#include <iostream>
#include "SortedBag.h"
#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation r) {
    this->root = nullptr;
    this->nr_elems = 0;
    this->rel = r;
}

void SortedBag::add(TComp e) {
    Node *new_n = new Node;
    new_n->info = e;
    new_n->left = nullptr;
    new_n->right = nullptr;

    Node *current = this->root;
    Node *prev = nullptr;
    while (current != nullptr) {
        prev = current;
        if (this->rel(current->info, e))
            current = current->right;
        else
            current = current->left;
    }

    if (prev == nullptr)
        this->root = new_n;
    else if (this->rel(prev->info, e))
        prev->right = new_n;
    else
        prev->left = new_n;
    this->nr_elems += 1;
}

bool SortedBag::remove(TComp e) {
    Node *current = this->root;
    Node *prev = nullptr;

    while (current != nullptr and current->info != e) {
        prev = current;
        if (this->rel(current->info, e))
            current = current->right;
        else
            current = current->left;
    }
    if (current == nullptr)
        return false;

    if (current->left == nullptr or current->right == nullptr) {
        Node *n_curr;
        if (current->left == nullptr)
            n_curr = current->right;
        else
            n_curr = current->left;

        if (prev == nullptr) {
            delete current;
            this->root = n_curr;
            this->nr_elems -= 1;
            return true;
        }

        if (current == prev->left)
            prev->left = n_curr;
        else
            prev->right = n_curr;
        this->nr_elems -= 1;
        delete current;
        return true;
    } else {
        Node *p = nullptr;
        Node *temp;

        temp = current->right;
        while (temp->left != nullptr) {
            p = temp;
            temp = temp->left;
        }
        if (p != nullptr)
            p->left = temp->right;
        else
            current->right = temp->right;
        current->info = temp->info;
        delete temp;
        this->nr_elems -= 1;
        return true;
    }
}

bool SortedBag::search(TComp elem) const {
    Node *current = this->root;
    bool found = false;
    while (current != nullptr and !found) {
        if (current->info == elem)
            found = true;
        else if (this->rel(current->info, elem))
            current = current->right;
        else
            current = current->left;
    }
    return found;
}

int SortedBag::nrOccurrences(TComp elem) const {
    Node *current = this->root;
    int count = 0;
    while (current != nullptr) {
        if (current->info == elem)
            count++;
        if (this->rel(current->info, elem))
            current = current->right;
        else
            current = current->left;
    }
    return count;
}

int SortedBag::size() const {
//    int *viz = new int(this->nr_elems);
    return this->nr_elems;
}

bool SortedBag::isEmpty() const {
    if (this->nr_elems == 0)
        return true;
    return false;
}

SortedBagIterator SortedBag::iterator() const {
    return SortedBagIterator(*this);
}

SortedBag::~SortedBag() {
    SortedBag::delete_tree(this->root);
}

void SortedBag::delete_tree(Node *r) {
    if (r == nullptr)
        return;
    SortedBag::delete_tree(r->left);
    SortedBag::delete_tree(r->right);
    delete r;
}

// BC Theta(1) BST is empty
// WC Theta(n^2 + n) BST is not empty
// Total => O(n^2)
int SortedBag::elementsWithMinimumFrequency() const {
    if (this->isEmpty()) return 0;

    int viz[nr_elems];
    Node *current = this->root;
    Node *prev = nullptr;
    int count = 0, pos = 0, min_occ = nr_elems + 1;

    while (current != nullptr) {
        if (prev && prev->info != current->info) viz[pos++] = this->nrOccurrences(current->info);
        prev = current;
        current = current->right;
    }
    current = this->root;
    while (current != nullptr) {
        if (prev && prev->info != current->info) viz[pos++] = this->nrOccurrences(current->info);
        viz[pos++] = this->nrOccurrences(current->info);
        prev = current;
        current = current->left;
    }

    for (int i = 0; i < pos; i++) {
        if (viz[i] == min_occ) count++;
        else if (viz[i] < min_occ) {
            count = 1;
            min_occ = viz[i];
        }
    }

    return count;
}


