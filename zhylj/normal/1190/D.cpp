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

struct BIT {
	int tr[N];
	void Modify(int o, int v) {
		for(; o < N; o += o & -o) tr[o] += v;
	}
	int Query(int o) {
		int res = 0;
		for(; o > 0; o -= o & -o) res += tr[o];
		return res;
	}
	int Query(int l, int r) {
		return Query(r) - Query(l - 1);
	}
} T;

int n, c, d[N], X[N], Y[N], tot[N];
std::vector <int> p[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) {
			rd(X[i], Y[i]);
			d[++c] = Y[i]; d[++c] = X[i];
		}
		std::sort(d + 1, d + c + 1);
		c = std::unique(d + 1, d + c + 1) - d - 1;
		for(int i = 1; i <= n; ++i) {
			X[i] = std::lower_bound(d + 1, d + c + 1, X[i]) - d;
			Y[i] = std::lower_bound(d + 1, d + c + 1, Y[i]) - d;
			p[Y[i]].push_back(X[i]);
			if(!tot[X[i]]) T.Modify(X[i], 1);
			++tot[X[i]];
		}
		for(int i = 1; i <= c; ++i)
			std::sort(p[i].begin(), p[i].end());
		ll ans = 0;
		for(int i = 1; i <= c; ++i) {
			int siz = p[i].size(), t = T.Query(1, c);
			ll tmp = 1LL * t * (t + 1) / 2;
			for(int j = -1; j < siz; ++j) {
				int l = (~j ? p[i][j] : 0), 
					r = (j != siz - 1 ? p[i][j + 1] : c + 1),
					cnt = T.Query(l + 1, r - 1);
				tmp -= 1LL * cnt * (cnt + 1) / 2;
			}
			for(int j = 0; j < siz; ++j) {
				int v = p[i][j]; --tot[v];
				if(!tot[v]) T.Modify(v, -1);
			}
			ans += tmp;
		}
		printf("%lld\n", ans);
	} return 0;
}