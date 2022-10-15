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

int n, m, k, q; ll a[kN], b[kN], f[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		ll ita_ans = 0;
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]), f[i] = b[i] = 0;
		if((n + 1) % 2 == 0) a[n + 1] = -kInf;
		for(int i = n; i <= n + 5; ++i) f[i] = 0;
		for(int i = 1; i <= n; i += 2) ita_ans = ita_ans + a[i];
		
		for(int i = 1; i < n; i += 2) b[i / 2 + 1] = a[i + 1] - a[i];
		for(int i = 1; i <= n / 2 + 1; ++i) f[i] = std::max(0LL, f[i - 1] + b[i]);
		ll max_sb = 0, max_ans = 0;
		for(int i = 1; i <= n / 2 + 1; ++i) max_sb = std::max(max_sb, f[i]);
		max_ans = std::max(max_ans, ita_ans + max_sb);

		for(int i = 1; i <= n + 5; ++i) f[i] = b[i] = 0;
		for(int i = 2; i < n; i += 2) b[i / 2] = a[i] - a[i + 1];
		max_sb = 0;
		for(int i = 1; i <= n / 2 + 1; ++i) f[i] = std::max(0LL, f[i - 1] + b[i]);
		for(int i = 1; i <= n / 2 + 1; ++i) max_sb = std::max(max_sb, f[i]);
		max_ans = std::max(max_ans, ita_ans + max_sb);

		printf("%lld\n", max_ans);
	} return 0;
}