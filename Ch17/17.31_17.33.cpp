#include <iostream>
#include <random>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void ex_17_31() {
	// if we declare those engine (e) and distribution (b) in do-while, then they are newely made by every loop,
	// which means that engine and distribution always make same return value and it has an effect on the value of first(bool type identifier).
	// after all, if that first's value has set as 1, then every game always be started as cpu player go first and vice versa.
}

void ex_17_32() {
	// compiler cannot recognize of the existence of 'resp' cuz its lifetime ends only to the last scope of 'do'.
}

const string& transform(const string& s, const multimap<string, string>& m) {
	auto map_it = m.equal_range(s);

	if (map_it.first == map_it.second)
		return s;
	else
	{
		static default_random_engine e(time(0));

		uniform_int_distribution<unsigned> rd(0, m.count(s) - 1);
		int rand_num = rd(e);

		for (int i = 0; i < rand_num; ++i)
			++map_it.first;

		return map_it.first->second;
	}
}

multimap<string, string> buildMap(ifstream& map_file) {
	multimap<string, string> trans_map;
	string key, value;
	while (map_file >> key && getline(map_file, value))		 
		if (value.size() > 1) 
			trans_map.insert(make_pair(key, value));
		else
			throw runtime_error("no rule for " + key);

	return trans_map;
}

void word_transform(ifstream& map_file, ifstream& input) {
	auto trans_map = buildMap(map_file);			
	string text;
	while (getline(input, text)) {
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word) {
			if (firstword) firstword = false;
			else cout << " ";
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

void ex_17_33() {
	// used multimap to keep many values with one key.
}