//#include<iostream>
//#define _for(i,a,b) for(int i=a;i<b;i++)
//using namespace std;
//int c[110][110] = {0};
//int a[110] = { 0 };
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0;i <= n;i++) { cin >> a[i]; }
//	for (int i = n-1; i >= 1;i--) {
//		for (int j = i+1; j<=n;j++) { // J 表示 矩阵索引从1开始
//			c[i][j] = c[i+1][j]+a[i-1]*a[i]*a[j];
//			for (int k = i;k <=j;k++) {
//				c[i][j] = min(c[i][k] + c[k+1][j] + a[i-1] * a[k] * a[j], c[i][j]);
//			}
//		}
//	}
//	cout << c[1][n] << endl;
//}