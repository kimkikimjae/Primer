#include <iostream>	
#include <map>	
using namespace std;

class Screen {
public:
    using pos = std::string::size_type;

    Screen() = default; // 1
    Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht* wd, ' ') {} // 2
    Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht* wd, c) {} // 3

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }
    inline Screen& move(pos r, pos c);
    inline Screen& set(char c);
    inline Screen& set(pos r, pos c, char ch);

    const Screen& display(std::ostream& os) const { do_display(os); return *this; }
    Screen& display(std::ostream& os) { do_display(os); return *this; }

private:
    void do_display(std::ostream& os) const { os << contents; }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline Screen& Screen::move(pos r, pos c)
{
    cursor = r * width + c;
    return *this;
}

inline Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen& Screen::set(pos r, pos c, char ch)
{
    contents[r * width + c] = ch;
    return *this;
}


// 7.27. ~ 7.29.

/*	If we set those member functions' return type as 'Screen', not 'Screen&', then the return value gonna be 'copied' value.
	Chaining of each code gonna be running, but the original member value would not be changed except for move(),
	'cause we didn't use myScreen as &(reference).
    Which means, if we run move() then the original value gonna be changed for this time, but move() returns copied value,
    and this be tossed to next chaining functions(.set() and .display()), so those two functions do not change original value.
	Each member function did 'call by value', not 'call by reference'. 
    */

// 7.30.
/*  pros: Using this or *this is efficient when the function's parameter name and memeber name are same. 
*           By using this, we can distinguish them.
*   cons: Inconvenient.
*/
