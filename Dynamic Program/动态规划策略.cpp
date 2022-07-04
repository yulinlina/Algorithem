#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
const int N = 2000010;
int a[50];
int dp[N];
int main() {
	int k, type;
	cin >> k >> type;
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 0;i < type;i++) {
		cin >> a[i];
	}
	for (int i = 0;i < type;i++) {
		for (int j = a[i];j <N;j++) {
			dp[j] = min(dp[j], dp[j - a[i]] + 1);
		}
	}
	int x = 0;
	while (dp[x] <= k)x++;
	cout << x - 1 << endl;;
	return 0;
}