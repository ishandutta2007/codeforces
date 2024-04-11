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

inline int Abs(int x) { return x < 0 ? -x : x; }

int n, m;

int fa[kN];
int Find(int x) { return fa[x] == x ? x : fa[x] = Find(fa[x]); }
bool Merge(int x, int y) {
	int f_x = Find(x), f_y = Find(y);
	if(f_x == f_y) return true;
	fa[f_x] = f_y;
	return false;
}

bool flag[kN], var[kN], vis[kN];
std::vector <int> o_x[kN], o_nx[kN];
std::vector <pii> E[kN];
bool Add(int u, int v, int idx) {
	bool ret = Merge(u, v);
//	printf("%d %d %d\n", u, v, ret);
	E[u].push_back(mkp(v, idx));
	E[v].push_back(mkp(u, -idx));
	return ret;
}

void Dfs(int u) {
	flag[u] = true;
	for(auto i : E[u]) {
		int v = i.fi, idx = -i.se;
		if(!vis[Abs(idx)] && !flag[v]) {
			vis[Abs(idx)] = true;
			if(idx > 0) var[idx] = true;
			Dfs(v);
		}
	}
}
std::vector <pii> on_cir;
void Solve() {
	for(auto i : on_cir) {
		int u = i.fi, idx = i.se;
		if(!flag[u]) {
			//printf("ON_CIR: %d %d\n", u, idx);
			vis[Abs(idx)] = true;
			if(idx > 0) var[idx] = true;
			Dfs(u);
			//printf("BEGIN CHECKING\n");
					//printf("idx: %d\n", idx);
			//printf("CHECKED SUCCESSFULLY\n");
		}
	}
	for(int i = 1; i <= n; ++i) if(flag[i]) {
		Dfs(i);
	}
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, m);
		for(int i = 1; i <= n; ++i) fa[i] = i;
		for(int i = 1; i <= n; ++i) {
			int k; rd(k);
			while(k--) {
				int v; rd(v);
				if(v > 0) o_x[v].push_back(i);
				else o_nx[-v].push_back(i);
			}
		}
		for(int i = 1; i <= m; ++i) {
			int siz = o_x[i].size(), nsiz = o_nx[i].size();
			if(siz > 1 || siz == 1 && !nsiz) {
				var[i] = vis[i] = true;
				for(auto j : o_x[i]) flag[j] = true;
			} else if(nsiz > 1 || nsiz == 1 && !siz) {
				vis[i] = true;
				for(auto j : o_nx[i]) flag[j] = true;
			} else if(siz && nsiz) {
				//printf("%d %d\n", o_x[i].front(), o_nx[i].front());
				bool b = Add(o_x[i].front(), o_nx[i].front(), i);
				if(b) on_cir.push_back(mkp(o_x[i].front(), i));
			}
		}
		Solve();
		for(int i = 1; i <= n; ++i) if(!flag[i]) {
			printf("NO\n");
			return 0;
		}
		printf("YES\n");
		for(int i = 1; i <= m; ++i)
			printf("%d", (int)var[i]);
	} return 0;
}