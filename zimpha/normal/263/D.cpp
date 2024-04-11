#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAXN=100000+10;

vector<int> path;
vector<int> G[MAXN];
int dis[MAXN];
int n, m, k;
bool flag;

void dfs(int u, int dep) {
	dis[u]=dep; path.push_back(u);
	for (int v, i=0; !flag&&i<(int)G[u].size(); i++) {
		v=G[u][i];
		if (dis[v]!=-1) {
			if (dep-dis[v]>=k) {
				printf("%d\n", dep-dis[v]+1);
				int pos=0;
				while (path[pos]!=v) pos++;
				for (; pos<=dep; pos++)
					printf("%d%c", path[pos], (pos==dep)?'\n':' ');
				flag=true;
			}
		}
		else dfs(v, dep+1);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=n; i++) G[i].clear();
	for (int x, y, i=0; i<m; i++) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	memset(dis, -1, sizeof(dis)); 
	path.clear(); flag=false;
	dfs(1, 0);
	return 0;
}