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
const int N = 1e6 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, b[N], f[N][6][6];
void Update(int &x, int y) {
	x = std::max(x, y);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		memset(f, ~0x3f, sizeof(f));
		rd(n, m);
		for(int i = 1; i <= n; ++i) {
			int x; rd(x);
			++b[x];
		}
		f[1][0][0] = 0;
		for(int i = 1; i <= m; ++i)
			for(int j = 0; j < 6; ++j)
				for(int k = 0; k <= j; ++k)
					for(int w = 0; w <= k && w <= b[i]; ++w)
						for(int r = 0; r < 6 && w + r <= b[i]; ++r) {
							Update(f[i + 1][r][j - w],
								f[i][j][k] + w + (b[i] - w - r) / 3);
						}
		int ans = 0;
		for(int i = 0; i < 6; ++i)
			for(int j = 0; j < 6; ++j)
				Update(ans, f[m + 1][i][j]);
		printf("%d\n", ans);
	} return 0;
}