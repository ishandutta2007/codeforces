#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(X) (X).begin(), (X).end()
#define lep(i, j, k) for (int i = (j); i <= (k); i++)
#define rep(i, j, k) for (int i = (j); i >= (k); i--)
#define Lep(i, j, k) for (int i = (j); i < (k); i++)
#define Rep(i, j, k) for (int i = (j); i > (k); i--)

using namespace std;

using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;

template <typename T>
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

const int N = 2e5 + 10;

int n, q, p[N], qp[N];

struct Node {int l, r, del;};
struct Qry {int r, id;};
vector<Qry> Q[N];
vector<Node> v[N];

struct ST_MIN {
	int o[N << 2];
	void Build(int x, int l, int r) {
		if (l == r) return o[x] = l, void();
		int mid = (l + r) >> 1;
		Build(x << 1, l, mid);
		Build(x << 1 | 1, mid + 1, r);
		if (p[o[x << 1]] > p[o[x << 1 | 1]]) o[x] = o[x << 1];
		else o[x] = o[x << 1 | 1];
	}
	int Qry(int x, int l, int r, int tl, int tr) {
		if (tl <= l && r <= tr) return o[x];
		int mid = (l + r) >> 1;
		if (tr <= mid) return Qry(x << 1, l, mid, tl, tr);
		if (tl > mid) return Qry(x << 1 | 1, mid + 1, r, tl, tr);
		int a1 = Qry(x << 1, l, mid, tl, tr);
		int a2 = Qry(x << 1 | 1, mid + 1, r, tl, tr);
		if (p[a1] > p[a2]) return a1;
		else return a2;
	}
}	st;

void make(int l, int r, int x, int y) {
	v[x].push_back((Node){y, r, 1});
	v[l - 1].push_back((Node){y, r, -1});
}

void solve(int l, int r) {
	if (l > r) return;
	int d = st.Qry(1, 1, n, l, r);
	for (int i = 1; i * i <= p[d]; i++)
		if (p[d] % i == 0 && i * i != p[d]) {
			int x = qp[i], y = qp[p[d] / i];
			if (y < x) swap(x, y);
			if (l <= x && x != y && y <= r)
				make(l, r, min(x, d), max(y, d));
		}
	solve(l, d - 1), solve(d + 1, r);
}

struct ST_ {
	struct Node {
		int lz1, lz2, lz3, len, tl;
		ll ans;
	}	o[N << 2]; // lz1: mdf, lz2 = ans af lz1, lz3 = mans
	void Build(int x, int l, int r) {
		o[x].len = r - l + 1;
		o[x].lz1 = o[x].lz2 = o[x].lz3 = o[x].ans = 0;
		if (l == r) return;
		int mid = (l + r) >> 1;
		Build(x << 1, l, mid);
		Build(x << 1 | 1, mid + 1, r);
	}
	void make(int x) {
		if (o[x].lz1 > 0) o[x].tl = o[x].len;
		else {
			if (o[x].len == 1) o[x].tl = 0;
			else o[x].tl = o[x << 1].tl + o[x << 1 | 1].tl;
		}
	}
	void ud1(int x, int v) {
		o[x].lz1 += v;
		make(x);
	}
	void ud2(int x, int v) {
		o[x].ans += 1ll * o[x].tl * v;
		if (o[x].lz1 > 0) o[x].lz3 += v;
		else o[x].lz2 += v;
	}
	void ud3(int x, int v) {
		o[x].ans += 1ll * o[x].len * v;
		o[x].lz3 += v;
	}
	void PushDown(int x) {
		if (o[x].lz2) {
			ud2(x << 1, o[x].lz2);
			ud2(x << 1 | 1, o[x].lz2);
			o[x].lz2 = 0;
		}
		if (o[x].lz3) {
			ud3(x << 1, o[x].lz3);
			ud3(x << 1 | 1, o[x].lz3);
			o[x].lz3 = 0;
		}
	}
	void Mdf1(int x, int l, int r, int tl, int tr, int del) {
		if (tl <= l && r <= tr) return ud1(x, del);
		int mid = (l + r) >> 1; PushDown(x);
		if (tl <= mid) Mdf1(x << 1, l, mid, tl, tr, del);
		if (tr > mid) Mdf1(x << 1 | 1, mid + 1, r, tl, tr, del);
		make(x);
	}
	ll Qry(int x, int l, int r, int tl, int tr) {
		if (tl <= l && r <= tr) return o[x].ans;
		int mid = (l + r) >> 1; ll ret = 0; PushDown(x);
		if (tl <= mid) ret += Qry(x << 1, l, mid, tl, tr);
		if (tr > mid) ret += Qry(x << 1 | 1, mid + 1, r, tl, tr);
		return ret;
	}
}	ts;

ll out[1000100];

int main() {
	read(n), read(q);
	for (int i = 1; i <= n; i++)
		read(p[i]), qp[p[i]] = i;
	for (int i = 1; i <= q; i++) {
		int l, r; scanf("%d%d", &l, &r);
		Q[l].push_back((Qry){r, i});
	}
	st.Build(1, 1, n);
	solve(1, n);
	ts.Build(1, 1, n);
	for (int i = n; i >= 1; i--) {
		for (Node nd : v[i]) ts.Mdf1(1, 1, n, nd.l, nd.r, nd.del);
		ts.ud2(1, 1);
		for (Qry nd : Q[i]) out[nd.id] = ts.Qry(1, 1, n, 1, nd.r);
	}
	for (int i = 1; i <= q; i++) print(out[i], '\n');
	return 0;
}