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
const int N = 2e6 + 5;

struct BIT {
	pii tr[N];
	void Modify(int o, pii v) {
		for(; o < N; o += o & -o)
			tr[o] = std::max(tr[o], v);
	}
	pii Query(int o) {
		pii res = mkp(0, N);
		for(; o; o -= o & -o)
			res = std::max(res, tr[o]);
		return res;
	}
} T_1, T_2;

int n; pii f[N];
std::pair <pii, int> p[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) {
			int a, b; rd(a, b);
			p[i] = mkp(mkp(a, b), i);
		}
		std::sort(p + 1, p + n + 1, [](const std::pair <pii, int> &x, const std::pair <pii, int> &y) {
			if((x.fi.fi > x.fi.se) != (y.fi.fi > y.fi.se)) return (x.fi.fi > x.fi.se) < (y.fi.fi > y.fi.se);
			return x.fi.fi > x.fi.se ? x.fi.fi > y.fi.fi : x.fi.fi < y.fi.fi;
		});
		for(int i = 1; i <= n; ++i)  {
			if(p[i].fi.fi > p[i].fi.se) {
				f[i] = T_1.Query(N - p[i].fi.se); ++f[i].fi;
				T_1.Modify(N - p[i].fi.fi, mkp(f[i].fi, i));
			} else {
				f[i] = T_2.Query(p[i].fi.se); ++f[i].fi;
				T_2.Modify(p[i].fi.fi, mkp(f[i].fi, i));
			}
		}
		pii ans = mkp(0, N);
		for(int i = 1; i <= n; ++i)
			ans = std::max(ans, mkp(f[i].fi, i));
		printf("%d\n", ans.fi);
		for(int i = ans.se, j = 0; i < N && j < ans.fi; i = f[i].se, ++j)
			printf("%d ", p[i].se);
		printf("\n");
	} return 0;
}