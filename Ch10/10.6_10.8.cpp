#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;



// 10.6 
int main()
{
	vector<int> vec;
	fill_n(back_inserter(vec), 10, 0);
	for (const int& i : vec) cout << i << " ";
	return 0;
}

/* 10.7
	(a) 
	: algorithms, including 'copy', require the destination container to already have initial element capacity.
	: vec.begin() -> back_inserter(vec)

	(b)
	: reserve() does not take size for real and it's just reservation of capacity.
	: vec.begin() -> back_inserter(vec.begin())
*/

/* 10.8
	back_inserter does not be included in <algorithm>. 
	it is in <iterator>.
*/