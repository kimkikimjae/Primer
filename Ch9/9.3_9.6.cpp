#include <iostream>
#include <vector>
#include <list>

void ex_9_3() {
	// iterator range : [ start, end )		: including start iterator's value but not end's value, rather it contains ** (end - 1)'s value **.
	// so we can know this expression like [ start, end - 1 ], which means this expression shows the value of start ~ end -1.

	// suppose that we have a vector which contains values with [1, 2, 3, 4, 5], and here the start iterator would point to head part that has value of 1.
	// in STL, the iterator name 'end' does not mean the last value of its container, rather it does 'the out of range of container', 
		// so it(end) does not point to the value of 5. it points to next to of value 5, the out-range of appropriate container index.
		// 
	// In this case, (end -1) iterator points to the value of 5, so if you want to read the correct value in safe way, do not forget you do not have to read 'end' itself.
}

bool ex_9_4(std::vector<int>& vec, int key, std::vector<int>::iterator it1, std::vector<int>::iterator it2) {
	if (it1 >= it2) return false;
	if (it1 < vec.begin() || it2 >vec.end()) return false;

	for (auto it = it1; it != it2; ++it) {
		if (*it == key) return true;
	}

	return false;
}

std::vector<int>::iterator ex_9_5(std::vector<int>& vec, int key, std::vector<int>::iterator it1, std::vector<int>::iterator it2){
	if (it1 >= it2) return vec.end();
	if (it1 < vec.begin() || it2 >vec.end()) return vec.end();

	for (auto it = it1; it != it2; ++it) {
		if (*it == key) return it;
	}

	return vec.end();
}

void ex_9_6() {
	// STL list<T> has no '.end()' iterator member.
	// it only has '.begin()'
}


int main() {
	std::vector<int> vec{ 1,2,3,4,5 };
	std::vector<int>::iterator it = ex_9_5(vec, 5, vec.begin(), vec.end());

	if (it != vec.end()) std::cout << *it << '\n';

	return 0;
}