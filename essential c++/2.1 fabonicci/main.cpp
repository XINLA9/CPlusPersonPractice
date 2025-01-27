#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "fabonacci.h"
using namespace std;

const vector<int>*fibon_seq(int size) {
	const int max_size = 1024;
	static vector<int> elems;
	if (size <= 0 || size >= max_size) {
		cerr << "fibon_seq(): invalid size: "
			<< size << "can't fulfill request.\n";
		return nullptr;
	}

	/*if (size <= elems.size()) {
		cout << "No need to extend! The size of the current fequence is" << elems.size() << endl;
	}*/

	for (size_t ix = elems.size(); ix < size; ix++)
	{
		if (ix == 0 || ix == 1) {
			elems.push_back(1);
		}
		else
			elems.push_back(elems[ix - 1] + elems[ix - 2]);
	}

	return &elems;
}

bool seq_elem(int pos, int& elem) {

	if (pos <= 0 || pos > 1024) {
		elem = 0;
		return false;
	}
	const vector<int> *elems = fibon_seq(pos);
	elem = elems->at(pos - 1);

	cout << "The sequence recorded now is :" << endl;
	for (size_t i = 0; i < elems->size(); i++)
	{
		cout << elems->at(i) << (((i+1) % 8 == 0) ? "\n" : " ");
	}
	cout << endl;

	return true;
}
template <typename elemType>
void display_information() {

}

int main() {

	int elem = 0;
	int pos =0;

	while (pos != -1) {
		cout << "Please enter the index of the number you want to get, or enter -1 to leave." << endl;
		cin >> pos;


		if (seq_elem(pos, elem)) {
			cout << "The " << pos << " number in fabonacci sequence is " << elem  << "\n" << endl;
		}
		else
		{
			cout << "please enter a vaild index number.\n" << endl;
		}
	}
	
	return 0;
}