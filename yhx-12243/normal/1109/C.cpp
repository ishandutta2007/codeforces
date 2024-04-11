#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
typedef std::pair <int, int> pr;
typedef std::map <int, int> map;
const int N = 100054;

struct request {
	int op, arg[3];
	friend std::istream & operator >> (std::istream &in, request &B) {
		switch (in >> B.op, B.op) {
			case 1: return in >> B.arg[0] >> B.arg[1];
			case 2: return in >> B.arg[0];
			case 3: return in >> B.arg[0] >> B.arg[1] >> B.arg[2];
			default: return in;
		}
	}
} qry[N];

int n;
int left[N];
map C;

inline int min(const int x, const int y) {return x < y ? x : y;}
inline ll min(const ll x, const ll y) {return x < y ? x : y;}

namespace DC {
	int F[N]; pr D[N];

	int Discretize(int n) {
		int i, cnt = 0; std::sort(D, D + n);
		for (i = 0; i < n; ++i)
			F[D[i].second] = (i && D[i].first == D[i - 1].first ? cnt - 1 : (D[cnt] = D[i], cnt++));
		return cnt;
	}
}

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	#define exist_pd if (x[id].tag) push_down(x[id], x[lc], x[rc], L, M, R)
	struct node {int v; bool tag; ll s, m;} x[265000];

	inline void update(node &ret, const node &l, const node &r) {ret.s = l.s + r.s, ret.m = min(l.m, l.s + r.m);}
	inline void cover(node &ret, int L, int R, int v) {ret.v = v, ret.tag = true, ret.s = ll(left[R + 1] - left[L]) * v, ret.m = min(ret.s, 0ll);}
	inline void push_down(node &ret, node &l, node &r, int L, int M, int R) {cover(l, L, M, ret.v), cover(r, M + 1, R, ret.v), ret.v = 0, ret.tag = false;}

	void adj(int id, int L, int R, int ql, int qr, int v) {
		if (ql <= L && R <= qr) return cover(x[id], L, R, v);
		segc; exist_pd;
		if (ql <= M) adj(lc, L, M, ql, qr, v);
		if (qr > M) adj(rc, M + 1, R, ql, qr, v);
		update(x[id], x[lc], x[rc]);
	}

	int integral, extraB;
	ll extraA;
	bool succ;

	ll query(int id, int L, int R, int h, ll v) {
		if (h <= L) {
			if (v + x[id].m > 0) return x[id].s;
			if (L == R) return assert(x[id].v < 0), integral = left[L], extraA = v, extraB = -x[id].v, succ = true;
		}
		segc; exist_pd;
		if (h > M) return query(rc, M + 1, R, h, v);
		ll ls = query(lc, L, M, h, v), rs;
		if (succ) return 0;
		rs = query(rc, M + 1, R, h, v + ls);
		return ls + rs;
	}
}

int main() {
	int i, j, q, t, u, v; ll w; map::iterator it;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> q, cout << std::setprecision(12);
	for (i = 0; i < q; ++i) if (cin >> qry[i], qry[i].op != 3) DC::D[i] = pr(qry[i].arg[0], i);
	DC::D[q] = pr(0, q), DC::D[q + 1] = pr(1000000001, q + 1);
	n = DC::Discretize(q + 2);
	for (i = 0; i < n; ++i) left[i] = DC::D[i].first;
	for (i = 0; i < q; ++i) if (qry[i].op != 3) qry[i].arg[0] = DC::F[i];
	C.emplace(0, 0), C.emplace(n - 1, 0);
	for (i = 0; i < q; ++i)
		switch (qry[i].op) {
			case 1:
				t = qry[i].arg[0], it = C.emplace(t, v = qry[i].arg[1]).first, u = (++it)->first,
				ST::adj(1, 0, n - 2, t, u - 1, v); break;
			case 2:
				t = qry[i].arg[0], it = C.find(t), u = std::next(it)->first;
				ST::adj(1, 0, n - 2, t, u - 1, std::prev(it)->second), C.erase(it); break;
			case 3:
				t = qry[i].arg[0], u = qry[i].arg[1], w = qry[i].arg[2];
				if (!w) {cout << t << '\n'; continue;}
				j = std::lower_bound(left, left + n, t) - left, j = C.lower_bound(j)->first;
				if (left[j] >= u) {cout << "-1\n"; continue;}
				if (ST::succ = false, j < n - 1) ST::query(1, 0, n - 2, j, w);
				cout << (ST::succ && ST::extraA <= ST::extraB * ll(u - ST::integral) ? ST::integral + (double)ST::extraA / ST::extraB : -1.) << '\n'; break;
		}
	return 0;
}