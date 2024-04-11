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

int n, A[kN], u, v;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		rd(n, u, v);
		for(int i = 1; i <= n; ++i) {
			rd(A[i]);
		}
		int d = 0;
		for(int i = 2; i <= n; ++i) {
			d = std::max(d, abs(A[i] - A[i - 1]));
		}
		if(d >= 2) {
			printf("0\n");
		} else if(d == 1) {
			printf("%d\n", std::min(u, v));
		} else {
			printf("%d\n", std::min(u + v, 2 * v));
		}
	} return 0;
}