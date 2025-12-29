#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

void ex_10_3()
{
	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	int res = accumulate(vec.begin(), vec.end(), 0);
	cout << res << endl;
}

// 10.4.
// third element's tpye is integer, so double type values' decimals gonna be cut into integer.

// 10.5.
// char sequentials also can be evaluated, but they should use begin() & end() pointer for arrays.
void ex_10_5() {
	char roster1[] = "aaaaa";
	char roster2[] = "aaaab";
	auto it1 = begin(roster1), it2 = begin(roster2);
	char* ed1 = end(roster1), *ed2 = end(roster2);
	bool res = equal(it1, ed1, it2);
	cout << boolalpha << res << endl;
}

int main() {
	ex_10_5();
	return 0;
}