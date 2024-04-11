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

int n, a, b, p[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, a, b);
		if(abs(a - b) > 1 || !(std::max(a, b) <= (n - 1) / 2 && std::min(a, b) <= (n - 2) / 2)) {
			printf("-1\n");
		} else {
			int l = 1, r = n, cur;
			if(a > b) {
				cur = l;
			} else {
				cur = r;
			}
			for(int i = 1; i <= n; ++i) {
				printf("%d ", cur);
				if(cur == l) {
					cur = ++l;
					if(a) --a, cur = r;
				} else {
					cur = --r;
					if(b) --b, cur = l;
				}
			}
			printf("\n");
		}
	} return 0;
}