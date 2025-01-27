#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "method.h"
using namespace std;

int main() {
	int v[8] = {32,13,2,4,5,7,8,11};
	vector<int> vec(v, v+8);

	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i]  << " ";
	}

	ofstream ofil ("data.txt");

	cout << "\n";
	bubble_sort(vec);
	//bubble_sort(vec, &ofil);

	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}



	return 0;
}


