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
const int N=110,S=0,T=101,P=110,M=1010,V=2020,Inf=1<<20;
int n,m,a[N]={},p[V]={},u[M]={},v[M]={},ptot=0,ans=0,dis[P]={};
int last[P]={},nlast[P]={},next[M]={},end[M]={},f[M]={},total_edge=1;
void add_edge(int u,int v,int flow)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
	f[total_edge]=flow;
}
void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		int x=a[i];
		for(int j=2;j*j<=a[i];++j)
		{
			if(x%j==0)
				p[++ptot]=j;
			while(x%j==0)
				x/=j;
		}
		if(x!=1)
			p[++ptot]=x;
	}
	sort(p+1,p+ptot+1);
	ptot=unique(p+1,p+ptot+1)-p-1;
	for(int i=1;i<=m;++i)
	{
		cin>>u[i]>>v[i];
		if(u[i]%2==0)
			swap(u[i],v[i]);
	}
}
bool bfs()
{
	int q[P]={},head=0,tail=0;
	bool v[P]={};
	q[++tail]=T;
	v[T]=true;
	dis[T]=0;
	while(head!=tail)
	{
		int s=q[++head];
		for(int i=last[s];i;i=next[i])
		{
			int j=end[i];
			if(f[i^1] && !v[j])
			{
				v[j]=true;
				q[++tail]=j;
				dis[j]=dis[s]+1;
			}
		}
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
		if(f[i] && dis[s]==dis[j]+1)
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
	int s=0;
	while(bfs())
	{
		copy(last+S,last+T+1,nlast+S);
		s+=dinic(S,Inf);
	}
	return s;
}
void work()
{
	for(int i=1;i<=ptot;++i)
	{
		total_edge=1;
		for(int j=S;j<=T;++j)
			last[j]=0;
		for(int j=1;j<=n;j+=2)
		{
			int x=a[j],t=0;
			while(x%p[i]==0)
				x/=p[i],++t;
			add_edge(S,j,t);
			add_edge(j,S,0);
		}
		for(int j=2;j<=n;j+=2)
		{
			int x=a[j],t=0;
			while(x%p[i]==0)
				x/=p[i],++t;
			add_edge(j,T,t);
			add_edge(T,j,0);
		}
		for(int j=1;j<=m;++j)
		{
			add_edge(u[j],v[j],Inf);
			add_edge(v[j],u[j],0);
		}
		ans+=maxflow();
	}
	cout<<ans<<endl;
}
int main()
{
	init();
	work();
	return 0;
}