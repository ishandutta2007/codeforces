#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<list>
using namespace std;
typedef long long ll;
int f[100010][20];
int d[100010];
list<int> l[100010];
int g[100010];
void dfs(int x,int fa,int dep)
{
	f[x][0]=fa;
	d[x]=dep;
	int i;
	for(i=1;i<=19;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(auto v:l[x])
		if(v!=fa)
			dfs(v,x,dep+1);
}
int x[100010];
int y[100010];
int getlca(int x,int y)
{
	if(d[x]<d[y])
		swap(x,y);
	int i;
	for(i=19;i>=0;i--)
		if(d[f[x][i]]>=d[y])
			x=f[x][i];
	if(x==y)
		return x;
	for(i=19;i>=0;i--)
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	return f[x][0];
}
void dfs2(int x)
{
	for(auto v:l[x])
		if(v!=f[x][0])
		{
			dfs2(v);
			g[x]+=g[v];
		}
}
int main()
{
	int n;
	scanf("%d",&n);
	int i,m;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		l[x[i]].push_back(y[i]);
		l[y[i]].push_back(x[i]);
	}
	dfs(1,0,1);
	memset(g,0,sizeof g);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		int qx,qy;
		scanf("%d%d",&qx,&qy);
		g[qx]++;
		g[qy]++;
		g[getlca(qx,qy)]-=2;
	}
	dfs2(1);
	for(i=1;i<n;i++)
	{
		if(f[x[i]][0]==y[i])
			printf("%d ",g[x[i]]);
		else
			printf("%d ",g[y[i]]);
	}
	return 0;
}