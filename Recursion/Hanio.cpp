#include<iostream>
#include<vector>
#include<math.h>
#include<functional>
#include<algorithm>
#define _for(i,a,b) for(int i =(a);i<b;i++)
using namespace std;
void move(int n, char a, char b,char c,int & step) {
	if (n > 0) {
		move(n - 1, a, c, b,step);
		cout << "step " << ++step << ": " << n << " From "<<a<<" To "<<b<< endl;
		move(n - 1, c, b, a,step);
	}
	return;
}
int main() {
	int n;
	while (cin >> n) {
		int step = 0;
		cout << pow(2, n) - 1 << endl;
		move(n - 1,'A', 'B','C',step);// A - > B
		cout << "step " << ++step <<": " << n << " From A To C" << endl;
		move(n - 1, 'B', 'C','A',step); // B - >C
	}
}