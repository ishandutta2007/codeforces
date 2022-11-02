#include <algorithm>
#include <cstdio>
#include <cstring>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXN=305;
const int MAXS=180005;
int n,v;
int a[MAXN];
int b[MAXN];
int g[MAXN][MAXN];
int vis[MAXN];
int pre[MAXN];
int ans[MAXS][3];
int ansn;
void init()
{
	int e;
	scanf("%d%d%d",&n,&v,&e);
	for (int i=0;i<n;++i)
		scanf("%d",&a[i]);
	for (int i=0;i<n;++i)
		scanf("%d",&b[i]);
	for (int i=0;i<e;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		--x;--y;
		g[x][y]=g[y][x]=1;
	}
}
void DFS(int x)
{
	vis[x]=1;
	for (int i=0;i<n;++i)
		if (g[x][i]&&!vis[i])
		{
			pre[i]=x;
			DFS(i);
		}
}
void transfer(int x,int y,int d)
{
	if (x==y) return;
	int p=pre[y];
	int v=std::min(a[p],d);
	a[p]-=v;
	a[y]+=v;
	ans[ansn][0]=p;
	ans[ansn][1]=y;
	ans[ansn][2]=v;
	++ansn;
	transfer(x,p,d);
	a[p]-=d-v;
	a[y]+=d-v;
	ans[ansn][0]=p;
	ans[ansn][1]=y;
	ans[ansn][2]=d-v;
	++ansn;
}
void work(int x)
{
	memset(vis,0,sizeof(vis));
	DFS(x);
	for (int i=0;i<n;++i)
		if (vis[i]&&a[i]<b[i])
		{
			int d=std::min(a[x]-b[x],b[i]-a[i]);
			if (d==0) break;
			transfer(x,i,d);
		}
}
void solve()
{
	for (int i=0;i<n;++i)
		if (a[i]>b[i])
			work(i);
	int fl=1;
	for (int i=0;i<n;++i)
		if (a[i]!=b[i])
		{
			fl=0;break;
		}
	if (fl)
	{
		printf("%d\n",ansn);
		for (int i=0;i<ansn;++i)
			printf("%d %d %d\n",ans[i][0]+1,ans[i][1]+1,ans[i][2]);
	}
	else printf("NO\n");
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("5489.in","r",stdin);
	freopen("5489.out","w",stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}