#include <bits/stdc++.h>
using namespace std;

const int maxn = 20, maxm = 1 << maxn, inf = 1e9;
int n, m, all[maxn + 3], a[maxn + 3][maxn + 3], dp[maxm + 3], k, t[maxn + 3];
char s[maxm + 3];

void add(int x, int y) {
	if (x == y) return;
	a[x][y]++, a[y][x]++, all[x]++, all[y]++;
}

void upd(int &x, int y) {
	x > y ? x = y : 0;
}

int main() {
	scanf("%d %d %s", &n, &m, s + 1);
	for (int i = 1; i < n; i++) {
		add(s[i] - 'a' + 1, s[i + 1] - 'a' + 1);
	}
	dp[0] = 0;
	for (int msk = 1; msk < 1 << m; msk++) {
		dp[msk] = inf, k = 0;
		for (int i = 1; i <= m; i++) if (msk >> (i - 1) & 1) {
			t[++k] = i;
		}
		for (int i = 1; i <= k; i++) {
			int sum = 0;
			for (int j = 1; j <= k; j++) if (i != j) {
				sum += a[t[i]][t[j]];
			}
			sum = sum * 2 - all[t[i]];
			upd(dp[msk], dp[msk ^ (1 << (t[i] - 1))] + sum * k);
		}
	}
	printf("%d\n", dp[(1 << m) - 1]);
	return 0;
}