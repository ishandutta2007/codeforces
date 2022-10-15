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

int n; std::pair <pii, int> p[N];
bool vis[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= 2 * n - 1; ++i) {
			rd(p[i].fi.fi, p[i].fi.se);
			p[i].se = i;
		}
		std::sort(p + 1, p + 2 * n);
		std::reverse(p + 1, p + 2 * n);
		printf("YES\n");
		ll tot = 0, hlf = 0;
		for(int i = 1; i <= 2 * n - 1; ++i)
			tot += p[i].fi.se, hlf += (i % 2 == 1) * p[i].fi.se;
		if(2 * hlf >= tot) {
			for(int i = 1; i <= 2 * n - 1; i += 2) 
				printf("%d ", p[i].se);
			printf("\n");
		} else {
			printf("%d ", p[1].se);
			for(int i = 2; i <= 2 * n - 1; i += 2)
				printf("%d ", p[i].se);
			printf("\n");
		}
	} return 0;
}