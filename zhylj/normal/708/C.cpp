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

int n, d[kN], siz[kN], fa[kN], f[kN];
std::vector <int> E[kN];
void Add(int u, int v) { E[u].push_back(v); }

void Dfs(int cur) {
	siz[cur] = 1;
	for(auto i : E[cur])
		if(fa[cur] != i) {
			fa[i] = cur;
			Dfs(i); siz[cur] += siz[i];
			if(siz[i] <= n / 2) d[cur] = std::max(d[cur], siz[i]);
			d[cur] = std::max(d[cur], d[i]);
		}
}
bool flag[kN];
void Dfs2(int cur) {
	int mx = 0, cnt = 0;
	f[cur] = std::max(f[cur], f[fa[cur]]);
	for(int i = 0; i < E[cur].size(); ++i) {
		int v = E[cur][i];
		if(fa[cur] != v) {
			f[v] = std::max(mx, n - siz[v] <= n / 2 ? n - siz[v] : 0);
			mx = std::max({mx, d[v], siz[v] <= n / 2 ? siz[v] : 0});
		}
	}
	mx = 0;
	for(int i = E[cur].size() - 1; ~i; --i) {
		int v = E[cur][i];
		if(fa[cur] != v) {
			if(siz[v] > n / 2) {
				if(siz[v] - d[v] <= n / 2) ++cnt;
				else flag[cur] = false;
			}
			f[v] = std::max(mx, f[v]);
			mx = std::max({mx, d[v], siz[v] <= n / 2 ? siz[v] : 0});
			Dfs2(v);
		}
	}
	if(fa[cur] && n - siz[cur] > n / 2) {
		if(n - siz[cur] - f[cur] <= n / 2) ++cnt;
		else flag[cur] = false;
	}
	if(cnt >= 2) flag[cur] = false;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		memset(flag, true, sizeof(flag));
		rd(n);
		for(int i = 1; i < n; ++i) {
			int u, v; rd(u, v);
			Add(u, v); Add(v, u);
		}
		Dfs(1); Dfs2(1);
		for(int i = 1; i <= n; ++i) printf("%d ", (int)flag[i]);
		printf("\n");
	} return 0;
}