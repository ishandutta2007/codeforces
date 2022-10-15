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
const int N = 100 + 5, M = 2e4 + 300, O = 1e4 + 105, MID = 1e4;

int n, a[N], b[N];
bool f[N][M];

int Sq(int x) { return x * x; }

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		memset(f, false, sizeof(f));
		rd(n);
		int tot_sq = 0, tot = 0;
		for(int i = 1; i <= n; ++i) rd(a[i]), tot_sq += a[i] * a[i], tot += a[i];
		for(int i = 1; i <= n; ++i) rd(b[i]), tot_sq += b[i] * b[i], tot += b[i];
		f[0][O] = true;
		for(int i = 1; i <= n; ++i) {
			for(int j = -MID; j <= MID; ++j) {
				int cur = O + j, dlt = a[i] - b[i];
				f[i][cur] = (f[i - 1][cur - dlt] || f[i - 1][cur + dlt]);
			}
		}
		int mn_dlt = 1e9;
		for(int i = 0; i <= MID; ++i) {
			int cur = O + i;
			if(f[n][cur]) {
				mn_dlt = std::min(mn_dlt, i);
			}
		}
		int ans = (n - 2) * tot_sq + Sq((tot + mn_dlt) / 2) + Sq((tot - mn_dlt) / 2);
		printf("%d\n", ans);
	} return 0;
}