#include <iostream>
#include <string>
#include <memory>
#include <new>
#include "StrBlob.h"
#include <cassert>
// 12.1.
// 4 elements left in b1. 
// b2 disappears but StrBlob class has smart pointer, so it doesn't have any effect on b1's member.


// 12.2.
// in "StrBlob.h" header file.


// 12.3.
// personally, this example is very impressive to me to think in profound way.

/*	if we set member function 'push_back' and 'pop_back' as 'const', surprisignly, there is no compile error.
*	definitely, we set member function as const, then we know that this member can't change data member (const *this). But the result does not prove it.
*	In specific, we DO NOT CHANGE data member of which data type is 'shared_ptr<vector<string>>'.
* 
*	Which means, we CHANGE ** external vector<string> ** that is pointed by 'shared_ptr'(StrBlob::data), and DO NOT CHANGE it(StrBlob::data) itself.
*	So this is allowed, because const member function does not control shared_ptr, rather doing on external vector.
* 
*	So anyway, we could use const version. However, we SHOULD NOT.
*	
*	'const' keyword has two roles; one is for compiler, and another is for 'users' (programmers).
*	Not only it blocks any change on the original value of identity, but also shows us(users) editor's intention that he/she set this value as immutable.
*/

// for additional experiment for ex.12.3., using StrBlob's function as const. 
// I will not change those as const for this example.
// no error occurs.
void ex_12_3() {
	StrBlob b({ "aa", "bb", "cc" });
	b.push_back("dd");
	b.show_elems();
}


// 12.4.
// SERIOUSLY WHO READ string[-1]? string[-2]? -3? -100? -100000?
// Whoever doing that should move to python.


// 12.5.
// pros: more safe, definite code obejective and easy to find error.
// cons: bothering.


int main()
{
	ex_12_3();
	return 0;
}

