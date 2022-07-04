//#include<iostream>
//#include<cstring>
//#define _for(i,a,b) for(int i=(a);i<(b);i++)
//using namespace std;
//#define N  1010
//int y[N];
//int V[N];
//int dp[N][N] = { 0 };
//int n, v;
//int max_magic = 0;
//int bag() {
//	int t;
//	cin >> t;
//	_for(i, 0, t) {
//		memset(dp, 0, sizeof(int) * N*N);
//		cin >> n >> v;
//		//cout << "n:" <<n<< endl;
//		_for(i, 1, n+1) cin >> y[i];// 魔力
//		for (int j = 1; j <=n;j++) cin >> V[j];
//		//cout << "需要魔力值" << V[1];//所需魔力
//		//_for(i, V[1], n + 1)  dp[1][i] = y[1];
//		//_for(i, 0, n) cout << "初始值"<<dp[1][i] << endl;
//		_for(i, 1, n+1) {
//			_for(j, 1, v+1) {
//				if (j - V[i] >=0)
//					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - V[i]] + y[i]);
//				else
//					dp[i][j] = dp[i - 1][j];
//			}
//		}
//		cout << dp[n][v] << endl;
//	}
//	return 0;
//}