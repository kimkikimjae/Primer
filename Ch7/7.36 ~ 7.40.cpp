#include <iostream>
#include <string>
#include "Sales_data.h"


// 7.36.
// as following initializing rule, rem is first initialized and base is next.
// but as initializing list shows, rem is initialized by base % j, but base is yet initialized.


// 7.37.
// Sales_data(std::istream&) { follows what parameter 'is' has. }
// Sales_data() { "", 0, 0 }
// Sales_data(const std::string& s) { "s", 0, 0 }


// 7.38.
// Sales_data(std::istream& is = std::cin);


// 7.39.
// ... is there any answer for this? It depends on what purpose the user uses this program.
// Even they can be evaluated by their type like, std::string has its own initialized constructor, so even if I do not set basic argument, it would be already initialized as empty string.
// In this view, it is not dangerous in the view of non-initialzing basic value. Unlike built-in type like int or double, std::string is template library type and is well-structured.
// std::string is ok, but istream& type is not sure, cause istream& paramter could be standard input or other things like external file existing in other directory in computer.
// If we set basic paramter as std::cin, then the program would be working in somehow different purpose. In this case, placing basic argument can be dangerous.


// 7.40.
// I chose (a) Book.
// I made it as simple as possible, so I think you can interpret what I made and intended.
// Just made some members regarding book, like you can save your last page you read, remark sentences that touched you, whatever.

class Book {
public:
	Book(const int& pn = 0, const int& bmn = 0, const std::string& stc = "Choose your setence!") :
		page_num(pn), book_mark_num(bmn), chose_sentence(stc) {};
	friend void show_book_info(const Book&);
	void set_page_num(const int&);
	void set_mark_num(const int&);
	void set_setence(const std::string&);
private:
	int page_num = 0;
	int book_mark_num = 0;
	std::string chose_sentence;
};

inline void show_book_info(const Book& B) {std::cout << B.page_num << " " << B.book_mark_num << " " << B.chose_sentence << std::endl;}
inline void Book::set_page_num(const int& i) { page_num = i; }
inline void Book::set_mark_num(const int& i) { book_mark_num = i; }
inline void Book::set_setence(const std::string& s) { chose_sentence = s; }


