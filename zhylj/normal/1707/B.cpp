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

int n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		std::map <int, int> a;
		for(int i = 1; i <= n; ++i) {
			int x; rd(x);
			++a[x];
		}
		for(int i = 1; i < n; ++i)  {
			int lst = -1;
			std::map <int, int> b;
			for(auto p : a) {
				if(~lst) ++b[p.fi - lst];
				if(p.se) {
					b[0] += p.se - 1;
					lst = p.fi;
				}
			}
			std::swap(a, b);
		}
		for(auto p : a) {
			if(p.se) printf("%d ", p.fi);
		}
		printf("\n");
	} return 0;
}