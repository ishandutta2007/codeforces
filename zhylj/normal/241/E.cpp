#include <bits/stdc++.h>

const int kN = 1e5 + 5;

std::vector <int> E2[kN];
struct Edge {
	int v, w;
}; std::vector <Edge> E[kN];
int n, m, d[kN], cnt[kN], eu[kN], ev[kN]; bool vis[kN], flag[kN];
std::queue <int> que;
void Add(int u, int v, int w) {
	//printf("%d %d %d\n", u, v, w);
	E[u].push_back((Edge) { v, w });
}

void Build(int cur) {
	vis[cur] = true;
	if(cur == n) {
		flag[cur] = true;
		return;
	}
	for(int i = 0; i < E2[cur].size(); ++i) {
		int v = E2[cur][i];
		if(!vis[v]) Build(v);
		flag[cur] = flag[cur] || flag[v];
		if(flag[v]) {
			Add(cur, v, 2);
			Add(v, cur, -1);
		}
	}
}
bool Spfa() {
	memset(vis, false, sizeof(vis));
	memset(d, 0x3f, sizeof(d));
	d[1] = 0; que.push(1); ++cnt[1];
	while(!que.empty()) {
		int cur = que.front(); que.pop(); vis[cur] = false;
		for(int i = 0; i < E[cur].size(); ++i) {
			int v = E[cur][i].v, w = E[cur][i].w;
			if(d[v] > d[cur] + w) {
				d[v] = d[cur] + w;
				if(!vis[v]) {
					que.push(v);
					vis[v] = true;
					if(++cnt[v] > n) return false;
				}
			}
		}
	}
	return true; 
}

int main() {
	//freopen("a.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d", eu + i, ev + i);
		E2[eu[i]].push_back(ev[i]);
	//	printf("R: %d %d\n", eu[i], ev[i]);
	}
	Build(1);
	if(!flag[1] || !Spfa()) {
		printf("No\n");
	} else {
		printf("Yes\n");
		for(int i = 1; i <= m; ++i) {
			int u = eu[i], v = ev[i];
			if(flag[v] && flag[u])
				printf("%d\n", d[v] - d[u]);
			else printf("%d\n", 1);
		}
	}
	return 0;
}