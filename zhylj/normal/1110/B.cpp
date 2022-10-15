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
const int N = 5e5 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, k, b[N], d[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m, k);
		for(int i = 1; i <= n; ++i) rd(b[i]);
		for(int i = 1; i < n; ++i) {
			d[i] = std::max(b[i + 1] - (b[i] + 1), 0);
		}
		int s = b[n] - b[1] + 1;
		std::sort(d + 1, d + n);
		std::reverse(d + 1, d + n);
		for(int i = 1; i < std::min(k, n); ++i) {
			s -= d[i];
		}
		printf("%d\n", s);
	} return 0;
}