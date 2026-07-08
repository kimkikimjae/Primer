#include <iostream>
using namespace std;

void ex_1_16() {
	cout << "How many times you type integers?\n";
	int num = 0, count = 0, sum = 0;
	cin >> count;
	for (int i = 0; i < count; ++i) {
		cin >> num;
		sum += num;
	}

	cout << "The sum is " << sum;
}

int main() {
	ex_1_16();
	return 0;
}