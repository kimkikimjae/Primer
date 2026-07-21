#include <iostream>
#include <string>

void ex_9_43(std::string& s, std::string oldVal, std::string newVal) {
	std::string::iterator it = s.begin();

	while (it != s.end()) {
		if (std::string(it, it + oldVal.size()) == oldVal) {
			s.erase(it, it + oldVal.size());
			it = s.insert(it, newVal.begin(), newVal.end());
			it += newVal.size();
		}
		else
			++it;
	}
}

int main() {
	
}