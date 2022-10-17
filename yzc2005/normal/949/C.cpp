#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10;
const int inf = 0x3f3f3f3f;
#define rg register
#define fu(i, a, b) for(rg int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(rg int i = a, I = (b) - 1; i > I; --i)
#define go(G, u) for(rg int o = G.head[u], v = G.to[o]; o; o = G.nxt[o], v = G.to[o])
typedef pair<int, int> P;
typedef long long ll;
template <class T> inline void read(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
template <class T> inline void print(T x) {
    if(x > 9) print(x / 10);
    putchar(x % 10 + 48);
}
template <class T> inline void ckmax(T &a, T b) {a = max(a, b);}
template <class T> inline void ckmin(T &a, T b) {a = min(a, b);}
template <class T> inline void addmod(T &a, T b) {a = (a + b) % 10;}
struct Graph {
	int to[M], nxt[M], head[M], cnt;
	inline void add(int u, int v) {
		to[++cnt] = v;
		nxt[cnt] = head[u];
		head[u] = cnt;
	}
} G, G1, G2;

int n, m, h, id[N], a[N], q[N], sz[N], out[N], tot;
bool vis[N];

void dfs(int u) {
	vis[u] = 1;
	go(G2, u) if(!vis[v]) dfs(v); 
	q[++tot] = u;
}

void col(int u, int c) {
	id[u] = c, ++sz[c];
	go(G1, u) if(!id[v]) col(v, c);
}

int main() {
	read(n), read(m), read(h);
	fu(i, 1, n) read(a[i]);
	for(int i = 1, u, v; i <= m; ++i) {
		read(u), read(v);
		if((a[u] + 1) % h == a[v]) G1.add(u, v), G2.add(v, u);
		if((a[v] + 1) % h == a[u]) G1.add(v, u), G2.add(u, v);
	}
	fu(i, 1, n) if(!vis[i]) dfs(i);
	tot = 0; fd(i, n, 1) if(!id[q[i]]) col(q[i], ++tot);
	int ans = inf, p;
	fu(u, 1, n) go(G1, u) if(id[u] ^ id[v]) ++out[id[u]];
	fu(i, 1, tot) if(!out[i] && ans > sz[i]) ans = sz[i], p = i;
	print(ans), puts("");
	fu(i, 1, n) if(id[i] == p) print(i), printf(" ");
	return 0;
}