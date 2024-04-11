#include<bits/stdc++.h>
#define ll long long
#define Ul unsigned long long
#define INF 0x3f3f3f3f3f3f3f3f
#define N 100100
using namespace std;
 
ll T,n,m,tt,num[N],qz[N];
struct Node
{
	ll ls,rs,mn,mx;
}node[N<<1];
 
void build(ll now,ll l,ll r)
{
	if(l==r)
	{
		node[now].mn=node[now].mx=qz[l];
		return;
	}
	ll mid=((l+r)>>1);
	node[now].ls=++tt;
	build(tt,l,mid);
	node[now].rs=++tt;
	build(tt,mid+1,r);
	node[now].mn=min(node[node[now].ls].mn,node[node[now].rs].mn);
	node[now].mx=max(node[node[now].ls].mx,node[node[now].rs].mx);
}
 
ll ask(ll now,ll l,ll r,ll u,ll v)
{
	if(u<=l && r<=v) return node[now].mx;
	ll res=-INF,mid=((l+r)>>1);
	if(u<=mid) res=max(res,ask(node[now].ls,l,mid,u,v));
	if(mid<v) res=max(res,ask(node[now].rs,mid+1,r,u,v));
	return res;
}
 
ll ask2(ll now,ll l,ll r,ll u,ll v)
{
	if(u<=l && r<=v) return node[now].mn;
	ll res=INF,mid=((l+r)>>1);
	if(u<=mid) res=min(res,ask2(node[now].ls,l,mid,u,v));
	if(mid<v) res=min(res,ask2(node[now].rs,mid+1,r,u,v));
	return res;
}
 
int main()
{
	ll i,j,p,q,t;
	cin>>n>>m;
	for(i=1;i<=n;i++) scanf("%lld",&num[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&t);
		num[i]-=t;
		qz[i]=qz[i-1]+num[i];
	}
//	for(i=1;i<=n;i++) cout<<" "<<qz[i];puts("");
	build(tt=1,1,n);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&p,&q);
		if(qz[q]-qz[p-1])
		{
			puts("-1");
			continue;
		}
		t=ask(1,1,n,p,q)-qz[p-1];
//		cout<<t<<endl;
		if(t>0)
		{
			puts("-1");
			continue;
		}
		printf("%lld\n",qz[p-1]-ask2(1,1,n,p,q));
	}
}