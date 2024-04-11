#include <bits/stdc++.h>
using namespace std;

const int N = 100005, M = N << 1;

struct node {
	int u, v, w;
	inline friend bool operator < (const node &n1, const node &n2) {
		return n1.w > n2.w;
	}
} e[M];

int n, m, a[N];
int fa[N], sz[N];
double ans;

int get(int x) {
	return x == fa[x] ? x : fa[x] = get(fa[x]);
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d", &e[i].u, &e[i].v);
		e[i].w = min(a[e[i].u], a[e[i].v]);
	}
	for(int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1;
	sort(e + 1, e + m + 1);
	for(int i = 1; i <= m; ++i) {
		int u = get(e[i].u), v = get(e[i].v);
		if(u == v) continue;
		ans += (double) e[i].w * sz[u] * sz[v];
		if(sz[u] < sz[v]) swap(u, v);
		sz[u] += sz[v], fa[v] = u; 
	}
	printf("%lf\n", ans / (1.0 * n * (n - 1) / 2));
}