#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n, q, a[3][maxn + 3], A[maxn + 3], B[maxn + 3], C[maxn + 3];

int main() {
	scanf("%d %d", &n, &q);
	int cur = 0;
	for (int x, y; q --> 0; ) {
		scanf("%d %d", &x, &y);
		if (A[y] == 2) cur--;
		if (B[y - x + 1] == 2) cur--;
		if (C[y + x - 1] == 2) cur--;
		if (a[x][y]) {
			A[y]--, B[y - x + 1]--, C[y + x - 1]--;
		} else {
			A[y]++, B[y - x + 1]++, C[y + x - 1]++;
		}
		a[x][y] ^= 1;
		if (A[y] == 2) cur++;
		if (B[y - x + 1] == 2) cur++;
		if (C[y + x - 1] == 2) cur++;
		if (cur == 0) {
			puts("Yes");
		} else {
			puts("No");
		}
	}
	return 0;
}