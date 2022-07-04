#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef struct activity {
	int l;
	int r;
	
}activity;
bool cmp(activity a, activity b) {
	return a.r < b.r;
}

int main() {
	int t;
	cin >> t;
	while (t)
	{
		int n;
		cin >> n;
		activity* a = (activity*)malloc(sizeof(activity) * n);
		for (int i = 0;i < n;i++) {
			cin >> a[i].l >> a[i].r;
		}
		sort(a, a + n, cmp);
		int cnt = 1;
		int right = a[0].r;
		for (int i = 0;i <n;i++) {
			if (a[i].l>=right) {
				right = a[i].r;
				cnt++;
			}
		}
		cout << cnt << endl;
		free(a);
		t--;
	}
	return 0;
}