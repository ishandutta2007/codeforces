#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
#define mx(o) seg[o].mx
#define lc(o) seg[o].lc
#define rc(o) seg[o].rc
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 1e5 + 5;
const ff Eps = 1e-9, Inf = 1e6;

struct Seg {
	int mx, lc, rc;
} seg[N * 100];
int rt, n_cnt;
void Update(int o) { mx(o) = std::max(mx(lc(o)), mx(rc(o))); }
void Modify(int &o, ff l, ff r, ff q, int v) {
	if(!o) o = ++n_cnt;
	if(r - l < Eps) mx(o) = std::max(mx(o), v);
	else {
		ff mid = (l + r) / 2;
		if(q < mid || fabs(q - mid) < Eps) Modify(lc(o), l, mid, q, v);
		else Modify(rc(o), mid + Eps, r, q, v);
		Update(o);
	}
}
int Query(int o, ff l, ff r, ff ql, ff qr) {
	if(!o) return 0;
	if(ql <= l && r <= qr) return mx(o);
	ff mid = (l + r) / 2; int ret = 0;
	if(ql < mid || fabs(ql - mid) < Eps)
		ret = std::max(ret, Query(lc(o), l, mid, ql, qr));
	if(qr > mid)
		ret = std::max(ret, Query(rc(o), mid + Eps, r, ql, qr));
	return ret;
}

int idx[N], f[N];
ff X[N], Y[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		int n; ll a, b, c, d; rd(n, a, b, c, d);
		for(int i = 1; i <= n; ++i) {
			ll x, y; rd(x, y);
			X[i] = (ff)(d * y - c * x) / (a * d - b * c);
			Y[i] = (ff)(b * y - a * x) / (b * c - a * d);
			idx[i] = i;
		}
		X[++n] = 0; Y[n] = 0; idx[n] = n;
		std::sort(idx + 1, idx + n + 1, [&](const int &x, const int &y) {
			return fabs(X[x] - X[y]) > Eps ? X[x] > X[y] : Y[x] < Y[y];
		});
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			int u = idx[i];
			f[u] = Query(rt, -Inf, Inf, Y[u] + Eps, Inf + Eps) + 1;
			Modify(rt, -Inf, Inf, Y[u], f[u]);
			ans = std::max(ans, f[u]);
		}
		printf("%d\n", f[n] - 1);
	} return 0;
}