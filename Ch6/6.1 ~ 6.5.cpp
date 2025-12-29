#include <iostream>
#include <string>
using namespace std;

// 6.1.
// parameter == variable(local). It also has its own memory space.
// argument == value

// 6.2.
	// (a): No match between return type of function and actual return value's type.
	// (b): Function has no return type.
	// (c): It loses left brace {.
	// (d): It loses a pair of braces { and }. Function must have its body with braces.

// 6.3.
// This function works in iterative way rather than recursive.
int fact(int val) {
	int ret = 1;
	while (val > 1) ret *= val--;
	return ret;
}

// 6.4.
int square(int x) {
	return x * x;
}

// 6.5.
int modulus(int x) {
	if (x > 0) return x;
	else return -x;
}

/* including ex 6.4 and 6.5 */
int main() {
	int x = 10;
	int res1 = square(x);
	int res2 = modulus(x);
	return 0;
}
