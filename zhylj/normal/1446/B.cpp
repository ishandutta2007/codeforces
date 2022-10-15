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
const int kN = 5e3 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, f[kN][kN]; char s[kN], t[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, m);
		scanf("%s%s", s + 1, t + 1);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j) {
				f[i][j] = std::max({
					f[i - 1][j] - 1,
					f[i][j - 1] - 1,
					f[i - 1][j - 1] + 4 * (s[i] == t[j]) - 2,
					0
				});
			}
		int ans = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j) 
				ans = std::max(ans, f[i][j]);
		printf("%d\n", ans);
	} return 0;
}