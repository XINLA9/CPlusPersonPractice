
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
有一个服务器组，每个服务器组有最大处理数量和生命值，分别记录在数组 health 和 request 中，
一个黑客需要每次给所有仍在运作的服务器发送最大处理，同时选择一个服务器发送病毒，
病毒会对服务器的生命造成k的伤害，如果服务的生命小于等于0就会关闭。
请问最少要发多少处理请求才能关闭所有的服务器。
*/

int minRequestsToShutDownServer(vector<int> health, vector<int> request, int k){
	int ans;
	int n = health.size();

	priority_queue<pair<double, int>> queue;
	for (int i = 0; i < n; i++) {
		int attackCount = ceil((double)health[i] / k);
		double eff = (double)request[i] / attackCount;
		queue.push({eff, i});
	}

	while (!queue.empty()) {
		for (int i = 0; i < n; i++) {
			if (health[i] > 0) {
				ans += request[i];
			}
		}
		int server = queue.top().second; 
		health[server] -= k;
		if (health[server] <= 0) {
			queue.pop();
		}
	}
	return ans;
}

int main() {
	vector<int> healths = { 10, 5, 12 };
	vector<int> requests = { 100, 20, 60 };
	int k = 5;
	cout << minRequestsToShutDownServer(healths, requests, k) << endl;
	return 0;
}