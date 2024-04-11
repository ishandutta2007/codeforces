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
const int kN = 5e3 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, A[kN], f[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		memset(f, 0, sizeof(f));
		rd(n);
		for(int i = 1; i <= n; ++i) {
			rd(A[i]);
		}
		ll ans = 0;
		for(int i = 1; i <= n; ++i) {
			ans += std::max(A[i] - 1 - f[i], 0);
			f[i] -= A[i] - 1;
			if(f[i] > 0) {
				f[i + 1] += f[i];
			}
			for(int j = i + 2; j <= std::min(n, i + A[i]); ++j) {
				++f[j];
			}
		}
		printf("%lld\n", ans);
	} return 0;
}