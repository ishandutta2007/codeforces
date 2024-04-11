#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,last[N]={},next[N+N]={},end[N+N]={},d[N]={},in[N]={},total_edge=0;
int q[N]={},inmain[N]={},v[N]={},now=0,dis[N]={};
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
	++d[u];
}
void init()
{
	scanf("%d",&n);
	for(int i=2,u,v;i<=n;++i)
	{
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
	copy(d+1,d+n+1,in+1);
}
void getchain()
{
	if(n<=4)
	{
		puts("Yes");
		return;
	}
	int head=0,tail=0;
	for(int i=1;i<=n;++i)
		if(in[i]==1)
			q[++tail]=i;
	++now;
	while(head!=tail)
	{
		int s=q[++head];
		v[s]=now;
		if(d[s]>=4)
		{
			inmain[s]=true;
			continue;
		}
		if(d[s]==3)
		{
			for(int i=last[s];i;i=next[i])
				if(!v[end[i]])
					inmain[end[i]]=true;
			continue;
		}
		for(int i=last[s];i;i=next[i])
		{
			int j=end[i];
			if(v[j]!=now && (--in[j])==1)
				q[++tail]=j;
		}
	}
}
void bfs(int s)
{
	int head=0,tail=0;
	++now;
	q[++tail]=s;
	v[s]=now;
	dis[s]=inmain[s];
	
	while(head!=tail)
	{
		int s=q[++head];
		for(int i=last[s];i;i=next[i])
		{
			int j=end[i];
			if(v[j]!=now)
			{
				v[j]=now;
				dis[j]=dis[s]+inmain[j];
				q[++tail]=j;
			}
		}
	}
}
void work()
{
	if(n<=4)
		return;
	bfs(1);
	bfs(max_element(dis+1,dis+n+1)-dis);
	if(*max_element(dis+1,dis+n+1)<accumulate(inmain+1,inmain+n+1,0))
		puts("No");
	else
		puts("Yes");
}
int main()
{	
	init();
	getchain();
	work();
	return 0;
}