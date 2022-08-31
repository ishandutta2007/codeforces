#include <bits/stdc++.h>
#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
#define copy(x, y) memcpy(y, x, sizeof(mat))

typedef long long ll;
typedef int mat[2][2], (*pmat)[2];
typedef std::tuple <ll, int, int> tup;
const int N = 50054;

int mod;

ll nth;
int n, D, E = 0;
int c[N];
tup diff[N * 2];
mat x[N * 4], O, ans = {{1, 0}, {0, 1}};
pmat leaf[N];
bool tag[N * 4];

inline void define(pmat mat, int a00, int a01, int a10, int a11) {mat[0][0] = a00, mat[0][1] = a01, mat[1][0] = a10, mat[1][1] = a11;}

inline void __builtin_matmul(pmat a, pmat b, pmat ret) {
	ret[0][0] = ((ll)a[0][0] * b[0][0] + (ll)a[0][1] * b[1][0]) % mod;
	ret[0][1] = ((ll)a[0][0] * b[0][1] + (ll)a[0][1] * b[1][1]) % mod;
	ret[1][0] = ((ll)a[1][0] * b[0][0] + (ll)a[1][1] * b[1][0]) % mod;
	ret[1][1] = ((ll)a[1][0] * b[0][1] + (ll)a[1][1] * b[1][1]) % mod;
}

inline void matmul(pmat a, pmat b, pmat ret) {mat tmp; __builtin_matmul(a, b, tmp), copy(tmp, ret);}

void matPowerMod(pmat a, ll n, pmat c) {mat tmp; for (copy(a, tmp); n; n >>= 1, matmul(tmp, tmp, tmp)) if (n & 1) matmul(tmp, c, c);}

void build(int id, int L, int R) {
	if (L == R) return define(leaf[L] = x[id], c[L + 1], c[L], 1, 0);
	segc; build(lc, L, M), build(rc, M + 1, R);
	__builtin_matmul(x[rc], x[lc], x[id]);
}

void adj(int id, int L, int R, int h, int r, int c, int v) {
	tag[id] = true;
	if (L == R)	{x[id][r][c] = v; return;}
	segc; h <= M ? adj(lc, L, M, h, r, c, v) : adj(rc, M + 1, R, h, r, c, v);
	__builtin_matmul(x[rc], x[lc], x[id]);
}

void recover(int id, int L, int R) {
	if (L == R) return define(x[id], c[L + 1], c[L], 1, 0);
	segc; if (tag[lc]) recover(lc, L, M); if (tag[rc]) recover(rc, M + 1, R);
	__builtin_matmul(x[rc], x[lc], x[id]), tag[id] = false;
}

int main() {
	int i, j, k, v; ll p, la = -1;
	scanf("%lld%d%d", &nth, &mod, &n);
	if (!nth--) return putchar(48), putchar(10), 0;
	for (i = 0; i < n; ++i) scanf("%d", c + i), c[i] %= mod; c[n] = *c;
	scanf("%d", &D);
	for (i = 0; i < D; ++i) {
		scanf("%lld%d", &p, &v);
		if (p > nth) continue;
		diff[E++] = tup(p / n, p % n, v %= mod);
		if (!(p % n)) diff[E++] = tup(p / n - 1, n, v);
	}
	diff[E++] = tup(nth / n, nth % n, c[nth % n]);
	std::sort(diff, diff + E);
	build(1, 0, n - 1), copy(x[1], O);
	for (j = i = 0; i < E; i = j) {
		p = std::get<0>(diff[i]);
		matPowerMod(O, p - la - 1, ans);
		for (la = p; j < E && std::get<0>(diff[j]) == p; ++j) {
			std::tie(p, k, v) = diff[j];
			if (k < n) adj(1, 0, n - 1, k, 0, 1, v);
			if (k) adj(1, 0, n - 1, k - 1, 0, 0, v);
		}
		if (j == E) // last round
			for (assert(p == nth / n), v = nth % n, k = 0; k < v; ++k)
				matmul(leaf[k], ans, ans);
		else
			matmul(x[1], ans, ans), recover(1, 0, n - 1), la = p;
	}
	printf("%d\n", ans[0][0] % mod);
	return 0;
}