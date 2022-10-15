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

int n, m, c, a[N], b[N], d[N], vis[N], cnt[N];
std::vector <int> E[N], t[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m); c = 0;
		for(int i = 1; i <= n; ++i) t[i].clear();
		for(int i = 1; i <= n; ++i) vis[i] = cnt[i] = 0, E[i].clear();
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			d[++c] = a[i];
		}
		std::sort(d + 1, d + c + 1);
		c = std::unique(d + 1, d + c + 1) - d - 1;
		for(int i = 1; i <= n; ++i) {
			b[i] = std::lower_bound(d + 1, d + c + 1, a[i]) - d;
			++cnt[b[i]];
		}
		for(int i = 1; i <= m; ++i) {
			int x, y; rd(x, y);
			x = std::lower_bound(d + 1, d + c + 1, x) - d;
			y = std::lower_bound(d + 1, d + c + 1, y) - d;
			E[x].push_back(y);
			E[y].push_back(x);
		}
		std::vector <int> lg_cnt;
		for(int i = 1; i <= n; ++i)
			if(cnt[i]) {
				t[cnt[i]].push_back(i);
				lg_cnt.push_back(cnt[i]);
			}
		for(int i = 1; i <= n; ++i) {
			std::sort(t[i].begin(), t[i].end(), [&](const int &x, const int &y) {
				return d[x] > d[y];
			});
		}
		std::sort(lg_cnt.begin(), lg_cnt.end());
		lg_cnt.erase(std::unique(lg_cnt.begin(), lg_cnt.end()), lg_cnt.end());
		ll ans = 0;
		for(int u_c : lg_cnt)
			for(int v_c : lg_cnt) if(u_c <= v_c) {
				for(int u : t[u_c]) {
					for(int v : E[u]) vis[v] = 1;
					for(int v : t[v_c])
						if(!vis[v] && v != u) {
							ans = std::max(ans, (u_c + v_c) * (ll)(d[u] + d[v]));
							break;
						}
					for(int v : E[u]) vis[v] = 0;
				}
			}
		printf("%lld\n", ans);
	} return 0;
}