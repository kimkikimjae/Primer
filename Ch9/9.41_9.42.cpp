#include <iostream>
#include <vector>
#include <cstring>
void ex_9_41(std::vector<char>& vec) {
	std::vector<char>::iterator start = vec.begin(), end = vec.end();
	std::string s(start, end);
	std::cout << s << '\n';
}

void ex_9_42(char* pc) {
	// rather than reading a character at of each time, just read an entire word (including space ' ') and push it into string.
	
	char* p1 = pc;
	char* p2 = pc;

	// instead of doing below, 
	std::string s1;
	while (*p1 != '\0')
		s1.push_back(*(p1++));

	// do this!	
	char str2[101];
	strcpy_s(str2, sizeof(str2), p2);
	std::string s2(str2);
	std::cout << s1 << " and " << s2 << '\n';
}


int main() {
	char str[101]{ "Hello World!" };
	std::string strstr = str;
	std::vector<char> vec(strstr.begin(), strstr.end());

	ex_9_41(vec);
	ex_9_42(str);

	return 0;
}