#include<bits/stdc++.h>
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define N 300100
using namespace std;

ll n,ans,tt,num[N],pos[N];
P gg[5];
struct Node
{
    ll ls,rs,dw;
    P mn,m2;
    void add(ll u){dw+=u,mn.fi+=u,m2.fi+=u;}
}node[N<<1];

inline void up(ll now)
{
    ll i,L=node[now].ls,R=node[now].rs;
    gg[0]=node[L].mn,gg[1]=node[L].m2;
    gg[2]=node[R].mn,gg[3]=node[R].m2;
    sort(gg,gg+4);
    node[now].mn=gg[0];
    for(i=1;i<4;i++)
    {
	if(gg[i].fi!=gg[0].fi) break;
	node[now].mn.se+=gg[i].se;
    }
    if(i<4)
    {
	node[now].m2=gg[i];
	for(i++;i<4;i++)
	{
	    if(gg[i].fi!=node[now].m2.fi) break;
	    node[now].m2.se+=gg[i].se;
	}
    }
    else node[now].m2=mp(INF,0);
}

inline void down(ll now)
{
    ll L=node[now].ls,R=node[now].rs;
    if(node[now].dw)
    {
	node[L].add(node[now].dw);
	node[R].add(node[now].dw);
	node[now].dw=0;
    }
}

void build(ll now,ll l,ll r)
{
    if(l==r)
    {
	node[now].mn=mp(0,1);
	node[now].m2=mp(INF,0);
	return;
    }
    ll mid=((l+r)>>1);
    node[now].ls=++tt;
    build(tt,l,mid);
    node[now].rs=++tt;
    build(tt,mid+1,r);
    up(now);
}

void add(ll now,ll l,ll r,ll u,ll v,ll w)
{
    if(u<=l&&r<=v)
    {
	node[now].add(w);
	return;
    }
    down(now);
    ll mid=((l+r)>>1);
    if(u<=mid) add(node[now].ls,l,mid,u,v,w);
    if(mid<v) add(node[now].rs,mid+1,r,u,v,w);
    up(now);
}

ll ask(ll now,ll l,ll r,ll u,ll v)
{
    if(u<=l&&r<=v)
    {
	ll res=0;
	if(node[now].mn.fi<=2) res+=node[now].mn.se;
	if(node[now].m2.fi<=2) res+=node[now].m2.se;
	return res;
    }
    down(now);
    ll res=0,mid=((l+r)>>1);
    if(u<=mid) res+=ask(node[now].ls,l,mid,u,v);
    if(mid<v) res+=ask(node[now].rs,mid+1,r,u,v);
    return res;
}

void out(ll now,ll l,ll r)
{
    if(l==r)
    {
	cout<<node[now].mn.fi<<" ";
	return;
    }
    down(now);
    ll mid=((l+r)>>1);
    out(node[now].ls,l,mid);
    out(node[now].rs,mid+1,r);
}

void Out(ll now,ll l,ll r)
{
//    cout<<l<<" "<<r<<": "<<node[now].mn.fi<<"("<<node[now].mn.se<<") "<<node[now].m2.fi<<"("<<node[now].m2.se<<")"<<endl;
    if(l==r) return;
    down(now);
    ll mid=((l+r)>>1);
    Out(node[now].ls,l,mid);
    Out(node[now].rs,mid+1,r);
}

int main()
{
    ll i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    {
	scanf("%lld",&num[i]);
	pos[num[i]]=i;
    }
    build(tt=1,1,n);
    for(i=1;i<=n;i++)
    {
	add(1,1,n,1,i,1);
	if(pos[i]>1&&num[pos[i]-1]<i) add(1,1,n,1,num[pos[i]-1],-1);
	if(pos[i]<n&&num[pos[i]+1]<i) add(1,1,n,1,num[pos[i]+1],-1);
//	if(i>1) cerr<<" "<<ask(1,1,n,1,i-1)<<endl;
	if(i>1) ans+=ask(1,1,n,1,i-1);
//	Out(1,1,n);
//	out(1,1,n);puts("");
    }
    cout<<ans;
}