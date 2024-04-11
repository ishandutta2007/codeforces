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
const int N=100010;
struct edge
{
	int u,v,l;
	long long s1,s2;
}e[N]={};
int n,q,last[N]={},end[N+N]={},next[N+N]={},num[N+N]={},total_edge=0;
double ans=0;
inline double f(double x)
{
	return x*(x-1)*(x-2)/6;
}
inline void add_edge(int u,int v,int no)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
	num[total_edge]=no;
}
int dfs(int s,int f)
{
	int sz=1;
	for(int i=last[s];i;i=next[i])
		if(end[i]!=f)
		{
			int tmp=dfs(end[i],s);
			e[num[i]].s1=tmp;
			e[num[i]].s2=n-tmp;
			sz+=tmp;
		}
	return sz;
}
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].l);
		add_edge(e[i].u,e[i].v,i);
		add_edge(e[i].v,e[i].u,i);
	}
	dfs(1,0);
	for(int i=1;i<n;++i)
		ans+=e[i].l*2*(1.0-(f(e[i].s1)+f(e[i].s2))/f(n));
	scanf("%d",&q);
	for(int i=1,r=0,w=0;i<=q;++i)
	{
		scanf("%d%d",&r,&w);
		ans+=(w-e[r].l)*2*(1.0-(f(e[r].s1)+f(e[r].s2))/f(n));
		e[r].l=w;
		printf("%.10f\n",ans);
	}
	return 0;
}