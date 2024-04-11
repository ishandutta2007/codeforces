#include <bits/stdc++.h>

#define gc() getchar()
template <typename T> inline void rd(T& x) {
	int si = 1; char c = gc(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
#define mkt std::make_tuple
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 2e5 + 5, B = 30;

struct Base {
	int b[B + 5], st[B + 5], top;
	void Insert(int v) {
		for(int i = B - 1; ~i && v; --i) {
			if((~v >> i) & 1) continue;
			if(b[i]) v ^= b[i];
			else {
				b[i] = v;
				st[++top] = i;
				break;
			}
		}
	}
	int Query(int v) {
		for(int i = B - 1; ~i; --i)
			if((v ^ b[i]) < v) v ^= b[i];
		return v;
	}
	void Undo() { b[st[top--]] = 0; }
} A;
struct Dsu {
	int fa[N], siz[N], w[N], top; pii st[N];
	void Init(int n) { for(int i = 1; i <= n; ++i) fa[i] = i, siz[i] = 1; }
	int Find(int x) { return x == fa[x] ? x : Find(fa[x]); }
	int Find(int x, int &r) { return x == fa[x] ? x : (r ^= w[x], Find(fa[x], r)); }
	int Merge(int x, int y, int c) {
		int f_x, w_x = 0, f_y, w_y = 0;
		f_x = Find(x, w_x); f_y = Find(y, w_y);
		if(siz[f_x] > siz[f_y])
			std::swap(f_x, f_y);
		if(f_x != f_y) {
			fa[f_x] = f_y;
			siz[f_y] += siz[f_x];
			st[++top] = mkp(f_x, w[f_x]);
			w[f_x] = w_x ^ w_y ^ c;
			return 0;
		} else return w_x ^ w_y ^ c;
	}
	void Undo() {
		int x = st[top].fi, w_x = st[top].se, y = fa[x]; --top;
		siz[y] -= siz[x]; w[x] = w_x; fa[x] = x;
	}
} D;

int n, m, q;
std::vector <pii> ask[N];
std::vector <std::tuple <int, int, int> > E[N << 2];
std::map <pii, pii> s;
void Insert(int o, int l, int r, int ql, int qr, std::tuple <int, int, int> t) {
	if(ql > qr) return;
	if(ql <= l && r <= qr) E[o].push_back(t);
	else {
		int mid = (l + r) >> 1;
		if(ql <= mid) Insert(o << 1, l, mid, ql, qr, t);
		if(qr > mid) Insert(o << 1 | 1, mid + 1, r, ql, qr, t);
	}
}
void Div(int o, int l, int r) {
	int _d_top = D.top, _a_top = A.top;
	for(auto t : E[o]) {
		int u = std::get <0>(t), v = std::get <1>(t), w = std::get <2>(t);
		A.Insert(D.Merge(u, v, w));
	}
	if(l == r) {
		for(pii p : ask[l]) {
			int w = 0; D.Find(p.fi, w); D.Find(p.se, w);
			printf("%d\n", A.Query(w));
		}
	} else {
		int mid = (l + r) >> 1;
		Div(o << 1, l, mid);
		Div(o << 1 | 1, mid + 1, r);
	}
	while(D.top != _d_top) D.Undo();
	while(A.top != _a_top) A.Undo();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m); D.Init(n);
		for(int i = 1; i <= m; ++i) {
			int u, v, w; rd(u, v, w);
			s[mkp(u, v)] = mkp(w, 1);
		}
		rd(q);
		for(int i = 1; i <= q; ++i) {
			int opt, u, v; rd(opt, u, v);
			if(opt == 1) {
				int d; rd(d);
				s[mkp(u, v)] = mkp(d, i);
			} else if(opt == 2) {
				pii p = s[mkp(u, v)]; s.erase(mkp(u, v));
				Insert(1, 1, q, p.se, i - 1, mkt(u, v, p.fi));
			} else {
				ask[i].push_back(mkp(u, v));
			}
		}
		for(auto p : s)
			Insert(1, 1, q, p.se.se, q, mkt(p.fi.fi, p.fi.se, p.se.fi));
		Div(1, 1, q);
	} return 0;
}