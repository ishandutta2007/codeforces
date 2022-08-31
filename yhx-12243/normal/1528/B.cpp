#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 1000054, mod = 998244353;

int n;
int pn = 0, c[N], p[78540];
int f[N], fd[N];

inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}

void sieve(int n) {
	int i, j, v; f[1] = fd[1] = 1;
	memset(c, -1, sizeof c);
	for (i = 2; i <= n; ++i) {
		if (!~c[i]) p[pn] = i, c[i] = pn++, f[i] = 2, fd[i] = 1;
		for (j = 0; (v = i * p[j]) <= n && j < c[i]; ++j) c[v] = j, f[v] = f[i] * 2, fd[v] = f[i];
		if (v <= n) c[v] = j, f[v] = f[i] + fd[i], fd[v] = fd[i];
	}
}

int main() {
	int i, S = 0;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n, sieve(n);
	for (i = 1; i <= n; ++i) add(f[i], S), add(S, f[i]);
	cout << f[n] << '\n';
	return 0;
}