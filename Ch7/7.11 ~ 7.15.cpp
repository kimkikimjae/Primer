#include <iostream>
#include <string>
#include <istream>
#include <ostream>


// 7.11.
std::ostream& print(std::ostream& os, const Sales_data& item);
class Sales_data {
public:
	Sales_data() = default;
	Sales_data(const std::string& s, unsigned int n, double p) : bookNo(s), units_sold(n), revenue(p* n) {};
	Sales_data(const std::string& s) : bookNo(s) {};
	// for 7.14.
	// Sales_data(const string& s) : bookNo(s), units_sold(0), revenue(.0) {};
	Sales_data(std::istream&);
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const { return units_sold ? revenue / units_sold : 0; }
	std::string bookNo;
	unsigned int units_sold = 0;
	double revenue = .0;
};

std:: istream& read(std:: istream& is, Sales_data& item) {
	double price = .0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

Sales_data::Sales_data(std::istream& is) { read(is, *this); }

int main() {
	Sales_data s1(); // s3.bookNo = "" && s3.units_sold = 0 && s3.revenue = .0;
	Sales_data s2("s2", 10, 1.0);
	Sales_data s3("s3"); // s3.units_sold = 0 && s3.revenue = .0;
	Sales_data s4(std::cin); // just an example of constructor using std::cin as istream parameter.
	return 0;
}

/*	7.12.
*	Sales_data(istream& is){
*		string name;
*		is >> name;
*		cout << name << endl;
*	}
*/

// 7.13.
// I dont understand what the question is istructing to do.
// I think my code is not correct for this, so i hope you read others' codes.
void ex_7_13() {
	Sales_data total(std::cin);
	if (total.bookNo == "") std::cerr << "No data?!" << std::endl;
	Sales_data trans;
	while (read(std::cin, trans)) {
		if (total.isbn() == trans.isbn())
			total.combine(trans);
		else {
			print(std::cout, total) << std::endl;
			total = trans;
		}
	}
	print(std::cout, total) << std::endl;
}


// 7.15.
// ?? where is it ??
// I can't find class Person :( but it could be easy to make some constructors.
// below code is just an imaginary code for not founded class: Person.
struct Person {
	std::string name;
	int num;
	Person() = default;
	Person(const std::string& s) : name(s), num(0) {};
	Person(const std::string& s, const int& n) : name(s), num(n) {};
};