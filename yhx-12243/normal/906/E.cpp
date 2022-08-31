#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 1000054, INF = 0x3f3f3f3f;

int n;
int f[N], F[N], g[N], G[N];
char s[N], t[N], *ptr;
int u[N], v[N];

inline bool down(int &x, const int y) {return x > y ? x = y, 1 : 0;}

namespace PAM {
	int p, cnt;
	int d[N][26], fail[N], val[N];
	int per[N], fst[N];

	void init() {val[1] = -1, p = 0, *fail = cnt = 1;}

	int get_fail(int x) {for (; ptr[~val[x]] != *ptr; x = fail[x]); return x;}

	int extend(int x) {
		int &q = d[p = get_fail(p)][x];
		if (!q)
			fail[++cnt] = d[get_fail(fail[p])][x], val[q = cnt] = val[p] + 2,
			per[cnt] = val[cnt] - val[fail[cnt]],
			fst[cnt] = (per[cnt] == per[fail[cnt]] ? fst[fail[cnt]] : fail[cnt]);
		return p = q;
	}
}

int main() {
	int i, j, p = 0, l;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> t, n = strlen(t), cin >> (t + n);
	for (i = 0, j = n; i < n; s[p++] = t[i++], s[p++] = t[j++]);
	n = p, PAM::init(), memset(f, 63, sizeof f), memset(F, 63, sizeof F);
	for (*f = 0, i = 1, ptr = s; i <= n; ++i, ++ptr) {
		for (p = PAM::extend(*ptr - 97); p; p = j) {
			j = PAM::fst[p], l = PAM::val[j] + PAM::per[p], F[p] = f[i - l], G[p] = i - l;
			if (PAM::val[p] != l && down(F[p], F[PAM::fail[p]])) G[p] = G[PAM::fail[p]];
			if (!(i & 1) && down(f[i], F[p] + 1)) g[i] = G[p];
			if (!(i & 1) && *ptr == ptr[-1] && down(f[i], f[i - 2])) g[i] = i - 2;
		}
	}
	if (f[n] >= INF) return cout << "-1\n", 0;
	for (j = 0, i = n; i; i = g[i]) if (i - g[i] > 2) u[++j] = g[i] / 2 + 1, v[j] = i / 2;
	assert(f[n] == j);
	for (cout << j << '\n'; j; --j) cout << u[j] << ' ' << v[j] << '\n';
	return 0;
}