#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
*对于一个激光打印文件，其包含若干个几何图形，打印每个图形的速度，每个几何图形包含的若干个顶点。
* 激光打印机可以在任何位置开始，但是最后必须返回初始点。
* 现在请计算最快完成所有图形的路径与时间。
* 输入的文件如下所示
* n（表示总图形数）
* s（不打印时激光头的移动速度）
* s1 s2 s3 s4 ...（打印每个图形时激光头的移动速度）
* ...
* n1
* x1 y1
* x2 y2
* x3 y3
* ...
* n2
* x1 y1
* x2 y2
* x3 y3
* ...
* ......
*/



struct Point
{
	int x, y;
};

double distance(Point a, Point b) {
	return sqrt((a.x - b.x)* (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

/*
算法的可能解法：
1.贪心算法：
a. 从任意图形出发进行绘制，绘制完成后寻找最近的未绘制图形
b. 最近的判断标准，是图形质点之间的距离
c. 对于封闭的图形，选择端点的标准
	- 使用离质点最近的端点
	- 计算所有图形质点的中心点，选择离中心点最近的端点

2.dijkstra算法
a.将图形视作一个点，将所有图形视为一个无向图，求解tsp问题
b.

2.a*算法：
a. 
b. 
c. 

3. 


*/

double minPath(int speed, vector<int>& speeds, vector<vector<Point>> & paths) {

}

int main() {
	
	int n;
	cin >> n;

	int s;
	cin >> s;

	vector<int> speeds;

	for (int i = 0; i < n; i++) {
		int speed;
		cin >> speed;
		speeds.push_back(speed);
	}
	vector<vector<Point>> paths;

	for (int i = 0; i < n; i++) {
		int nodeNum;
		cin >> nodeNum;
		vector<Point> path;
		for (int j = 0; j < nodeNum; j++) {
			int x, y;
			cin >> x >> y;
			path.push_back({x,y});
		}
		paths.push_back(path);
	}
	
	
	return 0;
}




