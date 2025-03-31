#include <iostream>
#include <vector>
using namespace std;

vector<int> get_next(string s){
	int m = s.size();
	vector<int> next(m,0);
	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && s[i] != s[j]) {
			j = next[j - 1];
		}
		if (s[i] == s[j]) {
			j++;
		}
		next[i] = j;
	}
	return next;
}

int compare(string pattern, string s) {
	
	int m = pattern.size();
	int n = s.size();

	if (m == 0) {
		return 0;
	}
	else if (m > n) {
		return -1;
	}

	auto next = get_next(pattern);

	for (int i = 0, j = 0; i < n - 1;) {
		while (s[i] == pattern[j]) {
			j++;
			i++;
			if (j == m) {
				return i - j;
			}
		}
		while (j > 0 && s[i] != pattern[j]) {
			j = next[j - 1];
		}
		if (j == 0 && s[i] != pattern[j]) {
			i++;
		}
	}
	return -1;
}

int main(){
	
	string s;
	string pattern;
	cin >> s >> pattern;
	auto next = get_next(pattern);
	cout << "next: " << endl;
	for (auto& i : next) {
		cout << i << " ";
	}
	int index = compare(pattern, s);
	cout << index;

	return 0;
}
