#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN=3000+10;

queue<int> q;
vector<int> G[MAXN];
int deg[MAXN], dis[MAXN];
int n, m;

void findcycle() {
	while (!q.empty()) q.pop();
	for (int i=1; i<=n; i++) {
		dis[i]=0;
		if (deg[i]==1) q.push(i);
	}
	while (!q.empty()) {
		int v, u=q.front(); q.pop(); dis[u]=-1;
		for (int i=0; i<(int)G[u].size(); i++)
			if (deg[v=G[u][i]]>1) {
				deg[v]--;
				if (deg[v]==1) q.push(v);
			}
	}
}

void dfs(int u) {
	for (int v, i=0; i<(int)G[u].size(); i++) 
		if (dis[v=G[u][i]]==-1) {
			dis[v]=dis[u]+1;
			dfs(v);
		}
}

int main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++) G[i].clear();
	for (int x, y, i=0; i<n; i++) {
		scanf("%d%d", &x, &y);
		deg[x]++; deg[y]++;
		G[x].push_back(y); 
		G[y].push_back(x);
	}
	findcycle();
	for (int i=1; i<=n; i++)
		if (dis[i]==0) dfs(i);
	for (int i=1; i<=n; i++)
		printf("%d%c", dis[i], (i==n)?'\n':' ');
	return 0;
}