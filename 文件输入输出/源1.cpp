#include <iostream>
#include <fstream>
using namespace std;

int main() {
	fstream out;
	out.open("hello_world.txt",0);

	string oldInformation;

	out >> oldInformation;

	cout << oldInformation << endl;

	cout << "input information!" << endl;
	string data;
	cin >> data;

	out << data << endl;

}
