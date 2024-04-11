#include <bits/stdc++.h>
#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
#define exist_pd if (x[id].tagc || x[id].taga) push_down(x[id], x[lc], x[rc])

typedef long long ll;
const int N = 100054;
const ll pw42[12] = {1ll, 42ll, 1764ll, 74088ll, 3111696ll, 130691232ll, 5489031744ll, 230539333248ll, 9682651996416ll, 406671383849472ll, 17080198121677824ll, 717368321110468608ll};

struct node {
	ll gap, tagc, taga;
	int log;
} x[N * 4];

int n;
int _init_[N];

inline ll min(const ll x, const ll y) {return x < y ? x : y;}
inline int Log(const ll x) {return std::lower_bound(pw42, pw42 + 12, x) - pw42;}
inline void update(node &ret, const node &l, const node &r) {ret.gap = min(l.gap, r.gap);}
inline void cov(node &ret, ll v) {ret.log = Log(v), ret.gap = pw42[ret.log] - v, ret.tagc = v, ret.taga = 0;}
inline void add(node &ret, ll v) {ret.tagc ? ret.tagc += v : ret.taga += v, ret.gap -= v;}

inline void push_down(node &ret, node &l, node &r) {
	ret.tagc && (cov(l, ret.tagc), cov(r, ret.tagc), ret.tagc = 0);
	ret.taga && (add(l, ret.taga), add(r, ret.taga), ret.taga = 0);
}

void build(int id, int L, int R, int *v) {
	if (L == R) {x[id].log = Log(v[L]), x[id].gap = pw42[x[id].log] - v[L]; return;}
	segc; build(lc, L, M, v), build(rc, M + 1, R, v);
	update(x[id], x[lc], x[rc]);
}

ll get(int id, int L, int R, int h) {
	if (L == R) return pw42[x[id].log] - x[id].gap;
	segc; exist_pd; return h <= M ? get(lc, L, M, h) : get(rc, M + 1, R, h);
}

void cov(int id, int L, int R, int ql, int qr, ll v) {
	if (ql <= L && R <= qr) return cov(x[id], v);
	segc; exist_pd;
	if (ql <= M) cov(lc, L, M, ql, qr, v);
	if (qr > M) cov(rc, M + 1, R, ql, qr, v);
	update(x[id], x[lc], x[rc]);
}

void add(int id, int L, int R, int ql, int qr, ll v) {
	if (ql <= L && R <= qr) return add(x[id], v);
	segc; exist_pd;
	if (ql <= M) add(lc, L, M, ql, qr, v);
	if (qr > M) add(rc, M + 1, R, ql, qr, v);
	update(x[id], x[lc], x[rc]);
}

inline bool check_validity(int id, int L, int R) {
	if (x[id].gap >= 0) return x[id].gap;
	if (L == R) {
		ll v = pw42[x[id].log] - x[id].gap;
		return x[id].log = Log(v), x[id].gap = pw42[x[id].log] - v;
	}
	segc; exist_pd;
	check_validity(lc, L, M), check_validity(rc, M + 1, R);
	return update(x[id], x[lc], x[rc]), x[id].gap;
}

int main() {
	int i, op, l, r, v, q;
	scanf("%d%d", &n, &q);
	for (i = 1; i <= n; ++i) scanf("%d", _init_ + i);
	build(1, 1, n, _init_);
	for (; q; --q)
		switch (scanf("%d", &op), op) {
			case 1: scanf("%d", &i), printf("%lld\n", get(1, 1, n, i)); break;
			case 2: scanf("%d%d%d", &l, &r, &v); cov(1, 1, n, l, r, v); break;
			case 3: 
				scanf("%d%d%d", &l, &r, &v);
				do add(1, 1, n, l, r, v); while (!check_validity(1, 1, n)); break;
		}
	return 0;
}