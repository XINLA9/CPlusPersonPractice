#include <iostream>
#include <algorithm>
using namespace std;

string recurisve(int no, unsigned long long index, bool flip = 0) {
    if (no == 1) {
        return flip == 0 ? "red" : "blue";
    }
    unsigned long long length = pow(2, no - 2);
    if (index >= length) {
        return recurisve(no - 1, index - length, flip);
    }
    else {
        return recurisve(no - 1, index, !flip);
    }
}

int main() {
    cout << 1 << 0 << recurisve(1, 0) << endl;
    cout << 2 << 1 << recurisve(2, 1) << endl;
    cout << 3 << 2 << recurisve(3, 2) << endl;
    cout << 4 << 6 << recurisve(4, 6) << endl;
    cout << 5 << 8 << recurisve(5, 8) << endl;
}