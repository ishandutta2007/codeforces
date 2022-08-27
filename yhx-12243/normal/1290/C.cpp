#include <bits/stdc++.h>

const int N = 600054;

int n, K, ans = 0;
int u[N], v[N];
int p[N], sz0[N], sz1[N];
char s[N];

inline int min(const int x, const int y) {return x < y ? x : y;}
int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}

inline int S(int x) {
	if (ancestor(0) == x) return sz1[x];
	if (ancestor(K) == x) return sz0[x];
	return min(sz0[x], sz1[x]);
}

bool test(int x, int y) {
    if ((x = ancestor(x)) == (y = ancestor(y))) return true;
	ans -= S(x) + S(y);
    p[x] = y, sz0[y] += sz0[x], sz1[y] += sz1[x];
    ans += S(y);
    return false;
}

int main() {
	int i, m, x;
	scanf("%d%d%s", &n, &K, s + 1);
	for (++K, i = 1; i < K; ++i)
		for (scanf("%d", &m); m; --m)
			scanf("%d", &x), (u[x] ? v[x] : u[x]) = i;
	std::iota(p, p + 2 * K, 0);
	for (i = 1; i < K; ++i) sz0[i] = sz1[i + K] = 1;
	for (i = 1; i <= n; ++i) {
		if (v[i]) {
			if (s[i] & 1) // u[i] == v[i]
				test(u[i], v[i]),
				test(u[i] + K, v[i] + K);
			else // u[i] != v[i]
				test(u[i], v[i] + K),
				test(u[i] + K, v[i]);
		} else {
			if (s[i] & 1) // u[i] == 0
				test(u[i], 0),
				test(u[i] + K, K);
			else // u[i] == 1
				test(u[i], K),
				test(u[i] + K, 0);
		}
		printf("%d\n", ans / 2);
	}
	return 0;
}