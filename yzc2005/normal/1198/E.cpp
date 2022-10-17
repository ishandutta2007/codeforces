#include <bits/stdc++.h>
using namespace std;

const int inf = INT_MAX;
const int NN = 66666, MM = 666666;
int nn, s, t, d[NN], qu[NN];
int cnt = 1, head[NN], cur[NN], to[MM], nxt[MM], val[MM];
inline void addedge(int u, int v, int w) {
	to[++cnt] = v;
	val[cnt] = w;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
inline void add(int u, int v, int w) {
	addedge(u, v, w);
	addedge(v, u, 0); 
}
inline bool bfs() {
	for(int i = 1; i <= nn; ++i) cur[i] = head[i], d[i] = 0;
	int l = 1, r = 0; d[qu[++r] = s] = 1;
	while(l <= r) {
		int u = qu[l++];
		for(int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
			if(val[i] && !d[v]) d[v] = d[u] + 1, qu[++r] = v;
	} 
	return d[t];
}
int dfs(int u, int flow) {
	if(u == t) return flow;
	int rest = flow;
	for(int &i = cur[u]; i; i = nxt[i]) {
		int v = to[i], w = val[i];
		if(d[v] != d[u] + 1 || !w) continue;
		int k = dfs(v, min(rest, w));
 		rest -= k, val[i] -= k, val[i ^ 1] += k; 		
		if(!k) d[v] = 0;
		if(!rest) break;
	}
	return flow - rest;
}
inline int dinic() {
	int res = 0;
	while(bfs()) res += dfs(s, inf); 
	return res;
}
//namespace::flow

const int N = 55;
int _, n, X1[N], Y1[N], X2[N], Y2[N], x[N << 1], y[N << 1], idx[N << 1], idy[N << 1], cx, cy; 
bool vis[N << 1][N << 1];
int main() {
	scanf("%d%d", &_, &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d%d%d", &X1[i], &Y1[i], &X2[i], &Y2[i]);
		x[++cx] = X1[i], x[++cx] = ++X2[i];
		y[++cy] = Y1[i], y[++cy] = ++Y2[i];
	}
	sort(x + 1, x + cx + 1), sort(y + 1, y + cy + 1);
	cx = unique(x + 1, x + cx + 1) - x - 1; cy = unique(y + 1, y + cy + 1) - y - 1;
	s = ++nn, t = ++nn;
	for(int i = 1; i < cx; ++i) add(s, idx[i] = ++nn, x[i + 1] - x[i]);
	for(int i = 1; i < cy; ++i) add(idy[i] = ++nn, t, y[i + 1] - y[i]);
	for(int i = 1; i <= n; ++i) {
		X1[i] = lower_bound(x + 1, x + cx + 1, X1[i]) - x;
		Y1[i] = lower_bound(y + 1, y + cy + 1, Y1[i]) - y;
		X2[i] = lower_bound(x + 1, x + cx + 1, X2[i]) - x;
		Y2[i] = lower_bound(y + 1, y + cy + 1, Y2[i]) - y;
		for(int j = X1[i]; j < X2[i]; ++j)
			for(int k = Y1[i]; k < Y2[i]; ++k)
				if(!vis[j][k]) vis[j][k] = 1, add(idx[j], idy[k], inf);
	}
	printf("%d\n", dinic());
	return 0;
}