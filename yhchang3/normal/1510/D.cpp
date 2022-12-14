#include <bits/stdc++.h>

#define prev pp
using namespace std;

double f[100005][12];
int prev[100005][12];
int ans = -1;
int idx;
int n, k, a[200001];
int top, stk[200001];
int main( ) {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 0; i <= n; i ++)
		for (int j = 0; j < 10; j ++)
			f[i][j] = -1;
	f[0][1] = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < 10; j ++) {
			f[i][j] = f[i - 1][j];
			prev[i][j] = -1;
		}
		for (int j = 0; j < 10; j ++) {
			int nx = j * a[i] % 10;
			if (f[i - 1][j] == -1) continue;
			if (f[i - 1][j] + log(a[i]) > f[i][nx]) {
				f[i][nx] = f[i - 1][j] + log(a[i]);
				prev[i][nx] = j;
			}
		}
}
	if (f[n][k] == -1) printf("-1\n");
	else {
		int cur = k;
		for (int i = n; i >= 1; i --) {
			int tmp = prev[i][cur];
			if (tmp == -1) continue;
			else {
				stk[++ top] = a[i];
				cur = tmp;
			}
		}
		if (top == 0) printf("-1\n");
		else {
			printf("%d\n", top);
			for (int i = 1; i <= top; i ++)
				printf("%d ", stk[i]);
			puts("");
		}
	}
	return 0;
}