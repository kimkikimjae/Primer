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

std::istream& operator>>(std::istream& in, Sales_data& data) {
	in >> data.bookNo >> data.units_sold >> data.revenue;

	return in;
}

std::ostream& operator<<(std::ostream& out, const Sales_data& data)
{
	out << data.isbn() << ' '
		<< data.units_sold << ' '
		<< data.revenue << ' '
		<< data.avg_price();

	return out;
}




