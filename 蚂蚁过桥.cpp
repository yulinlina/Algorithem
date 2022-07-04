#include<iostream>

using namespace std;

void process() {
	int Length,n;
	int mint = 0;
	int maxt = 0;
	cin >> Length>>n;

	int* a = (int*)malloc(sizeof(int) * n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
		mint = max(mint,min(a[i], Length + 1 - a[i]));
		maxt = max(maxt,max(a[i], Length + 1 - a[i]));
	}
	
	cout << mint << " "<<maxt << endl;
	free(a);
	
}
int main() {
	int t;
	cin >> t;
	while (t) {
		process();
		t--;
	}
}