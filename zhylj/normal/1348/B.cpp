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
typedef std::pair <int, int> pii;
const int kN = 1e3 + 5;
const ll kMod = 998244353;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

int a[kN], n, k; bool vis[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		memset(vis, false, sizeof(vis));
		rd(n, k);
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
		}
		for(int i = 1; i <= n; ++i) vis[a[i]] = true;
		int cnt = 0;
		for(int i = 1; i <= n; ++i) cnt += vis[i];
		if(cnt > k) {
			printf("-1\n");
			continue;
		} else {
			printf("%d\n", k * n);
			for(int i = 1; i <= n; ++i) {
				for(int j = 1; j <= n; ++j)
					if(vis[j]) printf("%d ", j);
				for(int j = 1; j <= k - cnt; ++j)
					printf("%d ", 1);
			}
			printf("\n");
		}
	} return 0;
}