#include <iostream>
#include <string>
#include "Sales_data.h"
// 7.23 && 7.24.
class Screen {
public:
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(const pos& ht, const pos& wd, const char c) : height(ht), width(wd), contents(ht* wd, c) {};
	Screen(const pos& ht, const pos& wd, const int& i) : height(ht), width(wd), contents(i, ' ') {};
	char get() const { return contents[cursor]; }
	char get(const pos& ht, const pos& wd)	const;
	Screen& move(const pos& r, const pos& c);
	
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};

// 7.25.
// Yes. We set initial values for each data.
// Each Built-in types are 0, and contents is included in stl library type that predefined initial set value for constructor.

// 7.26.
inline double Sales_data::avg_price() const { return units_sold ? revenue / units_sold : 0; }

