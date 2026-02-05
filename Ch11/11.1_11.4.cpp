#include <iostream>
#include <map>
#include <vector>
#include <string>

// 11.1.
// vector : Sequential container. No automatic elements sorting.
// map : Associative container. Automatic elements sorting. It has a pair of key and value.


// 11.2.
// list : When you code some logic that needs much of middle insertion or deleting. It requires O(1) time complexity.
// vector : Every and anytime, especially whenever you don't need any special implementations. It is like array in C, and vector is easier than C array.
// deque : It complements limits of list, especially when you insert/erase elements of both side of deque, front and end.
// map : It basically uses pair type, so we can use it without declaring some class or struct like we did in C. 
// set : It just saves elements without duplication, so it is good when you just check whether the element does exist, or not.


// 11.3.
void ex_11_3() {
	// collection of words' occurence.
	std::map<std::string, int> word_count;
	// input strings.
	std::string to_find;
	while (std::cin >> to_find) ++word_count[to_find];
	for (const std::map<std::string, int>::value_type& p : word_count)
		std::cout << "The word \'" << p.first << "\' occurs " << p.second << " " <<
		(p.second > 1 ? "times!" : "time!") << '\n';
}


// 11.4.
void ex_11_4() {
	// collection of words' occurence.
	std::map<std::string, int> word_count;
	// input strings.
	std::string to_find;
	while (std::cin >> to_find) {
		std::string& temp = to_find;
		std::string::size_type sz = temp.size();
		if (temp[sz - 1] == '.' || temp[sz - 1] == ',') temp.pop_back();
		for (int i = 0; i < temp.size(); ++i) {
			temp[i] = std::tolower(temp[i]);
		}
		++word_count[to_find];
	}
	for (const std::map<std::string, int>::value_type& p : word_count)
		std::cout << "The word \'" << p.first << "\' occurs " << p.second << " " <<
		(p.second > 1 ? "times!" : "time!") << '\n';
}


int main() {
	// ex_11_3();
	ex_11_4();
	return 0;
}