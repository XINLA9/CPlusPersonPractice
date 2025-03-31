#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void change(vector<int>& weights, int diff, int& count) {
    sort(weights.begin(), weights.end(),greater<int>());
    count++;
    if (weights[0] >= diff) {
        return;
    }
    else {
        diff = diff - weights[0];
        weights[0] = 0;
        //cout << "still need to change weight, different is " << diff << endl;
        change(weights, diff, count);
    }
}

int main() {
    int left_num, right_num, count = 0;
    vector<int> weights;
    int diff = 0;
    cin >> left_num;
    for (int i = 0; i < left_num; i++) {
        int w;
        cin >> w;
        weights.push_back(w);
        diff += w;
    }
    cin >> right_num;
    for (int i = 0; i < right_num; i++) {
        int w;
        cin >> w;
        w = -w;
        weights.push_back(w);
        diff += w;
    }

    if (diff == 0) {
        cout << 0;
    }
    else if(diff > 0)
    {
        for(auto& weight : weights) {
            if (weight > 0) {
                weight = weight - 1;
            }
            else {
                weight = weight + 10;
            }
        }
    }
    else if (diff < 0)
    {
        for (auto& weight : weights) {
            if (weight > 0) {
                weight = 10 - weight;
            }
            else {
                weight = -1 - weight;
            }
        }
    }
    
    diff = abs(diff);

    change(weights, diff, count);
    cout << count;

}



// 64 Î»Êä³öÇëÓÃ printf("%lld")
