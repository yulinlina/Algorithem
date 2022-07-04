#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef struct activity {
	int l;
	int r;

}activity;
bool cmp1(activity a, activity b) {
	return a.r >b.r;
}
bool cmp2(activity a, activity b) {
	return a.l < b.l;
}

void Process();
int main() {
	int t;
	cin >> t;
	while (t)
	{
		Process();
		t--;
	}
	return 0;
}
void Process() {
	int n, m;
	cin >> n >> m;
	activity* a = (activity*)malloc(sizeof(activity) * n);
	for (int i = 0;i < n;i++) {
		cin >> a[i].l >> a[i].r;
	}
	sort(a, a + n, cmp1);
	sort(a, a + n, cmp2);
	
	
	int cnt = 0; // 第一个已经找到
	int right = 0, j = 0;
	while (right<m)
	{
		int left = right + 1;
		for (int i = 0;i < n;i++) {
			if (a[i].l <= left)
				right = right > a[i].r ? right : a[i].r;
			else if (a[i].l > left) {
				j = i;
				break;
			}
		}
		if (right < left) break; // 没有更新表示没有区间的左边界在内
		else cnt++;

	
	}
	if (right >= m) cout << cnt << endl;
	else cout << -1 << endl;
	free(a);
}