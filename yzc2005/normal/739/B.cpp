#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rg register
#define go(u) for(rg int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
#define fu(i, a, b) for(rg int i = a; i <= b; ++i)
#define fd(i, a, b) for(rg int i = a; i >= b; --i)
inline void read(int &x) {
	char op = getchar(); x = 0;
	while(op < '0' || op > '9') op = getchar();
	while(op >= '0' && op <= '9') x = (x << 3) + (x << 1) + op - 48, op = getchar();
}

const int N = 200005, K = 20;
int n, to[N], nxt[N], val[N], head[N], a[N], d[N], fa[N][K], cnt;
ll dep[N];

inline int get(int u) {
	int f = u;
	fd(k, 18, 0) if(dep[u] - dep[fa[f][k]] <= a[u] && fa[f][k] != 0) f = fa[f][k];
	return f;
}

void dfs(int u) {
	++d[fa[u][0]], --d[fa[get(u)][0]];
	go(u) {
		dep[v] = dep[u] + val[i];
		fa[v][0] = u;
		fu(k, 1, 18) fa[v][k] = fa[fa[v][k - 1]][k - 1];
		dfs(v); 
	}
}

void dfs1(int u) {
	go(u) dfs1(v), d[u] += d[v];
}

int main() {
	read(n);
	fu(i, 1, n) read(a[i]);
	for(int i = 2, fa, w; i <= n; ++i) read(fa), read(w), to[++cnt] = i, val[cnt] = w, nxt[cnt] = head[fa], head[fa] = cnt;
	dfs(1), dfs1(1);
	fu(i, 1, n) printf("%d ", d[i]);
	return 0;
}