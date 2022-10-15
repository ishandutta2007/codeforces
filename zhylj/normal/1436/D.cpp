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

int n, a[kN], fa[kN], siz[kN]; ll s[kN], mx[kN];
std::vector <int> E[kN];

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		memset(mx, ~0x3f, sizeof(mx));
		rd(n);
		for(int i = 1; i <= n; ++i) siz[i] = 1;
		for(int i = 2; i <= n; ++i) {
			rd(fa[i]); E[fa[i]].push_back(i);
			siz[fa[i]] = 0;
		}
		for(int i = 1; i <= n; ++i) {
			rd(a[i]); s[i] = a[i];
		}
		for(int i = n; i; --i) {
			s[fa[i]] += s[i];
			siz[fa[i]] += siz[i];
		}
		for(int u = n; u; --u) {
			for(int v : E[u])
				mx[u] = std::max(mx[u], mx[v]);
			mx[u] = std::max(mx[u], s[u] ? (s[u] - 1) / siz[u] + 1 : 0);
		}
		printf("%lld\n", mx[1]);
	} return 0;
}