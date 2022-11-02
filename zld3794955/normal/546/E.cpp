#include<bits/stdc++.h>
using namespace std;
const int N=220,M=2020,Inf=1<<20;
int n,m,a[N]={},b[N]={},S=0,T=0;
int last[N]={},next[M]={},end[M]={},f[M]={},total_edge=1;
int nlast[N]={},dis[N]={},ans[N][N]={};
inline void add_edge(int u,int v,int flow)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
	f[total_edge]=flow;
}
void init()
{
	cin>>n>>m;
	S=0,T=n+n+1;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		add_edge(S,i,a[i]),add_edge(i,S,0);
	}
	for(int i=1;i<=n;++i)
	{
		cin>>b[i];
		add_edge(i+n,T,b[i]),add_edge(T,i+n,0);
	}
	for(int i=1;i<=n;++i)
		add_edge(i,i+n,Inf),add_edge(i+n,i,0);
	for(int i=1,u=0,v=0;i<=m;++i)
	{
		cin>>u>>v;
		add_edge(u,v+n,Inf),add_edge(v+n,u,0);
		add_edge(v,u+n,Inf),add_edge(u+n,v,0);
	}
}
bool bfs()
{
	int q[N]={},head=0,tail=0;
	bool v[N]={};
	q[++tail]=T;
	dis[T]=0;
	v[T]=true;
	while(head!=tail)
		for(int s=q[++head],i=last[s];i;i=next[i])
		{
			int j=end[i];
			if(f[i^1] && !v[j])
				v[j]=true,dis[j]=dis[s]+1,q[++tail]=j;
		}
	return v[S];
}
int dinic(int s,int flow)
{
	if(s==T)
		return flow;
	int x=flow;
	for(int &i=nlast[s];i;i=next[i])
	{
		int j=end[i];
		if(dis[s]==dis[j]+1 && f[i])
		{
			int a=dinic(j,min(x,f[i]));
			f[i]-=a;
			f[i^1]+=a;
			if((x-=a)==0)
				return flow;
		}
	}
	return flow-x;
}
int maxflow()
{
	int ans=0;
	while(bfs())
	{
		copy(last+S,last+T+1,nlast+S);
		ans+=dinic(S,Inf);
	}
	return ans;
}
void work()
{
	int sa=accumulate(a+1,a+n+1,0),sb=accumulate(b+1,b+n+1,0);
	if(sa!=sb || maxflow()!=sa)
	{
		puts("NO");
		return;
	}
	puts("YES");
	for(int s=1;s<=n;++s)
		for(int i=last[s];i;i=next[i])
			if(end[i]>n)
				ans[s][end[i]-n]=f[i^1];
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			cout<<ans[i][j]<<' ';
		cout<<endl;
	}
}
int main()
{	
	init();
	work();
	return 0;
}