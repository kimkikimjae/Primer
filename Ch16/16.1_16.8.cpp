#include <iostream>
#include <functional>
#include <vector>
#include <list>

using namespace std;


void ex_16_1() {
	// what is instantitaion? 
	// 설명 더 추가할 것(예정)
}

// for ex.16.2
template <typename T> int compare(const T& t1, const T& t2) {
	if (less<T>()(t1, t2)) return -1;
	if (less<T>()(t2, t1)) return 1;
	return 0;
}
void ex_16_2() {
	int a = 10, b = 20;
	int res = compare(a, b);
	cout << res << '\n';
}



void ex_16_3() {
	// Sales_data.h 가져오시고
}


// for ex.16.4
template <typename T> void find(typename T::iterator it, const T& v) {
	cout << "finding key : ";
	typename T::value_type value;
	cin >> value;

	while (it != v.end()) {
		if (*it == value) {
			cout << "value exists!\n";
			return;
		}
		else ++it;
	}

	cout << "value does not exist!\n";
}
void ex_16_4() {
	vector<int> vec{ 1,2,3,4,5 };
	find(vec.begin(), vec);
	list<string> li{ "aaa", "bbb", "ccc", "dddd" };
	find(li.begin(), li);
}

