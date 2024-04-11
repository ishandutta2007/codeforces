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
const int kN = 5e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 1e9 + 7, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ret = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ret = ret * bas % kMod;
	return ret;
}

int n; ll x[kN], cnt[100], pw[100];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		rd(n);
		memset(cnt, 0, sizeof(cnt));
		ll ans = 0;
		for(int i = 1; i <= n; ++i) {
			rd(x[i]);
			for(int j = 0; j <= 60; ++j)
				if((x[i] >> j) & 1) ++cnt[j];
		}
		for(int j = 0; j <= 60; ++j) pw[j] = QPow(2, j);
		for(int i = 1; i <= n; ++i) {
			ll sum_and = 0, sum_or = 0;
			for(int j = 0; j <= 60; ++j) {
				if((x[i] >> j) & 1) {
					sum_and = (sum_and + cnt[j] * pw[j]) % kMod;
					sum_or = (sum_or + n * pw[j]) % kMod;
				} else {
					sum_or = (sum_or + cnt[j] * pw[j]) % kMod;
				}
			}
			ans = (ans + sum_and * sum_or) % kMod;
		}
		printf("%lld\n", ans);
	} return 0;
}