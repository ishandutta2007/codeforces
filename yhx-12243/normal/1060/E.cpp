#include <bits/stdc++.h>
#define N 200005
#define M 400010

typedef long long ll;

int n, E;
int to[M], first[N], next[M];
int p[N], dep[N], size[N];
int fy[2];

inline void addedge(int u, int v){
	to[++E] = v; next[E] = first[u]; first[u] = E;
	to[++E] = u; next[E] = first[v]; first[v] = E;
}

void dfs(int x) {
	int i, y; size[x] = 1;
	++fy[dep[x] & 1];
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x]) {
			p[y] = x; dep[y] = dep[x] + 1;
			dfs(y); size[x] += size[y];
		}
}

int main() {
	int i, u, v; ll ans = 0;
	scanf("%d", &n);
	for (i = 1; i < n; ++i)
		scanf("%d%d", &u, &v), addedge(u, v);
	dfs(1);	
	for (i = 2; i <= n; ++i) ans += (ll)size[i] * (n - size[i]);
	ans = (ans + (ll)fy[0] * fy[1]) / 2;
	printf("%lld\n", ans);
	return 0;
}