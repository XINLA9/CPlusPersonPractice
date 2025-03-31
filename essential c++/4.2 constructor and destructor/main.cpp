#include <iostream>
#include<vector>

using namespace std;

int main() {
	int ia[] = {1,2,3,4,5};
	
	vector<int> iv( ia, ia + 5);

	for (size_t i = 0; i < iv.size(); i++)
	{
		cout << iv[i];
	}
	
	return 0;
}