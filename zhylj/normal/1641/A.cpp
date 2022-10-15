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

int n; ll x, a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, x);
		std::map <ll, int> s;
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			if(!s.count(a[i])) s[a[i]] = 0;
			++s[a[i]];
		}
		std::sort(a + 1, a + n + 1);
		int res = n;
		for(int i = 1; i <= n; ++i) {
			if(s[a[i]]) {
				int d = std::min(s[a[i]], s[a[i] * x]);
				res -= 2 * d;
				s[a[i]] -= d; s[a[i] * x] -= d;
			}
		}
		printf("%d\n", res);
	} return 0;
}