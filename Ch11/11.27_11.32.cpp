#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <iterator>
#include <vector>

// 11.24.
void ex_11_24() {
	// m has nothing at first.
	std::map<int, int> m;

	// when you implement [] operation, map automatically makes memory for element which has key == 0.
	// and that element has value == 1.
	m[0] = 1;
}

// 11.25.
void ex_11_25() {
	std::vector<int> v;
	// unlike map, vector must have its own element memories before value allocation.
	// below code is not error at grammar check, but makes a trouble at running.
	v[0] = 1;
}

