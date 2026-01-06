#include <iostream>
#include <string>

// 7.31.
struct X {
	Y* y;
};
struct Y {
	X x;
};