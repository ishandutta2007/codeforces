#include <bits/stdc++.h>

#define gc() getchar()
template <typename T> inline void rd(T& x) {
	int si = 1; char c = gc(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 1e4 + 5, M = 100 + 5;

int n, x, c[N]; ff f[N], g[N], h[N], p[N][M], _p[N][M];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, x);
		int tot = 0;
		for(int i = 1; i <= n; ++i) rd(c[i]), tot += c[i];
		ff ans = 0, fac = 1;
		p[0][0] = 1;
		for(int i = 1; i <= n; ++i) fac *= i;
		for(int i = 0; i <= n; ++i) {
			f[i] = ((ff)n / (n - i) - 1) * x / 2 + x;
			g[i] = 1 / fac;
			for(int j = 1; j <= i; ++j)
				g[i] *= j;
			for(int j = 1; j <= n - i; ++j)
				g[i] *= j;
			h[i] = f[i];
		}
		for(int i = 1; i <= n; ++i) h[i] += h[i - 1];
		f[n] = 0;
		std::reverse(g, g + n + 1);
		int s = 0;
		if(tot < n * f[0]) {
			p[0][0] = 0;
			ans += tot;
		} else ans += f[0];
		for(int i = 1; i <= n; ++i) {
			memcpy(_p, p, sizeof(_p));
			for(int j = 0; j <= s; ++j)
				for(int k = 0; k <= i; ++k) {
					if(p[j][k] < 1e-8) continue;
					if(tot - j - c[i] < (n - k - 1) * f[k + 1]) {
						ans += p[j][k] * g[k + 1] * (tot - j - c[i]) / (n - k - 1);
						//p[j][k] = 0;
					} else {
						ans += p[j][k] * g[k + 1] * f[k + 1];
						//_p[j + c[i]][k + 1] += p[j][k];
					}
					_p[j + c[i]][k + 1] += p[j][k];
				}
			s += c[i];
			memcpy(p, _p, sizeof(p));
		}
		printf("%.12lf\n", ans);
	} return 0;
}