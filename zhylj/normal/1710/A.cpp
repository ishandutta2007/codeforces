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

int n, m, k, a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m, k);
		for(int i = 1; i <= k; ++i)
			rd(a[i]);
		std::sort(a + 1, a + k + 1, std::greater <int>());
		ll cnt_1 = 0, cnt_2 = 0;
		for(int i = 1; i <= k; ++i) {
			if(a[i] / n >= 2 && cnt_1 < m)
				cnt_1 += a[i] / n;
			if(a[i] / m >= 2 && cnt_2 < n)
				cnt_2 += a[i] / m;
		}
		if(cnt_1 == m || cnt_2 == n ||
			(cnt_1 > m && a[1] / n > 2) || (cnt_2 > n && a[1] / m > 2))
			printf("Yes\n");
		else printf("No\n");
	} return 0;
}