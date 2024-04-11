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

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		ll p, q; rd(p, q);
		if(p % q != 0) printf("%lld\n", p);
		else {
			ll k = p / q, o_q = q, x = kInfLL;
			for(ll i = 2; i * i <= q; ++i) if(q % i == 0) {
				//printf("%lld ", i);
				ll rm = 1;
				while(q % i == 0) q /= i;
				while(k % i == 0) k /= i, rm *= i;
				rm *= i;
				x = std::min(x, rm);
			}
			if(q > 1) {
				//printf("%lld ", q);
				ll rm = 1;
				rm *= q;
				while(k % q == 0) k /= q, rm *= q;
				x = std::min(x, rm);
			}
			printf("%lld\n", p / x);
		}
	} return 0;
}