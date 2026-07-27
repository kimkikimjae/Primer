#include <iostream>
using namespace std;

void ex_1_17() {
	// 1. If those inputs are all same, then only one sentence that telling only one input value occurence would be printed.
	// 2. If those inputs are all different, then each of them would be printed as "currVal occurs 1 times" for each inputs, 
	//		unlike those with same values.
}

void ex_1_18_1() {
	int currVal = 0, val = 0;
	cout << "Type integers or type -1 if you want exit this program\n";
	if (std::cin >> currVal) {
		int cnt = 1;
		while (std::cin >> val) {
			if (val == -1) break;	// added this code for exit


			if (val == currVal)
				++cnt;
			else {
				std::cout << currVal << " occurs " << cnt
					<< " times" << std::endl;
				currVal = val;
				cnt = 1;
			}
		}
		std::cout << currVal << " occurs " << cnt
			<< " times" << std::endl;
	}
}

void ex_1_18() {
	// Edited original code with break sentence : if (val == -1)
	// do it!
	ex_1_18_1();
}


void ex_1_19(int start, int end) {
	// Unlike the original code of ex_1_11, here we force these two inputs(start and end) as start must to be smaller than end.
	if (start > end) {
		int temp = start;
		start = end;
		end = temp;
	}

	for (int i = start + 1; i < end; ++i) {
		std::cout << i << " ";
	}
}
int main() {
	ex_1_17();
	ex_1_18();

	cout << "\n\nType two integers as start and end\n";
	int start = 0, end = 0;
	cin >> start >> end;
	ex_1_19(start, end);

	return 0;
}