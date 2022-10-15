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
typedef std::pair<int, int> pii;
const int kN = 1e6 + 5;
const ll kMod = 998244353;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

int n, m, k, q, d[kN], idx[kN], fa[kN], t[kN], siz[kN];
std::vector <int> E[kN];
void Dfs(int cur) {
	siz[cur] = 1;
	for(auto x : E[cur]) if(x != fa[cur]) {
		fa[x] = cur; d[x] = d[cur] + 1; Dfs(x); siz[cur] += siz[x];
	}
}
int main() { int T = 1; //rd(T);
	while(T--) {
		rd(n, k);
		for(int i = 1; i < n; ++i) {
			int a, b; rd(a, b);
			E[a].push_back(b);
			E[b].push_back(a);
		}
		for(int i = 1; i <= n; ++i) idx[i] = i;
		d[1] = 1;
		Dfs(1);
		std::sort(idx + 1, idx + n + 1, [](int a, int b) { return d[a] - siz[a] > d[b] - siz[b]; });
		ll ans = 0;
		for(int i = 1; i <= k; ++i) ans += d[idx[i]] - siz[idx[i]];
		printf("%lld", ans);
	} return 0;
}