#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 300005, M = N << 2;
#define rg register
#define go(G, u) for(rg int o = G.head[u], v = G.to[o], w = G.val[o]; o; o = G.nxt[o], v = G.to[o], w = G.val[o])
#define fu(i, a, b) for(rg int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(rg int i = a, I = (b) - 1; i > I; --i)
struct Graph {
	int to[M], nxt[M], val[M], head[N], cnt = 1;
	inline void add(int u, int v, int w) {
		to[++cnt] = v;
		val[cnt] = w;
		nxt[cnt] = head[u];
		head[u] = cnt;
	}
} G, _G, G1, G2;
int n, m, Q, id[N], a[N], f[N], q[N], tot;
bool vis[N];
void dfs(int u) {
	vis[u] = 1;
	go(_G, u) if(!vis[v]) dfs(v); 
	q[++tot] = u;
}
void col(int u, int c) {
	id[u] = c;
	go(G, u) if(!id[v]) col(v, c);
}
typedef long long ll;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll dep[N], w[N];
void dp(int u) {
  vis[u] = 1;
  go(G2, u) {
    if (!vis[v]) dep[v] = dep[u] + w, dp(v);
    else ::w[id[u]] = gcd(::w[id[u]], dep[u] - dep[v] + w);
  }
}
int main() {
  scanf("%d%d", &n, &m);  
  for (int i = 1; i <= m; ++i) {
    int u, v, w; scanf("%d%d%d", &u, &v, &w);
    G.add(u, v, w), _G.add(v, u, w); 
  } 
	fu(i, 1, n) if(!vis[i]) dfs(i);
	tot = 0; fd(i, n, 1) if(!id[q[i]]) col(q[i], ++tot);
	fu(u, 1, n) go(G, u) if(id[u] == id[v]) G2.add(u, v, w), G2.add(v, u, -w);
	memset(vis, 0, sizeof vis); 
  fu(u, 1, n) if (!vis[u]) dp(u);
  for (scanf("%d", &Q); Q; --Q) {
    int u, s, t; scanf("%d%d%d", &u, &s, &t), u = id[u];
    puts((gcd(t - s, t) % gcd(w[u], t) == 0) ? "YES" : "NO");
  }
  return 0;
}