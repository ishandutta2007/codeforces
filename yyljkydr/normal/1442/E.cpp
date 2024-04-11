#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,a[N];

vector<int>g[N];

int mx,p;

void dfs(int x,int f,int lc,int d)
{
	if(d>=mx)
		mx=d,p=x;
	for(auto v:g[x])
	{
		if(v==f)
			continue;
		dfs(v,x,a[v]>0?a[v]:lc,d+(lc>0&&a[v]>0&&lc!=a[v]));
	}
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int s=-1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i])
				s=i;
			g[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(s==-1)
		{
			puts("1");
			continue;
		}
		mx=0,p=s;
		dfs(s,0,a[s],0);
		mx=0;
		dfs(p,0,a[p],0);
		printf("%d\n",(mx+1)/2+1);
	}
}