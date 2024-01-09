#include <string>
#include <iostream>
using namespace std;
int main() {
	int findGCD(int, int);
	int findLCM(int, int);
	int num1, num2;
	cin >> num1 >> num2;
	cout << findGCD(num1,num2) << "\n" << findLCM(num1, num2) << endl;	
}

int findGCD(int num1, int num2) {
	while (num1 != num2) {
	if (num1 > num2) {
		num1 -= num2;
		}
	else if (num1 < num2) {
		num2 -= num1;
		}
	}
	return num1;
}
int findLCM(int num1, int num2) {
	return (num1 * num2) / findGCD(num1, num2);
}