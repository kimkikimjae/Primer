#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <thread>
#include <sstream>

using namespace std;

void ex_17_34() {
	std::ios_base::sync_with_stdio(false);

	// boolalpha & noboolalpha
	cout << boolalpha << "true : " << true << "	/ false : " << false << '\n';
	cout << noboolalpha << "true : " << true << "	/ false : " << false << "\n\n";

	// showbase & noshowbase
	cout << hex << showbase  << 1024 << " " << noshowbase << 1024 << "\n\n";

	// showpoint & noshowpoint
	cout << noshowpoint << 10.00 << " " << showpoint << 10.00 << "\n\n";

	// uppercase & nouppercase
	cout << hex << showbase <<  uppercase << 1024 << " " << nouppercase << 1024 << noshowbase << "\n\n";

	// hex & oct & dec
	cout << hex << "hex : " << 1024 << '\n' << oct << "oct : " << 1024 << '\n' << dec << "dec : " << 1024 << "\n\n";

	// left & right
	cout << left << setw(10) << "left" << setw(10) << right << "right" << '\n';

	// internal
	cout << internal << setw(10) << -10 << "\n\n";

	// fixed & scientific & hexfloat & defaultfloat
	cout << fixed  << sqrt(2.0) << '\n'
		<< scientific << sqrt(2.0) << '\n'
		<< hexfloat << sqrt(2.0) << '\n'
		<< defaultfloat << sqrt(2.0) << "\n\n";

	// skipws & noskipws
	string text = "a    b\n ccc d";
	string result;
	istringstream is(text);
	is >> skipws;
	while (is >> result)
		cout << result;
	cout << "\n\n";
	is >> noskipws;
}

void ex_17_35() {
	cout << hexfloat << uppercase << 100 * sqrt(2.0) << defaultfloat << nouppercase << "\n\n";
}

void ex_17_36() {
	cout << left
		<< setw(20) << "default format" << setw(10) << " : " << setw(10) << 100 * sqrt(2.0) << '\n'
		<< setw(20) << "scientific" << setw(10) << " : " << setw(10) << scientific << 100 * sqrt(2.0) << '\n'
		<< setw(20) << "fixed decimal" << setw(10) << " : " << setw(10) << fixed << 100 * sqrt(2.0) << '\n'
		<< setw(20) << "hexadecimal" << setw(10) << " : " << setw(10) << hexfloat << 100 * sqrt(2.0) << '\n'
		<< setw(20) << "use default" << setw(10) << " : " << setw(10) << defaultfloat << 100 * sqrt(2.0) << "\n\n";
}
int main() {
	ex_17_34();
	cout << "-----------------------------------\n\n";
	ex_17_35();
	cout << "-----------------------------------\n\n";
	ex_17_36();

	return 0;
}