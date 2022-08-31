#include <bits/stdc++.h>
#define N 200005
using namespace std;

typedef long long ll;
typedef pair <ll, int> pr;

int n, a, b;
ll h[N], d[N], zz[N];
pr g[N];

int main() {
	int i; ll init = 0, sum = 0, ans = 0, la, v;
	scanf("%d%d%d", &n, &a, &b);
	for (i = 1; i <= n; ++i) scanf("%lld%lld", h + i, d + i), init += d[i];
	if (!b) return printf("%lld\n", init), 0;
	for (i = 1; i <= n; ++i) g[i] = pr(max(h[i] - d[i], 0ll), i), zz[i] = -1;
	sort(g + 1, g + (n + 1), greater <pr> ());
	for (i = 1; i <= b; ++i) sum += g[i].first, zz[g[i].second] = g[i].first;
	la = g[b].first; ans = sum;
	for (i = 1; i <= n; ++i) {
		v = max((h[i] << a) - d[i], 0ll);
		if (~zz[i]) ans = max(ans, sum - zz[i] + v);
		else ans = max(ans, sum - la + v);
	}
	printf("%lld\n", init + ans);
	return 0;
}

/*
20 17 |  3 23 63 143
18  4 | 14 32 68 152

20 16 |  4 24 64 144
21 17 |  4 25 67 151
*/