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
const int kN = 150 + 5, kB = 40, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, ans = 0;
struct Edge {
	int u, v, w;
} E[kN];
std::bitset <kN> g[kB][kN], lst, tmp;
int GetPow(int dlt) {
	int b;
	for(b = 1; dlt >> b; ++b) {
		for(int i = 0; i < n; ++i) 
			g[b][i].reset();
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j) if(g[b - 1][i][j])
				g[b][i] |= g[b - 1][j];
	}
	return b;
}
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		bool flag = false;
		rd(n, m);
		for(int i = 1; i <= m; ++i) {
			rd(E[i].u, E[i].v, E[i].w);
			--E[i].u; --E[i].v;
		}
		g[0][n - 1][n - 1] = 1;
		std::sort(E + 1, E + m + 1, [](const Edge &x, const Edge &y) { return x.w < y.w; });
		lst[0] = 1;
		if(E[1].w) {
			printf("Impossible\n");
			break;
		}
		E[m + 1].w = kInf;
		for(int i = 1; i <= m; ) {
			int ret, cur_d = E[i].w, nxt_d;
			for(; E[i].w == cur_d; ++i)
				g[0][E[i].u][E[i].v] = 1;
			nxt_d = E[i].w;
			ret = GetPow(nxt_d - cur_d);
			for(int b = ret - 1; ~b; --b) 
				if(cur_d + (1 << b) <= nxt_d) {
					tmp.reset();
					for(int j = 0; j < n; ++j)
						if(lst[j])
							tmp |= g[b][j];
					if(!tmp[n - 1]) {
						cur_d += 1 << b;
						lst = tmp;
					} else flag = true;
				}
			if(flag) {
				ans = cur_d + 1;
				break;
			}
		}
		if(flag) printf("%d\n", ans);
		else printf("Impossible\n");
	} return 0;
}