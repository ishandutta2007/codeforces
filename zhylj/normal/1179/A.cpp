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

int n, q; pii ans[N];
std::deque <int> d;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, q);
		for(int i = 1; i <= n; ++i) {
			int x; rd(x);
			d.push_back(x);
		}
		for(int i = 1; i <= n << 1; ++i) {
			int A = d[0], B = d[1]; ans[i] = mkp(A, B);
			d.pop_front(); d.pop_front();
			if(A < B) std::swap(A, B);
			d.push_front(A);
			d.push_back(B);
		}
		while(q--) {
			ll m; rd(m);
			if(m > n) m = n + (m - n) % (n - 1);
			printf("%d %d\n", ans[m].fi, ans[m].se);
		}
	} return 0;
}