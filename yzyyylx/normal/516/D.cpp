#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define lg 18
#define INF 0x3f3f3f3f3f3f3f3f
#define N 100100
using namespace std;

ll n,m,bb,first[N],mx[N][2],d[N],son[N],gen,fa[N][20],cf[N],ans[N];
struct Bn
{
	ll to,next,quan;
}bn[N<<1];

inline void add(ll u,ll v,ll w)
{
	bb++;
	bn[bb].to=v;
	bn[bb].quan=w;
	bn[bb].next=first[u];
	first[u]=bb;
}

void get(ll now,ll last)
{
	ll p,q,t;
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		if(bn[p].to==last) continue;
		get(bn[p].to,now);
		t=mx[bn[p].to][0]+bn[p].quan;
		if(t>mx[now][0]) mx[now][1]=mx[now][0],mx[now][0]=t,son[now]=bn[p].to;
		else mx[now][1]=max(mx[now][1],t);
	}
}

void g2(ll now,ll last,ll sum)
{
	ll p,q;
	d[now]=max(d[now],mx[now][0]);
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		if(bn[p].to==last) continue;
		d[bn[p].to]=max(d[bn[p].to],sum+bn[p].quan);
		if(bn[p].to==son[now])
		{
			d[bn[p].to]=max(d[bn[p].to],mx[now][1]+bn[p].quan);
			g2(bn[p].to,now,max(sum,mx[now][1])+bn[p].quan);
		}
		else
		{
			d[bn[p].to]=max(d[bn[p].to],mx[now][0]+bn[p].quan);
			g2(bn[p].to,now,max(sum,mx[now][0])+bn[p].quan);
		}
	}
}

void dfs(ll now,ll last)
{
	ll p,q;
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		if(bn[p].to==last) continue;
		fa[bn[p].to][0]=now;
		dfs(bn[p].to,now);
	}
}

inline ll find(ll u,ll v)
{
	ll i,yu=u;
	for(i=lg;i>=0&&u;i--)
	{
		if(d[yu]-d[fa[u][i]]<=v) u=fa[u][i];
	}
	return fa[u][0];
}

ll Dfs(ll now,ll last)
{
	ll p,q,t=cf[now];
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		if(bn[p].to==last) continue;
		t+=Dfs(bn[p].to,now);
	}
	ans[now]=t;
	return t;
}

int main()
{
	memset(first,-1,sizeof(first));
	ll i,j,p,q,o;
	cin>>n;
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld%lld",&p,&q,&o);
		add(p,q,o),add(q,p,o);
	}
	get(1,0);
	g2(1,0,0);
//	for(i=1;i<=n;i++) cout<<d[i]<<" ";
	p=INF;
	for(i=1;i<=n;i++)
	{
		if(d[i]<p)
		{
			p=d[i];
			gen=i;
		}
	}
	dfs(gen,-1);
	for(i=1;i<=lg;i++)
	{
		for(j=1;j<=n;j++)
		{
			fa[j][i]=fa[fa[j][i-1]][i-1];
		}
	}
//	cout<<gen;return 0;
	d[0]=-INF;
	cin>>m;
	for(i=1;i<=m;i++)
	{
		memset(ans,0,sizeof(ans));
		memset(cf,0,sizeof(cf));
		scanf("%lld",&p);
		for(j=1;j<=n;j++)
		{
			q=find(j,p);
			cf[j]++,cf[q]--;
		}
		Dfs(gen,-1);
		q=0;
		for(j=1;j<=n;j++)
		{
			q=max(q,ans[j]);
		}
		printf("%lld\n",q);
	}
}