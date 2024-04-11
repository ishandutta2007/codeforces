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
const int kN = 5e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll Gcd(ll a, ll b) {
	return b ? Gcd(b, a % b) : a;
}

int n; ll A[kN], k;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		rd(n, k);
		for(int i = 1; i <= n; ++i) 
			rd(A[i]);
		for(int i = 2; i <= n; ++i) {
			A[i] -= A[1];
			if(A[i] < 0) A[i] = -A[i];
		}
		ll g = 0;
		for(int i = 2; i <= n; ++i)
			g = Gcd(g, A[i]);
		if((k - A[1]) % g == 0) {
			printf("YES\n");
		} else printf("NO\n");
	} return 0;
}