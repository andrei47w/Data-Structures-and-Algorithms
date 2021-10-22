#pragma once
//DO NOT INCLUDE SORTEDBAGITERATOR

//DO NOT CHANGE THIS PART
typedef int TElem;
typedef TElem TComp;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TELEM -11111

class SortedBagIterator;

const int INITIAL_CAPACITY = 127; // 7 levels
const int NONEXISTENT_POSITION = -1;


struct Node {
    TComp info;
    int left;
    int right;
    int parent;
};
const Node NULL_NODE = { NULL_TELEM, NONEXISTENT_POSITION, NONEXISTENT_POSITION, NONEXISTENT_POSITION };


class SortedBag {
	friend class SortedBagIterator;

private:
    Node* elements;
    int elementCount;
    int arrayCapacity;
    Relation relation;
    int rootPosition;
    int* nextEmpty;
    int firstEmpty; // index of the first empty position (used in nextEmpty)

    int findPositionOf(TComp elem) const;

    void addNewNode(TComp elem, int position, bool isLeftChild, int parentPosition);

    void resizeArrays();

    bool isLeftChild(int position) const;

    bool isRightChild(int position) const;

    int getPositionOfMaximum(int rootPosition) const;

    int getPositionOfMinimum(int rootPosition) const;

    void addToNextEmpty(int position);

    void removeWithNoSuccessors(int position);

    void removeWithOneSuccessor(int position, bool hasLeftChild);

    void removeWithTwoSuccessors(int position);

    void resetEmpty();

    void independentListsCopy(const SortedBag& originalSet);

    
public:
	//constructor
	SortedBag(Relation r);

	//adds an element to the sorted bag
	void add(TComp e);

	//removes one occurence of an element from a sorted bag
	//returns true if an eleent was removed, false otherwise (if e was not part of the sorted bag)
	bool remove(TComp e);

	//checks if an element appearch is the sorted bag
	bool search(TComp e) const;

	//returns the number of occurrences for an element in the sorted bag
	int nrOccurrences(TComp e) const;

	//returns the number of elements from the sorted bag
	int size() const;

	//returns an iterator for this sorted bag
	SortedBagIterator iterator() const;

	//checks if the sorted bag is empty
	bool isEmpty() const;

	//destructor
	~SortedBag();

    SortedBag(const SortedBag& originalSet);

    SortedBag& operator = (const SortedBag& originalSet);
};