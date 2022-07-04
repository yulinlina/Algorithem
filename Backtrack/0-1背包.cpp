#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<math.h>
using namespace std;

long long n;
long long v;
long long res;
long long best;
int x[100] = { 0 };
struct good {
	int v;
	int w;
}goods[100];

bool cmp(good x, good y) {
	return x.v/float(x.w)> y.v/float(y.w);
}

void backtrack(int index,long curWeight) {
	if (index == n) {
		best = max(best, res);
		return;
	}
	if (curWeight + goods[index].w <= v) {
		curWeight += goods[index].w;
		res += goods[index].v;
		backtrack(index + 1, curWeight);
		curWeight -= goods[index].w;
		res -= goods[index].v;
	}
	backtrack(index + 1, curWeight);
	

}

int main() {
	
	cin >> n >> v;
	for (int i = 0;i < n;i++) {
		cin >> goods[i].w >> goods[i].v;
	}
	sort(goods, goods + n, cmp);
	backtrack(0,0);
	cout << best << endl;
	return 0;
}





 






