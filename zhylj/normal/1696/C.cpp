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

int n, m, k, a[N], b[N], c[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		ll s = 0;
		for(int i = 1; i <= n; ++i) {
			rd(a[i]); s += a[i];
			c[i] = 1;
			while(a[i] % m == 0)
				c[i] *= m, a[i] /= m;
		}
		rd(k);
		bool flag = true;
		for(int i = 1, j = 1; i <= k; ++i) {
			rd(b[i]);
			s -= b[i];
			int cur_c = 1;
			while(b[i] % m == 0)
				cur_c *= m, b[i] /= m;
			while(cur_c && j <= n && a[j] == b[i]) {
				int d = std::min(cur_c, c[j]);
				cur_c -= d; c[j] -= d;
				if(!c[j]) ++j;
			}
			if(cur_c) flag = false;
		}
		if(s != 0) flag = false;
		printf(flag ? "Yes\n" : "No\n");
	} return 0;
}