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
const int N = 1e3 + 5;

int n, m, x, y;
ff f[N][N], A[N][N], B[N][N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m, x, y);
		if(m == 1) {
			printf("%.10lf\n", 2.0 * (n - x));
			return 0;
		}
		for(int i = 1; i <= m; ++i) f[n][i] = 0;
		for(int i = n - 1; i; --i) {
			A[i][m] = (ff)1 / 2;
			B[i][m] = (f[i + 1][m] + 3) / 2;
			for(int j = m - 1; j > 1; --j) {
				ff d = 1 / (3 - A[i][j + 1]);
				A[i][j] = d;
				B[i][j] = d * (f[i + 1][j] + B[i][j + 1] + 4);
			}
			f[i][1] = 1 / (2 - A[i][2]) * (f[i + 1][1] + B[i][2] + 3);
			for(int j = 2; j <= m; ++j)
				f[i][j] = A[i][j] * f[i][j - 1] + B[i][j];
		}
		printf("%.10lf\n", f[x][y]);
	} return 0;
}