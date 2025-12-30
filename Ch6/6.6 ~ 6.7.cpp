#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 6.6.

/*	Parameter
*	: A local variable that is included in its own covering function.
*   : It has its own memory space and the space is allocated when its function is called and desappears the function is over.
*	: Actually same works in structure of variable, but it is more be viewed as 'passage' to external identifiers.
*	: It receives external values that be called by external call sign(by caller) and can be also used in the function where it exits(callee).
*/

/*	Local variable
*	: Just a variable in a function.
*	: Parameter above is local varaible. 
*	: It has its own memory space. 
*/

/*	Static Local variable
*	: The core difference with common local variable appears within its functioning mechanism.
*	: SLV(Static Local Variable) is initialized only once in when the 'program' begins and after the compiler passes through its definition part, 
*		and the lifetime of it runs through the whole running time of the program. Only one initialization and living through whole running time.
*		Function is called -> Function's SLV is initialized(first time) -> Function is over but its SLV is not deleted and stays over the whole program while its running.
* 
*	: LV(Local Variable) is different with SLV that it is initialized whenever its belonging function is called by caller.
*		Function is called -> Function's  LV is initialized -> Function overs -> Function's LV is deleted. -> Function is called -> ... Loop
*/

void ex_6_6() {
	static int stt = 0; // stt is local vari.
	int loc = 0; // loc is local vari.
	cout << "loc : " << loc++ << " and stt : " << stt++;
	cout << '\n';
}

// 6.7.
int ex_6_7() {
	static int num = 0;
	return num++;
}

int main() {
	/*
	Because loc is local variable, everytime that I call its belonging function, it cannot be staying consistently through running.
	But stt can!
	*/
	for (int i = 0; i < 5; ++i) ex_6_6(); // for testing ex 6.6.

	// for testing ex 6.7.
	vector<int> vec;
	int num = 0;
	for (int i = 0; i < 10; ++i) {
		num = ex_6_7();
		vec.push_back(num);
	}
	cout << '\n';
	for (const int& i : vec) cout << i << " ";
	
	return 0;
}