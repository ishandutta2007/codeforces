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
typedef long long ll;
typedef double ff;
typedef std::pair <ll, ll> pii;
const int N = 5e5 + 5, Mod = 998244353;
const ll InfLL = 1e16;

int n, m, top; ll f[N][2], a[N];
pii I[N], st[N];

ll Calc(int l, int r, int c_l, int c_r) {
	int bg = std::upper_bound(I + 1, I + m + 1, mkp(a[l], InfLL)) - I,
		ed = std::upper_bound(I + 1, I + m + 1, mkp(a[r], InfLL)) - I;
	ll ret = InfLL;
	for(int i = std::max(bg - 1, 1); i <= std::min(ed, m - 1); ++i)
		ret = std::min(ret, c_l * std::max(I[i].fi - a[l], 0LL) + c_r * std::max(a[r] - I[i + 1].se, 0LL));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int test_case_cnt = 1; rd(test_case_cnt);
    while(test_case_cnt--) {
        rd(n, m);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		std::sort(a + 1, a + n + 1);
		for(int i = 1; i <= m; ++i) {
			ll l, r; rd(l, r);
			I[i] = mkp(l, r);
		}
		I[++m] = mkp(-InfLL, -InfLL);
		I[++m] = mkp(InfLL, InfLL);
		std::sort(I + 1, I + m + 1, [&](const pii &x, const pii &y) {
			return x.fi != y.fi ? x.fi < y.fi : x.se > y.se;
		});
		top = 0;
		for(int i = 1; i <= m; ++i) {
			while(top && st[top].se >= I[i].se)
				--top;
			st[++top] = I[i];
		}
		for(int i = 1; i <= top; ++i)
			I[i] = st[i];
		m = top;
		a[0] = -InfLL; a[n + 1] = InfLL;
		for(int i = 1; i <= n + 1; ++i) {
			f[i][0] = f[i][1] = InfLL;
			f[i][0] = std::min(f[i][0], f[i - 1][0] + Calc(i - 1, i, 1, 2));
			f[i][0] = std::min(f[i][0], f[i - 1][1] + Calc(i - 1, i, 2, 2));
			f[i][1] = std::min(f[i][1], f[i - 1][0] + Calc(i - 1, i, 1, 1));
			f[i][1] = std::min(f[i][1], f[i - 1][1] + Calc(i - 1, i, 2, 1));
		}
		printf("%lld\n", std::min(f[n + 1][0], f[n + 1][1]));
    } return 0;
}