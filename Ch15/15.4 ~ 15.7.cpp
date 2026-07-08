#include <iostream>
#include "Quote.h"

// 15.4
// (a) is wrong. Class itself cannot declared as direct base.
// (c) is wrong. Declaration of class does not need direct base. It only needs its name.


// 15.5
// in "Quote.h"


// 15.6
double print_total(std::ostream& os, const Quote& item, std::size_t n);

void ex_15_6() {
	Quote q("q1", 100);
	Bulk_quote bq("bq", 100, 10, 0.6);

	// each third argument is just arbitrarily tossed to parameter, just for testing example.
	// you can type it in following example context.
	print_total(std::cout, q, 1);
	print_total(std::cout, bq, 2);
}


// 15.7
class ex_15_7 {
public:
	ex_15_7() = default;
	ex_15_7(const std::size_t qty, const double rate) : qtt(qty), dis_rate(rate) {}
	virtual void set_rate();
protected:
	std::size_t qtt = 0;
	double dis_rate = .0;
	double net_price = .0;
};

class ex_15_7c : public ex_15_7 {
public:
	ex_15_7c() = default;
	ex_15_7c(const std::size_t qty, const double rate) : ex_15_7(qty, rate) {
		net_price = qty * (1 - dis_rate);
	}
	void set_rate() override {
		// set discount rate 30%, with threshold 5 books.
		if (qtt <= 5) dis_rate = 0.3; 
		else dis_rate = 1;
	}
};

