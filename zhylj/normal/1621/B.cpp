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
const int N = 5e5 + 5, INF = 0x7fffffff;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		int n; rd(n);
		int l_mn = INF, r_mx = -INF, sg_cost = INF, l_cost = 0, r_cost = 0;
		for(int i = 1; i <= n; ++i) {
			int l, r, c; rd(l, r, c);
			if(l < l_mn) l_mn = l, sg_cost = INF, l_cost = c;
			else if(l_mn == l) l_cost = std::min(l_cost, c);
			if(r > r_mx) r_mx = r, sg_cost = INF, r_cost = c;
			else if(r_mx == r) r_cost = std::min(r_cost, c);
			if(l == l_mn && r == r_mx) sg_cost = std::min(sg_cost, c);
			printf("%d\n", std::min(l_cost + r_cost, sg_cost));
		}
	} return 0;
}