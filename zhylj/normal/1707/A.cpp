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

int a[N], b[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		int n, q; rd(n, q);
		int j = 0;
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			//if(a[i] > q) a[i] = q + 1;
			b[i] = 0;
		}
		for(int i = n, j = 0; i; --i) {
			if(a[i] > j && j + 1 <= q) ++j, b[i] = 1;
			if(a[i] <= j) b[i] = 1;
		}
		for(int i = 1; i <= n; ++i)
			printf("%d", b[i]);
		printf("\n");
	} return 0;
}