#include <bits/stdc++.h>

const int kN = 2e5 + 5;

struct Edge { int nxt, v; } E[kN];
int d[kN], deg[kN], fa[kN], head[kN], id[kN], cnt = 0, dfv = 0; bool vis[kN], is_leaf[kN];
void AddEdge(int u, int v) {
	E[cnt] = (Edge) {head[u], v}; head[u] = cnt++;
}

int main() {
	memset(head, 0xff, sizeof(head));
	memset(id, 0xff, sizeof(id));
	int n; scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		AddEdge(u, v); AddEdge(v, u);
		++deg[u]; ++deg[v];
	}
	for(int i = 1; i <= n; ++i) 
		if(deg[i] == 1) {
			if(id[head[i] & ~1] == -1) {
				id[head[i] & ~1] = dfv++;
				//printf("Q: %d %d %d\n", i, dfv - 1, head[i] & ~1);
			}
		}
	for(int i = 0; i < n - 1; ++i)
		if(id[i * 2] == -1) {
			id[i * 2] = dfv++;
			//printf("%d i\n");
		}
	for(int i = 0; i < n - 1; ++i)
		printf("%d\n", id[i * 2]);
	return 0;
}