#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rg register
#define fu(i, a, b) for(rg int i = a; i <= b; ++i)
#define fd(i, a, b) for(rg int i = a; i >= b; --i)
#define go(u) for(rg int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
inline void read(int &x) {
	x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - 48, ch = getchar();
}

const int N = 100010;
int n, siz[N], heavy[N], c[N], tot[N], fa[N], cnt, head[N], to[N << 1], nxt[N << 1], mxcol;
ll sum, ans[N];

inline void add(int u, int v) {
	to[++cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}

void dfs1(int u) {
	siz[u] = 1;
	go(u) {
		if(v == fa[u]) continue;
		fa[v] = u;
		dfs1(v);
		siz[u] += siz[v];
		if(siz[heavy[u]] < siz[v]) heavy[u] = v;
	} 
}

void calc(int u, int val, int son) {
	tot[c[u]] += val;
	if(tot[c[u]] > mxcol) mxcol = tot[c[u]], sum = c[u];
	else if(tot[c[u]] == mxcol) sum += c[u];
	go(u) if(v != fa[u] && v != son) calc(v, val, 0);
}

void dfs2(int u) {
	go(u) if(v != fa[u] && v != heavy[u]) dfs2(v);
	if(heavy[u]) dfs2(heavy[u]);
	calc(u, 1, heavy[u]);
	ans[u] = sum;
	if(heavy[fa[u]] != u) calc(u, -1, 0), sum = mxcol = 0;
}

int main() {
	read(n);
	fu(i, 1, n) read(c[i]);
	for(int i = 1, u, v; i < n; ++i) read(u), read(v), add(u, v), add(v, u);
	dfs1(1), dfs2(1);
	fu(i, 1, n) printf("%lld ", ans[i]);
}