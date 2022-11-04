#include<bits/stdc++.h>
#define v first
#define cost second
using namespace std;
typedef pair<int,int> edge;
typedef long long LL;

const int maxn = 200009;
vector<edge> e[maxn];
LL pre[maxn], suf[maxn], L[maxn], R[maxn], dist[maxn], f[maxn], base, ans, best;
int ring[maxn], vis[maxn], flag[maxn];
int n, a, b, c, m, rt;

int getloop(int u, int fa){
	if (vis[u]) { rt = u; return 1; }
	vis[u] = 1; int res;
	for (int i=0; i<e[u].size(); i++)
		if (e[u][i].v != fa && (res = getloop(e[u][i].v, u))){
			if (res == 1){
				ring[++m] = u; dist[m] = e[u][i].cost; flag[u] = 1;
				if (u != rt) return 1;
			}
			return 2;
		}
	return 0;
}

void dfs(int u, int fa){
	LL mx1 = 0, mx2 = 0, tmp;
	for (int i=0; i<e[u].size(); i++)
		if (e[u][i].v != fa && !flag[e[u][i].v]){
			dfs(e[u][i].v, u); tmp = f[e[u][i].v] + e[u][i].cost;
			if (tmp > mx1) { mx2 = mx1; mx1 = tmp; }
			else if (tmp > mx2) mx2 = tmp;
		}
	f[u] = mx1; base = max(base, mx1 + mx2);
}

int main(){
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		scanf("%d%d%d", &a, &b, &c);
		e[a].push_back(make_pair(b, c));
		e[b].push_back(make_pair(a, c));
	}
	getloop(1, 0);
	for (int i=3; i<=m; i++) dist[i] += dist[i-1];
	for (int i=1; i<=m; i++) dfs(ring[i], 0);
	pre[1] = L[1] = best = f[ring[1]];
	for (int i=2; i<=m; i++){
		L[i] = max(L[i-1], dist[i] + f[ring[i]]);
		pre[i] = max(pre[i-1], f[ring[i]] + dist[i] + best);
		best = max(best, f[ring[i]] - dist[i]);
	}
	best = 0;
	for (int i=m; i>=2; i--){
		R[i] = max(R[i+1], dist[m]-dist[i] + f[ring[i]]);
		suf[i] = max(suf[i+1], f[ring[i]] - dist[i] + best);
		best = max(best, f[ring[i]] + dist[i]);
	}
	ans = pre[m];
	for (int i=1; i<=m-1; i++)
		ans = min(ans, max(max(pre[i], suf[i+1]), L[i] + dist[1] + R[i+1]));
	printf("%I64d\n", max(ans, base));
}