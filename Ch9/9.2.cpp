#include <iostream>
#include <deque>
#include <forward_list>

void ex_9_2() {
	std::deque<int> dq;
}

template<typename T>
class mylist {
public:
	mylist() = default;
	
	bool empty() const {
		if (fl.empty()) return 1;
		else return 0;
	}

	void push_front(T t) {
		fl.push_front(t);
		++num;
	}
	void pop_front() {
		if (!fl.empty()) {
			fl.pop_front();
			--num;
		}
		else exit(1);
	}
	size_t size() const { return num; }
private:
	unsigned size_t num = 0;
	std::forward_list<T> fl;
};