#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
#define N 20

struct country
{
	int visit;
	int adj[3];
}countries[30];

vector<int> res;
int start;
int cnt;

void outputs(int cnt) {
	printf("%d:  ", cnt);
	for (int i = 0;i < 20;i++) {
		printf("%d ", res[i]);
	}
	printf("%d\n",start);
	
}
void backtrack(int index) {
	if (index == N) {
		for (int i = 0;i < 3;i++) {
			if (countries[res.back()].adj[i] == start) {
				cnt++;
				outputs(cnt);
			}
		}
	}
	for (int i = 0;i <3;i++) {
		int opt = countries[res.back()].adj[i];
		if (!countries[opt].visit) {
			res.push_back(opt);
			countries[opt].visit = 1;
			backtrack(index + 1);
			countries[opt].visit = 0;
			res.pop_back();
		}
	}

}

int main() {
	
	for (int i = 1;i <= N;i++) {
		for (int j = 0;j < 3;j++) {
			cin >> countries[i].adj[j];
		}
		sort(countries[i].adj, countries[i].adj + 3);
		countries[i].visit = 0;
	}
	cin >> start;
	countries[start].visit = 1;
	res.push_back(start);
	backtrack(1);
	
	return 0;
}