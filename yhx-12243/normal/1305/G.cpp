#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair <int, int> pr;
const int N = 262154, ALL = 262143;

int n;
int a[N];
int p[N], size[N];
pr max[N], cc[N], empty;

int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}

inline bool test(int x, int y, bool un = false) {
	if ((x = ancestor(x)) == (y = ancestor(y))) return true;
	return un && (size[x] < size[y] ? (p[x] = y, size[y] += size[x]) : (p[y] = x, size[x] += size[y]), false);
}

inline void up(pr &x, const int y) {
	if (a[x.first] < a[y]) test(x.first, y) || (x.second = x.first), x.first = y;
	else if (a[x.second] < a[y] && !test(x.first, y)) x.second = y ;
}

inline void up(pr &x, const pr &y) {up(x, y.first), up(x, y.second);}

inline void up(pr &x, const int y, const int z) {
	if (!test(y, z) && a[x.first] + a[x.second] < a[y] + a[z]) x = pr(y, z);
}

inline void up(pr &x, const int y, const pr &z) {up(x, y, z.first), up(x, y, z.second);}

int main() {
	int i, j, k, len, nCC; ll ans = 0;
	scanf("%d", &n), p[n + 1] = nCC = n + 1, a[nCC] = -1, empty = pr(nCC, nCC);
	for (i = 1; i <= n; ++i) scanf("%d", a + i), ans -= a[i], p[i] = i, size[i] = 1;
	for (; nCC > 1; ) {
		for (i = 0; i <= ALL; ++i) max[i] = empty;
		for (i = 0; i <= n; ++i) if (p[i] == i) cc[i] = empty;
		for (i = 0; i <= n; ++i) up(max[a[i]], i);
		for (len = 1, i = 0; i < 18; ++i, len <<= 1)
			for (j = 0; j <= ALL; j += len << 1)
				for (k = j; k < j + len; ++k) up(max[k + len], max[k]);
		for (i = 0; i <= n; ++i) up(cc[ancestor(i)], i, max[~a[i] & ALL]);
		for (i = 0; i <= n; ++i) if (p[i] == i)
			if (cc[i].second != n + 1 && !test(i, cc[i].second, true))
				--nCC, ans += a[cc[i].first] + a[cc[i].second];
	}
	printf("%lld\n", ans);
	return 0;
}