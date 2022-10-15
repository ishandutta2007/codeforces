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
const int kN = 5e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ff Dist(ff x, ff y) {
	return sqrt(x * x + y * y);
}

int n, a[kN], b[kN], cnt_1, cnt_2;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		rd(n); cnt_1 = 0; cnt_2 = 0;
		for(int i = 1; i <= 2 * n; ++i) {
			int x, y; rd(x, y);
			if(x < 0) x = -x;
			if(y < 0) y = -y;
			if(x) a[++cnt_1] = x;
			if(y) b[++cnt_2] = y;
		}
		std::sort(a + 1, a + n + 1);
		std::sort(b + 1, b + n + 1);
		ff ans = 0;
		for(int i = 1; i <= n; ++i) {
			ans += Dist(a[i], b[i]);
		}
		printf("%.12lf\n", ans);
	} return 0;
}