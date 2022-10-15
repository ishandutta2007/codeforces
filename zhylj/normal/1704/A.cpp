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

char a[N], b[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		int n, m; rd(n, m);
		scanf("%s%s", a + 1, b + 1);
		bool flag = true, flag_0 = false, flag_1 = false;
		for(int i = 1; i < m; ++i) 
			if(b[m - i + 1] != a[n - i + 1]) flag = false;
		for(int i = 1; i <= n - m + 1; ++i) {
			if(a[i] == '0') flag_0 = true;
			if(a[i] == '1') flag_1 = true;
		}
		if(b[1] == '1' && !flag_1) flag = false;
		if(b[1] == '0' && !flag_0) flag = false;
		printf(flag ? "YES\n" : "NO\n");
	} return 0;
}