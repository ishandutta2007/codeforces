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
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 1e6 + 5;

int n, c; ll a[N], s[N], s_d[N], f[N], g[N];

ll tr[N];
void Modify(int o, ll v) {
	for(; o <= c; o += o & -o)
		tr[o] = std::max(tr[o], v);
}
ll Query(int o) {
	ll ret = -1e18;
	for(; o; o -= o & -o)
		ret = std::max(ret, tr[o]);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		c = 0;
		s[0] = 0;
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			s[i] = s[i - 1] + a[i];
			s_d[++c] = s[i];
			f[i] = -1e18;
		}
		s_d[++c] = s[0];
		std::sort(s_d + 1, s_d + c + 1);
		for(int i = 0; i <= c; ++i) tr[i] = g[i] = -1e18;
		f[0] = 0;
		ll mx = 0;
		s[0] = std::lower_bound(s_d + 1, s_d + c + 1, s[0]) - s_d;
		Modify(s[0], 0);
		g[s[0]] = 0;
		for(int i = 1; i <= n; ++i) {
			s[i] = std::lower_bound(s_d + 1, s_d + c + 1, s[i]) - s_d;
			f[i] = std::max({ -i + mx, i + Query(s[i] - 1), g[s[i]] });
			Modify(s[i], f[i] + (-i));
			mx = std::max(mx, f[i] + i);
			g[s[i]] = std::max(g[s[i]], f[i]);
		}
		printf("%lld\n", f[n]);
	} return 0;
}