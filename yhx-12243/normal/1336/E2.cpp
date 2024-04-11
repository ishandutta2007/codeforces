#include <bits/stdc++.h>
#define popc64 __builtin_popcountll
#define ctz __builtin_ctz

typedef long long ll;
typedef unsigned long long u64;
const int N = 65, mod = 998244353, pmod = mod - 1;

int n, m, rank;
u64 lb[N], tr[N];
int C[N][N], g[N];

inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}

ll PowerMod(ll a, int n, ll c = 1) {for (n += n >> 31 & pmod; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

void init() {
	int i, j;
	for (*C[0] = i = 1; i < N; ++i)
		for (*C[i] = j = 1; j <= i; ++j)
			add(C[i][j] = C[i - 1][j], C[i - 1][j - 1]);
}

bool insert(u64 x) {
	for (int i = 0; i < m; ++i) if (x >> i & 1) {
		if (lb[i]) x ^= lb[i];
		else return lb[i] = x, ++rank;
	}
	return false;
}

void normalize() {
	int i, j, r = 0, o[N]; u64 tmp[N];
	for (i = 0; i < m; ++i) if (lb[i]) o[r] = i, tmp[r++] = lb[i];
	for (i = 0; i < m; ++i) if (!lb[i]) o[r++] = i;
	memset(lb, 0, sizeof lb);
	for (i = 0; i < rank; ++i)
		for (lb[i] = j = 0; j < m; ++j)
			lb[i] |= (tmp[i] >> o[j] & 1) << j;
	for (i = 0; i < rank; ++i) for (j = 0; j < i; ++j)
		if (lb[j] >> i & 1) lb[j] ^= lb[i];
}

int CI(int P1, int P2) {
	int i, j, ret = 0;
	for (i = 0, j = P2; i <= P1 && j >= 0; ++i, --j)
		ret = (ret + ll(i & 1 ? -C[P1][i] : C[P1][i]) * C[m - P1][j]) % mod;
	return ret + (ret >> 31 & mod);
}

int main() {
	int i, j, k, pc, ret; u64 x; ll base;
	scanf("%d%d", &n, &m), init();
	for (i = 0; i < n; ++i) scanf("%llu", &x), insert(x);
	normalize();
	if (rank * 2 <= m) {
		for (j = 1 << rank, x = i = 0; i < j; x ^= lb[ctz(++i)]) ++g[popc64(x)];
		base = PowerMod(2, n - rank);
		for (i = 0; i <= m; ++i)
			printf("%d%c", int((ll)g[i] * base % mod), i == m ? 10 : 32);
	} else {
		for (i = 0; i < m; ++i) for (j = 0; j < m; ++j) tr[j] |= (lb[i] >> j & 1) << i;
		for (k = m - rank, j = 0; j < k; ++j) tr[j] = tr[j + rank];
		for (j = 1 << k, x = pc = i = 0; i < j; x ^= tr[ctz(i)])
			++g[popc64(x) + pc], ++i, i >> ctz(i) & 2 ? --pc : ++pc;
		base = PowerMod(2, n - m);
		for (i = 0; i <= m; ++i) {
			for (ret = j = 0; j <= m; ++j) ret = (ret + (ll)g[j] * CI(j, i)) % mod;
			ret = ret * base % mod, printf("%d%c", ret, i == m ? 10 : 32);
		}
	}
	return 0;
}