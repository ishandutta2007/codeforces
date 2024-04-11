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

int T, n, m, x[N], p[N], y[N], ct;
ll h[N], h1[N], h2[N], h3[N];
pair<int,int> o[N];

struct ST_MAX {
	#define mid ((l + r) >> 1)
	#define ls p << 1
	#define rs p << 1 | 1 
	struct Node {ll v, l;} o[N << 2];
	void pu(int p) {o[p].v = max(o[ls].v, o[rs].v);}
	void ud(int p, int v) {o[p].v += v, o[p].l += v;}
	void pd(int p) {if(o[p].l){ud(ls, o[p].l), ud(rs, o[p].l), o[p].l = 0;};}
	void Build(int p, int l, int r, ll *F) {
		o[p].l = 0; if (l == r) return o[p].v = F[l], void();
		Build(ls, l, mid, F), Build(rs, mid + 1, r, F), pu(p); 
	}
	ll Qry(int p, int l, int r, int tl, int tr) {
		if (tr < l || r < tl || tl > tr) return -infll;
		if (tl <= l && r <= tr) return o[p].v; pd(p);
		return max(Qry(ls, l, mid, tl, tr), Qry(rs, mid + 1, r, tl, tr));
	}
	void op(int p, int l, int r) {
		if (l == r) return print(o[p].v, ' '), void();
		op(ls, l, mid), op(rs, mid + 1, r);
	}
	void check(int n) {op(1, 1, n), puts("");}
	#undef mid
	#undef ls
	#undef rs
}	st1, st2, st3;

int as[N];

int main() {
	for (read(T); T; T--) {
		read(n), read(m);
		ct = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &x[i], &p[i]);
			o[i] = mp(x[i], p[i]);
			y[++ct] = x[i];
		}
		sort (y + 1, y + ct + 1);
		ct = unique(y + 1, y + ct + 1) - y - 1;
		sort (o + 1, o + n + 1);
		ll s = 0;
		multiset <int> st;
		for (int i = 1, j = 1; i <= ct; i++) {
			while (j <= n && o[j].fi <= y[i]) {
				s += o[j].fi + o[j].se;
				st.insert(o[j].fi + o[j].se);
				j++;
			}
			while (st.size() && (*st.begin()) <= y[i]) {
				s -= *st.begin();
				st.erase(st.begin());
			}
			h[i] = s - 1ll * st.size() * y[i];
		}
		s = 0, st.clear();
		for (int i = ct, j = n; i >= 1; i--) {
			while (j >= 1 && o[j].fi > y[i]) {
				s += o[j].fi - o[j].se;
				st.insert(o[j].fi - o[j].se);
				j--;
			}
			while (st.size() && (*st.rbegin() >= y[i])) {
				s -= *st.rbegin();
				st.erase(--st.end());
			}
			h[i] += -s + 1ll * st.size() * y[i];
		}
		for (int i = 1; i <= ct; i++) {
			ll mor = -infll;
			if (h[i] >= m) mor = h[i] - m;
			h1[i] = mor, h2[i] = mor - y[i], h3[i] = mor + y[i];
		}
		st1.Build(1, 1, ct, h1);
		st2.Build(1, 1, ct, h2);
		st3.Build(1, 1, ct, h3);
		for (int i = 1; i <= n; i++) {
			int wh = lower_bound(y + 1, y + ct + 1, x[i]) - y;
			int t1 = lower_bound(y + 1, y + ct + 1, x[i] - p[i]) - y;
			int t2 = lower_bound(y + 1, y + ct + 1, x[i] + p[i]) - y - 1;
			as[i] = 1;
			if (st1.Qry(1, 1, ct, 1, t1 - 1) > 0) as[i] = 0;
			if (st1.Qry(1, 1, ct, t2 + 1, ct) > 0) as[i] = 0;
			if (st2.Qry(1, 1, ct, t1, wh - 1) > p[i] - x[i]) as[i] = 0;
			if (st3.Qry(1, 1, ct, wh + 1, t2) > p[i] + x[i]) as[i] = 0;
			if (h[wh] - p[i] > m) as[i] = 0;
		}
		for (int i = 1; i <= n; i++)
			printf("%d", as[i]);
		puts("");
	}
	return 0;
}