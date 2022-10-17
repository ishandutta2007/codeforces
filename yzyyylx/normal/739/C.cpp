#include<iostream>
#include<cstdio>
#define ll long long
#define mid ((l+r)>>1)
#define N 300100
using namespace std;

ll n,m,num[N],tt=1;
struct Node
{
	ll ls,rs,lm,rm,mx,ln,rn,len;
};
Node node[N<<1];

inline bool lj(ll u,ll v){return u>0&&v||u<0&&v<0;}

inline void up(ll now)
{
	ll u=node[now].ls,v=node[now].rs;
	if(!u||!v)
	{
		node[now]=node[u+v];
		return;
	}
	node[now].ln=node[u].ln;
	node[now].rn=node[v].rn;
	node[now].len=node[u].len+node[v].len;
	node[now].mx=max(node[u].mx,node[v].mx);
	if(lj(node[u].rn,node[v].ln))
	{
		if(node[u].lm==node[u].len) node[now].lm=node[u].lm+node[v].lm;
		else node[now].lm=node[u].lm;
		if(node[v].rm==node[v].len) node[now].rm=node[v].rm+node[u].rm;
		else node[now].rm=node[v].rm;
		node[now].mx=max(node[now].mx,node[u].rm+node[v].lm);
	}
	else
	{
		node[now].lm=node[u].lm;
		node[now].rm=node[v].rm;
	}
}

void build(ll now,ll l,ll r)
{
	if(l==r)
	{
		if(num[l]) node[now].lm=node[now].rm=node[now].mx=1;
		node[now].ln=node[now].rn=num[l];
		node[now].len=1;
		return;
	}
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

void chg(ll now,ll l,ll r,ll u)
{
	if(l==r)
	{
		if(num[u]) node[now].lm=node[now].rm=node[now].mx=1;
		node[now].ln=node[now].rn=num[u];
		return;
	}
	if(u<=mid) chg(node[now].ls,l,mid,u);
	else chg(node[now].rs,mid+1,r,u);
	up(now);
}

void out(ll now,ll l,ll r)
{
	printf("%lld <%lld %lld> {%lld %lld} [%lld %lld] &%lld& |-%lld-|\n",now,l,r,node[now].ln,node[now].rn,node[now].lm,node[now].rm,node[now].mx,node[now].len);
	if(l==r) return;
	if(l<=mid) out(node[now].ls,l,mid);
	if(mid<r) out(node[now].rs,mid+1,r);
}

int main()
{
	ll i,j,p,q,o;
	cin>>n;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&num[i]);
	}
	n--;
	for(i=n;i>=1;i--) num[i]-=num[i-1];
	build(1,1,n);
//	for(i=1;i<=n;i++) cout<<num[i]<<" ";puts("");
//	out(1,1,n);puts("");
//	cout<<node[1].mx<<endl;
	cin>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&p,&q,&o);
		if(p>1) num[p-1]+=o,chg(1,1,n,p-1);
		if(q<=n) num[q]-=o,chg(1,1,n,q);
		printf("%lld\n",node[1].mx+1);
//		puts("");for(j=1;j<=n;j++) cout<<num[j]<<" ";puts("");
	}
}