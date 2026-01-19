#include <iostream>
#include <memory>

// 12.10.
// no wrong, though there are somehow useless copying operations.
void process(std::shared_ptr<int> ptr) {}


// 12.11.
// problem happens when function call is end.
// p.get() only the original dynamic allocated object, not other information member (control block).
// so when the function overs, the original object would be deleted by ptr, but the residual information member be still existing which makes an illusion to original variable (p).


// 12.12.
//	(a) : OK. sp is fundamentally shared_ptr type. No problem at copying.
//	(b) : No. shared_ptr must be explicit when it takes a pointer type.
//	(c) : No. should be explicit also. p is int* type, not shared_ptr type.
//	(d) : definitely no. shared_ptr<int>(p) is temporary type casting, so it is going to be deleted by ptr, and dereferencing it is UB.
void ex_12_12() {
	auto p = new int(); // typeid(p).name() == int*
	auto sp = std::make_shared<int>(); // typeid(sp).name() == shared_ptr<int>

	process(sp);
	// process(new int());
	// process(p);
	process(std::shared_ptr<int>(p)); // no grammatical error before compile but serious UB.
}


// 12.13.
void ex_12_13() {
	// sp == shared_ptr<int> && *sp == 0.
	auto sp = std::make_shared<int>(); 

	auto p = sp.get(); 
	// dangerous behaviour!! 
	// sp's original pointing obeject be deleted by p, and sp get destructed.
	delete p;
}

