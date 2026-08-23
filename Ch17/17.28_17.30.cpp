#include <iostream>
#include <random>
#include <ctime>

using namespace std;

unsigned int ex_17_28() {
	static default_random_engine e;
	static uniform_int_distribution<unsigned> rd(0, 9);
	return rd(e);
}

unsigned int ex_17_29(unsigned int seed) {
	default_random_engine e(seed);
	uniform_int_distribution<unsigned> rd(0, 9);
	return rd(e);
}

unsigned int ex_17_30(unsigned int min, unsigned int max) {
	static default_random_engine e(time(0));
	uniform_int_distribution<unsigned> rd(min, max);
	return rd(e);
}


int main() {
	for (int i = 0; i < 10; ++i)
		cout << ex_17_28() << " ";
	cout << '\n';
	for (int i = 0; i < 10; ++i)
		cout << ex_17_29(i) << " ";
	cout << '\n';
	for (int i = 0; i < 10; ++i)
		cout << ex_17_30(i, i + 10) << " ";
	return 0;
}