#include <bits/stdc++.h>

#define gc() getchar()
template <typename T> inline void rd(T& x) {
	int si = 1; char c = gc(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 100 + 5, M = 1e5 + 5, INF = 0x3f3f3f3f;

struct Edge {
	int v, nxt, c, w;
} E[M];
int e_cnt, head[N];
void Add(int u, int v, int c, int w) {
	E[e_cnt] = (Edge) { v, head[u], c, w }; head[u] = e_cnt++;
	E[e_cnt] = (Edge) { u, head[v], 0, -w }; head[v] = e_cnt++;
}
int s, t, cur_ed[N], d[N];
std::queue <int> que;
int GetLev() {
	memcpy(cur_ed, head, sizeof(cur_ed));
	memset(d, 0x3f, sizeof(d));
	que.push(s); d[s] = 0;
	while(!que.empty()) {
		int u = que.front(); que.pop();
		for(int i = head[u]; ~i; i = E[i].nxt) {
			int v = E[i].v, c = E[i].c, w = E[i].w;
			if(c && d[u] + w < d[v]) {
				d[v] = d[u] + w;
				que.push(v);
			}
		}
	}
	return d[t];
}
bool vis[N];
int Incr(int u, int res_f, int &tot_w) {
	if(u == t) return res_f;
	int dlt, ret = 0;
	vis[u] = true;
	for(int &i = cur_ed[u]; ~i; i = E[i].nxt) {
		int v = E[i].v, c = E[i].c, w = E[i].w;
		if(c && d[u] + w == d[v] && !vis[v] &&
			(dlt = Incr(v, std::min(res_f, c), tot_w))) {
			E[i].c -= dlt; E[i ^ 1].c += dlt;
			res_f -= dlt; ret += dlt;
			tot_w += dlt * w;
			if(!res_f) break;
		}
	}
	vis[u] = false;
	return ret;
}
int MCMF() {
	int mn_w = 0, mx_f = 0;
	while(GetLev() < INF)
		mx_f += Incr(s, INF, mn_w);
	return mn_w;
}

int g[N][N], dg[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		memset(head, 0xff, sizeof(head));
		memset(g, 0xff, sizeof(g));
		int n, m; rd(n, m);
		s = n + 1; t = n + 2;
		for(int i = 1; i <= m; ++i) {
			int u, v; rd(u, v);
			++dg[u];
			g[u][v] = 1; g[v][u] = 0;
		}
		for(int u = 1; u <= n; ++u) {
			g[u][u] = 0;
			for(int v = u + 1; v <= n; ++v)
				if(g[u][v] == -1) {
					++dg[u];
					Add(u, v, 1, 0);
				}
			for(int i = 0; i < n; ++i)
				Add(u, t, 1, i);
		}
		for(int u = 1; u <= n; ++u)
			Add(s, u, dg[u], 0);
		int ans = n * (n - 1) * (n - 2) / 6 - MCMF();
		for(int u = 1; u <= n; ++u)
			for(int i = head[u]; ~i; i = E[i].nxt) {
				int v = E[i].v, c = E[i].c;
				if(v <= n) {
					if(c) g[u][v] = 1, g[v][u] = 0;
					else g[v][u] = 1, g[u][v] = 0;
				}
			}
		for(int u = 1; u <= n; ++u) {
			for(int v = 1; v <= n; ++v)
				printf("%d", g[u][v]);
			printf("\n");
		}
	} return 0;
}