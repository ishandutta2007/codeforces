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
const int kN = 233;
const ll kMod = 998244353;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

ll a[kN]; int n;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	//printf("?");
	while(T--) {
		rd(n); //printf("%d\n", n);
		int tot = 0, x = 1;
		a[0] = tot = 1;
		//printf("%d %d\n", tot);
		for(; tot + (1LL << x) <= n; ++x) {
			//printf("%d\n", x);
			a[x] = (1LL << x);
			tot += (1LL << x);
		}
		--x;
		if(n - tot) a[++x] = n - tot;
		std::sort(a + 1, a + x + 1);
		printf("%d\n", x);
		for(int i = 1; i <= x; ++i) printf("%lld ", a[i] - a[i - 1]);
		printf("\n");
	} return 0;
}