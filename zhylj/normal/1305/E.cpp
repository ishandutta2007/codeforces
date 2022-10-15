#include <bits/stdc++.h>

const int kN = 5e3 + 5;

int ans[kN];

int main() {
	int n, m, t = 0;
	scanf("%d%d", &n, &m);
	int x;
	for(x = 1; x <= n && t + (x - 1) / 2 <= m; ++x) {
		ans[x] = x; t += (x - 1) / 2;
	}
	if(x == n + 1 && t != m) { printf("-1"); return 0; }
	if(x != n + 1) ans[x] = x + 2 * (t + (x - 1) / 2 - m);
	ans[x + 1] = 1e8;
	for(int i = x + 2; i <= n; ++i) ans[i] = ans[i - 1] + ans[x] + 1;
	for(int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	return 0;
}