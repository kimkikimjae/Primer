#include <iostream>
#include <string>
#include <istream>
#include <ostream>
#include "Sales_data.h"

Sales_data::Sales_data(std::istream& is) { read(is, *this); }

std::istream& read(std::istream& is, Sales_data& item) {
	double price = .0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}
