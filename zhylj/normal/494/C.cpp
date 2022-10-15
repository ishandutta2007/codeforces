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
const int N = 3e5 + 5, B = 20, M = 5e3 + 5;
const ff Eps = 1e-9;

struct Itv {
	int l, r; ff p;
} I[N];
int n, q, a[N], f[B][N], log_2[N];
int Query(int l, int r) {
	int k = log_2[r - l + 1];
	return std::max(f[k][l], f[k][r - (1 << k) + 1]);
}

int fa[N];
ff g[M][M << 1];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, q);
		int mx = 0; log_2[0] = -1; ff ans;
		for(int i = 1; i <= n; ++i) {
			rd(a[i]); mx = std::max(mx, a[i]);
			log_2[i] = log_2[i - 1] + (i == (i & -i));
		}
		ans = mx - q;
		for(int i = 1; i <= n; ++i) {
			a[i] = std::max(0, a[i] - (mx - q));
			f[0][i] = a[i];
		}
		for(int i = 1; i < B; ++i)
			for(int j = 1; j <= n; ++j)
				f[i][j] = std::max(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
		for(int i = 1; i <= q; ++i) {
			rd(I[i].l, I[i].r);
			scanf("%lf", &I[i].p);
		}
		std::sort(I + 1, I + q + 1, [](const Itv &x, const Itv &y) {
			return x.r - x.l < y.r - y.l;
		});
		I[++q] = (Itv) { 1, n, 0 };
		for(int i = 1; i <= q; ++i) {
			int cur_mx = Query(I[i].l, I[i].r);
			for(int j = cur_mx; j <= q << 1; ++j)
				g[i][j] = 1;
			for(int j = 1; j < i; ++j)
				if(!fa[j] && I[i].l <= I[j].l && I[j].r <= I[i].r) {
					fa[j] = i;
					for(int k = 1; k <= q << 1; ++k)
						g[i][k] *= g[j][k];
				}
			for(int j = q << 1; j; --j) 
				g[i][j] = (1 - I[i].p) * g[i][j] + I[i].p * g[i][j - 1];
			if(g[i][0] > Eps) g[i][0] = (1 - I[i].p) * g[i][0];
		}
		for(int i = 0; i <= q << 1; ++i)
			ans += 1 - g[q][i];
		printf("%.10lf\n", ans);
	} return 0;
}