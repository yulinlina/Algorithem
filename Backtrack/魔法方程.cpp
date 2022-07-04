#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;
int flag;

struct equ {
	int visit;
	vector<char> v;
};

void backtrack(char opt,map<char,equ>& m) {
	if (flag) return;
	if (opt == 'm') {
		flag = 1;
		return;
	}
	for (int i = 0;i < m[opt].v.size();i++) {
		if (!m[opt].visit) {
			m[opt].visit = 1;
			backtrack(m[opt].v[i],m);
			m[opt].visit = 0;
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t)
	{
		int n;
		cin >> n;
		map<char,equ> m;
		flag = 0;
		for(int i=0;i<n;i++) {
			string s;
			cin >> s;
			m[s[0]].v.push_back(s.back());
			m[s[0]].visit = 0;
		}
		backtrack('b', m);
		if(flag) cout << "Yes." << endl;
		else cout << "No." << endl;
		t--;
	}
	
	
}

