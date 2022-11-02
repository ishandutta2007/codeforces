#include<bits/stdc++.h>
using namespace std;
const int N=3030;
int n,last[N]={},end[N+N]={},next[N+N]={},total_edge=0;
int cirsize=0,incir[N]={},num[N]={},d[N]={},fa[N]={},v[N]={},now=0;
int dis[N][N]={};
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void init()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<=n;++i)
	{
		scanf("%d%d",&u,&v);
		++u,++v;
		add_edge(u,v),add_edge(v,u);
	}
}
bool get_circle(int s)
{
	v[s]=now;
	for(int i=last[s];i;i=next[i])
	{
		int j=end[i];
		if(j==fa[s])
			continue;
		if(v[j])
		{
			for(incir[j]=j,num[j]=++cirsize; s!=j; s=fa[s])
				incir[s]=s,num[s]=++cirsize;
			return true;
		}
		fa[j]=s;
		if(get_circle(j))
			return true;
	}
	return false;
}
void dfs(int s,int cir)
{
	v[s]=now;
	incir[s]=cir;
	for(int i=last[s];i;i=next[i])
	{
		int j=end[i];
		if(incir[j] || v[j]==now)
			continue;
		d[j]=d[s]+1;
		dfs(j,cir);
	}
}
void get_dis(int s,int *dis)
{
	v[s]=now;
	for(int i=last[s];i;i=next[i])
	{
		int j=end[i];
		if(v[j]==now || incir[j]!=incir[s])
			continue;
		dis[j]=dis[s]+1;
		get_dis(j,dis);
	}
}
void work()
{
	++now;
	fa[1]=0;
	get_circle(1);
	++now;
	for(int i=1;i<=n;++i)
		if(incir[i] && v[i]!=now)
			dfs(i,incir[i]);
	for(int i=1;i<=n;++i)
	{
		++now;
		dis[i][i]=0;
		get_dis(i,dis[i]);
	}
	double ans=0;
	for(int a=1;a<=n;++a)
		for(int b=1;b<=n;++b)
			if(incir[a]==incir[b])
				ans+=1.0/(dis[a][b]+1);
			else
			{
				int x=d[a]+d[b];
				int y=abs(num[incir[a]]-num[incir[b]]),z=cirsize-y;
				ans+=1.0/(x+y+1)+1.0/(x+z+1)-1.0/(x+y+z);
			}
	printf("%.15f\n",ans);
}
int main()
{
	init();
	work();
	return 0;
}