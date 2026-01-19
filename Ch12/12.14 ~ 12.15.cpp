#include <iostream>
#include <memory>

// 12.14. ~ 12.15.
struct destination{};
struct connection {};
connection connect(destination*);
void disconnect(connection);
void end_connection(connection* p) { disconnect(*p); }
void f(destination& d, ...) {
	connection c = connect(&d);
	// ex.12.14.
	// std::shared_ptr<connection> p(&c, end_connection);

	// ex.12.15.
	auto f = [](connection* p) {disconnect(*p); };
	std::shared_ptr<connection> p(&c, f);
}