#include<iostream>
#include <sstream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
#define N 10005
int n, m;
vector<int> ans[N];
int value[N];
int visit[N];
void dfs(int q,int& res) {
	for (auto i : ans[q]) {
		res += value[i];
		dfs(i,res);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1;i <=n;i++) { 
		cin >> value[i];
	}
	visit[1] = 1;
	for (int i = 0;i < n-1;i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			ans[a].push_back(b);
			visit[b] = 1;
		}
		else if (b == 1) {
			ans[b].push_back(a);
			visit[a] = 1;
		}
		else {
			if (visit[a]) {
				ans[a].push_back(b);
				visit[b] = 1;
			}
			else
			{
				ans[b].push_back(a);
				visit[a] = 1;
			}
		}
		
	}
	for (int i = 0;i < m;i++) {
		int q;
		cin >> q;
		int res = value[q];
		dfs(q, res);
		cout << res << endl;
	}
	return 0;


}