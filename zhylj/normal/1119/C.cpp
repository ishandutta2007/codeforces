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
const int N = 500 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, A[N][N], B[N][N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				rd(A[i][j]);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j) {
				rd(B[i][j]);
			}
		for(int i = 1; i < n; ++i)
			for(int j = 1; j < m; ++j) {
				if(A[i][j] != B[i][j]) {
					A[i][j] ^= 1;
					A[i + 1][j] ^= 1;
					A[i][j + 1] ^= 1;
					A[i + 1][j + 1] ^= 1;
				}
			}
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				if(A[i][j] != B[i][j]) {
					printf("No\n");
					return 0;
				}
		printf("Yes\n");
	} return 0;
}