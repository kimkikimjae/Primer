#include <iostream>
#include <string>
using namespace std;

// 6.25. && 6.26.
int main(int argc, char* argv[]) {
	string temp;
	for (int i = 1; i < argc; ++i) {
		temp = argv[i];
		cout << temp << '\n';
	}
	cout << endl;
	return 0;
}

/*	How to set chapter's Command-Line Arguments
*	(1) Right-click on Project -> Properties
*	(2) Configuration properties -> Debugging -> Command Arguments
*	(3) Type, prog -d -o ofile data0
*	(4) Apply it and make some codes on the program like I did on ex.6.25 & 6.26.
*/
