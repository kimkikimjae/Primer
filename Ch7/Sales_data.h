#pragma once
#include <iostream>
#include <string>
#include <istream>
#include <ostream>
using namespace std;

class Sales_data {
public:
	Sales_data() = default;
	Sales_data(const std::string& s, unsigned int n, double p) : bookNo(s), units_sold(n), revenue(p* n) {};
	Sales_data(const std::string& s) : bookNo(s) {};
	Sales_data(std::istream&);
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
	std::string bookNo;
	unsigned int units_sold = 0;
	double revenue = .0;
};
std::istream& read(std::istream& is, Sales_data& item);
std::ostream& print(std::ostream& os, const Sales_data& item);






