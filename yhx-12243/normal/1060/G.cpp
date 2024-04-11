#include <bits/stdc++.h>
#define N 100005
#define lg2(x) (31 - __builtin_clz(x))

typedef long long ll;

namespace BIT {
	#define lowbit(x) (x & -x)
	int n, x[N];
	void init(int _n) {int i; for (n = _n, i = 1; i <= n; ++i) x[i] = lowbit(i);}
	void add(int h, int v) {for (; h <= n; h += lowbit(h)) x[h] += v;}
	int sum(int h) {int s = 0; for (; h; h -= lowbit(h)) s += x[h]; return s;}
	int kth(int k) {
		int l = 0, r, i;
		for (i = lg2(n); ~i; --i) if ((r = (1 << i) + l) <= n && x[r] < k) k -= x[l = r];
		return ++l;
	}
}

namespace ST {
	struct node {int v, lc, rc;} x[20030731];
	int cnt = 0;

	int add(int id, int L, int R, int h, int v) {
		int nid = ++cnt; x[nid] = x[id]; x[nid].v += v;
		if (L == R) return nid;
		int M = L + R - 1 >> 1;
		h <= M ? x[nid].lc = add(x[id].lc, L, M, h, v) : (x[nid].rc = add(x[id].rc, M + 1, R, h, v));
		return nid;
	}

	int range(int id, int L, int R, int ql, int qr) {
		if (ql <= L && R <= qr) return x[id].v;
		int M = L + R - 1 >> 1, s = 0;
		if (ql <= M) s += range(x[id].lc, L, M, ql, std::min(qr, M));
		if (qr > M) s += range(x[id].rc, M + 1, R, std::max(ql, M + 1), qr);
		return s;
	}

	int kth(int id, int L, int R, int k) {
		for (int M; L != R; k <= x[id].lc[x].v ? (id = x[id].lc, R = M) : (k -= x[id].lc[x].v, id = x[id].rc, L = M + 1)) M = L + R - 1 >> 1;
		return L;
	}
}

int n, q, b;
int a[N], rnd[N], last[N];
int mod[N], root[N];
ll sum[N];

inline void compute(ll k, int *blo, ll *pos) { // number on position 0 after k rounds
	k < 0 ? *pos = *blo = 0 : (*blo = std::upper_bound(rnd, rnd + n, k) - rnd, *pos = (ll)(k + 1) * *blo - sum[*blo] - 1);
}

int main() {
	int i, j, Round, fy, Fy; ll t, L, R, M, x;
	scanf("%d%d%d", &n, &q, &b);
	for (i = 1; i < n; ++i) scanf("%d", &j), a[i] = j - b;
	for (i = 1; i < n; ++i) {
		x = (a[i] - last[i - 1]) / i;
		rnd[i] = rnd[i - 1] + x;
		last[i] = last[i - 1] + x * i;
		sum[i + 1] = sum[i] + rnd[i];
	}
	BIT::init(n);
	for (i = n - 1; i >= 0; --i) BIT::add(mod[i] = BIT::kth(a[i] - last[i] + 1), -1);
	for (i = 0; i < n; ++i) root[i + 1] = ST::add(root[i], 1, n, mod[i], 1);
	for (; q; --q) {
		scanf("%lld%d", &x, &Round);
		if (x < b) {printf("%lld\n", x); continue;}
		for (x -= b, L = 0, R = x; L < R; x <= t ? R = M : (L = M + 1))
			compute(M = (L + R) / 2, &j, &t);
		compute(L, &j, &t);
		fy = x - (t - j);
		Fy = ST::kth(root[j], 1, n, fy);
		compute(L += Round, &j, &t);
		fy = ST::range(root[j], 1, n, 1, Fy);
		x = t - j + fy;
		printf("%lld\n", x + b);
	}
	return 0;
}