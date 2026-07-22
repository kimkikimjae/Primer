#include <iostream>
#include <vector>
#include <list>
#include <string>


void ex_9_7() {
	// use vector<int>::size_type for index of vector.
	std::vector<int>::size_type idx = 5;
	std::vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::cout << vec[idx] << '\n';
}

void ex_9_8() {
	// use list<string>::value_type to read elements.
	std::list<std::string> mylist{ "aaa", "bbb", "ccc", "ddd", "eee" };
	std::list<std::string>::value_type rd = *mylist.begin();
	std::cout << rd << '\n';

	// if we write on it, we use list<string>::reference.
	std::list<std::string>::reference wr = mylist.back();
	wr = "fff";
	for (const std::string& s : mylist) std::cout << s << ' ';
}

int main() {
	ex_9_7();
	ex_9_8();

	return 0;
}