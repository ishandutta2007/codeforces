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
const int kN = 3e3 + 5;
const ll kMod = 998244353;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

char s[kN], t[kN]; int n, m;
ll f[kN][kN];
int main() { int T = 1; //rd(T);
	while(T--) {
		scanf("%s%s", s + 1, t + 1); n = strlen(s + 1); m = strlen(t + 1);
		for(int i = 1; i <= n; ++i) f[i][i] = 2 * (i <= m ? s[1] == t[i] : 1);
		for(int len = 1; len < n; ++len)
			for(int i = 1; i + len - 1 <= n; ++i) {
				int j = i + len - 1, x = len + 1;
				if(j < n && (j + 1 > m || s[x] == t[j + 1])) f[i][j + 1] = (f[i][j + 1] + f[i][j]) % kMod;
				if(i > 1 && (i - 1 > m || s[x] == t[i - 1])) f[i - 1][j] = (f[i - 1][j] + f[i][j]) % kMod;
			}
		ll ans = 0;
		for(int i = m; i <= n; ++i) 
			ans = (ans + f[1][i]) % kMod;
		printf("%lld", ans);
	} return 0;
}