#include <bits/stdc++.h>
#define ctz __builtin_ctz
using std::cin;
using std::cout;

typedef long long ll;
const int N = 100054;

int mod;
int n, q;
int a[N], cop[N], rio[N][9];
int cinv[N], wwj[9][2003731];
int _1[N], _2[N];
int om = 0, pr[9], al[9];

inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}

int exgcd(int a, int b, int &x, int &y) {
	if (b) {int d = exgcd(b, a % b, y, x); return y -= a / b * x, d;}
	else return x = 1, y = 0, a;
}

void factor(int n) {
	int i;
	if (!(n & 1)) pr[om] = 2, n >>= al[om++] = ctz(n);
	for (i = 3; i * i <= n; i += 2)
		if (!(n % i)) {
			for (pr[om] = i; !(n % i); n /= i, ++al[om]);
			++om;
		}
	if (n != 1) pr[om] = n, al[om++] = 1;
}

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	#define exist_pd if (x[id].tag) push_down(x[id], x[lc], x[rc])
	
	struct node {int v, s, pw[9], mul; bool tag;} x[262200];

	inline void update(node &ret, const node &l, const node &r) {add(ret.s = l.s, r.s);}

	inline void cover(node &ret, int v_tag, int *pw_tag, int mul_tag) {
		ret.v = (ll)ret.v * v_tag % mod,
		ret.s = (ll)ret.s * mul_tag % mod;
		for (int i = 0; i < om; ++i) ret.pw[i] += pw_tag[i];
		ret.mul = (ll)ret.mul * mul_tag % mod,
		ret.tag = true;
	}

	void push_down(node &ret, node &l, node &r) {cover(l, ret.v, ret.pw, ret.mul), cover(r, ret.v, ret.pw, ret.mul), ret.tag = false, ret.v = ret.mul = 1, memset(ret.pw, 0, om << 2);}

	void build(int id, int L, int R) {
		x[id].v = x[id].mul = 1, x[id].tag = false;
		if (L == R) return x[id].v = cop[a[L]], x[id].s = a[L] % mod, (void)memcpy(x[id].pw, rio[a[L]], om << 2);
		segc; build(lc, L, M), build(rc, M + 1, R);
		update(x[id], x[lc], x[rc]);
	}

	void mul(int id, int L, int R, int ql, int qr, int v) {
		if (ql <= L && R <= qr) return cover(x[id], cop[v], rio[v], v);
		segc; exist_pd;
		if (ql <= M) mul(lc, L, M, ql, qr, v);
		if (qr > M) mul(rc, M + 1, R, ql, qr, v);
		update(x[id], x[lc], x[rc]);
	}

	void div(int id, int L, int R, int h, int v) {
		if (L == R) {
			x[id].s = x[id].v = (ll)x[id].v * cinv[v] % mod;
			for (int i = 0; i < om; ++i) x[id].s = (ll)x[id].s * wwj[i][ x[id].pw[i] -= rio[v][i] ] % mod;
			return;
		}
		segc; exist_pd; h <= M ? div(lc, L, M, h, v) : div(rc, M + 1, R, h, v);
		update(x[id], x[lc], x[rc]);
	}

	int range(int id, int L, int R, int ql, int qr) {
		if (ql <= L && R <= qr) return x[id].s;
		segc, s = 0; exist_pd;
		if (ql <= M) add(s, range(lc, L, M, ql, qr));
		if (qr > M) add(s, range(rc, M + 1, R, ql, qr));
		return s;
	}
}

int main() {
	int i, j, l, r, x;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> mod, factor(mod);
	for (*_1 = i = 1; i <= 100000; ++i) {
		int &x = cop[i]; x = i;
		for (j = 0; j < om; ++j)
			for (; !(x % pr[j]); x /= pr[j], ++rio[i][j]);
		_1[i] = (ll)_1[i - 1] * (x %= mod) % mod;
	}
	--i, exgcd(_1[i], mod, _2[i], j), _2[i] += _2[i] >> 31 & mod;
	for (; i; --i) _2[i - 1] = (ll)_2[i] * cop[i] % mod;
	for (i = 1; i <= 100000; ++i) cinv[i] = (ll)_1[i - 1] * _2[i] % mod;
	for (i = 0; i < om; ++i)
		for (*wwj[i] = j = 1; j < 2003731; ++j) wwj[i][j] = (ll)wwj[i][j - 1] * pr[i] % mod;
	for (i = 1; i <= n; ++i) cin >> a[i];
	ST::build(1, 1, n);
	for (cin >> q; q; --q)
		switch (cin >> i, i) {
			case 1: cin >> l >> r >> x, ST::mul(1, 1, n, l, r, x); break;
			case 2: cin >> i >> x, ST::div(1, 1, n, i, x); break;
			case 3: cin >> l >> r, cout << ST::range(1, 1, n, l, r) << '\n'; break;
		}
	return 0;
}