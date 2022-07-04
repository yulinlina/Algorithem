#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef struct thread {
	int o;
	int r;
}thread;

bool cmp(thread a, thread b) {
	return a.r - a.o >b.r - b.o;
}


int main() {
	int n;
	cin >> n;
	thread* t = (thread*)malloc(sizeof(thread) * n);
	for (int i = 0;i < n;i++) {
		cin >> t[i].r;
		cin >> t[i].o;
	}
	sort(t, t + n,cmp);

	int sum = 0;
	for (int i = 0;i < n-1;i++) {
		sum += t[i].o;
	}
	cout << sum + t[n - 1].r << endl;
	free(t);
}