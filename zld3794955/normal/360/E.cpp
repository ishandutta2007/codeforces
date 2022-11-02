#include<bits/stdc++.h>
using namespace std;
const int N=10010,M=10010,K=110;
const long long Inf=1ll<<50;
struct edge
{
	int u,v,l,r;
}e[K]={};
int n,m,k,s1,s2,f;
int last[N]={},end[M+K]={},next[M+K]={},l[M+K]={},total_edge=0;
long long dis1[N]={},dis2[N]={};
inline void add_edge(int u,int v,int len)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
	l[total_edge]=len;
}
void init()
{
	scanf("%d%d%d%d%d%d",&n,&m,&k,&s1,&s2,&f);
	for(int i=1,u,v,l;i<=m;++i)
	{
		scanf("%d%d%d",&u,&v,&l);
		add_edge(u,v,l);
	}
	for(int i=1;i<=k;++i)
	{
		scanf("%d%d%d%d",&e[i].u,&e[i].v,&e[i].l,&e[i].r);
		add_edge(e[i].u,e[i].v,e[i].r);
	}
}
void dijkstra(int s,long long *dis)
{
	fill(dis+1,dis+n+1,Inf);
	priority_queue<pair<long long,int> > q;
	bool v[N]={};
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		pair<long long,int> p=q.top();
		q.pop();
		long long d=-p.first,s=p.second;
		if(v[s])
			continue;
		v[s]=true;
		dis[s]=d;
		for(int i=last[s];i;i=next[i])
			if(!v[end[i]])
				q.push(make_pair(-(d+l[i]),end[i]));
	}
}
bool check(int d)
{
	for(int i=1;i<=k;++i)
		l[m+i]=e[i].r;
	bool flag=true;
	while(flag)
	{
		flag=false;
		dijkstra(s1,dis1);
		dijkstra(s2,dis2);
		for(int i=1;i<=k;++i)
			if(dis1[e[i].u]<dis2[e[i].u]+d && l[m+i]!=e[i].l)
			{
				l[m+i]=e[i].l;
				flag=true;
			}
	}
	return dis1[f]<dis2[f]+d;
}
void work()
{
	if(check(0))
	{
		puts("WIN");
		for(int i=1;i<=k;++i)
			printf("%d%c",l[i+m]," \n"[i==k]);
	}
	else if(check(1))
	{
		puts("DRAW");
		for(int i=1;i<=k;++i)
			printf("%d%c",l[i+m]," \n"[i==k]);
	}
	else puts("LOSE");
}
int main()
{	
	init();
	work();
	return 0;
}