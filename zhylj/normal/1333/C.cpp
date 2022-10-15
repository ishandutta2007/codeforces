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

ll a[kN]; int n, m, k, q;
std::map <ll, int> sb;
ll s[kN];
int main() { int T = 1; //Read(T);
	while(T--) {
		ll ans = 0;
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]), s[i] = s[i - 1] + a[i];
		sb[0] = 1;
		int lst = 0;
		for(int i = 1; i <= n; ++i) {
			ans += (i - std::max(lst, sb[s[i]]));
			lst = std::max(sb[s[i]], lst);
			sb[s[i]] = i + 1;
		}
		printf("%lld", ans);
	} return 0;
}