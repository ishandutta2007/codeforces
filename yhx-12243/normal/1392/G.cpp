#include <bits/stdc++.h>
#define popc __builtin_popcount
using std::cin;
using std::cout;

const int N = 1050000;

int n, D, L, ALL;
int f[N], g[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int operate(int x, int a, int b) {return (x >> a & 1) << b | (x >> b & 1) << a | (x & ~(1 << a | 1 << b));}

void FMT() {
	int i, j, k, len = 1;
	for (i = 0; i < L; ++i, len <<= 1)
		for (j = 0; j <= ALL; j += len << 1)
			for (k = j; k < j + len; ++k) down(f[k], f[k + len]), up(g[k], g[k + len]);
}

int main() {
	int i, a, b, s, t, ans = 0, p[25]; char si[25], ti[25];
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> D >> L >> si >> ti, ALL = ~(-1 << L),
	s = strtol(si, NULL, 2), t = strtol(ti, NULL, 2), std::iota(p, p + L, 0);
	memset(f, 63, sizeof f), memset(g, 192, sizeof g);
	f[s] = g[t] = 0;
	for (i = 1; i <= n; ++i)
		cin >> a >> b, std::swap(p[a = L - a], p[b = L - b]),
		s = operate(s, p[a], p[b]), down(f[s], i),
		t = operate(t, p[a], p[b]), up(g[t], i);
	FMT(), a = 0, b = n;
	for (i = 0; i <= ALL; ++i) if (g[i] - f[i] >= D && popc(i) > ans) ans = popc(i), a = f[i], b = g[i];
	cout << 2 * ans + L - popc(s) - popc(t) << '\n' << a + 1 << ' ' << b << '\n';
	return 0;
}