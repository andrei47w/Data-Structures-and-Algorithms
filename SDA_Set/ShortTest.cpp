#include "ShortTest.h"
#include <assert.h>
#include <iostream>
#include "Set.h"
#include "SetIterator.h"


void testAll() {
	Set s;
	assert(s.isEmpty() == true);
	assert(s.size() == 0); 
	assert(s.add(5)==true);
	assert(s.add(1)==true);
	assert(s.add(10)==true);
	assert(s.add(7)==true);
	assert(s.add(1)==false);
	assert(s.add(10)==false);
	assert(s.add(-3)==true);
	assert(s.size() == 5);
	assert(s.search(10) == true);
	assert(s.search(16) == false);
	assert(s.remove(1) == true);
	assert(s.remove(6) == false);
	assert(s.size() == 4);

	SetIterator it = s.iterator();
	it.first();
	int sum = 0;
	while (it.valid()) {
		TElem e = it.getCurrent();
		sum += e;
		it.next();
	}
	assert(sum == 19);

	// extra operation tests
    SetIterator it2 = s.iterator();
    /// current elements: 5, -3, 10, 7

    it2.first();
    it2.jumpForward(1);
    assert(it2.getCurrent() == -3);

    it2.first();
    it2.jumpForward(2);
    assert(it2.getCurrent() == 10);

    it2.first();
    it2.jumpForward(3);
    assert(it2.getCurrent() == 7);

    bool exceptionThrown = false;
    try {
        it2.first();
        it2.jumpForward(4);
      } catch(...) {
        exceptionThrown = true;
      } assert(exceptionThrown);

    exceptionThrown = false;
    try {
        it2.first();
        it2.jumpForward(-2);
    } catch(...) {
        exceptionThrown = true;
    } assert(exceptionThrown);

    exceptionThrown = false;
    try {
        it2.first();
        it2.jumpForward(0);
    } catch(...) {
        exceptionThrown = true;
    } assert(exceptionThrown);
}

