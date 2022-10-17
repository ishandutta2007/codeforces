#include<iostream>
#include<cstdio>
#define ll long long
#define N 600100
using namespace std;

ll n,m,h[N],d[N],sum,tt;
bool sta;
struct Node
{
	ll lp,rp,mx,lx,rx,ls,rs;
}node[N<<1],ans;

inline void up(ll u)
{
	ll L=node[u].ls,R=node[u].rs;
	node[u].lp=node[L].lp;
	node[u].rp=node[R].rp;
	node[u].lx=max(node[L].lx,node[R].lp-node[L].lp+node[R].lx);
	node[u].rx=max(node[R].rx,node[L].rx+node[R].rp-node[L].rp);
	node[u].mx=max(max(node[L].mx,node[R].mx),node[L].rx+node[R].lx+node[R].lp-node[L].rp);
}

inline Node hb(Node L,Node R)
{
	Node res;
	res.lp=L.lp;
	res.rp=R.rp;
	res.lx=max(L.lx,R.lp-L.lp+R.lx);
	res.rx=max(R.rx,L.rx+R.rp-L.rp);
	res.mx=max(max(L.mx,R.mx),L.rx+R.lx+R.lp-L.rp);
	return res;
}

void build(ll now,ll l,ll r)
{
	if(l==r)
	{
		node[now].lx=node[now].rx=h[l]*2;
		node[now].lp=node[now].rp=d[l];
		return;
	}
	ll mid=((l+r)>>1);
	if(l<=mid)
	{
		node[now].ls=++tt;
		build(tt,l,mid);
	}
	if(mid<r)
	{
		node[now].rs=++tt;
		build(tt,mid+1,r);
	}
	up(now);
}

void as(ll now,ll l,ll r,ll u,ll v)
{
	if(l==u&&v==r)
	{
//		printf("%lld: <%lld %lld> mx:[(%lld %lld) %lld] {%lld %lld}\n",now,l,r,node[now].lx,node[now].rx,node[now].mx,node[now].lp,node[now].rp);
		if(sta)
		{
			ans=hb(ans,node[now]);
		}
		else
		{
			ans=node[now];
			sta=1;
		}
//		printf("mx:[(%lld %lld) %lld] {%lld %lld}\n",ans.lx,ans.rx,ans.mx,ans.lp,ans.rp);
		return;
	}
	ll mid=((l+r)>>1);
	if(u<=mid)
	{
		as(node[now].ls,l,mid,u,min(mid,v));
	}
	if(mid<v)
	{
		as(node[now].rs,mid+1,r,max(mid+1,u),v);
	}
}

inline ll ask(ll u,ll v)
{
	sta=0;
	as(1,1,n*2,u,v);
//	printf("mx:[(%lld %lld) %lld] {%lld %lld}\n",ans.lx,ans.rx,ans.mx,ans.lp,ans.rp);
	return ans.mx;
}

void out(ll now,ll l,ll r)
{
//	printf("%lld: <%lld %lld> mx:[(%lld %lld) %lld] {%lld %lld}\n",now,l,r,node[now].lx,node[now].rx,node[now].mx,node[now].lp,node[now].rp);
	if(l==r)
	{
		return;
	}
	ll mid=((l+r)>>1);
	out(node[now].ls,l,mid);
	out(node[now].rs,mid+1,r);
}

int main()
{
	ll i,j,p,q;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&p);
		sum+=p;
		d[i+1]=d[i]+p;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&h[i]);
		h[n+i]=h[i];
	}
	for(i=n+1;i<=n*2;i++) d[i]=d[i-n]+sum;
//	for(i=1;i<=n*2;i++) cout<<d[i]<<" ";return 0;
	build(++tt,1,2*n);
//	out(1,1,2*n);return 0;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&p,&q);
		if(p>q) q+=n;
		printf("%lld\n",ask(q+1,p+n-1));
	}
}