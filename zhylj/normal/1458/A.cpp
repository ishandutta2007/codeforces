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

int n, m; ll A[kN], B[kN];
ll Gcd(ll a, ll b) { return b ? Gcd(b, a % b) : a; }

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, m);
		for(int i = 1; i <= n; ++i) rd(A[i]);
		std::sort(A + 1, A + n + 1);
		for(int i = 1; i <= m; ++i) rd(B[i]);
		if(n == 1) {
			for(int j = 1; j <= m; ++j) {
				printf("%lld ", A[1] + B[j]);
			}
			printf("\n");
			return 0;
		}
		ll g = A[n] - A[n - 1];
		for(int i = n - 1; i > 1; --i) g = Gcd(g, A[i] - A[i - 1]);
		for(int i = 1; i <= m; ++i) {
			printf("%lld ", Gcd(g, A[1] + B[i]));
		}
		printf("\n");
	} return 0;
}