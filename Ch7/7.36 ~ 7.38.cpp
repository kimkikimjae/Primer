#include <iostream>
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