#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

struct C{
	int x,y;
	int fx,fy;
	int p;
}c[N];

int n,m;

vector<int>g[N];

int anc[N][21],dep[N],st[N],ed[N],dc;

void dfs(int x,int f)
{
	st[x]=++dc;
	anc[x][0]=f;
	dep[x]=dep[f]+1;
	for(auto v:g[x])
	{
		if(v==f)
			continue;
		dfs(v,x);
	}
	ed[x]=dc;
}

void pre()
{
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

int getp(int x,int d)
{
	for(int i=20;i>=0;i--)
		if(d>=(1<<i))
			x=anc[x][i],d-=(1<<i);
	return x;
}

long long ans;

vector<C>can[N];

int cnt[N];

void calc(int x,int f)
{
	for(auto v:g[x])
	{
		if(v==f)
			continue;
		calc(v,x);
	}
	int sum=0;
	for(auto v:g[x])
	{
		if(v==f)
			continue;
		for(auto c:can[v])
		{
			assert(cnt[0]==0);
			ans+=sum-cnt[c.fy]-cnt[c.fx];
		}
		for(auto c:can[v])
		{
			sum++;
			if(c.fy)
				cnt[c.fy]++;
		}
	}
}

int dw[N];

vector<C>cad[N];

vector<int>mov[N];

int ps[N];

void ca(int x,int f)
{
	int sc=dw[x];
	for(auto v:g[x])
	{
		if(v==f)
			continue;
		ca(v,x);
		ps[x]+=ps[v];
	}
	for(auto c:mov[x])
		dw[c]--;
	for(auto v:g[x])
	{
		if(v==f)
			continue;
		sc+=dw[v];
	}
	for(auto c:cad[x])
	{
		assert(dw[0]==0);
		ans+=sc-dw[c.fx]-dw[c.fy];
	}
	dw[x]=sc;
}

int vis[N];

vector<int>qry;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	pre();
	scanf("%d",&m);
	st[0]=n+1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&c[i].x,&c[i].y);
		c[i].p=lca(c[i].x,c[i].y);
		if(c[i].x==c[i].y)
		{
			qry.push_back(c[i].x);
			ans+=vis[c[i].x];
			vis[c[i].x]++;
			i--,m--;
			continue;
		}
		ps[c[i].x]++;
		ps[c[i].y]++;
		ps[c[i].p]--;
		ps[anc[c[i].p][0]]--;
		if(c[i].p==c[i].y)
			swap(c[i].x,c[i].y);
		if(c[i].x==c[i].p)
		{
			c[i].fy=getp(c[i].y,dep[c[i].y]-dep[c[i].p]-1);
			dw[c[i].y]++;
			mov[c[i].p].push_back(c[i].fy);
		}
		else
		{
			c[i].fx=getp(c[i].x,dep[c[i].x]-dep[c[i].p]-1);			
			c[i].fy=getp(c[i].y,dep[c[i].y]-dep[c[i].p]-1);	
			dw[c[i].x]++;
			dw[c[i].y]++;
			mov[c[i].p].push_back(c[i].fx);
			mov[c[i].p].push_back(c[i].fy);
		}
		if(st[c[i].fx]>st[c[i].fy])
			swap(c[i].x,c[i].y),swap(c[i].fx,c[i].fy);
		cad[c[i].p].push_back(c[i]);
		can[c[i].fx].push_back(c[i]);
	}
	calc(1,0);
	ca(1,0);
	for(auto x:qry)
		ans+=ps[x];
	printf("%lld\n",ans);
}