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

int n, a[N][N], b[N][N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				rd(a[i][j]);
		for(int x = 2; x <= n; ++x) 
			for(int y = 1; y <= n; ++y)  {
				b[x][y] = a[x - 1][y] ^ b[x - 2][y] ^ b[x - 1][y - 1] ^ b[x - 1][y + 1];
			}
		int ans = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				ans ^= b[i][j];
		printf("%d\n", ans);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				a[i][j] = b[i][j] = 0;
	} return 0;
}