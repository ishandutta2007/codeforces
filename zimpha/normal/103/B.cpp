#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=100+10;

queue<int> q;
vector<int> G[MAXN];
bool vis[MAXN];
int deg[MAXN];
int n, m;

void dfs(int u) {
	vis[u]=true;
	for (int i=0; i<(int)G[u].size(); i++)
		if (!vis[G[u][i]]) dfs(G[u][i]);
}

bool isconnect() {
	memset(vis, 0, sizeof(vis));
	dfs(1);
	for (int i=1; i<=n; i++) 
		if (!vis[i]) return false;
	return true;
}

bool findcycle() {
	while (!q.empty()) q.pop();
	for (int i=1; i<=n; i++) {
		vis[i]=true;
		if (deg[i]==1) q.push(i);
	}
	while (!q.empty()) {
		int v, u=q.front(); q.pop(); vis[u]=false;
		for (int i=0; i<(int)G[u].size(); i++)
			if (deg[v=G[u][i]]>1) {
				deg[v]--;
				if (deg[v]==1) q.push(v);
			}
	}
	int cnt=0;
	for (int i =1; i<=n; i++)
		if (vis[i]) {
			cnt++;
			if (deg[i]!=2) return false;
		}
	if (!cnt) return false;
	else return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++) G[i].clear();
	for (int x, y, i=0; i<m; i++) {
		scanf("%d%d", &x, &y);
		deg[x]++; deg[y]++;
		G[x].push_back(y); 
		G[y].push_back(x);
	}
	if (isconnect()&&findcycle()) puts("FHTAGN!");
	else puts("NO");
	return 0;
}