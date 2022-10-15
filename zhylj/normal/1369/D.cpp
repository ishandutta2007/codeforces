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
const int kN = 4e6 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 1e9 + 7, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

int n, m, k, q; ll f[kN]; bool col_root[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	col_root[3] = true; f[3] = 4;
	for(int i = 4; i <= 2e6; ++i) {
		f[i] = (f[i - 1] + f[i - 2] * 2 % kMod) % kMod;
		if((!col_root[i - 1]) && (!col_root[i - 2])) col_root[i] = true, f[i] = (f[i] + 4) % kMod;
	}
	while(T--) {
		rd(n);
		printf("%lld\n", f[n]);
	} return 0;
}