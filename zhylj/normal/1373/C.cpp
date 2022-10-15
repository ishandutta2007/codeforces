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
const int kN = 1e6 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

int n, top[kN]; char str[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		scanf("%s", str + 1);
		int n = strlen(str + 1);
		for(int i = 1; i <= n; ++i) {
			if(str[i] == '+') top[i] = top[i - 1] + 1;
			else top[i] = top[i - 1] - 1;
		}
		for(int i = 1; i <= n; ++i) top[i] = std::min(top[i], top[i - 1]);
		ll ans = 0;
		for(int i = 1; i <= n; ++i) ans += (top[i - 1] - top[i]) * ((ll)(i));
		printf("%lld\n", ans + n);
	} return 0;
}