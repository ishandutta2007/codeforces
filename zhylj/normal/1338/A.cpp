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

int a[kN];
int Log2(int x) {
	if(x == 0) return 0;
	int ret = 0;
	for(int i = 0; i <= 31; ++i)
		if((x >> i) & 1) ret = i;
	return ret + 1;
}

int main() { int T = 1; rd(T);
	while(T--) {
		int n; rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = i + 1; j <= n && a[j] < a[j - 1]; ++j)
				ans = std::max(ans, Log2(a[i] - a[j])), a[j] = a[i];
		}
		printf("%d\n", ans);
	} return 0;
}