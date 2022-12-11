#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<list>
using namespace std;
typedef long long ll;
list<int> l[1000010];
int fa[1000010];
int f[1000010];
int g;
int b[1000010];
void dfs(int x,int ff,int mi)
{
	fa[x]=ff;
	mi=min(mi,x);
	f[x]=mi;
	for(auto v:l[x])
		if(v!=ff)
			dfs(v,x,mi);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i,x,y;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		l[x].push_back(y);
		l[y].push_back(x);
	}
	scanf("%d%d",&x,&y);
	y=y%n+1;
	memset(b,0,sizeof b);
	b[y]=1;
	dfs(y,0,0x7fffffff);
	g=y;
	int ans;
	int last=0;
	for(i=2;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		y=(y+last)%n+1;
		if(x==1)
		{
			while(!b[y])
			{
				b[y]=1;
				g=min(g,y);
				y=fa[y];
			}
		}
		else
		{
			ans=min(g,f[y]);
			printf("%d\n",ans);
			last=ans;
		}
	}
	return 0;
}