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
		std::sort(a + 1, a + n + 1);
		n = std::unique(a + 1, a + n + 1) - a - 1;
		bool flag = true;
		for(int i = 1; i <= n; ++i) {
			if(a[i] == 1) flag = false;
		}
		if(flag) {
			printf("YES\n");
			continue;
		}
		bool flag_2 = true;
		for(int i = 1; i < n; ++i)
			if(a[i + 1] == a[i] + 1) flag_2 = false;
		if(flag_2) {
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	} return 0;
}