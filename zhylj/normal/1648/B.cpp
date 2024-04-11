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
const int N = 1e6 + 5;

int n, c, a[N], s[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, c);
		for(int i = 1; i <= c; ++i) s[i] = 0;
		for(int i = 1; i <= n; ++i) rd(a[i]), s[a[i]] = 1;
		for(int i = 1; i <= c; ++i) s[i] += s[i - 1];
		bool flag = true;
		for(int i = 1; i <= c; ++i) if(s[i] - s[i - 1])
			for(int j = i; j <= c; j += i)
				if(s[std::min(c, j + i - 1)] - s[std::max(j, 1) - 1] &&
					!(s[j / i] - s[j / i - 1])) {
					flag = false;
				}
		printf(flag ? "Yes\n" : "No\n");
	} return 0;
}