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

int n, F[kN]; pii e[kN];
std::vector <pii> E[kN];
void Add(int u, int v, int idx) {
	E[u].push_back(mkp(v, idx));
	E[v].push_back(mkp(u, idx));
}

bool vis_e[kN];
int siz[kN], typ[kN];
void Dfs(int u, int p, int k, int &cut) {
	siz[u] = 1;
	for(auto i : E[u]) {
		int v = i.fi, idx = i.se;
		if(!vis_e[idx] && v != p) {
			Dfs(v, u, k, cut);
			siz[u] += siz[v];
			if(siz[v] == F[k - 1] || siz[v] == F[k - 2]) {
				typ[v] = siz[v] == F[k - 1] ? k - 1 : k - 2;
				typ[u] = siz[v] == F[k - 1] ? k - 2 : k - 1;
				cut = idx;
			}
		}
	}
}
void Div(int u, int k) {
	if(k <= 1) return;
	int cut = 0;
	Dfs(u, 0, k, cut);
	if(!cut) {
		printf("NO\n");
		exit(0);
	}
	vis_e[cut] = true;
	int x = e[cut].fi, y = e[cut].se;
	Div(x, typ[x]); Div(y, typ[y]);
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n);
		F[0] = F[1] = 1;
		for(int i = 2; i <= 26; ++i) {
			F[i] = F[i - 1] + F[i - 2];
		}
		int k = 0;
		for(int i = 1; i <= 26; ++i) 
			if(n == F[i]) k = i;
		if(!k) {
			printf("NO\n");
			return 0;
		}
		for(int i = 1; i < n; ++i) {
			int u, v; rd(u, v);
			Add(u, v, i);
			e[i] = mkp(u, v);
		}
		Div(1, k);
		printf("YES\n");
	} return 0;
}