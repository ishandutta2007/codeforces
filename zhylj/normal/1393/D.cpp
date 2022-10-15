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
#define V std::vector
#define H std::priority_queue
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 2e3 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

int n, m, f1[kN][kN], f2[kN][kN], f3[kN][kN], f4[kN][kN];
char mp[kN][kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, m);
		for(int i = 1; i <= n; ++i) scanf("%s", mp[i] + 1);
		for(int i = 1; i <= n; ++i) 
			for(int j = 1; j <= m; ++j)
				f1[i][j] = f2[i][j] = f3[i][j] = f4[i][j] = 1;
		for(int i = 1; i <= n; ++i) 
			for(int j = 1; j <= m; ++j) {
				if(mp[i][j] == mp[i - 1][j] && mp[i][j] == mp[i][j - 1])
					f1[i][j] = std::min(f1[i - 1][j], f1[i][j - 1]) + 1;
			}
		for(int i = 1; i <= n; ++i) scanf("%s", mp[i] + 1);
		for(int i = n; i; --i) 
			for(int j = 1; j <= m; ++j) {
				if(mp[i][j] == mp[i + 1][j] && mp[i][j] == mp[i][j - 1])
					f2[i][j] = std::min(f2[i + 1][j], f2[i][j - 1]) + 1;
			}
		for(int i = n; i; --i) 
			for(int j = m; j; --j) {
				if(mp[i][j] == mp[i + 1][j] && mp[i][j] == mp[i][j + 1])
					f3[i][j] = std::min(f3[i + 1][j], f3[i][j + 1]) + 1;
			}
		for(int i = 1; i <= n; ++i) 
			for(int j = m; j; --j) {
				if(mp[i][j] == mp[i - 1][j] && mp[i][j] == mp[i][j + 1])
					f4[i][j] = std::min(f4[i - 1][j], f4[i][j + 1]) + 1;
			}
		ll ans = 0;
		for(int i = 1; i <= n; ++i) 
			for(int j = 1; j <= m; ++j) {
				f1[i][j] = std::min({f1[i][j], f2[i][j], f3[i][j], f4[i][j]});
				ans += f1[i][j];
			}
		printf("%lld\n", ans);
	} return 0;
}