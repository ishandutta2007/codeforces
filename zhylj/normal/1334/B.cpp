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

ll a[kN]; int n, m, k, q;
int main() { int T = 1; rd(T);
	while(T--) {
		ll x;
		rd(n, x);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		std::sort(a + 1, a + n + 1, [](int i, int j) { return i > j; });
		ll cur = 0; int i;
		for(i = 0; i < n; ++i) {
			if(cur + a[i + 1] < x * (i + 1)) { break; }
			cur += a[i + 1];
		}
		printf("%d\n", i);
	} return 0;
}