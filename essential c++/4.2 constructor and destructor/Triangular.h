#pragma once
#include<vector>

using namespace std;


class Triangular {
public:

	int length() const { return _length; }
	int beg_pos() const { return _beg_pos; }
	int next() const { return _next; }

	Triangular& copy(const Triangular& rhs);

	bool next(int& val);
	void next_reset() { _next = _beg_pos - 1; }

	~Triangular()
	{

	}
private:
	vector<int> iv = vector<int>(10, 1);
	int _length;
	int _beg_pos;
	int _next;

	static vector<int> _elems;

};

class Triangular_iterator {
public:
	Triangular_iterator(int index) :_index(index){}
	bool operator==(const Triangular_iterator&) const;
	bool operator!=(const Triangular_iterator&) const;
	Triangular_iterator& operator++();
	Triangular_iterator operator++(int);
private:
	int _index;
	void check_integrity()const;
	bool operator==(const Triangular_iterator& rhs) const;
};
