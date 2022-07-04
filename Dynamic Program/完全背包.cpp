//#include<iostream>
//#include<cstring>
//#define _for(i,a,b) for(int i=(a);i<(b);i++)
//using namespace std;
//#define N 50010
//int weight[N];
//int beauty[510];
//int dp[N] = { 0 };
//int n, v;
//int main() {
//	int t;
//	cin >> t;
//	_for(i, 0, t) {
//		cin >> n >> v;
//		v *= 100;
//		memset(dp, 0, sizeof(int) * N);
//		//cout << "n:" <<n<< endl;
//		_for(i, 1, n + 1) cin >> beauty[i];// 魔力
//		_for(i, 1, n + 1) {
//			float tmp;
//			cin >> tmp;
//			weight[i] = tmp * 100;
//		}
//		// 把浮点重量转化成整数
//		_for(i, 1, n + 1) {
//			_for(j, weight[i], v + 1) {
//					dp[j] = max(dp[j - weight[i]] + beauty[i], dp[j]);
//			}
//		}
//		cout << dp[v] << endl;
//	}
//	return 0;
//}