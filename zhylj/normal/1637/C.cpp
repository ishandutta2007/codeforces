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

int n, a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		if(n == 3) {
			if(a[2] % 2 == 0) printf("%d\n", a[2] / 2);
			else printf("-1\n");
		} else {
			bool flag = false;
			ll cnt = 0;
			for(int i = 2; i < n; ++i) {
				if(a[i] >= 2) {
					flag = true;
				}
				cnt += (a[i] + 1) / 2;
			}
			if(flag) printf("%lld\n", cnt);
			else printf("-1\n");
		}
	} return 0;
}