#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int head[N],cnt;

struct node{
	int ne,to;
}edg[N*2+1];

void build(int u,int v)
{
	++cnt;
	edg[cnt].to=v;
	edg[cnt].ne=head[u];
	head[u]=cnt;
}

int n,k,dep[N],sz[N],val[N];

void dfs(int x,int f)
{
	sz[x]=1;
	for(int tmp=head[x];tmp;tmp=edg[tmp].ne)
	{
		int v=edg[tmp].to;
		if(v==f)
			continue;
		dep[v]=dep[x]+1;
		dfs(v,x);
		sz[x]+=sz[v];
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		build(u,v);
		build(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		val[i]=dep[i]-(sz[i]-1);
	sort(val+1,val+n+1);
	long long ans=0;
	for(int i=n;i>=n-k+1;i--)
		ans+=val[i];
	printf("%lld",ans);
}