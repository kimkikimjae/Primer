#include <iostream>	
#include <string>
#include <vector>
using namespace std;

// 6.54.
int func(int, int);
int (*pf)(int, int);
vector<int(*)(int, int)> vec;

// 6.55.
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { 
	if (b == 0) exit(1);
	return a / b; 
}

void ex_6_55() {
	vec.push_back(add);
	vec.push_back(subtract);
	vec.push_back(multiply);
	vec.push_back(divide);
}


// 6.56.
void ex_6_56() {
	int res;
	for (int i = 0; i < 4; ++i) {
		res = vec[i](4, 2);
		cout << res << '\n';
	}
	cout << endl;
}

int main()
{
	ex_6_55();
	ex_6_56();
	return 0;
}