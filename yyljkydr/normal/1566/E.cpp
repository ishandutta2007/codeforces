#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n;

vector<int>g[N];

int ans;

int dfs(int x,int f)
{
	int slf=0;
	for(auto v:g[x])
	{
		if(v==f)
			continue;
		slf+=dfs(v,x);
	}
	if(!slf)
		return 1;
	else
	{
		ans+=slf-1;
		return 0;
	}
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			g[i].clear();
		ans=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		printf("%d\n",ans+1);
	}
}