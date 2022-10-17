#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define LG 16
#define N 200100
using namespace std;

ll n,m,first[N],deep[N],dep[N],fa[N][20],d[50][N],num[N],bb=1,cnt,Q,ans;
bool vis[N],in[N];
struct Bn
{
	ll to,next,quan;
}bn[N<<1];
priority_queue<P,vector<P>,greater<P> >pq;

inline void add(ll u,ll v,ll w)
{
	bb++;
	bn[bb].to=v;
	bn[bb].next=first[u];
	bn[bb].quan=w;
	first[u]=bb;
}

void dfs(ll now)
{
	ll p,q;
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		if(deep[bn[p].to]) continue;
		vis[p>>1]=1;
		fa[bn[p].to][0]=now;
		deep[bn[p].to]=deep[now]+bn[p].quan;
		dep[bn[p].to]=dep[now]+1;
		dfs(bn[p].to);
	}
}

inline ll lca(ll u,ll v)
{
	if(dep[u]<dep[v]) swap(u,v);
	ll i,j;
	for(i=LG;dep[u]!=dep[v];i--)
	{
		if(dep[fa[u][i]]>=dep[v])
		{
			u=fa[u][i];
		}
	}
	for(i=LG;i>=0;i--)
	{
		if(fa[u][i]!=fa[v][i])
		{
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	if(u!=v) u=fa[u][0];
	return u;
}

inline ll dis(ll u,ll v)
{
	ll l=lca(u,v);
	return deep[u]-deep[l]*2+deep[v];
}

inline void get(ll u,ll v)
{
	ll i,j,p,q,a,b;
	P tmp;
	pq.push(mp(0,u));
	d[v][u]=0;
	for(;!pq.empty();)
	{
		tmp=pq.top();
		pq.pop();
		a=tmp.fi,b=tmp.se;
		if(a>d[v][b]) continue;
		for(p=first[b];p!=-1;p=bn[p].next)
		{
			if(d[v][bn[p].to]<=a+bn[p].quan) continue;
			d[v][bn[p].to]=a+bn[p].quan;
			pq.push(mp(d[v][bn[p].to],bn[p].to));
		}
	}
}

int main()
{
	memset(d,0x3f,sizeof(d));
	memset(first,-1,sizeof(first));
	ll i,j,p,q,o;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&p,&q,&o);
		add(p,q,o);
		add(q,p,o);
	}
	deep[1]=dep[1]=1;
	dfs(1);
	for(i=1;i<=LG;i++)
	{
		for(j=1;j<=n;j++)
		{
			fa[j][i]=fa[fa[j][i-1]][i-1];
		}
	}
	
	for(i=2;i<=bb;i+=2)
	{
		if(vis[(i>>1)]) continue;
		p=bn[i].to;
		if(!in[p])
		{
			num[++cnt]=p;
			in[p]=1;
			get(p,cnt); 
		}
		p=bn[i+1].to;
		if(!in[p])
		{
			num[++cnt]=p;
			in[p]=1;
			get(p,cnt); 
		}
	}
	
	cin>>Q;
	for(i=1;i<=Q;i++)
	{
		scanf("%lld%lld",&p,&q);
		ans=dis(p,q);
		for(j=1;j<=cnt;j++)
		{
			ans=min(ans,dis(p,num[j])+d[j][q]);
		}
		printf("%lld\n",ans);
	}
}