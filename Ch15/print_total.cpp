#include <iostream>
#include <ostream>
#include "Quote.h"

double print_total(std::ostream& os, const Quote& item, std::size_t n) {
	double ret = item.net_price(n);
	os << item.isbn() << " " << n << " " << ret << std::endl;
	return ret;
}