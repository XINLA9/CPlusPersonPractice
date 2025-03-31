#include "Triangular.h"

Triangular& Triangular::copy(const Triangular &rhs){
	_length = rhs.length();
	_beg_pos = rhs.beg_pos();
	_next = rhs.next();
	
	return;
}

inline bool Triangular_iterator::
operator== (const Triangular_iterator & rhs)const {
	return _index == rhs._index;
}
