#pragma once

#include <iostream>
#include <string>
#include <istream>
#include <ostream>

using namespace std;

class Sales_data;
std::istream& read(std::istream& is, Sales_data& item);
// std::ostream& print(std::ostream& os, const Sales_data& item);



class Sales_data {
public:
	friend istream& read(istream&, Sales_data&);
	friend istream& operator>>(istream&, Sales_data&);
	friend ostream& operator<<(ostream&, const Sales_data&);

	Sales_data() = default;
	Sales_data(const std::string& s, unsigned int n, double p) : bookNo(s), units_sold(n), revenue(p* n) {};
	Sales_data(const std::string& s) : bookNo(s) {};
	Sales_data(std::istream&);


	Sales_data& combine(const Sales_data&);
	Sales_data& operator+= (const Sales_data& rhs);

	std::string isbn() const { return bookNo; }

	// by ex_17_8, an operator+ needs here.
	/*Sales_data& operator+(const Sales_data& sd) {
		units_sold += sd.units_sold;
		revenue += sd.revenue;
		return *this;
	}*/

	double avg_price() const { return revenue / units_sold; }

private:
	std::string bookNo;
	unsigned int units_sold = 0;
	double revenue = .0;
};



