#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define _for(i,a,b) for(int i=(a);i<b;i++)
const int N = 1e6;
int a[N];
int n;
int k;
int partition(int left, int right) {
	int tmp = a[left];  // 存储标记位置的值
	while (left < right) {
		while (a[right] > tmp && right)right--;
		swap(a[right], a[left]);
		while (a[left] < tmp && left < n)left++;
		swap(a[left], a[right]);
	}
	a[left] = tmp;
	return left;
}
void Find(int l, int r) {
	int pos = partition(l, r);
	if (pos == n - k)  printf("%d\n", a[pos]);
	else if (pos < n - k) Find(pos + 1, r);
	else Find(l, pos - 1);
}

int main() {
	cin >> n >> k;
	_for(i, 0, n) scanf("%d",&a[i]);
	Find(0, n - 1);
	return 0;
}