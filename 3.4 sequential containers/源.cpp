#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

template <typename containerType, typename iter>
void print(const containerType &con, const iter &cit) {
	for (auto it = con.begin(); it != con.end(); it++)
	{
		if(it == cit)
			cout << "|" << *it << "| ";
		else
			cout << *it << " ";
			
	}
	cout << endl;
}

int main() {
	deque<int> a_line;
	int ival;
	//while (cin >> ival) {
	//	a_line.push_back(ival);

	//	int current_val = a_line.front();

	//	a_line.pop_front();
	//}

	list<int> alist(5,1);
	list<int>::iterator it = alist.begin();
	print(alist, it);


	alist.insert(it, 2);
	print(alist, it);

	it++;
	alist.insert(it, 3, 3);
	print(alist, it);

	it--;
	alist.insert(it, 4);
	print(alist, it);

	return 0;
}
