#include <bits/stdc++.h>
#define N 100054

typedef long long ll;

int n, cnt = 0;
int a[N];
ll ans = 0;

inline void up(ll &x, const ll y) {x < y ? x = y : 0;}

namespace S {
	#define pa p[nd]
	#define C(x) c[x][nd]
	#define root S::nd[N - 1].c[0]
	
	struct node {int sz, p, c[2]; ll v, tag_k, tag_b;} nd[N];

	inline int dir(int x) {return x == nd[x].pa.c[1];}
	inline void cover(int x, ll k, ll b) {nd[x].tag_k += k, nd[x].tag_b += b, nd[x].v += k * nd[x].C(0).sz + b;}
	inline void push_down(int x) {
		ll &k = nd[x].tag_k, &b = nd[x].tag_b;
		if (!(k || b)) return;
		int l = nd[x].c[0], r = nd[x].c[1];
		if (l) cover(l, k, b); if (r) cover(r, k, b + (nd[l].sz + 1) * k);
		k = b = 0;
	}
	void pull_down(int x) {if (nd[x].p != N - 1) pull_down(nd[x].p); push_down(x);}
	inline void update(int x) {nd[x].sz = nd[x].C(0).sz + nd[x].C(1).sz + 1;}
	void rotate(int x) {
		int y = nd[x].p, d = !dir(x);
		nd[ nd[y].c[!d] = nd[x].c[d] ].p = y;
		nd[x].p = nd[y].p;
		nd[y].pa.c[dir(y)] = x;
		nd[ nd[x].c[d] = y ].p = x;
		update(y);
	}
	void splay(int x, int g = N - 1) {for (; nd[x].p != g; rotate(x)) if (nd[x].pa.p != g) rotate(dir(x) ^ dir(nd[x].p) ? x : nd[x].p); update(x);}
	int kth(int x, int k) {
		assert(k <= nd[x].sz);
		for (int j; ; x = nd[x].c[k > j], k -= j - k >> 31 & j + 1)
			if (push_down(x), k == (j = nd[x].C(0).sz) + 1) return splay(x), x;
	}
	// -------- advanced -------- //
	void push_back(int &r, ll value, int p = N - 1) {
		if (!r) {nd[ r = ++cnt ].p = p, nd[cnt].v = value, nd[cnt].sz = 1; return;}
		int x = r;
		for (; push_down(x), nd[x].c[1]; x = nd[x].c[1]); splay(x, p);
		nd[ nd[x].c[1] = ++cnt ].p = x, nd[cnt].v = value, nd[cnt].sz = 1, update(x);
	}
	inline void insert_before(int x, ll value) {splay(x), push_back(nd[x].c[0], value, x), update(x);}
	void traversal(int x) {
		push_down(x), up(ans, nd[x].v);
		if (nd[x].c[0]) traversal(nd[x].c[0]);
		if (nd[x].c[1]) traversal(nd[x].c[1]);
	}
	void debug(int x) {
		push_down(x);
		if (nd[x].c[0]) debug(nd[x].c[0]);
		fprintf(stderr, "    #%d: val %lld, size %d, p %d, lc %d, rc %d\n", x, nd[x].v, nd[x].sz, nd[x].p, nd[x].c[0], nd[x].c[1]);
		if (nd[x].c[1]) debug(nd[x].c[1]);
	}
}

inline ll f(int x) {return x ? S::nd[S::kth(root, x)].v : 0;}

int main() {
	int i, L, R, M, g; ll t;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", a + i);
	S::nd[N - 1].sz = 1;
	for (i = 1; i <= n; ++i) {
		for (L = 1, R = i; L < R; f(M - 1) + (ll)M * a[i] <= f(M) ? (L = M + 1) : (R = M))
			M = (L + R) / 2;
//		fprintf(stderr, "%d => %d\n", i, L);
		t = f(L - 1);
		if (L == i) S::push_back(root, t + (ll)L * a[i]);
		else {
			L == 1 ? S::insert_before(g = S::kth(root, 1), a[i])
				   : S::insert_before(g = S::kth(root, L - 1), t);
			S::splay(cnt);
			assert(g == S::nd[cnt].c[1]);
			S::cover(g, a[i], (L == 1 ? 2ll : (ll)L) * a[i]);
		}
//		fprintf(stderr, "    data: (root = %d)\n", root); S::debug(root); fputc(10, stderr);
	}
	assert(cnt == n), S::traversal(root);
	printf("%lld\n", ans);
}