#include <bits/stdc++.h>

typedef long long ll;
typedef void (*func)(ll &, const ll);
const int N = 1000054;

struct event {
	int op, arg1, arg2;
	event * read() {return scanf("%s%d", &op, &arg1), ((op &= 255) & 7) == 5 && scanf("%d", &arg2), this;}
} e[N];

struct sweepLine {
	int v, c, t, id;
	sweepLine (int node = 0, int coefficient = 0, int time = 0, int id_ = 0) : v(node), c(coefficient), t(time), id(id_) {}
	inline bool operator < (const sweepLine &B) const {return t < B.t;}
} sl[N];

int n, q, qn = 0;
int cnt = 0;
ll global[N], ans[N];

inline void up(ll &x, const ll y) {x < y ? x = y : 0;}
inline void add(ll &x, const ll y) {x += y;}

namespace DSU {
	int tot;
	int p[N], size[N], st[N];
	ll w[N];
	func f;

	inline void init(int n, func oper) {
		tot = n, f = oper, std::iota(p, p + (n + 1), 0), std::fill(size + 1, size + (n + 1), 1);;
	}

	int ancestor(int x) {
		int i = 0;
		for (; x != p[x]; st[++i] = x, x = p[x]);
		for (st[i + 1] = x; i; p[st[i]] = x, --i) f(w[st[i]], w[st[i + 1]]);
		return x;
	}

	inline ll get_w(int x) {return ancestor(x), w[x];}

	inline void combine(int x, int y, bool additive = false) {
		x = ancestor(x), y = ancestor(y), ++tot;
		p[x] = p[y] = p[tot] = tot, size[tot] = size[x] + size[y];
		if (additive) w[x] = global[x], w[y] = global[y], global[x] = global[y] = global[tot] = 0;
	}
}

int main() {
	int i, j, u, v; ll t;
	scanf("%d%d", &n, &q);
	for (i = 0; i < q; ++i) e[i].read();
	memset(DSU::w, -1, sizeof DSU::w), DSU::init(n, up);
	for (i = 0; i < q; ++i)
		switch (e[i].op) {
			case 77:
				u = e[i].arg1, v = e[i].arg2, DSU::combine(u, v); break;
			case 81:
				v = e[i].arg1;
				sl[cnt++] = sweepLine(v, 1, i, qn);
				sl[cnt++] = sweepLine(v, -1, DSU::get_w(v), qn++);
				break;
			case 90:
				v = e[i].arg1, DSU::w[ DSU::ancestor(v) ] = i;
				break;
		}
	std::sort(sl, sl + cnt), sl[cnt].t = INT_MAX;
	memset(DSU::w, 0, sizeof DSU::w), DSU::init(n, add);
	for (j = 0; !~sl[j].t; ++j);
	for (i = 0; i < q; ++i) {
		switch (e[i].op) {
			case 65:
				v = DSU::ancestor( e[i].arg1 ), global[v] += DSU::size[v];
				break;
			case 85:
				u = e[i].arg1, v = e[i].arg2, DSU::combine(u, v, true); break;
		}
		for (; sl[j].t <= i; ++j) {
			v = sl[j].v, t = DSU::get_w(v), t += global[DSU::p[v]];
			ans[sl[j].id] += sl[j].c * t;
			
		}
	}
	for (i = 0; i < qn; ++i) printf("%lld\n", ans[i]);
    return 0; 
}