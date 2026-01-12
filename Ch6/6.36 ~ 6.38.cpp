#include <iostream>
#include <string>


// for all examples

std::string ary[10];


// 6.36.
std::string(&ex_6_36())[10];


// 6.37.
typedef std::string (&arr1)[10];
arr1 ex_6_37();

using arr2 = std::string(&)[10];
arr2 ex_6_37();

decltype(ary)& ex_6_37();


// 6. 38.
int odd[] = {1, 3, 5, 7, 9};
int even[] = { 2, 4, 6, 8, 10 };
decltype(odd)& arrPtr(int i) {
	return (i % 2) ? odd : even;
}