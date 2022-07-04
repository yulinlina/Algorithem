#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

#define MAX 0x3f3f
int map[1005][1005];
int dist[1005];
int flag[1005] = { 0 };
int n, m;

void process() {
	for (int i = 1;i <= n;i++) {
		dist[i] = map[1][i];
	}
	flag[1] = 1;  // 开始结点1选入
	dist[1] = 0;
	int sum = 0, pos = 1;
	for (int j = 0;j < n;j++) {  // 连接n-1个结点
		int min = MAX;
		for (int i = 1;i <= n;i++) {
			if (!flag[i] && dist[i] < min) {
				min = dist[i];
				pos = i;
			}
		}
		if(j)sum += min;
		flag[pos] = 1;

		for (int i = 1;i <= n;i++) { // 更新dist可以不加flag?
			if (dist[i] > map[pos][i]) {
				dist[i] = map[pos][i];
			}
		}
	}

	cout << sum << endl;
}

int main() {
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			map[i][j] = MAX;
		}
	}

	for (int i = 0;i < m;i++) {
		int x, y, r;
		scanf("%d%d%d", &x, &y, &r);
		map[x][y] = r;
		map[y][x] = r;
	}
	process();

	return 0;
}




