#include <iostream>
#include <string>
#include "Sales_data.h"

using namespace std;

// why this man use sales_data class in every chapter shit
// i dont even remember what i did in last chapter

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// for ex.18.9.

class out_of_stock : public runtime_error {
public:
	explicit out_of_stock(const string& s) : runtime_error(s) {}
};

class isbn_mismatch : public logic_error {
public:
	explicit isbn_mismatch(const string& s) : logic_error(s) {}
	isbn_mismatch(const string& s, const string& lhs, const string& rhs) : logic_error(s), left(lhs), right(rhs) {}
	const string left, right;
};


Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
	if (isbn() != rhs.isbn())
		throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());

	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data temp = lhs;
	temp += rhs;
	return temp;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ex_18_10_with_try_catch() {
	Sales_data item1("item1", 10, 100);
	Sales_data item2("item2", 20, 200);
	Sales_data temp;
	try {
		temp = item1 + item2;
	}
	catch (const isbn_mismatch& m) {
		cerr << m.what() << ": left isbn(" << m.left << ") right isbn(" << m.right << ")" << endl;
	}
}

void ex_18_10_without_try_catch() {
	Sales_data item1("item1", 10, 100);
	Sales_data item2("item2", 20, 200);
	Sales_data temp;
	temp = item1 + item2;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ex_18_11() {
	/*
	what() is normally called while handling an exception
	to obtain information about that exception.

	Therefore, what() itself must not throw.
	Otherwise, handling/reporting the original exception
	could itself fail.

	In C++11, what() is noexcept.
	*/
}
int main() {
	ex_18_10_with_try_catch();						// safely terminated with messsage alarm.
	// ex_18_10_without_try_catch();				// abort() has been called.
	
	return 0;
}