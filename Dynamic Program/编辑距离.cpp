#include<iostream>
#include<algorithm>
#include<cstring>
#define _for(i,a,b) for(int i=(a);i<b;i++)
using namespace std;
string str_a;;
string str_b;
int main() {
	int t;
	cin >> t;
	while (t) {
		int dp[1000][2] = { 0 };
	/*	memset(dp, 0, sizeof(int) * N);*/
		cin >> str_a >> str_b;
		dp[0][1] = 1;
		_for(i, 1, str_a.length() + 1)
			dp[i][0] = i;
		_for(i, 1, str_a.length() + 1) {
			_for(j, 1, str_b.length() + 1) {
				if (str_a[i-1] == str_b[j-1])
					dp[i][j%2] = dp[i - 1][(j - 1)%2];
				else
					dp[i][j] = max(dp[i - 1][j%2], dp[i][(j - 1) % 2],dp[i-1][(j - 1) % 2])+1;
			}
		}
		cout << dp[str_a.length()][str_b.length()%2] << endl;
		t--;
	}
	return 0;
}