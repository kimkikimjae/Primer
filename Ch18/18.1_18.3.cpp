#include <iostream>
#include <vector>
#include <fstream>
#include <memory>

using namespace std;

void ex_18_1() {
	// (a) typeof(r) == range_error
	// (b) typeof(*p) == exception

	// if we throw 'p' itself instead of '*p', then the type of the exception object would be exception*
}

void ex_18_2() {
	// vector<int> v would be deleted safely cuz it is based on STL, which means that it assures the extinction of the identifier of that type,
		// and this concept is samely applied to - ifstream in.

	// but int *p is initialized with 'new' and this means that if any exception occurs after the declaration of p, there's no way 
		// to delete it after the going out of that scope of - void exercise.
}


void ex_18_3() {
	/* 1st
	* cover such a raw built-int type with smart-pointer type.
	* it is structured in standard library and declared as local value, so its destructor is called when we get an out of this scope.
	*/
	int* b, * e;				// from parameters of - void exercise(int* b, int* e).
	vector<int> v(b, e);

	// instead of using : int* p = new int[v.size()],
	unique_ptr<int[]> p(new int[v.size()]);
	
	// or, we can include that pointer p as a member of specific class type and delete it when that class identifier's destructor is called.

	
	/* 2nd
	* build try - catch scope for exception.
	*/

	int* ip = new int[5];
	try {
		// occurs an exception here.
	}
	catch (...) {
		delete[] ip;
		throw;
	}

	delete[] ip;
}