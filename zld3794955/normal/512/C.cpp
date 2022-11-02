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
const int N=202,M=N*N,Inf=1<<20;
int n,a[N]={},last[N]={},next[M]={},end[M]={},f[M]={},total_edge=1;
int nlast[N]={},dis[N]={},S=0,T=0;
vector<int> v[N];
bool b[N]={};
inline void add_edge(int u,int v,int flow)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
	f[total_edge]=flow;
}
bool prime(int x) // x>=4
{
	for(int i=2;i*i<=x;++i)
		if(x%i==0)
			return false;
	return true;
}
void init()
{
	scanf("%d",&n);
	S=0,T=n+1;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		if(a[i]%2)
			add_edge(S,i,2),add_edge(i,S,0);
		else
			add_edge(i,T,2),add_edge(T,i,0);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(a[i]%2 && a[j]%2==0 && prime(a[i]+a[j]))
				add_edge(i,j,1),add_edge(j,i,0);
}
bool bfs()
{
	int q[N]={},head=0,tail=0;
	bool v[N]={};
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
				q[++tail]=j;
				v[j]=true;
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
	int s=0;
	while(bfs())
	{
		for(int i=S;i<=T;++i)
			nlast[i]=last[i];
		s+=dinic(S,Inf);
	}
	return s;
}
void dfs1(int,int,int);
void dfs2(int,int,int);
void dfs1(int tot,int s,int fa)
{
	if(b[s])
		return;
	b[s]=true;
	v[tot].push_back(s);
	for(int i=last[s];i;i=next[i])
		if(end[i]!=S && end[i]!=fa && !f[i])
		{
			dfs2(tot,end[i],s);
			return;
		}
}
void dfs2(int tot,int s,int fa)
{
	if(b[s])
		return;
	b[s]=true;
	v[tot].push_back(s);
	for(int i=last[s];i;i=next[i])
		if(end[i]!=T && end[i]!=fa && f[i])
		{
			dfs1(tot,end[i],s);
			return;
		}
}
void work()
{
	if(maxflow()!=n)
	{
		puts("Impossible");
		return;
	}
	int tot=0;
	for(int s=1;s<=n;++s)
		if(!b[s] && a[s]%2)
			dfs1(++tot,s,0);
	cout<<tot<<endl;
	for(int i=1;i<=tot;++i)
	{
		cout<<v[i].size();
		for(vector<int>::iterator it=v[i].begin();it!=v[i].end();++it)
			cout<<' '<<*it;
		cout<<endl;
	}
}
int main()
{	
	init();
	work();
	return 0;
}