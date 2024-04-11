#include <bits/stdc++.h>
#define lg2 std::__lg
using std::cin;
using std::cout;

typedef long long ll;
typedef std::pair <ll, ll> pr;
const int N = 200054;

struct diamond {
	int w, v, id;
	inline bool operator < (const diamond &B) {return v > B.v || (v == B.v && w < B.w);}
} a[N];

int n, q;
int o[N], c_[N];
ll c[N];

inline int min(const int x, const int y) {return x < y ? x : y;}
inline ll min(const ll x, const ll y) {return x < y ? x : y;}

inline pr operator + (const pr &A, const pr &B) {return pr(A.first + B.first, A.second + B.second);}

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1

	struct node {
		pr v[18];
		ll req[18];
	} x[530000];

	ll qW, qV;

	inline void update(node &ret, const node &l, const node &r) {
		for (int i = 0; i < 18; ++i) ret.v[i] = l.v[i] + r.v[i], ret.req[i] = min(l.req[i], l.v[i].first + r.req[i]);
	}

	void build(int id, int L, int R) {
		int i;
		if (L == R) {
			for (i = 17; a[L].w < 1 << i; --i) x[id].v[i] = pr(a[L].w * c[L], a[L].v * c[L]);
			memset(x[id].req, 63, 144); if (c[L]) x[id].req[i] = a[L].w;
			return;
		}
		segc; build(lc, L, M), build(rc, M + 1, R),
		update(x[id], x[lc], x[rc]);
	}

	void add(int id, int L, int R, int h, int v) {
		int i;
		if (L == R) {
			for (i = 17; a[L].w < 1 << i; --i) x[id].v[i] = pr(x[id].v[i].first + (ll)a[L].w * v, x[id].v[i].second + (ll)a[L].v * v);
			memset(x[id].req, 63, 144); if ((c[L] += v)) x[id].req[i] = a[L].w;
			return;
		}
		segc; h <= M ? add(lc, L, M, h, v) : add(rc, M + 1, R, h, v),
		update(x[id], x[lc], x[rc]);
	}

	void pre(int id, int L, int R, int bit, int h, pr &ret) {
		if (h > R) {ret = x[id].v[bit]; return;}
		for (ret = pr(0, 0); L != R; ) {
			segc;
			if (h <= M) id = lc, R = M;
			else ret = ret + x[lc].v[bit], id = rc, L = M + 1;
		}
	}

	int locate(int id, int L, int R, int bit, ll W, pr &ret) {
		if (W >= x[id].v[bit].first) return ret = x[id].v[bit], R + 1;
		for (ret = pr(0, 0); L != R; ) {
			segc;
			if (W < ret.first + x[lc].v[bit].first) id = lc, R = M;
			else ret = ret + x[lc].v[bit], id = rc, L = M + 1;
		}
		return L;
	}

	int scan(int id, int L, int R, int bit, int h, ll W) {
		if (x[id].req[bit] > W) return -1;
		if (L == R) return L;
		segc;
		if (h > M) return scan(rc, M + 1, R, bit, h, W - x[lc].v[bit].first);
		int p = (h > L || x[lc].req[bit] <= W ? scan(lc, L, M, bit, h, W) : -1); 
		return ~p ? p : scan(rc, M + 1, R, bit, M + 1, W - x[lc].v[bit].first);
	}
}

int main() {
	int i, j, b, op, count; ll W, V, mult; pr pre, cur;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> q;
	for (i = 0; i < n; ++i) cin >> c_[i] >> a[i].w >> a[i].v, a[i].id = i;
	std::sort(a, a + n);
	for (i = 0; i < n; ++i) o[a[i].id] = i, c[i] = c_[a[i].id];
	ST::build(1, 0, n - 1);
	for (; q; --q)
		switch (cin >> op, op) {
			case 1:
			case 2:
				cin >> count >> i, ST::add(1, 0, n - 1, o[i - 1], op == 2 ? -count : count);
				break;
			case 3:
				cin >> W, V = 0;
				for (i = 0; i < n && W; i = j) {
					b = min((int)lg2(W), 17), ST::pre(1, 0, n - 1, b, i, pre),
					j = ST::scan(1, 0, n - 1, b, i, W + pre.first);
					if (~j)
						ST::pre(1, 0, n - 1, b, j, cur),
						W -= cur.first - pre.first, V += cur.second - pre.second,
						assert(1 << b <= a[j].w && a[j].w <= W),
						W -= a[j].w, V += a[j].v, ++j;
					else {
						j = ST::locate(1, 0, n - 1, b, W + pre.first, cur),
						W -= cur.first - pre.first, V += cur.second - pre.second;
						if (W >= 1 << b && j < n)
							assert(a[j].w < 1 << b), mult = W / a[j].w,
							W -= a[j].w * mult, V += a[j].v * mult, ++j;
					}
				}
				cout << V << '\n';
				break;
		}
	return 0;
}