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
#define V std::vector
#define H std::priority_queue
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

int n, m, k, q, a[kN], w[kN], minn[kN], maxn[kN], idx[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		rd(n, k); ll ans = 0;
		for(int i = 1; i <= n; ++i) idx[i] = i;
		for(int i = 1; i <= n; ++i) rd(a[i]);
		std::sort(a + 1, a + n + 1); std::reverse(a + 1, a + n + 1);
		for(int i = 1; i <= k; ++i) rd(w[i]);
		std::sort(idx + 1, idx + k + 1, [&](const int &x, const int &y) { return w[x] < w[y]; });
		for(int i = 1; i <= k; ++i) --w[idx[i]], minn[idx[i]] = maxn[idx[i]] = a[i];
		std::reverse(a + 1, a + n + 1); std::reverse(idx + 1, idx + k + 1);
		for(int i = 1, cur = 1; i <= k; ++i)
			while(w[idx[i]]) minn[idx[i]] = std::min(a[cur++], minn[idx[i]]), --w[idx[i]];
		for(int i = 1; i <= k; ++i) ans += minn[i];
		for(int i = 1; i <= k; ++i) ans += maxn[i];
		printf("%lld\n", ans);
	} return 0;
}