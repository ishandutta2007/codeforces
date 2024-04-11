#include <bits/stdc++.h>
using namespace std;
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
#define go(G, u) for(int i = G.head[u], v = G.to[i]; i; i = G.nxt[i], v = G.to[i])
inline void rd(int &x) {
	x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
}

const int N = 1e5 + 5;
int n, q, cnt[N], c[N], ans[N], mx;
int fa[N], son[N], sz[N];

struct Graph {
	int head[N], to[N << 1], nxt[N << 1], cnt;
	inline void add(int u, int v) {
		to[++cnt] = v;
		nxt[cnt] = head[u];
		head[u] = cnt;
	}
} G, Q;

struct Bit {
	int b[N];
	inline void add(int p, int val) {
		if(!p) return;
		while(p <= mx) {
			b[p] += val;
			p += p & -p;
		}
	}
	inline int query(int p) {
		int res = 0;
		while(p) {
			res += b[p];
			p -= p & -p;
		}
		return res;
	}
	inline int ask(int p) {
		return query(mx) - query(p - 1);
	}
} bit;

void pre(int u) {
	sz[u] = 1;
	go(G, u) {
		if(v == fa[u]) continue;
		fa[v] = u, pre(v);
		sz[u] += sz[v];
		if(sz[son[u]] < sz[v]) son[u] = v;
	} 
}

void cal(int u, int val, int son) {
	bit.add(cnt[c[u]], -1);
	cnt[c[u]] += val; bit.add(cnt[c[u]], 1);
	go(G, u) if(v != fa[u] && v != son) cal(v, val, son);
}

void dfs(int u) {
	go(G, u) if(v != fa[u] && v != son[u]) dfs(v);
	if(son[u]) dfs(son[u]);
	cal(u, 1, son[u]);
	go(Q, u) if(v <= mx) ans[i] = bit.ask(v);
	if(son[fa[u]] != u) cal(u, -1, 0);
}

int main() {
	rd(n), rd(q);
	fu(i, 1, n) rd(c[i]), ++cnt[c[i]], mx = max(mx, cnt[c[i]]);
	memset(cnt, 0, sizeof(cnt));
	int u, v; fu(i, 1, n - 1) rd(u), rd(v), G.add(u, v), G.add(v, u);
	fu(i, 1, q) rd(u), rd(v), Q.add(u, v);
	pre(1), dfs(1);
	fu(i, 1, q) printf("%d\n", ans[i]);
	return 0;
}