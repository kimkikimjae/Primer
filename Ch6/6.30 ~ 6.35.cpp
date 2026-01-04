#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 6.30.
// ErrorCode C2561: 'str_subrange': function must return a value
/*bool str_subrange(const string& str1, const string& str2) {
	if (str1.size() == str2.size()) return str1 == str2;
	auto size = (str1.size() < str2.size() ? str1.size() : str2.size());
	for (decltype(size) i = 0; i != size; ++i) {
		if (str1[i] != str2[i]) return; //	<-- Error Occurs!
	}
}
*/


// 6.31.
// const&: By using const&, a function can return a local value (related with Lifetime Extension)
// non-const&: You MUST NOT return a local value with that type. It is deallocated its memory space after function call.


// 6.32.
// It works. 
// (1) Function 'get' returns int& type value but it is not a local variable, rather is caller's original value. 
//		So reference & refers to not a local value, it does not make error.
// (2) 'ia' decays to pointer, and *arry points to ia. This is not copying and it works.


// 6.33.
void ex_6_33(vector<int>::iterator beg, vector<int>::iterator end) {
	if (beg == end) return;
	cout << *beg << ' ';
	ex_6_33(++beg, end);
}


// 6.34.
// It falls into eternal loop.
// Consider when the argument is -1.
// It calls val = -2, and it again calls val = -3 ... and so on.


// 6.35.
// Postfix decrement operator actually decreases original val's value, but it returns the copied value of before decreasing val.
// So that tossed arguemnt to recursive function is always same as original val, and it falls into eternal loop in the end.
// If i set val as 5 : first factorial(5) returns second factorial(5) -> second factorial(5) returns third factorial(5)
//						-> third factorial(5) returns 4th, 5th, 6th...