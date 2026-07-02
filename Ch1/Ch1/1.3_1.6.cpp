#include <iostream>

void ex_1_3() {
	std::cout << "Hello World!" << std::endl;
}

void ex_1_4() {
	std::cout << "Enter tow numbers:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The multiplication of " << v1 << " and " << v2
		<< " is " << v1 * v2 << std::endl;
}

void ex_1_5() {
	std::cout << "Enter tow numbers:";
	std::cout << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1;
	std::cin >> v2;
	std::cout << "The multiplication of ";
	std::cout << v1;
	std::cout << " and ";
	std::cout << v2;
	std::cout << " is ";
	std::cout << v1 * v2;
	std::cout << std::endl;
}

void ex_1_6() {
	// wrong.
	// v1 and v2 must to be initialized or assigned with new values.
}

int main() {
	ex_1_3();
	ex_1_4();
	ex_1_5();
	ex_1_6();
	return 0;
}