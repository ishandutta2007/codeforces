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

int main() { int T = 1; rd(T);
	while(T--) {
		ll n, l, r; rd(n, l, r);
		for(ll k = 1, i = 1; k < n && i <= r; i += 2 * (n - k), ++k) {
			if(i + 2 * (n - k) < l) continue;
			for(ll j = i, j2 = k + 1; j < i + 2 * (n - k); ++j) {
				if(j % 2 == 1) {
					if(l <= j && j <= r) printf("%lld ", k);
				} else {
					if(l <= j && j <= r) printf("%lld ", j2);
					++j2;
				}
			}
		}
		if(r == n * (n - 1) + 1) printf("1");
		printf("\n");
	} return 0;
}