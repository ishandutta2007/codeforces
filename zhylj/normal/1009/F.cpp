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
#define V std::vector
#define H std::priority_queue
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 1e6 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, dep[kN], hvy[kN], fa[kN], ans[kN];
std::vector <int> E[kN], f[kN];
void Add(int u, int v) { E[u].push_back(v); }

void Dfs(int cur) {
	dep[cur] = 1;
	for(auto i : E[cur])
		if(i != fa[cur]) {
			fa[i] = cur; Dfs(i);
			dep[cur] = std::max(dep[i] + 1, dep[cur]);
			if(dep[i] > dep[hvy[cur]])
				hvy[cur] = i;
		}
}
int Solve(int cur, int tar) {
	int cur_ans;
	if(hvy[cur]) cur_ans = Solve(hvy[cur], cur);
	else cur_ans = 0;
	for(auto i : E[cur]) {
		if(i != fa[cur] && i != hvy[cur]) {
			Solve(i, i);
			int dlt = f[cur].size() - f[i].size();
			for(int j = 0; j < f[i].size(); ++j) {
				int cur_j = j + dlt;
				f[cur][cur_j] += f[i][j];
				if(f[cur][cur_j] > f[cur][cur_ans] ||
					(f[cur][cur_j] == f[cur][cur_ans] && cur_j > cur_ans))
						cur_ans = cur_j;
			}
			f[i].resize(0);
		}
	}
	f[cur].push_back(1);
	if(f[cur][cur_ans] == 1) cur_ans = f[cur].size() - 1;
	ans[cur] = f[cur].size() - cur_ans - 1;
	std::swap(f[cur], f[tar]);
	return cur_ans;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n);
		for(int i = 1; i < n; ++i) {
			int u, v; rd(u, v);
			Add(u, v); Add(v, u);
		}
		Dfs(1); Solve(1, 1);
		for(int i = 1; i <= n; ++i)
			printf("%d\n", ans[i]);
	} return 0;
}