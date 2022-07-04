#include<iostream>
#include<queue>
using namespace std;

void process() {
	long n;
	cin >> n;
	priority_queue<long, vector<long>, greater<long> >pqueue;
	
	for (int i = 0;i < n;i++) {
		long tmp = 0;
		cin >> tmp;
		pqueue.push(tmp);
	}

	long result = 0;
	while (pqueue.size()>=2) {
		long first = pqueue.top();
		pqueue.pop();
		long last = pqueue.top();
		pqueue.pop();
		pqueue.push(first + last);
		result += first + last;
	}

	cout << result << endl;
}


int main() {
	long t;
	cin >> t;
	while (t) {
		t--;
		process();
	}
	
}