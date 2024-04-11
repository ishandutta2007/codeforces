#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
    int si = 1; char c = getchar(); x = 0;
    while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
    while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
    x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int NM = 1e5 + 5, N = 300 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

struct Cmp {
	bool operator ()(const pii &x, const pii &y) {
		return x.fi != y.fi ? x.fi > y.fi : x.se < y.se;
	}
};

int n, m, a[NM], b[NM], d[NM], f[N][N], c;
std::priority_queue <pii, std::vector <pii>, Cmp> q[NM];
int GetRow(int id) { return (id - 1) / m + 1; }
int GetCol(int id) { return (id - 1) % m + 1; }
int Calc(int x, int y) {
	int ans = 0;
	for(int i = 1; i < y; ++i)
		ans += f[x][i];
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int test_case_cnt = 1; rd(test_case_cnt);
    while(test_case_cnt--) {
		memset(f, 0, sizeof(f));
        rd(n, m); c = 0;
		for(int i = 1; i <= n * m; ++i) rd(a[i]), d[++c] = a[i];
		std::sort(d + 1, d + n * m + 1);
		c = std::unique(d + 1, d + n * m + 1) - d - 1;
		for(int i = 1; i <= n * m; ++i) {
			a[i] = std::lower_bound(d + 1, d + c + 1, a[i]) - d;
			b[i] = a[i];
		}
		std::sort(b + 1, b + n * m + 1);
		for(int i = 1; i <= n * m; ++i)
			q[b[i]].push(mkp(GetRow(i), GetCol(i)));
		int ans = 0;
		for(int i = 1; i <= n * m; ++i) {
			pii u = q[a[i]].top();
			q[a[i]].pop();
			f[u.fi][u.se] = 1;
			ans += Calc(u.fi, u.se);
		}
		printf("%d\n", ans);
    } return 0;
}