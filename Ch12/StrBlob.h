#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>


using namespace std;
class StrBlobPtr;

class StrBlob {
	friend class StrBlobPtr;
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);

	size_type size()const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const std::string& t) { data->push_back(t); }
	StrBlobPtr begin();
	StrBlobPtr end();

	std::string& front() const;
	std::string& back() const;
	void pop_back() const;
	
	// just for seeing elements of data;
	// not included in example code.
	void show_elems() {
		std::weak_ptr<vector<string>> it(data);
		vector<string>::iterator mov = it.lock()->begin();
		vector<string>::iterator end = it.lock()->end();
		for (; mov != end; ++mov) std::cout << *mov << " ";
	}
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string& msg) const;
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {};
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {};
void StrBlob::check(size_type i, const string& msg) const {
	if (i >= data->size())
		throw out_of_range(msg);
}
string& StrBlob::front() const {
	check(0, "front on empty StrBlob");
	return data->front();
}
string& StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data->back();
}
void StrBlob::pop_back() const {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

class StrBlobPtr {
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
public:
	StrBlobPtr() : curr(0) {};
	StrBlobPtr(StrBlob& a, std::size_t sz = 0) : wptr(a.data), curr(sz) {};
	std::string& deref() const;
	StrBlobPtr& incr();
};

std::shared_ptr<std::vector<std::string>> 
StrBlobPtr::check(std::size_t i, const std::string& msg) const
{
	std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr\n");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

std::string& StrBlobPtr::deref() const {
	std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
	return (*p)[curr];
}
StrBlobPtr& StrBlobPtr::incr() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}
