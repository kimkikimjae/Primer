#include <iostream>
#include <vector>
#include <complex>
#include <initializer_list>
#include <string>

// 7.34.
// member function: void dummy_fcn(pos height) occurs compile error.
// unlike other members, type member follows general declaration rule, so it has to be preceded than other members using that type member.


// 7.35.

typedef std::string Type;
Type initVal(); // uses Type as std::string
class Exercise {
public:
	typedef double Type;
	Type setVal(Type); // Type here is double.
	Type initVal(); // same as above setVal.
private:
	int val;
};

Type Exercise::setVal(Type parm) { // return type Type precedes than class name Exercise, so it is researched by global scope -> std::string Type.
	// we should include Type in class scope by Exercise::Type.
	val = parm + initVal(); 
	return val;
}
