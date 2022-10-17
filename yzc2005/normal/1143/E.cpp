#include <bits/stdc++.h>
using namespace std;

const int N = 200005, K = 20;

int n, m, a[N], p[N], pos[N], lst[N], q;
int lg[N], f[N][K], st[N][K], ans[N];

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n; ++i) scanf("%d", &p[i]), pos[p[i]] = i;
	for(int i = 1; i <= n; ++i) lst[i] = m + 1;
	for(int i = 1; i <= m; ++i) scanf("%d", &a[i]);
	for(int i = m; i; --i) lst[a[i]] = i, f[i][0] = lst[p[pos[a[i]] == n ? 1 : pos[a[i]] + 1]];
	for(int k = 0; k <= 19; ++k) f[m + 1][k] = m + 1;
	for(int i = m; i; --i)
		for(int k = 1; k <= 19; ++k)
			f[i][k] = f[f[i][k - 1]][k - 1];
	for(int i = 1; i <= m; ++i) {
		st[i][0] = i;
		for(int k = 19; ~k; --k) if((n - 1) >> k & 1) st[i][0] = f[st[i][0]][k];
	}	
	for(int i = 2; i <= m; ++i) lg[i] = lg[i >> 1] + 1;
	for(int k = 1; k <= 19; ++k)
		for(int i = 1; i <= m - (1 << k) + 1; ++i)
			st[i][k] = min(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
	for(int i = 1, l, r; i <= q; ++i) {
		scanf("%d%d", &l, &r);
		int t = lg[r - l + 1];
		ans[i] = (min(st[l][t], st[r - (1 << t) + 1][t]) <= r);
	}
	for(int i = 1; i <= q; ++i) printf("%d", ans[i]);
	return 0;
}