#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
һ��������[0,9]��ɣ���ʾ26�������������������û�пո����ڸ���һ�δ�����ַ��������м��ֿ��ܵ����෽ʽ��
*/

int main() {
	int n;7   3
	cin >> n;
	if (n < 2) {
		cout << 1 << endl;
		return 0;
	}
	string s;
	cin >> s;
	int dp0 = 1;
	int dp1 = 1;
	for (int i = 2; i <= n; i++) {
		int dp2 = 0;
		if (s[i - 1] != '0') {
			dp2 += dp1;
		}
		if (i - 2 >= 0 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7'))) {
			dp2 += dp0;
		}
		dp0 = dp1;
		dp1 = dp2;
	}
	cout << dp1 << endl;

	return 0;
}


