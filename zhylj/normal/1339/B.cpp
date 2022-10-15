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
typedef std::pair<int, int> pii;
const int kN = 1e6 + 5;
const ll kMod = 998244353;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

int a[kN], b[kN], n;

int main() { int T = 1; rd(T);
	while(T--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		std::sort(a + 1, a + n + 1);
		for(int i = 1; i <= n / 2; ++i) {
			b[i * 2 - 1] = a[i];
			b[i * 2] = a[n - i + 1];
		}
		if(n % 2 == 1) {
			b[n] = a[n / 2 + 1];
		}
		std::reverse(b + 1, b + n + 1);
		for(int i = 1; i <= n; ++i) printf("%d ", b[i]);
		printf("\n");
	} return 0;
}