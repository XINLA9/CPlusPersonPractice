#include "stack.h"
#include<string>
#include<vector>
using namespace std;

bool
Stack::empty() {
	return _stack.empty();
};

bool 
Stack::push(const string&) {
	if (full()) {
		return false;
	}
};

bool Stack::full() {
	return (_stack.size() == _stack.max_size());
}

inline bool
Stack::pop(string& elem) {
	if (_stack.empty())
		return false;

}
bool Stack::peek(string &elem){
	if (empty()) {
		return false;
	}
	elem = _stack.back();
	return true;
}
