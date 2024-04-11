#include <bits/stdc++.h>

typedef long long ll;

const int kMaxN = 2e5 + 5;

std::vector<int> E[kMaxN];
void AddEdge(int u, int v) { E[u].push_back(v); }
int dep[kMaxN], top[kMaxN], hvy[kMaxN], siz[kMaxN], fa[kMaxN], dfv = 0;
ll d[kMaxN];
void GetHvy(int cur) {
	siz[cur] = 1;
	for(int i = 0; i < E[cur].size(); ++i)
		if(E[cur][i] != fa[cur]) {
			int v = E[cur][i];
			dep[v] = dep[cur] + 1; fa[v] = cur;
			GetHvy(v); siz[cur] += siz[v];
			if(siz[v] > siz[hvy[cur]]) hvy[cur] = v;
		}
}
void GetTop(int cur, int t) {
	top[cur] = t;
	if(hvy[cur]) GetTop(hvy[cur], t);
	for(int i = 0; i < E[cur].size(); ++i)
		if(E[cur][i] != fa[cur] && E[cur][i] != hvy[cur])
			GetTop(E[cur][i], E[cur][i]);
}
int Lca(int u, int v) {
	while(top[u] != top[v]) {
		if(dep[top[u]] < dep[top[v]]) std::swap(u, v);
		u = fa[top[u]];
	}
	return dep[u] < dep[v] ? u : v;
}
ll Dist(int x, int y) { return dep[x] + dep[y] - 2 * dep[Lca(x, y)]; }
bool Check(int d, int k) { return d <= k && d % 2 == k % 2; }

int main() {
	int n, q;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		AddEdge(x, y); AddEdge(y, x);
	}
	dep[1] = 1; GetHvy(1); GetTop(1, 1);
	scanf("%d", &q);
	while(q--) {
		int x, y, a, b, k;
		scanf("%d%d%d%d%d", &x, &y, &a, &b, &k);
		//printf("Len: %d %d %d %d\n", Dist(a, x) + Dist(y, b));
		if(Check(Dist(a, b), k) ||
			Check(Dist(a, x) + Dist(y, b) + 1, k) || Check(Dist(b, x) + Dist(y, a) + 1, k) ||
			Check(Dist(a, y) + Dist(x, b) + 1, k) || Check(Dist(b, y) + Dist(x, a) + 1, k))
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}