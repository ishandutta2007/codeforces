#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7,K=41;

int n,k,p;

vector<int>g[N];

int f[N][K],ans[N],h[N][K],a[N];

void dfs(int x,int fa)
{
	f[x][0]=a[x];
	for(auto v:g[x])
	{
		if(v==fa)
			continue;
		dfs(v,x);
		for(int j=0;j<p;j++)
			f[x][(j+1)%p]^=f[v][j];
	}
}

void calc(int x,int fa)
{
	for(int j=0;j<p;j++)
		f[x][j]^=h[x][j];
	for(auto v:g[x])
	{
		if(v==fa)
			continue;
		for(int j=0;j<p;j++)
			h[v][(j+2)%p]=f[x][(j+1)%p]^f[v][j];
		calc(v,x);
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	p=k*2;
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1,0);
	calc(1,0);
	for(int i=1;i<=n;i++)
		for(int j=k;j<p;j++)
			ans[i]^=f[i][j];
	for(int i=1;i<=n;i++)
		printf("%d%c",ans[i]?1:0," \n"[i==n]);
}