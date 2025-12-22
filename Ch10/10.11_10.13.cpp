#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

// 10.11
bool isShorter(const string& s1, const string& s2) {
	return s1.size() < s2.size();
}

void elimDups(vector<string>& words) {
	stable_sort(words.begin(), words.end(), isShorter);
	auto it = unique(words.begin(), words.end());
	for (const string& s : words) cout << s << " ";
	cout << '\n';
}

// 10.12
class Sales_data {
public:
	Sales_data() {};
	string isbn;
	~Sales_data() {};
};

bool compareIsbn(const Sales_data& s1, const Sales_data& s2) {
	return s1.isbn < s2.isbn;
}

void ex_10_12() {
	vector<Sales_data> vec; // arbitrary setting
	sort(vec.begin(), vec.end(), compareIsbn);
}

// 10.13
bool is_true(const string& s1) {
	if (s1.empty()) return false;
	else return true;
}
bool length_five(const string& s1) {
	if (s1.size() >= 5) return true;
	else return false;
}

void ex_10_13() {
	vector<string> vec{ "aaaaa", "ccccc", "ddd", "eeee", "\0", "bbbbb", "\0" };
	auto it = partition(vec.begin(), vec.end(), is_true);
	vec.erase(it, vec.end());
	for (const string& s : vec) {
		if (length_five(s)) cout << s << " ";
	}
	cout << "\n";
}

