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

std::map <int, int> g;
int n, a[N], s[N], f[N];
void Upd(int &x, int y) { x = std::min(x, y); }

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			s[i] = a[i];
		}
		for(int i = 1; i <= n; ++i)
			s[i] ^= s[i - 1];
		g[0] = 1e9;
		for(int i = 1; i <= n; ++i)
			f[i] = 1e9, g[s[i]] = 1e9;
		Upd(g[0], 0);
		for(int i = 1; i <= n; ++i) {
			Upd(f[i], f[i - 1] + 1);
			Upd(f[i], g[s[i]] + i - 1);
			Upd(g[s[i]], f[i] - i);
		}
		printf("%d\n", f[n]);
	} return 0;
}