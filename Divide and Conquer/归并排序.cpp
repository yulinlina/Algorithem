//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//#define _for(i,a,b) for(int i=(a);i<b;i++)
//int n;
//vector<int> c;
//vector<int> mergesort(int left,int right) {
//	if (left == right) { 
//		vector<int> v;
//		v.push_back(c[left]);
//		return v; 
//	}
//	int mid = (left + right) >> 1;
//	vector<int> a = mergesort(left, mid);
//	vector<int> b = mergesort(mid + 1, right);
//	vector<int> c1;
//	int i = 0, j = 0;
//	while (i < a.size() && j < b.size()) {
//		if (a[i] < b[j]) {
//			c1.push_back(a[i]);
//			i++;
//		}
//		else {
//			c1.push_back(b[j]);
//			j++;
//		}
//	}
//	if (i == a.size()) {
//		_for(k, j, b.size())
//			c1.push_back(b[k]);
//	}
//	else {
//		_for(k, i, a.size())
//			c1.push_back(a[k]);
//	}
//	return c1;
//}
//int main() {
//	while(cin >> n) {
//		int v;
//		c.clear();
//		_for(i, 0, n) {
//			cin >> v;
//			c.push_back(v);
//		}
//		c= mergesort(0, n - 1);
//		_for(i, 0, n) cout << c[i] << " ";
//		cout << endl;
//	}
//	return 0;
//}