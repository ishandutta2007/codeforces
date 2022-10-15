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
const int kN = 1e2 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, a[kN], b[kN]; ff f[kN][kN * kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n);
		ff s = 0; int s_ai = 0;
		for(int i = 1; i <= n; ++i) {
			rd(a[i], b[i]);
			s += b[i]; s_ai += a[i];
		}
		s /= 2;
		for(int i = 0; i <= n; ++i)
			for(int j = 0; j <= s_ai; ++j) 
				f[i][j] = -1e9;
		f[0][0] = 0;
		for(int i = 1; i <= n; ++i) {
			for(int k = i; k; --k)
				for(int j = s_ai; j >= a[i]; --j)
					f[k][j] = std::max(f[k][j], f[k - 1][j - a[i]] + b[i] / 2.0);
		}
		for(int i = 1; i <= n; ++i) {
			ff ans = 0;
			for(int j = 0; j <= s_ai; ++j) {
				ans = std::max(ans, std::min(s + f[i][j], (ff)j));
			}
			printf("%.11lf ", ans);
		}
		printf("\n");
	} return 0;
}