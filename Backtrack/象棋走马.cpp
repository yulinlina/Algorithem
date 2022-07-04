#include<iostream>
#include <sstream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;
int n, m;
int a[50][50]={0};
int row[] = { -1,1,-2,2,-2,2,-1,1 };
int col[] = { -2,-2,-1,-1,1,1,2,2 };
vector<string> res;
int flag;
void backtrack(int x,int y,int index) {
	if (index == n * m&&!flag) {
		for (int i = 0;i < res.size();i++)
			cout << res[i];
		flag = 1;
		return;
	}
	else {
		for (int i = 0;i < 8;i++) {
			int newx = x + row[i];
			int newy = y + col[i];
			if (newx >=0 && newx <n && newy >=0 && newy <m && a[newx][newy] == 0) {
				a[newx][newy] = 1;
				stringstream fmt;
				fmt <<char('A' + newy) << newx+1;
				string step=fmt.str();
				res.push_back(step);
				backtrack(newx, newy, index + 1);
				res.pop_back();
				a[newx][newy] = 0;
			}
		}
	}
}
int main() {
	cin>> n>> m;
	a[0][0] = 1;
	res.push_back("A1");
	backtrack(0, 0, 1);
	if (!flag) cout << "impossible" << endl;
	return 0;
	
	
}