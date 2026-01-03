#include <iostream>	
using namespace std;

// 6.11.
void reset(int& i) { i = 0; }


// 6.12.
void ex_6_12(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}


// 6.13.
// void f (T) uses local variable and works in call by value which causes copying value and this could make somehow inefficiency.
// reference parameter version of f works in call by reference and this is more efficient than copy version of it.


// 6.14.
// when you need to change caller's values but you also want to use at least memory.
// I'm not sure what should I answer to this question but mine could be an answer right? :)


// 6.15.
/*
*	Purpose of using reference(&) type is avoiding useless memory copy, and const or not means that using const is supposed not to change original value,
*		and non-const is supposed to change.
*	In this case, parameter const string& s works in reading-only aspect, which means that it DOES NOT CHANGE original vlaue.
*		Parameter string::size_type &occurs changes caller's original value.
*	In result, if we change each type of const string& s and size_type& occurs into opposite type, 
*		then we gonna be change original string, not the total count of appearance and this is wrong.
*	Like this, if we set char c as char &c, then we gonna change original character c, and we gonna be fall into wrong working.
*/