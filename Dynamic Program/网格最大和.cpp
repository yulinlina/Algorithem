#include<iostream>
#include<algorithm>
#define _for(i,a,b) for(int i=(a);i<b;i++)
using namespace std;
int farm[210][210] = {0};
int farm_max() {
	int m, n;
	cin >> n>>m;
	//memset(farm,-200, sizeof(int) * 40010);
	_for(i, 1, n+1) {
		_for(j, 1, m+1) {
			cin >> farm[i][j];
		}
	}
	_for(i, 1, n + 1) {
		_for(j, 1, m + 1) {
			if (i == 1) farm[i][j] += farm[i][j - 1];
			else if (j == 1) farm[i][j] += farm[i - 1][j];
			else
			farm[i][j] += max(farm[i][j - 1], farm[i - 1][j]);
		}
	}
	cout << farm[n][m] << endl;
	return 0;
}