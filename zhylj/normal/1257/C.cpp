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

int n, a[kN]; std::vector <int> aper[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		rd(n);
		int ans = kInf;
		for(int i = 1; i <= n; ++i) aper[i].clear();
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			if(aper[a[i]].size()) ans = std::min(ans, i - aper[a[i]][aper[a[i]].size() - 1] + 1);
			aper[a[i]].push_back(i);
		}
		if(ans >= kInf) printf("-1\n");
		else printf("%d\n", ans);
	} return 0;
}