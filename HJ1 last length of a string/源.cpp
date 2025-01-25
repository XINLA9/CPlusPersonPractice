#include <iostream>
#include <random>
using namespace std;

int main() {
    
    string s;
    char c;
    cin >> s >> c;
    int count = 0;
    for (string::iterator i = s.begin(); i != s.end(); i++)
    {
        if (tolower(*i) == c) {
            count++;
        }
    }

    cout << count << endl;
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 500);



}
// 64 Î»Êä³öÇëÓÃ printf("%lld")