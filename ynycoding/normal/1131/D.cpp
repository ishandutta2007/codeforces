#include <cstdio>
#include <vector>
#include <cstdlib>
#define MAXN 2005
using std::vector;
int n, m, dis[MAXN], vis[MAXN], ok[MAXN];
char s[MAXN];
vector<int> e[MAXN], w[MAXN];
void dfs(int u)
{
	vis[u]=1;
	for(int i=0; i<e[u].size(); ++i)
	{
		int v=e[u][i], c=w[u][i];
		if(dis[v]<dis[u]+c)
		{
			dis[v]=dis[u]+c;
			if(vis[v]) puts("No"), exit(0);
			dfs(v);
		}
	}
	vis[u]=0;
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i)
	{
		scanf("%s", &s);
		for(int j=1; j<=m; ++j) if(s[j-1]=='<') e[i].push_back(j+n), w[i].push_back(1);
		else if(s[j-1]=='=') e[i].push_back(j+n), w[i].push_back(0), e[j+n].push_back(i), w[j+n].push_back(0);
		else e[j+n].push_back(i), w[j+n].push_back(1);
	}
	for(int i=1; i<=n+m; ++i) dfs(i);
	puts("Yes");
	for(int i=1; i<=n; ++i) printf("%d ", dis[i]+1);
	puts("");
	for(int i=n+1; i<=n+m; ++i) printf("%d ", dis[i]+1);
	return 0;
}