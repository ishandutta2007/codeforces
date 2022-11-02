#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=1010,M=5050,Inf=1<<20;
struct edge
{
	int u,v;
}e[M]={};
int n,m,last[N]={},next[M+M]={},end[M+M]={},l[M+M]={},total_edge=0,dis[N]={};
bool del[N]={},v[N]={};
inline void add_edge(int u,int v,int len)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
	l[total_edge]=len;
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		e[i]=(edge){u,v};
		add_edge(u,v,2),add_edge(v,u,-1);
	}
	fill(del+1,del+n+1,true);
	del[n]=false;
	::v[n]=true;
}
void mark(int s)
{
	if(v[s])
		return;
	v[s]=true;
	for(int i=last[s];i;i=next[i])
	{
		if(l[i]<0)
			continue;
		int j=end[i];
		mark(j);
		if(!del[j])
			del[s]=false;
	}
}
void work()
{
	int cnt[N]={};
	queue<int> q;
	bool in[N]={};
	fill(dis+1,dis+n+1,Inf);
	q.push(1);
	dis[1]=0;
	in[1]=true;
	++cnt[1];
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		in[s]=false;
		for(int i=last[s];i;i=next[i])
		{
			int j=end[i];
			if(del[j])
				continue;
			if(dis[s]+l[i]<dis[j])
			{
				dis[j]=dis[s]+l[i];
				if(!in[j])
				{
					in[j]=true;
					q.push(j);
					if((++cnt[j])>n)
					{
						puts("No");
						return;
					}
				}
			}
		}
	}
	puts("Yes");
	for(int i=1;i<=m;++i)
		if(!del[e[i].u] && !del[e[i].v] && abs(dis[e[i].u]-dis[e[i].v])==2)
			puts("2");
		else
			puts("1");
}
int main()
{
	init();
	mark(1);
	work();
	return 0;
}