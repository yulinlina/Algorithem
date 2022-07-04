//#include<iostream>
//#define _for(i,a,b) for(int i=a;i<b;i++)
//using namespace std;
//#define N  1010
//int a[N];
//int b[N];
//int main() {
//	int n;
//	cin >> n;
//	_for(i, 0, n) cin >> a[i];
//	_for(i, 0, n)cin >> b[i];
//	int dp[2][N] = {0};
//	_for(i, 1, n) {
//		_for(j, 1, n) {
//			if (a[i] == b[j])
//				dp[i & 1][j] = dp[(i - 1) & 1][j-1] + 1;
//
//			else
//				dp[i & 1][j] = max(dp[i & 1][j - 1], dp[(i - 1) & 1][j]);
//		}
//	}
//	cout << dp[(n-1) & 1][n - 1] << endl;
//}
