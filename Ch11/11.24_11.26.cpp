#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

// 11.24
// It creates an element of which value shows [key = 0, mapped = 1].

// 11.25
// undefined action on vector cause' it has no preallocated element size.

// 11.26
void ex_11_26() {
	map<string, int> m;
	// key_type = std::string
	// mapped_type = int
	// value_type = std::pair<std::string, int>

	auto it = m["first"];
	// type of it = int && it = 0
	if (it == 0) cout << "0" << endl;
	else cout << "what" << endl;
}

int main()
{
	ex_11_26();
	return 0;
}

// test syntax for using jetriders...