#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int T,n,ans[N];

vector<int>g[N];

int dep[N],anc[N][21],sz[N],st[N],ed[N],dc;

void dfs(int x,int f)
{
	st[x]=++dc;
	anc[x][0]=f;
	dep[x]=dep[f]+1;
	sz[x]=1;
	for(auto v:g[x])
	{
		if(v==f)
			continue;
		dfs(v,x);
		sz[x]+=sz[v];
	}
	ed[x]=dc;
}

void pre()
{
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n;i++)
			anc[i][j]=0;
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n;i++)
			anc[i][j]=anc[anc[i][j-1]][j-1];
}

int lca(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=20;i>=0;i--)
		if(dep[x]-(1<<i)>=dep[y])
			x=anc[x][i];
	if(x==y)
		return x;
	for(int i=20;i>=0;i--)
		if(anc[x][i]!=anc[y][i])
			x=anc[x][i],y=anc[y][i];
	return anc[x][0];
}

int get(int x)
{
	for(int i=20;i>=0;i--)
		if(dep[x]-(1<<i)>=2)
			x=anc[x][i];
	return x;
}

signed main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			g[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%lld%lld",&u,&v);
			++u,++v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		int p=1,q=1;
		for(int i=0;i<=n+1;i++)
			ans[i]=0;
		ans[0]=1ll*n*(n-1)/2;
		for(auto v:g[1])
			ans[1]+=sz[v]*(n-1-sz[v])+sz[v]*2;
		ans[1]/=2;
		pre();
		for(int i=2;i<=n;i++)
		{
			int x=lca(p,i),y=lca(q,i);
			if(p==1&&q==1)
			{
				q=i;
				ans[i]=sz[q]*(n-sz[get(q)]);
			}
			else if(p==1)
			{
				if(y==i)
					ans[i]=sz[q]*(n-sz[get(q)]);
				else if(y==q)
				{
					q=i;
					ans[i]=sz[q]*(n-sz[get(q)]);
				}
				else if(st[i]<st[get(q)]||st[i]>ed[get(q)])
				{
					p=i;
					ans[i]=sz[p]*sz[q];
				}
				else
					break;
			}
			else
			{
				if(x==i||y==i)
					ans[i]=sz[p]*sz[q];
				else if(x==p||y==q)
				{
					if(x==p)
						p=i;
					if(y==q)
						q=i;
					ans[i]=sz[p]*sz[q];
				}
				else
					break;
			}
		}
		for(int i=0;i<=n;i++)
			ans[i]-=ans[i+1];
		for(int i=0;i<=n;i++)
			printf("%lld%c",ans[i]," \n"[i==n]);
	}
}