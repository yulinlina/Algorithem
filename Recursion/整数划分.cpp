#include<iostream>
#include<math.h>
using namespace std;
int DC(int n, int m) {
	if (m == 1||n==1) return 1;
	else if (n<m) return DC(n,n);
	else if (n == 0) return 1;
	else {
		return DC(n - m, m) + DC(n, m - 1);
	}
}
int main() {
	int n,m;
	while (cin >> n>>m) {
		if ((n - m) < 0) cout << 0 << endl;
		else
		cout << DC(n-m, m)<<endl;
	}
	return 0;
}