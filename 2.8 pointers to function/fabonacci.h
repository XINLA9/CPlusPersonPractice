#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const vector<int>* fibon_seq(int size);
const vector<int>* lucas_seq(int size);
const vector<int>* pell_seq(int size);
const vector<int>* triang_seq(int size);

bool seq_elem(int pos, int& elem);

void display_information();