#include <iostream>
using namespace std;

// 6.21.
// int type.


// 6.22.
void ex_6_22(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


// 6.23.
void print1(const int* p) { cout << *p << endl; }
void print2(const int* arr) {
	for (int i = 0; i < 2; ++i) cout << arr[i] << " ";
	cout << endl;
}
void ex_6_23(int& a, int arr[]) {
	print1(&a);
	print2(arr);
}

int main() {
	int i = 0, j[2] = { 0, 1 };
	ex_6_23(i, j);
}


/*	6.24.
*	DECAY occurs at const int ia[10] and this is definitely same with const int *ia.
*	So if you place an argument with the total size of array is smaller than 10, then reading it could make some undefined behaviour.
*/


