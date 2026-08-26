
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
/*

a b c d a v c a
a
c
*/

int main(){
	string line;
	getline(cin, line);
	stringstream ss(line);

	string song;
	vector<string> songs;
	while (getline(ss, song, ' ')) {
		if (!song.empty()) {
			songs.push_back(song);
		}
	}
	
	cout << endl;
	string song1, song2;
	cin >> song1 >> song2;
	int index1 = -1, index2 = -1;
	int minDis = INT_MAX;
	/*for (auto song : songs) {
		cout << song << " ";
	}*/
	cout << song1 << " " << song2 << " " << songs.size() << endl;

	for (int i = 0; i < songs.size(); i++) {
		cout << songs[i] << endl;
		cout << index1 << index2 << endl;
		if (songs[i] == song1) {
			cout << "Find " << song1 << " at " << i << endl;
			index1 = i;
			if (index2 != -1) {
				minDis = min(minDis, abs(index1 - index2));
			}
		}
		if (songs[i] == song2) {
			cout << "Find " << song2 << " at " << i << endl;
			index2 = i;
			if (index1 != -1) {
				minDis = min(minDis, abs(index1 - index2));
			}
		}
	}
	if (index1 != 0 && index2 != 0) {
		cout << minDis << endl;
	}
	else {
		cout << "song not found£¡" << endl;
	}

	return 0;
}
