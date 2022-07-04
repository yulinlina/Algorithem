#include<iostream>
#define _for(i,a,b) for(int i =(a);i<b;i++)
using namespace std;
int n, k,flag=1;
int a[20] = { 0 };
int total = 0;
void DFS(int pos) {
	if (flag) {
		if (total == k) {
			flag = 0;
			cout << "YE5" << endl;
		}
		else{
			_for(i, pos, n) {
				total += a[i];
				DFS(i + 1);
				total -= a[i];
			}
		}
	}
}
int main() {
	cin >> n >> k;
	_for(i, 0, n) {
		cin >> a[i];
	}
	DFS(0);
	if (flag) cout << "N0" << endl;
	return 0;
}
