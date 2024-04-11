#include <bits/stdc++.h>
using namespace std;
const int N = 3005, M = N << 1;
typedef long long ll;
 
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

#define go(G, u) for(int o = G.head[u], v = G.to[o]; o; o = G.nxt[o], v = G.to[o])
struct Graph {
    int to[M], nxt[M], head[N], cnt;
    inline void add(int u, int v) {
        to[++cnt] = v;
        nxt[cnt] = head[u];
        head[u] = cnt;
    }
} G;

int n, x, y, sz[N], dep[N];
ll f[N][N], ans;
bool vis[N][N];

void dfs(int x, int fax, int y, int fay, bool flg) {
	if(vis[x][y]) return;
	vis[x][y] = 1;
	go(G, x) {
		if(v == fax) continue;
		dfs(v, x, y, fay, dep[v] > dep[x]);
		ckmax(f[x][y], f[v][y]);
	}
	go(G, y) {
		if(v == fay) continue;
		dfs(x, fax, v, y, flg);
		ckmax(f[x][y], f[x][v]);
	}
	f[x][y] += (flg ? sz[x] : n - sz[fax]) * sz[y];
}

void pre(int u, int fa) {
	sz[u] = 1;
	go(G, u) {
		if(v == fa) continue;
		dep[v] = dep[u] + 1;
		pre(v, u);
		sz[u] += sz[v];
	}
}

void get_dp(int u, int fa) {
	go(G, u) {
		if(v == fa) continue;
		dfs(u, v, v, u, 0);
		get_dp(v, u);
	}
}

int main() {
	rd(n);
	fu(i, 1, n - 1) rd(x), rd(y), G.add(x, y), G.add(y, x);
	pre(1, 0);
	get_dp(1, 0);
	fu(i, 1, n) fu(j, 1, n) ckmax(ans, f[i][j]);
	return printf("%lld\n", ans), 0;
}