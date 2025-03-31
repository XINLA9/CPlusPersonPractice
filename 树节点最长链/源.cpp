#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

/*
* 查一个n节点的树上，所有值大于等于或小于等于父节点的节点组的最长链
节点数据输入是
n(节点数)
w1 w2 w3 w4 w5....（节点权重值）
n1 n2
n2 n3
n2 n4
..........（节点连接）
test sample
1. 5 1 2 3 4 5 1 2 2 3 1 4 4 5

5
1 2 3 4 5
1 2
2 3
1 4
4 5
-1 -1

5
1 3 3 2 4
1 2
2 3
3 4
3 5
-1 -1

*/

int main() {
	cout << "please input nodes number:" << endl;
	int n;
	cin >> n;
	if (n < 2) {
		cout << n;
		return 0;
	}

	vector<int> weights(n, 0);
	unordered_map<int, int> getParent;

	// 每个节点的数据， 是否是子节点， 小于链， 大于链
	vector<int> parInf(n, 0);
	vector<int> nodes_alpha(n, 1);
	vector<int> nodes_beta(n, 1);

	cout << "please input nodes weight" << endl;
	for (int i = 0; i < n; i++) {
		cin >> weights[i];
	}
	cout << "please input edge:" << endl;
	int parent1, children1;

	while (cin >> parent1 >> children1) {
		if (parent1 == -1 && children1 == -1) {
			break;
		}
		parInf[parent1 - 1] = 1;
		getParent[children1 - 1] = parent1 - 1;
	}

	queue<int> queue;
	set<int> inQueue;

	for (int i = 0; i < n; i++) {
		if (parInf[i] == 0) {
			queue.push(i);
		}
	}
	int maxL = 1;
	while (!queue.empty()) {
		int node = queue.front();
		queue.pop();
		inQueue.erase(node);
		if (node == 0) {
			continue;
		}
		int parent = getParent[node];
		bool upDated = false;

		if (weights[parent] >= weights[node]) {
			int alpha = nodes_alpha[node] + nodes_alpha[parent];
			if (alpha > maxL) {
				maxL = alpha;
				cout << "get a longer chain at node: " << parent << " ,which length is " << alpha << endl;
			}
			if (nodes_alpha[node] + 1 > nodes_alpha[parent]) {
				upDated = true;
				nodes_alpha[parent] = nodes_alpha[node] + 1;
			}
		}
		if (weights[parent] <= weights[node]) {
			int beta = nodes_beta[node] + nodes_beta[parent];
			if (beta > maxL) {
				maxL = beta;
				cout << "get a longer chain at node: " << parent << " ,which length is " << beta << endl;
			}
			if (nodes_beta[node] + 1 > nodes_beta[parent]) {
				upDated = true;
				nodes_beta[parent] = nodes_beta[node] + 1;
			}
		}
		if (upDated) {
			if (inQueue.find(parent) == inQueue.end()) {
				queue.push(parent);
				inQueue.insert(parent);
			}
		}

		/*cout << "parent node: " << parent << " ,alpha: " << incChain[parent] << " ,beta: " << desChain[parent] << endl;*/
	}

	cout << maxL;

}