#include <iostream>

using namespace std;

void ex_1_12() {
	// add the sequence of i of -100 ~ 100 to sum.
	// the result of sum here is 0.
	int sum = 0;
	for (int i = -100; i <= 100; ++i)
		sum += i;
	cout << sum << '\n';
}

void ex_1_13(int a, int b) {
	// for ex_1_9
	int sum = 0;
	for (int i = 50; i <= 100; ++i)
		sum += i;
	cout << sum << '\n';

	// for ex_1_10
	sum = 0;
	for (int i = 10; i >= 0; --i)
		sum += i;
	cout << sum << '\n';

	// for ex_1_11
	sum = 0;
	for (int i = a + 1; i < b; ++i)
		cout << i << " ";
}

void ex_1_14() {
	// for-loop 
		// easy and comfortable.

	// while-loop
		// has a little bit more of dangerous error of infinite loop if we forget the finishing condition.
		// like forgetting the incremental or decremental operation of variables for finishing loop, just running well the main code of block.
}

void ex_1_15() {
	// be familiarized!
}

int main() {
	ex_1_12();
	cout << '\n';

	int a = 0, b = 0;
	cin >> a >> b;
	ex_1_13(a, b);
	cout << '\n';
	ex_1_14();
	cout << '\n';
	ex_1_15();
	
	return 0;
}