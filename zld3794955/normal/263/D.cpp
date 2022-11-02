#include<bits/stdc++.h>
using namespace std;
const int N=100010,M=100010,K=100010;
int n,m,k,last[N]={},next[M+M]={},end[M+M]={},total_edge=0;
int d[N]={},f[N]={};
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void init()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x,y;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		add_edge(x,y),add_edge(y,x);
	}
}
void dfs(int s,int t)
{
	d[s]=t;
	for(int i=last[s];i;i=next[i])
	{
		int j=end[i];
		if(d[j]==0)
		{
			f[j]=s;
			dfs(j,t+1);
		}
		else
		{
			if(d[j]<=d[s]-k)
			{
				int x=s;
				printf("%d\n",d[s]-d[j]+1);
				printf("%d",x);
				while(x!=j)
				{
					x=f[x];
					printf(" %d",x);
				}
				printf("\n");
				exit(0);
			}
		}
	}
	d[s]=0;
}
int main()
{
	init();
	dfs(1,1);
	return 0;
}