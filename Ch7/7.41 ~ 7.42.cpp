#include <iostream>
#include <string>
#include <istream>
#include <ostream>
using namespace std;

class Sales_data;
std::istream& read(std::istream& is, Sales_data& item);

class Sales_data {
public:
	Sales_data() {
		std::cout << "This constructor is default constructor" << std::endl;
	}
	Sales_data(const std::string& s, unsigned int n, double p) : Sales_data(s){
		units_sold = n;
		revenue = p;
		std::cout << "This constructor is delegating to std::string argument constructor" << std::endl;
	};
	Sales_data(const std::string& s) : Sales_data() { 
		bookNo = s; std::cout << "This constructor is delegating to default constructor" << std::endl;
	};
	Sales_data(std::istream& is) { read(is, *this); }

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const {
		return units_sold ? revenue / units_sold : 0;
	}

	std::string bookNo;
	unsigned int units_sold = 0;
	double revenue = .0;
};

inline Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

/*
* 
* 
* 
* 
* 
*/

class Book {
public: // Past constructor's parameters were reference type, but normal type in this case, just with no reason. 
	Book(const int pn = 0, const int bmn = 0, const std::string stc = "Choose your setence!") :
		page_num(pn), book_mark_num(bmn), chose_sentence(stc) {
		std::cout << "This is default or you can insert arument you want!" << '\n';
	};

	Book(const string s) : Book(0, 0, s) {
		std::cout << "This constructor sets your sentence choice!\n";
	}

	friend void show_book_info(const Book&);
	void set_page_num(const int&);
	void set_mark_num(const int&);
	void set_setence(const std::string&);
private:
	int page_num = 0;
	int book_mark_num = 0;
	std::string chose_sentence;
};

inline void show_book_info(const Book& B) { std::cout << B.page_num << " " << B.book_mark_num << " " << B.chose_sentence << std::endl; }
inline void Book::set_page_num(const int& i) { page_num = i; }
inline void Book::set_mark_num(const int& i) { book_mark_num = i; }
inline void Book::set_setence(const std::string& s) { chose_sentence = s; }



// 7.41.
void ex_7_41() {
	Sales_data s1; std::cout << '\n';
	Sales_data s2("Second"); std::cout << '\n';
	Sales_data s3("Third", 0, 0);
}

// 7.42.
void ex_7_42() {
	Book b1; std::cout << '\n';
	Book b2("seoncd");
}

int main()
{
	ex_7_41();
	std::cout << "\n*****************************************\n";
	ex_7_42();
	return 0;
}