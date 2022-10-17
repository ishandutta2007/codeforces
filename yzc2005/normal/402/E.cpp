#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
const int inf = 0x3f3f3f3f;
#define rg register
#define fu(i, a, b) for(rg int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(rg int i = a, I = (b) - 1; i > I; --i)
#define go(G, u) for(rg int o = G.head[u], v = G.to[o]; o; o = G.nxt[o], v = G.to[o])
#define reset(a) memset(a, 0, sizeof(a))
#define finish(a) return a, 0;
typedef long long ll;
template <class T> inline void read(T &x) {
    x = 0; 
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
} 

int n, g[N][N], q[N], cnt, ans;
bool vis[N];

void dfs1(int u) {
	vis[u] = 1;
	fu(v, 1, n) if(g[v][u] && !vis[v]) dfs1(v);
	q[++cnt] = u;
}

void dfs2(int u) {
	++ans; vis[u] = 1;
	fu(v, 1, n) if(g[u][v] && !vis[v]) dfs2(v);
}

int main() {
	read(n);
	fu(i, 1, n) fu(j, 1, n) read(g[i][j]);
	fu(i, 1, n) if(!vis[i]) dfs1(i);
	reset(vis); dfs2(q[cnt]);
	puts(ans == n ? "YES" : "NO");
}