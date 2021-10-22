#pragma once
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
typedef int TElem;
typedef TElem TComp;

typedef bool(*Relation)(TComp, TComp);

typedef bool (*Condition)(TComp);
//    where Condition is a function which takes as parameter an element and returns true or false depending on whether the element respects the condition.
//    Obs. add the following typedef to the beginning of SortedSet.h

#define NULL_TELEM -11111

class SortedSetIterator;

// ADT  SortedSet –having  elements  of  type TComp,  sorted  using  a  relation  on  the  elements and stored in a dynamic array.
// ADT SortedSet–using a DLL where elements are ordered based on a relation between the elements

struct Node {
    TComp info;
    Node *nextNode;
    Node *prevNode;
};

class SortedSet {
    friend class SortedSetIterator;

private:
    Node *head;
    Node *tail;
    Relation currentRelation;
    int listLength;

    void insertBeforeNode(Node *rightNode, TComp info);

    /*
        Inserts a new node before a given node
        Complexity:
            - BC/AC/WC: theta(1)
        Input:
            - The node before we need to insert (which can be nullptr, signifying that we append to the list)
            - The information of the new node
        Output:
            - The new node is added to the list at the given position
    */

    Node *getNodeWithInfo(TComp info) const;

    /*
        Determines the node which contains some information, or the one which would have been right after it (if
        it doesn't exist)
        Complexity:
            - BC: theta(1), when the element is on the first position
            - AC: theta(n)
            - WC: theta(n), when the element is on the last position
        Input:
            - The information of the node we search for
        Output:
            - The required node (can be nullptr if we don't find anything)
    */

    static bool foundExactElement(Node *possiblePosition, TComp info);

    /*
        Determines if a given node contains exactly the information that we want
        Complexity:
            - BC/AC/WC: theta(1)
        Input:
            - The node which might hold the information that we want
            - The information that we want
        Output:
            - True, if the information coincides
            - False, otherwise
    */

    bool removeFromListWithOneElement(TComp e);

    /*
        Removes an instance of an element from a one-element-list
        Complexity:
            - BC/AC/WC: theta(1)
        Input:
            - The information of the element that we want to remove
        Output:
            - True, if the element existed, in which case the instance of the element is removed
            - False, otherwise
    */

    void deleteNode(Node *elementPosition);
    /*
        Deletes a given Node and ensures the list isn't broken
        Complexity:
            - BC/AC/WC: theta(1)
        Input:
            - The node that we want to delete
        Output:
            - The node is deleted, the previous and next nodes are linked (if possible)
    */
public:
    //constructor
    SortedSet(Relation r);

    //adds an element to the sorted set
    //if the element was added, the operation returns true, otherwise (if the element was already in the set)
    //it returns false
    bool add(TComp e);


    //removes an element from the sorted set
    //if the element was removed, it returns true, otherwise false
    bool remove(TComp e);

    //checks if an element is in the sorted set
    bool search(TElem elem) const;


    //returns the number of elements from the sorted set
    int size() const;

    //checks if the sorted set is empty
    bool isEmpty() const;

    //returns an iterator for the sorted set
    SortedSetIterator iterator() const;

    // destructor
    ~SortedSet();

    //keeps in the sortedset only those elements that respect the given condition

    void filter(Condition cond);
};
