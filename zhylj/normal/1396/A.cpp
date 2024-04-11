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

ll Exgcd(ll a, ll b, ll &x, ll &y) {
	if(!b) return x = 1, y = 0, a;
	ll g = Exgcd(b, a % b, x, y);
	ll t = x;
	x = y; y = t - a / b * y;
	return g;
}
int n; ll a[kN], b[kN], c[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n);
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
		}
		if(n == 1) {
			printf("1 1\n%lld\n1 1\n%lld\n1 1\n%lld\n", a[1], -a[1], -a[1]);
		} else {
			ll x, y;
			for(int i = 2; i <= n; ++i) {
				b[i] = 1; c[i] = -1;
				//Exgcd(n, n - 1, b[i], c[i]);
				b[i] *= n * a[i]; c[i] *= (n - 1) * a[i];
			}
			printf("1 1\n%lld\n", -a[1]);
			printf("1 %d\n", n);
			for(int i = 1; i <= n; ++i) printf("%lld ", -b[i]);
			printf("\n2 %d\n", n);
			for(int i = 2; i <= n; ++i) printf("%lld ", -c[i]);
			printf("\n");
		}
	} return 0;
}