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
 
int n, a[kN], f[kN][kN];
void Update(int &x, int y) { x = std::min(x, y); }
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		memset(f, 0x3f, sizeof(f));
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		f[1][0] = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 0; j <= n; ++j) {
				Update(f[i][j + 1], f[i][j] + 1);
				Update(f[i + 1][std::min(j, a[i])], f[i][j] + (j < a[i]));
				//printf("F[%d][%d] = %d\n", i, j, f[i][j]);
			}
		int ans = kInf;
		for(int i = 0; i <= n; ++i)
			ans = std::min(ans, f[n + 1][i]);
		printf("%d\n", ans);
	} return 0;
}