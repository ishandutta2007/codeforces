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
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, k, pre[kN], b[kN], flag[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		rd(n, k);
		for(int i = 1; i <= n; ++i) {
			int x; rd(x);
			pre[x] = i; flag[i] = 1;
		}
		flag[0] = flag[n + 1] = 0;
		ll ans = 1;
		for(int i = 1; i <= k; ++i) {
			rd(b[i]);
		}
		for(int i = k; i; --i) {
			ans = ans * (flag[pre[b[i]] - 1] + flag[pre[b[i]] + 1]) % kMod;
			flag[pre[b[i]]] = 0;
		}
		printf("%lld\n", ans);
	} return 0;
}