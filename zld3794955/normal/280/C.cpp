#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=100100;
int n,last[N]={},next[N+N]={},end[N+N]={},total_edge=0;
double ans=0;
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void dfs(int s,int f,int d)
{
	ans+=1.0/d;
	for(int i=last[s];i;i=next[i])
		if(end[i]!=f)
			dfs(end[i],s,d+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=2,u=0,v=0;i<=n;++i)
	{
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
	dfs(1,0,1);
	printf("%.12f\n",ans);
	return 0;
}