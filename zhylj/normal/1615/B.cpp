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
const int N = 5e5 + 5;

int Get(int x, int i) {
	int U = ~((1 << i) - 1), ret = 0;
	ret += (x >> i) / 2 * (1 << i);
	if((x >> i) & 1) ret += x - (x & U) + 1;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		int l, r; rd(l, r);
		int ans = 1;
		for(int i = 20; ~i; --i) {
			int U = ~((1 << i) - 1);
			ans = std::max(ans, Get(r, i) - Get(l - 1, i));
		}
		printf("%d\n", r - l + 1 - ans);
	} return 0;
}