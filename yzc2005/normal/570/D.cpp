#include <bits/stdc++.h>
using namespace std;
#define rg register
#define fu(i, a, b) for(rg int i = a; i <= b; ++i)
#define fd(i, a, b) for(rg int i = a; i >= b; --i)
#define go(u) for(rg int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
#define go_q(u) for(rg int i = qhead[u], dep = qdep[i]; i; i = qnxt[i], dep = qdep[i])
inline void read(int &x) {
	x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - 48, ch = getchar();
}

const int N = 500010, K = 30;
int n, q, tot, head[N], to[N], nxt[N], qdep[N], qnxt[N], qtot, qhead[N], fa[N], dep[N], siz[N], heavy[N], cnt[N];
bool odd[N][K], ans[N];
char s[N];

inline void add(int u, int v) {
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}

inline void addq(int u, int dep) {
	qdep[++qtot] = dep;
	qnxt[qtot] = qhead[u];
	qhead[u] = qtot;
}

void dfs1(int u) {
	siz[u] = 1;
	go(u) {
		if(v == fa[u]) continue;
		fa[v] = u, dep[v] = dep[u] + 1;
		dfs1(v);
		siz[u] += siz[v];
		if(siz[heavy[u]] < siz[v]) heavy[u] = v; 
	}
}

void calc(int u, int son) {
	odd[dep[u]][s[u] - 'a'] ^= 1;
	!odd[dep[u]][s[u] - 'a'] ? --cnt[dep[u]] : ++cnt[dep[u]];
	go(u) if(v != fa[u] && v != son) calc(v, 0);
}

void dfs2(int u) {
	go(u) if(v != fa[u] && v != heavy[u]) dfs2(v);
	if(heavy[u]) dfs2(heavy[u]);
	calc(u, heavy[u]);
	go_q(u) ans[i] = cnt[dep] <= 1;
	if(heavy[fa[u]] != u) calc(u, 0);
}

int main() {
	read(n), read(q);
	for(int i = 2, fa; i <= n; ++i) read(fa), add(fa, i);
	scanf("%s", s + 1);
	for(int i = 1, u, d; i <= q; ++i) read(u), read(d), addq(u, d);
	dep[1] = 1, dfs1(1), dfs2(1);
	fu(i, 1, q) puts(ans[i] ? "Yes" : "No");
	return 0;
}