#include <iostream>
#include <functional>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

// 10.20
bool is_true(const string& s1) {
	if (s1.empty()) return false;
	else return true;
}
bool length_five(const string& s1) {
	if (s1.size() >= 5) return true;
	else return false;
}

void ex_10_20() {
	vector<string> vec{ "aaaaaa", "cccccc", "ddd", "eeee", "\0", "bbbbbb", "\0" };
	auto res = count_if(vec.begin(), vec.end(), [](const string& s) {return s.size() >= 6; });
	cout << res << endl;
	cout << "\n";
}

// 10.21
void ex_10_21() {
	int a = 3;
	auto f = [&]() -> bool {
		for (; a > 0; --a) {
			if (a) cout << "not 0 yet!\n";
			else return true;
		}
	};
	/* test multiple times */
	f();
	f();
	f();
	cout << a << endl;
}

int main()
{
	ex_10_20();
	ex_10_21();
	list<int> list1{ 1, 3, 5, 7 };
	list<int> list2{ 2, 4, 6, 8 };
	list1.merge(list2);
	for (const int& i : list1) cout << i << ' ';

	return 0;
}

