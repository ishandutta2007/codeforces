#include <bits/stdc++.h>
#define N 1034
#define M 256101
#define INF 0x3f3f3f3f
using namespace std;

int V, E, Es = 0;
int u, v, final;
int to[M], first[N], next[M];

int anc, col[N], bel[N];
int que[M], dis[N], ans[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

inline void addedge(int u, int v){
	to[++Es] = v; next[Es] = first[u]; first[u] = Es;
	to[++Es] = u; next[Es] = first[v]; first[v] = Es;
}

bool dfs(int x, int c = 0){
	int i, y;
	bel[x] = anc; col[x] = c;
	for(i = first[x]; i; i = next[i]){
		y = to[i];
		if(col[y] == c) return true;
		if(col[y] == -1 && dfs(y, c ^ 1)) return true;
	}
	return false;
}

void bfs(int st){
	int h, t = 1, x, y, i, &res = ans[bel[st]];
	memset(dis, 63, sizeof dis);
	que[0] = st; dis[st] = 0;
	for(h = 0; h < t; ++h)
		for(i = first[x = que[h]]; i; i = next[i])
			if(dis[y = to[i]] >= INF){
				dis[y] = dis[x] + 1;
				up(res, dis[y]);
				que[t++] = y;
			}				
}

int main(){
	int i;
	scanf("%d%d", &V, &E);
	for(i = 0; i < E; ++i){
		scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	memset(col, -1, sizeof col);
	for(i = 1; i <= V; ++i)
		if(col[i] == -1)
			if(dfs(anc = i)) return puts("-1"), 0;
	for(i = 1; i <= V; ++i) bfs(i);
	final = 0;
	for(i = 1; i <= V; ++i) final += ans[i];
	printf("%d\n", final);
	return 0;
}