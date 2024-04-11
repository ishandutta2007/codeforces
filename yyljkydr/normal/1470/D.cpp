#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n,m;

vector<int>g[N],v[2];

int vis[N],cnt[2],dep[N],cho[N];

void dfs(int x)
{
	vis[x]=1;
	v[dep[x]&1].push_back(x);
	int ok=1;
	for(int i=0;i<g[x].size();i++)
	{
		int v=g[x][i];
		if(vis[v])
			ok&=!cho[v]; 
	}
	cho[x]=ok;
	for(int i=0;i<g[x].size();i++)
	{
		int v=g[x][i];
		if(!vis[v])
		{
			dep[v]=dep[x]+1;
			dfs(v);
		}
	}
}

void calc(int x)
{
	vis[x]=1;
	for(int i=0;i<g[x].size();i++)
		if(cho[x]||cho[g[x][i]])
		{
			if(!vis[g[x][i]])
				calc(g[x][i]);
		}
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			g[i].clear(),vis[i]=0;
		cnt[0]=cnt[1]=0;
		v[0].clear(),v[1].clear();
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
		fill(vis+1,vis+n+1,0);
		calc(1);
		int ok=1;
		for(int i=1;i<=n;i++)
			if(!vis[i])
				ok=0;
		if(!ok)
			puts("NO");
		else
		{
			puts("YES");
			int cnt=0;
			for(int i=1;i<=n;i++)
				if(cho[i])
					cnt++;
			printf("%d\n",cnt);
			for(int i=1;i<=n;i++)
				if(cho[i])
					printf("%d ",i);
			puts("");
		}
	}
}