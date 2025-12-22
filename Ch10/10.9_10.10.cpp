#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

// 10.9
void elimDups(vector<string>& words) {
	for (const string& wds : words) cout << wds << " ";
	cout << '\n';
	sort(words.begin(), words.end());
	auto it = unique(words.begin(), words.end());
	words.erase(it, words.end());
	for (const string& wds : words) cout << wds << " ";
	cout << '\n';
}

int main() {
	vector<string> words = { "Hello", "Dello", "Hello", "Yolo", "maYo", "Yolo" };
	elimDups(words);
	return 0;
}

// 10.10
// unique in <algorithms> does not erase itself elements in container and they are removed by container's own erase.