#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <memory>

using namespace std;

void ex_17_1() {
	tuple<int, int, int> mytuple(10, 20, 30);
}

void ex_17_2() {
	tuple<string, vector<string>, pair<string, int>> mytuple;
	mytuple = make_tuple("mytuple", vector<string>("my", "tuple"), pair<string, int>("mytuple", sizeof("mytuple")));
}



// ex_17_3()
class TextQuery {
public:
	using line_no = vector<string>;
	using QRtype = tuple <string, shared_ptr<set<line_no>>, shared_ptr<vector<string>>>;

	TextQuery(ifstream&);

	QRtype query(const string&) const;

private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::QRtype TextQuery::query(const string& sought) const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return make_tuple(sought, nodata, file);
	else
		return make_tuple(sought, loc->second, file);
}