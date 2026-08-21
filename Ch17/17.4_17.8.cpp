#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <utility>
#include <tuple>


using namespace std;

extern class Sales_data;
extern bool compareIsbn;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ex_17_4
typedef tuple<
	vector<Sales_data>::size_type,
	vector<Sales_data>::const_iterator,
	vector<Sales_data>::const_iterator> matches;

vector<matches>
findBook(const vector<vector<Sales_data>>& files, const string& book) {
	vector<matches> ret;

	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second)
			ret.push_back(make_tuple(it - files.cbegin(), found.first, found.second));
	}

	return ret;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ex_17_5
typedef
pair <vector<Sales_data>::size_type,
	pair<vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator>> fbpair;

vector<fbpair>
findBook_pair(const vector<vector<Sales_data>>& files, const string& book) {
	vector<fbpair> ret;

	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second)
			ret.push_back(make_pair(it - files.cbegin(), make_pair(found.first, found.second)));
	}

	return ret;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ex_17_6
class fbs {
public:
	fbs() = default;
	fbs(vector<Sales_data>::size_type st, vector<Sales_data>::const_iterator fb, vector<Sales_data>::const_iterator fe) 
		: size(st), fbegin(fb), fend(fe){ }

private:
	vector<Sales_data>::size_type size;
	vector<Sales_data>::const_iterator fbegin;
	vector<Sales_data>::const_iterator fend;
};

vector<fbs> 
findBook_fbs(const vector<vector<Sales_data>>& files, const string& book) {
	vector<fbs> ret;
	
	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second)
			ret.push_back(fbs(it - files.cbegin(), found.first, found.second));
	}

	return ret;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ex_17_7() {
	// I prefer the version of tuples :)
}

void ex_17_8() {
	// the sum(accumulation) of a book that has a specific isbn would be reflected into class members(units_sold && revenue)
	// and they would be printed.
}
