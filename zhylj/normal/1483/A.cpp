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
const int N = 5e5 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, dg[N], in_dg[N], c[N], usd[N];
std::vector <int> E[N], rE[N];
void Add(int u, int v) {
	E[u].push_back(v);
	rE[v].push_back(u);
	++dg[u];
}

std::queue <int> que;
bool vis[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		for(int i = 1; i <= n; ++i) E[i].clear();
		for(int i = 1; i <= m; ++i) rE[i].clear();
		for(int i = 1; i <= n; ++i) vis[i] = false, usd[i] = 0;
		for(int i = 1; i <= m; ++i) {
			rd(in_dg[i]); c[i] = 0;
			for(int j = 1; j <= in_dg[i]; ++j) {
				int u; rd(u);
				Add(u, i);
			}
		}
		for(int i = 1; i <= n; ++i)
			if(dg[i] <= (m + 1) / 2) {
				vis[i] = true; que.push(i);
			}
		while(!que.empty()) {
			int u = que.front(); que.pop();
			for(auto v : E[u]) {
				if(!c[v]) {
					in_dg[v] = 0; c[v] = u;
					for(auto w : rE[v]) {
						--dg[w];
						if(dg[w] <= (m + 1) / 2 && !vis[w]) {
							que.push(w);
							vis[w] = true;
						}
					}
				}
			}
		}
		for(int i = 1; i <= n; ++i)
			if(dg[i] > (m + 1) / 2) {
				for(auto v : E[i]) if(usd[i] < (m + 1) / 2) {
					if(in_dg[v] == 1 && !c[v]) {
						++usd[i];
						c[v] = i;
						--in_dg[v];
					}
				}
				for(auto v : E[i]) {
					if(usd[i] < (m + 1) / 2) {
						if(!c[v]) {
							++usd[i];
							c[v] = i;
						}
					}
					if(in_dg[v] > 0) --in_dg[v];
				}
			}
		bool flag = true;
		for(int i = 1; i <= m; ++i)
			if(!c[i]) flag = false;
		if(!flag) printf("NO\n");
		else {
			printf("YES\n");
			for(int i = 1; i <= m; ++i)
				printf("%d ", c[i]);
			printf("\n");
		}
	} return 0;
}