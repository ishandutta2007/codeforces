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
list<pii> l[200010];
int f[200010];
int g[200010];
void dfs1(int x,int fa)
{
	f[x]=0;
	for(auto v:l[x])
		if(v.first!=fa)
		{
			dfs1(v.first,x);
			f[x]+=f[v.first]+v.second;
		}
}
void dfs2(int x,int fa)
{
	for(auto v:l[x])
		if(v.first!=fa)
		{
			g[v.first]=g[x]+(v.second?-1:1);
			dfs2(v.first,x);
		}
}
int main()
{
	int n;
	scanf("%d",&n);
	int x,y,i;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		l[x].push_back(pii(y,0));
		l[y].push_back(pii(x,1));
	}
	dfs1(1,0);
	g[1]=f[1];
	dfs2(1,0);
	int ans=0x7fffffff;
	for(i=1;i<=n;i++)
		ans=min(ans,g[i]);
	printf("%d\n",ans);
	for(i=1;i<=n;i++)
		if(g[i]==ans)
			printf("%d ",i);
	return 0;
}