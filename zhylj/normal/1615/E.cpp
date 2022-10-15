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
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int n, k, d_mx[N], d_pos[N], idx[N], cnt[N];
std::vector <int> E[N];

ll Sq(ll x) { return x * x; }

void Dfs(int u, int p) {
	d_pos[u] = u;
	for(int v : E[u]) if(v != p) {
		Dfs(v, u);
		if(d_mx[v] + 1 > d_mx[u]) {
			d_mx[u] = d_mx[v] + 1;
			d_pos[u] = d_pos[v];
		}
	}
	++cnt[d_pos[u]];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, k);
		for(int i = 1; i < n; ++i) {
			int u, v; rd(u, v);
			E[u].push_back(v);
			E[v].push_back(u);
		}
		Dfs(1, 0);
		for(int i = 1; i <= n; ++i) idx[i] = i;
		std::sort(idx + 1, idx + n + 1, [&](const int &x, const int &y) {
			return cnt[x] > cnt[y];
		});
		int cur_w = 0;
		ll ans = -Sq(n / 2);
		for(int i = 1; i <= k; ++i) {
			cur_w += cnt[idx[i]] - 1;
			int m = n - i - cur_w;
			if(m <= n / 2) ans = std::max(ans, 1LL * (n - i - m) * (i - m));
			else ans = std::max(ans, -Sq(n / 2 - i));
		}
		printf("%lld\n", ans);
	} return 0;
}