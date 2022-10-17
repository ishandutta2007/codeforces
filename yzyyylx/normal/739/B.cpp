#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define N 200100
using namespace std;

ll bb,n,m,dn[N],fa[N][20],d[N][20],ans[N][20],an[N],first[N];
struct Bn
{
	ll to,next;
}bn[N*2];

inline void add(ll u,ll v)
{
	bb++;
	bn[bb].to=v;
	bn[bb].next=first[u];
	first[u]=bb;
}

void add(ll now,ll bs,ll dq)
{
	ll i,j;
	for(i=bs;i>=0;i--)
	{
		if(!fa[now][i]) continue;
		if(d[now][i]<=dq)
		{
			ans[now][i]++;
			add(fa[now][i],i-1,dq-d[now][i]);
			return;
		}
	}
}

inline void jk(ll u)
{
	ll i;
	for(i=19;i>=1;i--)
	{
		if(ans[u][i])
		{
			ans[u][i-1]+=ans[u][i];
			ans[fa[u][i-1]][i-1]+=ans[u][i];
		}
	}
	an[fa[u][0]]+=ans[u][0];
}

void dfs(ll now,ll last)
{
	ll p,q;
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		if(bn[p].to==last) continue;
		dfs(bn[p].to,now);
	}
	jk(now);
}

int main()
{
	memset(first,-1,sizeof(first));
	register ll i,j,p,q;
	cin>>n;
	for(i=1;i<=n;i++)
		scanf("%lld",&dn[i]);
	for(i=2;i<=n;i++)
	{
		scanf("%lld%lld",&p,&q);
		fa[i][0]=p;
		d[i][0]=q;
		add(i,p);
		add(p,i);
	}
	for(i=1;(1 << i)<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(!fa[fa[j][i-1]][i-1]) continue;
			fa[j][i]=fa[fa[j][i-1]][i-1];
			d[j][i]=d[j][i-1]+d[fa[j][i-1]][i-1];
		}
	}
	for(i=1;i<=n;i++)
	{
		add(i,19,dn[i]);
	}
	dfs(1,-1);
	for(i=1;i<=n;i++)
	{
		printf("%lld ",an[i]);
	}
}