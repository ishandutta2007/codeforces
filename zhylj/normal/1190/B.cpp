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

int a[N], mn[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		int n; rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		std::sort(a + 1, a + n + 1);
		int s = 0;
		mn[1] = 0;
		for(int i = 2; i <= n; ++i)
			if(a[i] == a[i - 1]) {
				a[i - 1] = std::max(a[i - 1] - 1, 0);
				s = 1;
				break;
			}
		for(int i = 2; i <= n; ++i)
			if(a[i] == a[i - 1]) {
				printf("cslnb\n");
				return 0;
			}
		for(int i = 2; i <= n; ++i)
			mn[i] = std::min(mn[i - 1] + 1, a[i]);
		for(int i = 1; i <= n; ++i) 
			s = (s + a[i] - mn[i]) % 2;
		printf(s ? "sjfnb\n" : "cslnb\n");
	} return 0;
}