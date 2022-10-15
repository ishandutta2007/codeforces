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

int n, d, tot_s = 0, tot_l = 0; ll a[kN], b[kN], ans = 0, m;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, d, m);
		for(int i = 1; i <= n; ++i) {
			ll x; rd(x);
			if(x > m) b[++tot_l] = x;
			else a[++tot_s] = x;
		}
		std::sort(b + 1, b + tot_l + 1, [](const int &x, const int &y) { return x > y; });
		std::sort(a + 1, a + tot_s + 1, [](const int &x, const int &y) { return x > y; });
		for(int i = 1; i <= tot_l; ++i) b[i] += b[i - 1];
		for(int i = 1; i <= n; ++i) a[i] += a[i - 1];
		for(int i = (tot_l + d) / (1 + d); i <= std::min(tot_l, (n - 1) / (d + 1) + 1); ++i) {
			if(!i) ans = std::max(ans, a[tot_s]);
			else ans = std::max(ans, b[i] + a[n - (i - 1) * (d + 1) - 1]);
		}
		printf("%lld\n", ans);
	} return 0;
}