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
const int kN = 1e6 + 5;
const ll kMod = 998244353;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}
ll Gcd(ll a, ll b) { return b ? Gcd(b, a % b) : a; }
ll Lcm(ll a, ll b) { return a * b / Gcd(a, b); }

ll a[kN], gd[kN]; int n;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		gd[n] = a[n];
		for(int i = n - 1; i; --i) gd[i] = Gcd(gd[i + 1], a[i]);
		//for(int i = 1; i <= n; ++i) printf("%lld ", gd[i]);
		//printf("\n");
		ll ans = Lcm(a[1], gd[2]);
		for(int i = 1; i < n; ++i) {
			ans = Gcd(ans, Lcm(a[i], gd[i + 1]));
		}
		printf("%lld", ans);
	} return 0;
}