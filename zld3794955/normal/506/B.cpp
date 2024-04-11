#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=100100,M=200200;
struct edge
{
	int u,v;
}e[M]={};
int n,m,last[N]={},end[M]={},next[M]={},total_edge=0,tot_dfn=0;
int c[N]={},totc=0,dfn[N]={},low[N]={},size[N]={};
int s[N]={},top=0,ans=0;
bool v[N]={},in_stack[N]={};
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&e[i].u,&e[i].v);
		add_edge(e[i].u,e[i].v);
	}
}
void Tarjan(int p)
{
	s[++top]=p;
	in_stack[p]=true;
	dfn[p]=low[p]=++tot_dfn;
	v[p]=true;
	for(int i=last[p];i;i=next[i])
	{
		int j=end[i];
		if(!v[j])
		{
			Tarjan(j);
			low[p]=min(low[p],low[j]);
		}
		else
			if(in_stack[j])
				low[p]=min(dfn[j],low[p]);
	}
	if(low[p]==dfn[p])
	{
		int pos=top;
		while(s[pos]!=p)
			--pos;
		++totc;
		for(int i=pos;i<=top;++i)
		{
			in_stack[s[i]]=false;
			c[s[i]]=totc;
		}
		size[totc]=top-pos+1;
		top=pos-1;
	}
}
void Tarjan()
{
	for(int i=1;i<=n;++i)
		if(!v[i])
			Tarjan(i);
	/*
	for(int i=1;i<=n;++i)
		cout<<c[i]<<' ';
	cout<<endl;
	for(int i=1;i<=totc;++i)
		cout<<size[i]<<' ';
	cout<<endl;
	*/
	for(int i=1;i<=n;++i)
		last[i]=0,v[i]=false;
	total_edge=0;
	for(int i=1;i<=m;++i)
	{
		e[i].u=c[e[i].u];
		e[i].v=c[e[i].v];
		if(e[i].u!=e[i].v)
			add_edge(e[i].u,e[i].v),add_edge(e[i].v,e[i].u);
	}
}
void bfs(int s)
{
	queue<int> q;
	bool flag=true;
	q.push(s);
	v[s]=true;
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		ans+=size[s];
		if(size[s]>1)
			flag=false;
		for(int i=last[s];i;i=next[i])
			if(!v[end[i]])
			{
				v[end[i]]=true;
				q.push(end[i]);
			}
	}
	ans-=flag;
}
void work()
{
	for(int i=1;i<=totc;++i)
		if(!v[i])
			bfs(i);
	cout<<ans<<endl;
}
int main()
{	
	init();
	Tarjan();
	work();
	return 0;
}