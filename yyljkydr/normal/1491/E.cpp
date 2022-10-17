#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

unordered_map<int,int>g[N];

int n,vis[N],sz[N],fib[N],isfib[N];

void getsz(int x,int f)
{
	sz[x]=1;
	for(auto v:g[x])
	{
		if(v.first==f)
			continue;
		getsz(v.first,x);
		sz[x]+=sz[v.first];
	}
}

int tot;

typedef pair<int,int> pii;

pii cle;

int dfs(int x,int f)
{
	vis[x]=1;
	int ret=-1;
	for(auto v:g[x])
	{
		if(v.first==f)
			continue;
		int r=dfs(v.first,x);
		if(r!=-1)
			ret=r;
	}
	if(ret==-1&&f&&isfib[sz[x]]&&isfib[tot-sz[x]])
	{
		cle=(make_pair(x,f));
		return x;
	}
	return ret;
}

int main()
{	
	fib[0]=1,fib[1]=1;
	isfib[1]=1;
	for(int i=1;;i++)
	{
		fib[i+1]=fib[i]+fib[i-1];
		if(fib[i+1]>=N)
			break;
		isfib[fib[i+1]]=1;
	}
	scanf("%d",&n);
	if(!isfib[n])
	{
		puts("NO");
		return 0;
	}
	int m=n-1;
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u][v]=1;
		g[v][u]=1;
	}
	while(m)
	{
		for(int i=1;i<=n;i++)
			vis[i]=0;
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				getsz(i,0);
				if(sz[i]==1)
					continue;
				tot=sz[i];
				int p=dfs(i,0);
				if(p==-1)
				{
					puts("NO");
					return 0;
				}
				g[cle.first].erase(cle.second);
				g[cle.second].erase(cle.first);
				m--;
			}
	}
	puts("YES");
}