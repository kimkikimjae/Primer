#include <iostream>

using namespace std;

void ex_6_10(int* pa, int* pb) {
	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

int main() {
	int a = 10, b = 20;
	cout << "before change: a = " << a << " and b = " << b << '\n';
	ex_6_10(&a, &b);
	cout << "after change : a = " << a << " and b = " << b << endl;
	return 0;
}