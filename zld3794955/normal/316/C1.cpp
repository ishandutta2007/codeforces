#include<bits/stdc++.h>
using namespace std;
const int x_[4]={0,1,0,-1},y_[4]={1,0,-1,0};
const int N=85,M=85,P=N*M,E=P*10,Inf=1<<20;
int n,m,a[N][M]={},S,T;
int last[P]={},next[E]={},end[E]={},f[E]={},c[E]={},total_edge=1;
int dis[P]={},fe[P]={};
inline void add_edge(int u,int v,int flow,int cost)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
	f[total_edge]=flow;
	c[total_edge]=cost;
}
void init()
{
	scanf("%d%d",&n,&m);
	S=0,T=n*m+1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	
	int num[N][M]={},tot=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			num[i][j]=++tot;
	
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if((i+j)%2)
			{
				add_edge(S,num[i][j],1,0);
				add_edge(num[i][j],S,0,0);
				for(int k=0;k<4;++k)
				{
					int x=i+x_[k],y=j+y_[k];
					if(x<=0 || n<x || y<=0 || m<y)
						continue;
					int v=a[i][j]!=a[x][y];
					add_edge(num[i][j],num[x][y],1,v);
					add_edge(num[x][y],num[i][j],0,-v);
				}
			}
			else
			{
				add_edge(num[i][j],T,1,0);
				add_edge(T,num[i][j],0,0);
			}
}
bool spfa()
{
	fill(dis+S,dis+T+1,Inf);
	
	queue<int> q;
	bool in[P]={};
	
	q.push(S);
	in[S]=true;
	dis[S]=0;
	
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		in[s]=false;
		for(int i=last[s];i;i=next[i])
		{
			int j=end[i];
			if(f[i] && dis[s]+c[i]<dis[j])
			{
				dis[j]=dis[s]+c[i];
				fe[j]=i;
				if(!in[j])
				{
					in[j]=true;
					q.push(j);
				}
			}
		}
	}
	if(dis[T]==Inf)
		return false;
	int now=T;
	while(now!=S)
	{
		int i=fe[now];
		--f[i],++f[i^1];
		now=end[i^1];
	}
	return true;
}
void work()
{
	int ans=0;
	while(spfa())
		ans+=dis[T];
	printf("%d\n",ans);
}
int main()
{
	init();
	work();
	return 0;
}