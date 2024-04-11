#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,a[N][2];

vector<int>g[N];

long long f[N][2];

void dfs(int x,int F)
{
	for(auto v:g[x])
	{
		if(v==F)
			continue;
		dfs(v,x);
		for(int j=0;j<2;j++)
			f[x][j]+=max(f[v][0]+abs(a[x][j]-a[v][0]),f[v][1]+abs(a[x][j]-a[v][1]));
	}
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i][0],&a[i][1]);
			g[i].clear();
			f[i][0]=f[i][1]=0;
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		printf("%lld\n",max(f[1][0],f[1][1]));
	}
}