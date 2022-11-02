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
const int N=100010,M=400030;
const long long Inf=1ll<<60;
int n,m,k,last[N]={},end[M+M]={},next[M+M]={},total_edge=1,bar=0;
long long l[M+M]={},dis[M+M]={};
inline void add_edge(int u,int v,long long len)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
	l[total_edge]=len;
}
void init()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u=0,v=0,l=0;i<=m;++i)
	{
		scanf("%d%d%d",&u,&v,&l);
		add_edge(u,v,l);
		add_edge(v,u,l);
	}
	bar=total_edge;
	for(int i=1,v=0,l=0;i<=k;++i)
	{
		scanf("%d%d",&v,&l);
		add_edge(1,v,l);
	}
}
struct state
{
	long long dis;
	int s,x;
};
struct state_cmp
{
	bool operator()(const state &s1,const state &s2)
	{
		return s1.dis>s2.dis || (s1.dis==s2.dis && s1.x>s2.x);
	}
};
void work()
{
	for(int i=1;i<=n;++i)
		dis[i]=Inf;
	priority_queue<state,vector<state>,state_cmp>q;
	int ans=k;
	bool in[N]={};
	in[1]=true;
	dis[1]=0;
	for(int i=last[1];i;i=next[i])
		q.push((state){l[i],end[i],i>bar});
	while(!q.empty())
	{
		state s=q.top();
		q.pop();
		if(in[s.s])
			continue;
		if(s.x)
			--ans;
		dis[s.s]=s.dis;
		in[s.s]=true;
		for(int i=last[s.s];i;i=next[i])
			if(dis[s.s]+l[i]<=dis[end[i]])
				q.push((state){dis[s.s]+l[i],end[i],0});
	}
	//for(int i=1;i<=n;++i)
	//	cout<<dis[i]<<' ';
	//cout<<endl;
	printf("%d\n",ans);
}
int main()
{	
	init();
	work();
	return 0;
}