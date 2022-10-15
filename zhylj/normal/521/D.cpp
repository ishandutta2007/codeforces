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
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, k, tidx[kN], cnt = 0; ll tb[kN], a[kN];
std::vector <pii> pls[kN];
struct Opt {
	int idx, typ; ll x, y;
} opt[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(k, n, m);
		for(int i = 1; i <= k; ++i) rd(a[i]), tb[i] = a[i];
		for(int i = 1; i <= n; ++i) {
			int typ, x; ll b; rd(typ, x, b);
			if(typ == 1 && b > tb[x]) {
				tb[x] = b; tidx[x] = i;
			} else if(typ == 2) {
				pls[x].push_back(mkp(b, i));
			} else if(typ == 3) {
				opt[++cnt] = (Opt) { i, typ, b, 1 };
			}
		}
		for(int i = 1; i <= k; ++i) {
			if(tidx[i])
				pls[i].push_back(mkp(tb[i] - a[i], tidx[i]));
			std::sort(pls[i].begin(), pls[i].end(), std::greater <pii>());
			for(auto j : pls[i]) {
				opt[++cnt] = (Opt) { j.se, j.se == tidx[i] ? 1 : 2, a[i] + j.fi, a[i] };
				a[i] += j.fi;
			}
		}
		std::sort(opt + 1, opt + cnt + 1, [](const Opt &x, const Opt &y) { return (ff)x.x / x.y > (ff)y.x / y.y; });
		std::sort(opt + 1, opt + std::min(cnt, m) + 1, [](const Opt &x, const Opt &y) { return x.typ < y.typ; });
		printf("%d\n", std::min(cnt, m));
		for(int i = 1; i <= std::min(cnt, m); ++i) {
			printf("%d ", opt[i].idx);
		}
		printf("\n");
	} return 0;
}