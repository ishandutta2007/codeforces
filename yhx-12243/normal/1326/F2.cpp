#include <bits/stdc++.h>
#define ctz __builtin_ctz
#define popc __builtin_popcount
#define parity __builtin_parity
 
typedef std::vector <int> vector;
typedef std::map <vector, int> map;
typedef long long ll;
const int N = 19, N2 = 262154, M = 666;
 
int n, ALL, P = 0;
int bel[N2], G[N];
map Su;
int major[M];
ll g[N][N2], dak[N2];
ll f[M], ans[N2];
vector par[M];

void FMT(int n, ll *f) {
	int i, j, k, len = 1;
	for (i = 0; i < n; ++i, len <<= 1)
		for (j = 0; j < 1 << n; j += len << 1)
			for (k = j; k < j + len; ++k)
				f[k + len] += f[k];	
}

void RIFMT(int n, ll *f) {
	int i, j, k, len = 1;
	for (i = 0; i < n; ++i, len <<= 1)
		for (j = 0; j < 1 << n; j += len << 1)
			for (k = j; k < j + len; ++k)
				f[k] -= f[k + len];
}

namespace dp {
	ll f[N2][N];
 
	void main() {
		int i, j, k, S;
		for (i = 0; i < n; ++i) f[1 << i][i] = 1;
		for (i = 1; i < ALL; ++i)
			for (j = 0; j < n; ++j) if (f[i][j])
				for (S = ~i & G[j]; S; S &= S - 1)
					k = ctz(S), f[i | 1 << k][k] += f[i][j];
		for (i = 1; i <= ALL; ++i)
			for (j = 0; j < n; ++j) g[popc(i)][i] += f[i][j];
		for (i = 0; i < n; ++i) FMT(n, g[i]);
	}
}
 
int main() {
	int i, j, c, t[20]; bool ret; char s[N];
	map::iterator it;
	scanf("%d", &n), ALL = ~(-1 << n);
	for (i = 0; i < 1 << (n - 1); ++i) {
		c = 0, *t = 1;
		for (j = 0; j < n - 1; ++j)
			i >> j & 1 ? ++t[c] : (t[++c] = 1);
		std::sort(t, t + ++c, std::greater <int> ());
		std::tie(it, ret) = Su.emplace(vector(t, t + c), P);
		if (ret) par[P] = vector(t, t + c), major[ bel[i] = P++ ] = i;
		else bel[i] = it->second;
	}
	for (i = 0; i < n; ++i)
		for (scanf("%s", s), j = 0; j < n; ++j)
			G[i] |= ((int)s[j] & 1) << j;
	dp::main();
	for (i = 0; i < P; ++i) {
		ll &ret = f[i];
		std::fill(dak, dak + (ALL + 1), 1);
		for (j = 0; j <= ALL; ++j)
			for (int x : par[i]) dak[j] *= g[x][j];
		for (j = 0; j <= ALL; ++j)
			parity(j) ? ret -= dak[j] : ret += dak[j];
		if (n & 1) ret = -ret;
	}
	for (i = 0; i < 1 << (n - 1); ++i) ans[i] = f[bel[i]];
	RIFMT(n - 1, ans), ALL >>= 1;
	for (i = 0; i <= ALL; ++i) printf("%lld%c", ans[i], i == ALL ? 10 : 32);
	return 0;
}