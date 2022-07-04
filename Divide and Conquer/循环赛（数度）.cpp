//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//#define _for(i,a,b) for(int i=(a);i<(b);i++)
//int a[1024][1024] = { 0 };
//void table(int n) {
//	if (!n) cout << 0 << endl;
//	_for(i, 0, n) {
//		_for(j, 0, n) {
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//int main() {
//	int n;
//	int k = 10;
//	a[0][0] = 1;a[0][1] = 2;a[1][0] = 2;a[1][1] = 1;
//	_for(i, 2, k + 1) {
//		int s = (2 << i - 2);
//		_for(row, 0, s) {
//			_for(col, 0, s) {
//				a[row][col + s] = a[row][col] + s;
//				a[row + s][col] = a[row][col] + s;
//				a[row + s][col + s] = a[row][col];
//			}
//		}
//	}
//	while (cin >> n)
//		table(n);
//	return 0;
//}