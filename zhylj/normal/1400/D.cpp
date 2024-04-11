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
const int kN = 3e3 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, a[kN]; ll cntl[kN], cntr[kN], cur_pi;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		rd(n);
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
		}
		ll ans = 0;
		for(int i = 1; i <= n; ++i) {
			cur_pi = 0;
			memset(cntr, 0, sizeof(cntr));
			memset(cntl, 0, sizeof(cntl));
			for(int j = i + 2; j <= n; ++j) ++cntr[a[j]];
			for(int j = i + 1; j < n; ++j) {
				if(a[i] == a[j]) {
					//printf("%d %d %lld %lld\n", i, j, cntl[2], cntr[2]);
					ans += cur_pi;
				}
				int col1 = a[j], col2 = a[j + 1];
				cur_pi -= cntl[col1] * cntr[col1];
				if(col1 != col2) cur_pi -= cntl[col2] * cntr[col2];
				++cntl[col1]; --cntr[col2];
				cur_pi += cntl[col1] * cntr[col1];
				if(col1 != col2) cur_pi += cntl[col2] * cntr[col2];
			}
		}
		printf("%lld\n", ans);
	} return 0;
}