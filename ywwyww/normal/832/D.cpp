#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<utility>
#include<list>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int d[100010];
int f[100010][20];
list<int> l[100010];
int st[100010];
int ed[100010];
int ti;
void dfs(int x,int fa,int dep)
{
	st[x]=++ti;
	d[x]=dep;
	f[x][0]=fa;
	int i;
	for(i=1;i<=19;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(auto v:l[x])
		if(v!=fa)
			dfs(v,x,dep+1);
	ed[x]=ti;
}
int getlca(int x,int y)
{
	int i;
	if(d[x]<d[y])
		swap(x,y);
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
int getdist(int x,int y)
{
	return d[x]+d[y]-2*d[getlca(x,y)]+1;
}
int main()
{
	int n,q;
	int i;
	scanf("%d%d",&n,&q);
	for(i=2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		l[x].push_back(i);
		l[i].push_back(x);	
	}
	ti=0;
	dfs(1,0,1);
	int x,y,z;
	int ans;
	for(i=1;i<=q;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		int lca=getlca(x,y);
		ans=0;
		if(st[z]<st[lca]||st[z]>ed[lca])
		{
			ans=max(ans,d[x]-d[lca]+1);
			ans=max(ans,d[y]-d[lca]+1);
			ans=max(ans,getdist(lca,z));
		}
		else
		{
			int lca1=getlca(x,z);
			int lca2=getlca(y,z);
			if(d[lca1]>d[lca2])
				ans=max(max(ans,d[z]-d[lca1]+1),max(d[x]-d[lca1]+1,d[lca1]+d[y]-2*d[lca]+1));
			else
				ans=max(max(ans,d[z]-d[lca2]+1),max(d[y]-d[lca2]+1,d[lca2]+d[x]-2*d[lca]+1));
		}
		printf("%d\n",ans);
	}
	return 0;
}