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

ll a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		int n; rd(n);
		int cnt = 0;
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			while(a[i] % 2 == 0) a[i] /= 2, ++cnt;
		}
		std::sort(a + 1, a + n + 1);
		while(cnt--) a[n] *= 2;
		ll s = 0;
		for(int i = 1; i <= n; ++i)
			s += a[i];
		printf("%lld\n", s);
	} return 0;
}