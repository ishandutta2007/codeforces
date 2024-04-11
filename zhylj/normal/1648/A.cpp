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
const int N = 5e5 + 5;

int c_cnt;
std::map <int, int> s;
std::vector <pii> p[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		int n, m; rd(n, m);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j) {
				int c; rd(c);
				if(!s.count(c)) s[c] = ++c_cnt;
				c = s[c];
				p[c].push_back(mkp(i, j));
			}
		ll ans = 0;
		for(int i = 1; i <= c_cnt; ++i) {
			std::sort(p[i].begin(), p[i].end());
			for(int j = 0; j < p[i].size(); ++j)
				ans += 1LL * p[i][j].fi * j - 1LL * p[i][j].fi * (p[i].size() - j - 1);
			std::sort(p[i].begin(), p[i].end(), [&](const pii &x, const pii &y) {
				return x.se < y.se;
			});
			for(int j = 0; j < p[i].size(); ++j)
				ans += 1LL * p[i][j].se * j - 1LL * p[i][j].se * (p[i].size() - j - 1);
		}
		printf("%lld\n", ans);
	} return 0;
}