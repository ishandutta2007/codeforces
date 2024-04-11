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
const int kN = 5e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, x[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		rd(n);
		int cnt = 0;
		for(int i = 1; i <= n; ++i) {
			rd(x[i]);
		}
		std::sort(x + 1, x + n + 1);
		x[n + 1] = kInf; x[0] = -kInf;
		for(int i = 1; i <= n; ++i) {
			if(x[i - 1] != x[i]) {
				++cnt;
			} else if(x[i - 1] == x[i] && x[i + 1] > x[i]) {
				++cnt; ++x[i];
			}
		}
		printf("%d\n", cnt);
	} return 0;
}