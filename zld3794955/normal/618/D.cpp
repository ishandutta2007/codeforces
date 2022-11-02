#include<bits/stdc++.h>
using namespace std;
const int N=200200;
int n,x,y,d[N]={},last[N]={},end[N+N]={},next[N+N]={},total_edge=1;
int f[N]={},g[N]={};
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void init()
{
	scanf("%d%d%d",&n,&x,&y);
	for(int i=2,u,v;i<=n;++i)
	{
		scanf("%d%d",&u,&v);
		++d[u],++d[v];
		add_edge(u,v);
		add_edge(v,u);
	}
}
void dfs(int s,int fa)
{
	int tot=0;
	for(int i=last[s];i;i=next[i])
	{
		int j=end[i];
		if(j==fa)
			continue;
		dfs(j,s);
		tot+=g[j];
		f[s]+=f[j];
	}
	if(tot==1)
		++f[s],g[s]=1;
	if(tot>1)
		f[s]+=2,g[s]=0;
	if(tot<1)
		g[s]=1;
}
void work()
{
	if(n==2)
	{
		cout<<x<<endl;
		return;
	}
	if(x>=y)
	{
		long long ans=y*1ll*(n-1);
		for(int i=1;i<=n;++i)
			if(d[i]==n-1)
				ans+=x-y;
		cout<<ans<<endl;
	}
	else
	{
		dfs(1,0);
		cout<<x*1ll*f[1]+y*1ll*(n-1-f[1])<<endl;
	}
}
int main()
{	
	init();
	work();
	return 0;
}