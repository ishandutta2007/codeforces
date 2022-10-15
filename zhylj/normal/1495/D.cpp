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
const int kN = 6e2 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, f[kN][kN], ans[kN][kN];
std::vector <int> E[kN];
void Add(int u, int v) {
	E[u].push_back(v);
	E[v].push_back(u);
}

int d[kN], dg[kN];
ll Calc(int u, int v) {
	memset(d, 0, sizeof(d));
	memset(dg, 0, sizeof(dg));
	ll ret = 1;
	for(int i = 1; i <= n; ++i) {
		for(auto j : E[i]) {
			if(f[u][j] == f[u][i] + 1 && f[v][j] == f[v][i] + 1) {
				++dg[j];
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(f[u][i] + f[v][i] != f[u][v]) {
			ret = ret * dg[i] % kMod;
		} else {
			if(d[f[u][i]] == 0) d[f[u][i]] = 1;
			else return 0;
		}
	}
	return ret;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		memset(f, 0x3f, sizeof(f));
		rd(n, m);
		for(int i = 1; i <= n; ++i) f[i][i] = 0;
		for(int i = 1; i <= m; ++i) {
			int u, v; rd(u, v);
			f[u][v] = f[v][u] = 1;
			Add(u, v);
		}
		for(int k = 1; k <= n; ++k)
			for(int i = 1; i <= n; ++i)	
				for(int j = 1; j <= n; ++j)
					f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
		for(int i = 1; i <= n; ++i)
			for(int j = i; j <= n; ++j) {
				ans[i][j] = ans[j][i] = Calc(i, j);
			}
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j)
				printf("%d ", ans[i][j]);
			printf("\n");
		}
	} return 0;
}