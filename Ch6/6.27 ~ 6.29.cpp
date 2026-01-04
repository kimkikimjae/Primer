#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <numeric>
using namespace std;

// 6.27.
// used accumulate() of <numeric>
int ex_6_27() {
	initializer_list<int> il = { 1,2,3,4,5 };
	int sum = accumulate(il.begin(), il.end(), 0);
	return sum;
}

// 6.28.
// type int.

// 6.29.
// yes. when you read each elements with efficiency of no-copying works.