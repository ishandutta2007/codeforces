#include<bits/stdc++.h>
using namespace std;
const int N=200200;
int n,last[N]={},next[N]={},end[N]={},total_edge=0;
int size[N]={},f[N][2]={},g[N][2]={};
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void init()
{
	scanf("%d",&n);
	for(int i=2,u=0,v=0;i<=n;++i)
	{
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
}
void dfs(int s)
{
	size[s]=!last[s];
	for(int i=last[s];i;i=next[i])
	{
		dfs(end[i]);
		size[s]+=size[end[i]];
	}
}
void get_ans1(int s,int c)
{
	if(!last[s])
	{
		f[s][c]=1;
		return;
	}
	f[s][c]=1;
	for(int i=last[s];i;i=next[i])
		get_ans1(end[i],!c);
	if(c==0)
		for(int i=last[s];i;i=next[i])
			f[s][c]=max(f[s][c],size[s]-size[end[i]]+f[end[i]][!c]);
	else
		for(int i=last[s];i;i=next[i])
			f[s][c]+=f[end[i]][!c]-1;
}
void get_ans2(int s,int c)
{
	if(!last[s])
	{
		g[s][c]=1;
		return;
	}
	g[s][c]=size[s];
	for(int i=last[s];i;i=next[i])
		get_ans2(end[i],!c);
	if(c==0)
		for(int i=last[s];i;i=next[i])
			g[s][c]-=size[end[i]]-g[end[i]][!c];
	else
		for(int i=last[s];i;i=next[i])
			g[s][c]=min(g[s][c],g[end[i]][!c]);
}
void work()
{
	dfs(1);
	get_ans1(1,0);
	get_ans2(1,0);
	cout<<f[1][0]<<' '<<g[1][0]<<endl;
}
int main()
{
	init();
	work();
	return 0;
}