#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n,a,b,da,db;

vector<int>g[N];

int f[N],d[N],dia;

void dfs(int x,int fa)
{
	f[x]=0,d[x]=0;
	for(auto v:g[x])
	{
		if(v==fa)
			continue;
		dfs(v,x);
		f[x]=max(f[x],d[x]+d[v]+1);
		d[x]=max(d[x],d[v]+1);
	}
	dia=max(dia,f[x]);
}

int getd(int x,int y,int f=0)
{
	if(x==y)
		return 0;
	int ret=-1;
	for(auto v:g[x])
	{
		if(v==f)
			continue;
		int to=getd(v,y,x);
		if(to!=-1)
			ret=to+1;
	}
	return ret;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
		for(int i=1;i<=n;i++)
			g[i].clear();
		dia=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		if(2*da>=dia||da>=getd(a,b))
		{
			puts("Alice");
			continue;
		}
		if(db>da*2)
			puts("Bob");
		else
			puts("Alice");
	}
}