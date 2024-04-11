#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n,mx[N],sz[N];

vector<int>g[N];

int mxs;

vector<int>grt;

void dfs(int x,int f)
{
	sz[x]=1;
	mx[x]=0;
	for(auto v:g[x])
	{
		if(v==f)
			continue;
		dfs(v,x);
		sz[x]+=sz[v];
		if(sz[v]>mx[x])
			mx[x]=sz[v];
	}
	if(n-sz[x]>mx[x])
		mx[x]=n-sz[x];
	mxs=min(mxs,mx[x]);
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			g[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		mxs=1e9;
		dfs(1,0);
		grt.clear();
		for(int i=1;i<=n;i++)
			if(mx[i]==mxs)
				grt.push_back(i);
		assert(grt.size()<=2);
		if(grt.size()==1)
		{
			int v=g[grt[0]][0];
			printf("%d %d\n",grt[0],v);
			printf("%d %d\n",grt[0],v);
		}
		else
		{
			int x=grt[0],y=grt[1];
			for(auto v:g[x])
			{
				if(v==y)
					continue;
				printf("%d %d\n",x,v);
				printf("%d %d\n",y,v);
				break;
			}
		}
	}
}