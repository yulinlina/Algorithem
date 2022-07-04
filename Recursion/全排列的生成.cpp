#include<iostream>
#include<algorithm>
#define _for(i,a,b) for(int i =(a);i<b;i++)
using namespace std;
int main() {
	int a[9];
	int n;
	scanf("%d", &n);
	_for(i, 0, n)
		a[i] = i + 1;
	do {
		_for(i, 0, n) {
			cout << a[i];
		}
		cout << endl;
	} while (next_permutation(a, a + n));
	return 0;
}
