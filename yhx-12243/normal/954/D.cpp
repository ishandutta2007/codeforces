#include <bits/stdc++.h>
#define N 1005
#define M 2005
#define INF 0x3f3f3f3f
using namespace std;

int V, E, Es, s, t, ans = 0;
int to[M], first[N], next[M];
int ds[N], dt[N], que[N];
int G[N][N];

inline void addedge(int u, int v){
	to[++E] = v; next[E] = first[u]; first[u] = E;
	to[++E] = u; next[E] = first[v]; first[v] = E;
}

void bfs(int ss, int *d){
	int h, t = 1, i, x, y;
	que[0] = ss;
	memset(d, 63, V + 1 << 2); d[ss] = 0;
	for(h = 0; h < t; ++h)
		for(i = first[x = que[h]]; i; i = next[i])
			if(d[y = to[i]] >= INF){
				d[y] = d[x] + 1;
				que[t++] = y;
			}
}

int main(){
	int u, v, i, j;
	scanf("%d%d%d%d", &V, &Es, &s, &t);
	for(i = 1; i <= Es; ++i){
		scanf("%d%d", &u, &v);
		addedge(u, v);
		G[u][v] = G[v][u] = 1;
	}
	bfs(s, ds);
	bfs(t, dt);
	for(i = 1; i < V; ++i)
		for(j = i + 1; j <= V; ++j){
			ans += !G[i][j] && ds[i] + dt[j] + 1 >= ds[t] && ds[j] + dt[i] + 1 >= ds[t];
	//		printf("(%d,%d) -%d\n", i,j,ans);
		}
	printf("%d\n", ans);
	return 0;
}