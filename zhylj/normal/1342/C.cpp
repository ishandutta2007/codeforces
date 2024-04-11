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

int a, b, lcm, q;
ll Gcd(ll x, ll y) { return y ? Gcd(y, x % y) : x; }
ll Cal(ll r) {
	ll ret = 0;
	for(int i = 0; i < a && i <= r; ++i) {
		//printf("%d\n", r - i);
		ret += (r - i) / lcm + 1;
	}
	return ret;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		rd(a, b, q); if(a < b) std::swap(a, b);
		lcm = a * b / Gcd(a, b);
		while(q--) {
			ll l, r; rd(l, r);
			printf("%lld ", r - l + 1 - (Cal(r) - Cal(l - 1)));
		}
		printf("\n");
	} return 0;
}