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
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ff;
typedef std::pair <int, int> pii;
typedef std::pair <ff, ff> pff;
const int N = 5e5 + 5;
const ff INF = 1e9, EPS = 1e-14, PI = acosl(-1);

int n, m;
ff rho[N], theta[N];

int nxt[N][18];
ff nxt_w[N];
pff rg[N];
bool Check(ff r) {
	for(int i = 1; i <= n; ++i) {
		ff alpha = acos(r / rho[i]);
		rg[i] = mkp(theta[i] - alpha, theta[i] + alpha);
		if(rg[i].se < 0) rg[i].fi += 2 * PI, rg[i].se += 2 * PI;
	}
	std::sort(rg + 1, rg + n + 1,
		[](const pff &x, const pff &y) { return x.se < y.se; }
	);
	for(int i = 1; i <= n; ++i) 
		rg[i + n] = mkp(rg[i].fi + 2 * PI, rg[i].se + 2 * PI);
	for(int i = 1, j = 1; i <= n << 1; ++i) {
		for(; j <= n << 1 && rg[j].fi <= rg[i].se + EPS; ++j);
		nxt[i][0] = j;
	}
	nxt[n << 1 | 1][0] = n << 1 | 1;
	for(int i = 1; i < 18; ++i)
		for(int j = 1; j <= (n << 1 | 1); ++j) {
			nxt[j][i] = nxt[nxt[j][i - 1]][i - 1];
		}
	for(int i = 1; i <= n; ++i) {
		int k = i; ff fin_p = 0;
		for(int j = 0; j < 18; ++j)
			if((m >> j) & 1)
				k = nxt[k][j];
		if(k - i >= n) return true;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		ff l = EPS, r = INF;
		for(int i = 1; i <= n; ++i) {
			ll x, y; rd(x, y);
			rho[i] = sqrtl(x * x + y * y);
			theta[i] = atan2l(y, x);
			r = std::min(r, rho[i]);
		}
		r -= EPS;
		for(int i = 1; i <= 60; ++i)  {
			ff mid = (l + r) / 2;
			if(Check(mid)) l = mid;
			else r = mid;
		}
		printf("%.9LF\n", l);
	} return 0;
}