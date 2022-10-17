#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
int n, fa[N], m, l[N], r[N];

int get(int x) {return x == fa[x] ? x : fa[x] = get(fa[x]);}
void dfs(int u) {
	if(u <= n) {
		printf("%d ", u);
		return;
	}
	dfs(l[u]), dfs(r[u]);
}

int main() {
	scanf("%d", &n), m = n;
	for(int i = 1; i < 2 * n; ++i) fa[i] = i;
	for(int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		u = get(u), v = get(v);
		fa[u] = fa[v] = ++m, l[m] = u, r[m] = v;
	}
	dfs(m);
}