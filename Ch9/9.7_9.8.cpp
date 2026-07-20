#include <iostream>
#include <vector>
#include <cstring>

int main() {
	std::string s1 = "Hello World!";
	std::string s2 = "Good new to you";
	const char* cp = "Stately plumpback";


	// insert는 iterator + const char* 조합이 없다. 
	// 그냥 size_t index를 쓸 것.
	s1.insert(0, "yoyoyo");		
	// 근데 erase는 또 있다. 지랄맞은!
	s1.erase(s1.begin(), s1.begin() + std::string("yoyoyo").size());

	s1.assign(cp, 7);
	s1.assign(s2, 0, s2.size());
	std::cout << s1 << '\n';


	std::string::size_type pos = 0;
	std::string name("kim dkim yoyo uwkwm kimkikim");

	while ((pos = name.find("kim", pos)) != std::string::npos) {
		std::cout << "found kim at index : " << pos << '\n';
		++pos;
	}
	return 0;
}