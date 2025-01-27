#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void bubble_sort(vector<int>& vec, ofstream &ofli) {
	for (int ix = 0; ix < vec.size()-1; ix++)
	{
		for (int jx = ix +1; jx < vec.size(); jx++)
		{
			if (vec[ix] > vec[jx]) {

				/*if ( ofli != 0) {
					
				}*/
				(ofli) << "About to swap " << ix << ": " << vec[ix]
					<< " \t with " << jx << ": " << vec[jx] << endl;
				int temp = vec[ix];
				vec[ix] = vec[jx];
				vec[jx] = temp;
			}
		}
	}
}

void bubble_sort(vector<int>& vec, ostream* os = &cout) {
	for (int ix = 0; ix < vec.size() - 1; ix++)
	{
		for (int jx = ix + 1; jx < vec.size(); jx++)
		{
			if (vec[ix] > vec[jx]) {

				if (os != 0) {
					(*os) << "About to swap " << ix << ": " << vec[ix]
						<< " \t with " << jx << ": " << vec[jx] << endl;
				}
				int temp = vec[ix];
				vec[ix] = vec[jx];
				vec[jx] = temp;
			}
		}
	}
}

