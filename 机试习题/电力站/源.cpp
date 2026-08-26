#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<vector<int>> powers;
    vector<int> groups;
    set<int> groupSet;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        int group = 0;
        int nn = powers.size();
        if (i == 0) {
            groups.push_back(1);
            powers.push_back({ x,y });
            ans.push_back(1);
            groupSet.insert(1);
            continue;
        }
        for (int j = 0; j < nn; j++) {
            if (groups[i] == group) {
                continue;
            }
            int powerX = powers[j][0];
            int powerY = powers[j][1];
            if (abs(powerX - x) <= 1 && abs(powerY - y) <= 1) {
                if (group == 0) {
                    group = groups[j];
                }
                else {
                    int changeGroup = max(group, groups[i]);
                    groupSet.erase(changeGroup);

                    group = min(group, groups[i]);
                    // cout << changeGroup << " " << group;
                    for (int k = 0; k < groups.size(); k++) {
                        if (groups[k] == changeGroup) {
                            groups[k] = group;
                        }
                    }
                }
            }
            else {
                group = groups[j]++;
            }
        }
        powers.push_back({ x,y });
        groups.push_back(group);
        groupSet.insert(group);
        int energy = 0;
        // cout << groupSet.size() << endl;
        for (int g1 : groupSet) {
            int count = 0;
            for (int g2 : groups) {
                if (g1 == g2) {
                    count++;
                }
            }
            energy += pow(count, 2);
        }
        ans.push_back(energy);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}