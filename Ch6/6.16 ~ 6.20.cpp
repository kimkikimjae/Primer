#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

// 6.16.
/* It is not wrong in functioning aspect, 
	but it is better to add 'const' to mark that we are not gonna change original value and just only read this value. */
// We can change the function like below...

bool is_empty(const string& s) { return s.empty(); }


// 6.17.
// A simple iterative way for both functions.

// 1. We use parameter as 'const' because we should not change original string value. 
//		We only just 'check(or read)' if there is capital letters.
bool checking_upper(const string& s) {
	string::size_type len = s.size();
	for (string::size_type i = 0; i < len; ++i)
		if (isupper(s[i])) return true;
	return false;
}

// 2. We should 'change' the original characters to lowercases, so we set parameter as non-const string.
void to_lower(string& s) {
	string::size_type len = s.size();
	for (string::size_type i = 0; i < len; ++i) {
		if (isupper(s[i])) s[i] = tolower(s[i]);
	}
}


// 6.18.
// (a)
class Matrix {};
bool compare(Matrix& m1, Matrix& m2);
// (b)
vector<int>::iterator change_val(int a, vector<int>::iterator b);


/*	6.19.
*	(a) no matches for variable numbers.
*	(b) OK
*	(c) OK but casting (from int to double) occurs.
*	(d) OK but casting (from double to int) occurs.
*/

/*	6.20.
*	(1) If you use const arguemnt or only want to read it with no changes happening.
*	(2) type error occurs when you get some mistake of using const referencer.
*/
