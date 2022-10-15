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
const int kN = 400 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, t[kN], f[kN][kN];
int Abs(int x) { return x < 0 ? -x : x; }

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		memset(f, 0x3f, sizeof(f));
		rd(n);
		for(int i = 1; i <= n; ++i) {
			rd(t[i]);
		}
		std::sort(t + 1, t + n + 1);
		f[0][0] = 0;
		for(int i = 1; i <= 2 * n; ++i) {
			f[i][0] = 0;
			for(int j = 1; j <= n; ++j)
				f[i][j] = std::min(f[i - 1][j], f[i - 1][j - 1] + Abs(t[j] - i));
		}
		printf("%d\n", f[2 * n][n]);
	} return 0;
}