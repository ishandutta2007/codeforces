#include <cstdio>
#include <cstring>
#include <vector>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXN=2005;
int n;
int d[MAXN][MAXN];
int vis[MAXN];
std::vector<std::pair<int,int> > e[MAXN];
long long dist[MAXN];
void init()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i)
		for (int j=0;j<n;++j)
			scanf("%d",&d[i][j]);
}
void DFS(int x)
{
	vis[x]=1;
	for (std::vector<std::pair<int,int> >::const_iterator i=e[x].begin();i!=e[x].end();++i)
		if (!vis[i->first])
		{
			dist[i->first]=dist[x]+i->second;
			DFS(i->first);
		}
}
int ok()
{
	for (int i=0;i<n;++i)
	{
		memset(vis,0,sizeof(vis));
		dist[i]=0;
		DFS(i);
		for (int j=0;j<n;++j)
			if (dist[j]!=d[i][j]) return 0;
	}
	return 1;
}
void solve()
{
	int mind[MAXN];
	int pre[MAXN];
	for (int i=1;i<n;++i)
		mind[i]=d[0][i],pre[i]=0;
	for (int i=1;i<n;++i)
	{
		int r=-1;
		for (int j=1;j<n;++j)
			if (!vis[j]&&(r==-1||mind[j]<mind[r])) r=j;
		if (mind[r]==0)
		{
			printf("NO\n");
			return;
		}
		e[pre[r]].push_back(std::make_pair(r,mind[r]));
		e[r].push_back(std::make_pair(pre[r],mind[r]));
		vis[r]=1;
		for (int j=1;j<n;++j)
			if (!vis[j]&&d[r][j]<mind[j])
				mind[j]=d[r][j],pre[j]=r;
	}
	if (ok()) printf("YES\n");
	else printf("NO\n");
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}