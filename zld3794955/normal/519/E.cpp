#include<bits/stdc++.h>
using namespace std;
const int N=100100,D=20;
int n,last[N]={},next[N+N]={},end[N+N]={},total_edge=0;
int f[N][D]={},d[N]={},size[N]={};
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
		add_edge(u,v),add_edge(v,u);
	}
}
void dfs(int s)
{
	size[s]=1;
	for(int i=last[s];i;i=next[i])
	{
		int j=end[i];
		if(f[s][0]!=j)
		{
			f[j][0]=s;
			for(int k=1;f[j][k-1];++k)
				f[j][k]=f[f[j][k-1]][k-1];
			d[j]=d[s]+1;
			dfs(j);
			size[s]+=size[j];
		}
	}
}
int LCA(int u,int v)
{
	if(d[u]<d[v])
		swap(u,v);
	for(int i=D-1;i>=0;--i)
		if((1<<i)<=d[u]-d[v])
			u=f[u][i];
	if(u==v)
		return u;
	for(int i=D-1;i>=0;--i)
		if(f[u][i]!=f[v][i])
			u=f[u][i],v=f[v][i];
	return f[u][0];
}
int up(int u,int l)
{
	for(int i=D-1;i>=0;--i)
		if((1<<i)<=l)
			l-=1<<i,u=f[u][i];
	return u;
}
void query()
{
	int m,u,v;
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		if(u==v)
		{
			printf("%d\n",n);
			continue;
		}
		if(d[u]<d[v])
			swap(u,v);
		int p=LCA(u,v),l=d[u]+d[v]-d[p]-d[p];
		if(l%2)
		{
			puts("0");
			continue;
		}
		int mid=up(u,l/2);
		if(mid==p)
			printf("%d\n",n-size[up(u,l/2-1)]-size[up(v,l/2-1)]);
		else
			printf("%d\n",size[mid]-size[up(u,l/2-1)]);
	}
}
int main()
{	
	init();
	dfs(1);
	query();
	return 0;
}