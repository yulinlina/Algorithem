#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef struct meat {
	int j;
	int f;
	float r;
}meat;
bool cmp(meat a, meat b){
	return a.r > b.r;
}
int main() {
	int w,n;
	cin >> w >> n;
	meat* m = (meat*)malloc(sizeof(meat) * n);
	for (int i = 0;i < n;i++) {
		cin >> m[i].j >> m[i].f;
		m[i].r = (float)m[i].j / m[i].f;
	}
	sort(m, m + n, cmp);
	float sum = 0;
	for (int i = 0;i < n;i++) {
		if (w >=m[i].f) {
			sum += m[i].j;
			w -= m[i].f;
		}
		else if (w > 0) {
			sum += w * m[i].r;
			break;
		}

	}
	printf("%.3f", sum);
	free(m);
}