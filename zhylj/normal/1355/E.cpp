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

int n; ll A, R, M, h[kN];
ll Check(ll rh) {
	ll totr = 0, tota = 0;
	for(int i = 1; i <= n; ++i) {
		if(h[i] < rh) tota += rh - h[i];
		else totr += h[i] - rh;
	}
	if(tota > totr) return totr * M + (tota - totr) * A;
	else return tota * M + (totr - tota) * R;
}
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, A, R, M); M = std::min(A + R, M);
		for(int i = 1; i <= n; ++i) { 
			rd(h[i]);
		}
		ll l = 0, r = 1e9 + 5;
		while(r - l + 1 > 10) {
			int mid = (l + r) >> 1;
			if(Check(mid) < Check(mid + 1)) r = mid;
			else l = mid;
		}
		ll ans = kInfLL;
		for(int i = l; i <= r; ++i)
			ans = std::min(ans, Check(i));
		printf("%lld", ans);
	} return 0;
}