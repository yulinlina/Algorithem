#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int n;
vector<int> res;
int visit[25] = { 0 };

bool isprime(int n) {
	if (n == 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
void backtrack(int index) {
	if (index == n+1) {
		for (int i = 0;i < n;i++)
			cout << res[i] << " ";
		cout << endl;
	}
	for (int i = 2;i <= n;i++) {
		if (!visit[i] && isprime(i + res.back())) {
			if(index==n && !isprime(1+i)) continue;
			visit[i]=1;
			res.push_back(i);
			backtrack(index+ 1);
			visit[i] = 0;
			res.pop_back();
		}
	}
		
}
int main() {
	cin >> n;
	res.push_back(1);
	visit[1] = 1;
	backtrack(2);
	return 0;
}