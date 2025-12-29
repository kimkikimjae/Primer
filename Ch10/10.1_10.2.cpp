#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

void ex_10_1(){
	vector<int> vec;
	int arr[10] = { 1, 1, 3, 2, 4, 1, 3, 3, 2, 2};
	for (const int& i : arr) vec.push_back(i);
	auto it = count(vec.begin(), vec.end(), 1);
	cout << it << endl;
}

void ex_10_2() {
	list<string> lis;
	string arr[5] = { "aaa", "bbb", "ccc", "aaa", "aaa" };
	for (const string& s : arr) lis.push_back(s);
	auto it = count(lis.begin(), lis.end(), "aaa");
	cout << it << endl;
}

int main() {
	ex_10_1();
	ex_10_2();
	return 0;
}