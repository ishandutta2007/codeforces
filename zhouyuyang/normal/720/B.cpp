#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 300010;

#define v e[i].to
#define ew e[i].w
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

int S, T;

namespace flow{ 
	const int inf = N;
	struct edge { int to, pre, w; } e[N << 1]; int l = 1, u[N], cur[N], q[N], h[N];
	void ins(int a, int b, int c) { e[++l] = (edge){b, u[a], c}, u[a] = l; }
	void insert(int a, int b, int c) { ins(a, b, c), ins(b, a, 0); }
	bool bfs() {
		int l = 0, r = 1; rep(i,S,T) h[i] = -1; q[h[S] = 0] = S;
		while (l < r) { int x = q[l++]; reg(i,x) if (ew && h[v] == -1) h[v] = h[x] + 1, q[r++] = v; }
		return h[T] != -1; 	
	}
	int dfs(int x, int f) {
		if (x == T) return f; 
		int w, used = 0;
		for(int i = cur[x]; i; i = e[i].pre) if (ew && h[v] == h[x] + 1) {
			w = min(f - used, ew), w = dfs(v, w);
			ew -= w; if (ew) cur[x] = i;
			e[i ^ 1].w += w;
			used += w; if (used == f) break;
		}
		if (!used) h[x] = -1;
		return used;
	}
	int ans;
	void dinic() {
		ans = 0;
		while (bfs()) {
			rep(i,S,T) cur[i] = u[i];
			ans += dfs(S, inf);
		}
	}
}

struct edge { int to, pre; } e[N << 1]; int l = 1, u[N];
void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; }

int n, m; 
bool vis[N]; int c[N];
int pre[N], dfn = 0, fa[N], r[N], cl = 0;
void dfs(int x) {
	pre[x] = ++dfn;
	reg(i,x) if (!pre[v]) fa[v] = x, r[v] = i, dfs(v);
	else if (v != fa[x] && pre[v] < pre[x]) {
		cl++;
		vis[i >> 1] = true; int cnt = 0; flow::insert(cl, n + c[i >> 1], 1);
		for(int t = x; t != v; t = fa[t]) {
			vis[r[t] >> 1] = true; flow::insert(cl, n + c[r[t] >> 1], 1); cnt++;
		}
		flow::insert(S, cl, cnt);
	}
}
int main() {
	scanf("%d%d",&n,&m); 
	S = 0, T = n + m + 1;
	rep(i,1,m) flow::insert(n + i, T, 1);
	rep(i,1,m) {
		int a, b; 
		scanf("%d%d%d",&a,&b,&c[i]);
		ins(a, b), ins(b, a);
	}
	fa[1] = 0; dfs(1);
	rep(i,1,m) if (!vis[i]) flow::insert(S, n + c[i], 1);
	flow::dinic(); printf("%d\n",flow::ans);
}