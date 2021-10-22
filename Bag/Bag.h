#pragma once
//DO NOT INCLUDE BAGITERATOR
#include <utility>

//DO NOT CHANGE THIS PART
typedef int TElem;
typedef int TFreq;
typedef std::pair<TElem, TFreq> TPair;
#define NULL_TVALUE -11111
#define NULL_TELEM pair<TKey, TFreq>(-11111, -11111)
const double HASH_LOAD_FACTOR = 0.7;
const int MULTIPLYING_FACTOR = 2;
const int INITIAL_HASH_TABLE_SIZE = 50;
class BagIterator;
struct Node {
    TPair keyValuePair;
    Node* nextNode = NULL;
};

class Bag {

private:
    int numberOfPairs;
    int numberOfElem;
    int numberOfPositions;
    int hashConstant; // used in the hash function
    Node** hashTable{}; // this will store the "heads" of the linked lists


	//DO NOT CHANGE THIS PART
	friend class BagIterator;
public:
	//constructor
	Bag();

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator() const;

	//checks if the bag is empty
	bool isEmpty() const;

	//destructor
	~Bag();

    int hashFunction(TElem originalKey) const;

    void addToLinkedList(Node *&linkedListHead, TElem elementKey, TFreq elementFreq);

    //adds an element to the bag
    void add(TElem elem);

    bool checkIfOverloaded();

    void resizeHashTable();

    void deleteHashTable(Node **&hashTable, int numberOfPositions);

    void deleteLinkedList(Node *&linkedListHead);

    Node *searchInLinkedList(int positionInHashTable, TElem searchedKey) const;

    //removes one occurrence of an element from a bag
    //returns true if an element was removed, false otherwise (if e was not part of the bag)
    bool remove(TElem c);

    void removeLinkedListHead(int positionInHashTable);

    Node *getNodeBeforeKey(int positionInHashTable, TElem searchedKey) const;

    void removeFromLinkedList(Node *positionBeforeKey);

    //checks if an element appears is the bag
    bool search(TElem c) const;

    //returns the number of occurrences for an element in the bag
    int nrOccurrences(TElem c) const;
};