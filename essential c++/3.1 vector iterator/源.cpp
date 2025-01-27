# include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

template<typename IteratorType, typename elemType>
IteratorType myFind(IteratorType first, IteratorType last ,const elemType &value) {
	for (;first  != last; first++)
	{
		if (value == *first) {
			return first;
		}
	}
	return last;
}

int main() {
	const int asize = 8;
	int ia[asize] = { 1,1,2,3,5,8,13,21 };
	cout << ia + asize - 1 << " is " << *(ia + asize - 1) << endl;

	vector<int> ivec(ia, ia+asize);
	list<int> ilist(ia, ia + asize);

	int* pia = myFind(ia, ia + asize, 23);
	if (pia != ia + asize)
		cout << "find it!" << endl;
	else
		cout << "do not find it!" << endl;

	vector<int>::iterator it;
	it = myFind(ivec.begin(), ivec.end(), 5);
	
	if (it != ivec.end()) {
		cout << "find it!" << endl;
	}
	else
		cout << "do not find it!" << endl;

	list<int>::iterator iter;
	iter = myFind(ilist.begin(), ilist.end(), 13);
	if (iter != ilist.end()) {
		cout << "find it!" << endl;
	}
	else
		cout << "do not find it!" << endl;

	return 0;
}


