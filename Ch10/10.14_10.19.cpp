#include <iostream>
#include <functional>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

bool isShorter(const string& s1, const string& s2) {
	return s1.size() < s2.size();
}

void elimDups(vector<string>& words) {
	stable_sort(words.begin(), words.end(), isShorter);
	auto it = unique(words.begin(), words.end());
	for (const string& s : words) cout << s << " ";
	cout << '\n';
}

// 10.14
void ex_10_14() {
	[](const int& a, const int& b) {return a + b; };
}

// 10.15
void ex_10_15(int& a) {
	[&a](const int& b) {return a + b; };
}

// 10.16
void biggies(vector<string>& words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {return a.size() < b.size(); });
	auto it = find_if(words.begin(), words.end(), [sz](const string& s) {return s.size() >= sz; });
	/* omitted this process */
	for_each(it, words.end(), [](const string& s) {cout << s << ' '; });
	cout << endl;
}

// 10.17
class Sales_data {
public:
	Sales_data() {};
	string isbn;
	~Sales_data() {};
};

void ex_10_17() {
	vector<Sales_data> vec; // arbitrary setting
	auto f = [](const Sales_data& a, const Sales_data& b) {return a.isbn < b.isbn; };
	sort(vec.begin(), vec.end(), f);
}

// 10.18
void biggies2(vector<string>& words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {return a.size() < b.size(); });
	auto it = partition(words.begin(), words.end(), [sz](const string& s) {return s.size() >= sz; });
	/* omitted this process */
	for_each(words.begin(), it, [](const string& s) {cout << s << ' '; });
	cout << endl;
}

// 10.19
void biggies3(vector<string>& words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {return a.size() < b.size(); });
	auto it = stable_partition(words.begin(), words.end(), [sz](const string& s) {return s.size() >= sz; });
	/* omitted this process */
	for_each(words.begin(), it, [](const string& s) {cout << s << ' '; });
	cout << endl;
}