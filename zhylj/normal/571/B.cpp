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
const int kN = 4e5 + 5, kM = 5e3 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, k, A[kN]; ll f[kM][kM], tot = 0;
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		memset(f, ~0x3f, sizeof(f));
		memset(A, 0, sizeof(A));
		rd(n, k);
		for(int i = 1; i <= n; ++i)
			rd(A[i]);
		std::sort(A + 1, A + n + 1);
		A[n + 1] = A[n];
		for(int i = 2; i <= n; ++i)
			tot += A[i] - A[i - 1];
		//printf("%lld\n", tot);
		f[0][0] = 0;
		for(int i = 1; i <= k; ++i)
			for(int j = 0; j <= n % k; ++j) {
				int cur = (n / k) * i + j;
				if(j) f[i][j] = std::max(f[i - 1][j], f[i - 1][j - 1]) + A[cur + 1] - A[cur];
				else f[i][j] = f[i - 1][j] + A[cur + 1] - A[cur];
				//printf("%d %d %d %d\n", i, j, cur, A[cur + 1] - A[cur]);
			}
		//printf("%lld\n", f[k][n % k]);
		printf("%lld\n", tot - f[k][n % k]);
	} return 0;
}