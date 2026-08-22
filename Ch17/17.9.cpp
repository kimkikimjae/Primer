#include <iostream>
#include <bitset>
using namespace std;

void ex_17_9() {
	bitset<64> bitvec(32); 
	cout << bitvec << '\n'; // 0000000000000000000000000000000000000000000000000000000000100000_(2)

	bitset<32> bv(1010101); 
	cout << bv << '\n'; // 00000000000011110110100110110101_(2)

	string bstr;
	// cin >> bstr;
	bstr = "11011010";
	bitset<8> bv2(bstr);
	cout << bv2 << '\n'; // 11011010_(2)
}

int main() {
	ex_17_9();

	return 0;
}