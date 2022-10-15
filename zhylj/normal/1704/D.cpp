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

int n, m; ll s[N], c[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		int pos = 0; ll mx = -1e18, mn = 1e18;
		for(int i = 1; i <= n; ++i) {
			s[i] = 0;
			for(int j = 1; j <= m; ++j) {
				rd(c[j]);
				c[j] += c[j - 1];
				s[i] += c[j];
			}
			mx = std::max(mx, s[i]);
			mn = std::min(mn, s[i]);
			if(s[i] == mn) pos = i;
		}
		printf("%d %lld\n", pos, mx - mn);
	} return 0;
}