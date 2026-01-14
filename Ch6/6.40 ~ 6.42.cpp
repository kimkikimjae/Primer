#include <iostream>
#include <string>
// 6.40.
// (b) is wrong. if you set default argument in one paremeter, then you should do same thing to all the following parameters.


// 6.41.
// (a) first parameter (int ht) has no default argument. you should set argument for it.
// (c) first argument (14) is for ht (int type) and this is correct. But next second one is '*' (char type) which does not match to int type.
//		(grammatically, it is correct cause char type can be converted to int, but do you know what ascii code for '*'?)


// 6.42.
// In my book(translated!), it says "set default argument to second parameter(const std::string& word)".
// But I think doing that is something awkward to do intended function in this example.
// So I interpret this question as setting default argument to "second string type parameter; const std::string& ending".
std::string make_plural(std::size_t ctr, const std::string& word, const std::string& ending = "s") {
	return (ctr > 1) ? word + ending : word;
}

int main()
{
	std::string plural, n_plural;
	plural = make_plural(2, std::string("success"));
	n_plural = make_plural(1, std::string("success"));
	std::cout << plural << " and " << n_plural << std::endl;

	plural = make_plural(2, std::string("failure"));
	n_plural = make_plural(1, std::string("failure"));
	std::cout << plural << " and " << n_plural << std::endl;
	return 0;
}