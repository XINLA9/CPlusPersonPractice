#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
	string user_name;
	cout << "Please enter user name!" << endl;
	cin >> user_name;


	ofstream outfile("seq_data.txt");
	if (!outfile)
		cerr << "Oops! Unable to open session data!\n";
	else
		outfile << user_name << ' '
		<< endl;

	return 0;
}