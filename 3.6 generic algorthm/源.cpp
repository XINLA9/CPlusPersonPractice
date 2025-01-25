#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	int ia[10] = {1,3,3,1,4,4,1,2,3};
	map<string,int> m;
	vector<int> iv(ia, ia + 10);

	set<int> s (iv.begin(),iv.end());

	string tword;
	while (cin >> tword){
		m[tword]++;
	}

	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it;
	}
	s.insert(5);
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it;
	}

	return 0;
}


