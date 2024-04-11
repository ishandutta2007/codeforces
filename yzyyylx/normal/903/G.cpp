#include<bits/stdc++.h>
#define ll long long
#define N 200100
using namespace std;

ll n,m,Q,bb,tt,a[N],b[N],first[N],num[N];
struct Bn
{
    ll to,next,quan;
}bn[N];
struct Node
{
    ll ls,rs,mn,sum;
}node[N<<1];
struct Pq
{
    priority_queue<ll,vector<ll>,greater<ll> >a,b;
    void push(ll u){a.push(u);}
    void del(ll u){b.push(u);}
    void cle(){for(;!b.empty() && a.top()==b.top();a.pop(),b.pop());}
    ll top(){cle();return a.top();}
}pq;

inline void ad(ll u,ll v,ll w)
{
    bb++;
    bn[bb].to=v;
    bn[bb].quan=w;
    bn[bb].next=first[u];
    first[u]=bb;
}

inline void up(ll u)
{
    ll L=node[u].ls,R=node[u].rs;
    node[u].mn=min(node[L].mn,node[R].mn)+node[u].sum;
}

void build(ll now,ll l,ll r)
{
    if(l==r)
    {
//	cerr<<' '<<now<<" "<<l<<" "<<b[l]<<endl;
	node[now].mn=b[l];
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
        node[now].mn+=w;
        node[now].sum+=w;
        return;
    }
    ll mid=((l+r)>>1);
    if(u<=mid) add(node[now].ls,l,mid,u,v,w);
    if(mid<v) add(node[now].rs,mid+1,r,u,v,w);
    up(now);
}

ll ask(ll now,ll l,ll r,ll u)
{
    if(l==r)
    {
//	cerr<<"   "<<now<<" "<<l<<endl;
	return node[now].mn+node[now].sum;
    }
    ll mid=((l+r)>>1);
    if(u<=mid) return node[now].sum+ask(node[now].ls,l,mid,u);
    return node[now].sum+ask(node[now].rs,mid+1,r,u);
}

void out()
{
    ll i,j;
//    for(i=1;i<=n;i++) ask(1,1,n,i);
    for(i=1;i<=n;i++) cout<<ask(1,1,n,i)<<" ";
    puts("");
}

inline void in(ll u)
{
    ll p,t;
    for(p=first[u];p!=-1;p=bn[p].next)
    {
        t=bn[p].to;
//	cerr<<' '<<1<<' '<<t<<' '<<bn[p].quan<<endl;
//	out();
	add(1,1,n,1,t,bn[p].quan);
//	out();
    }
}

int main()
{
    memset(first,-1,sizeof(first));
    ll i,j,p,q,o;
    cin>>n>>m>>Q;
    for(i=1;i<n;i++)
    {
        scanf("%lld%lld",&a[i],&b[i+1]);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%lld%lld%lld",&p,&q,&o);
        ad(p,q,o);
    }

//    for(i=1;i<=n;i++) cout<<b[i]<<" ";puts("");
    build(tt=1,1,n);
//    out();return 0;
    for(i=1;i<=n;i++)
    {
	in(i);
	num[i]=node[1].mn;
	pq.push(num[i]+a[i]);
    }
//    for(i=1;i<=n;i++) cout<<num[i]<<" ";puts("");return 0;
    cout<<pq.top()<<endl;
    while(Q--)
    {
	scanf("%lld%lld",&p,&q);
	pq.del(num[p]+a[p]);
	a[p]=q;
	pq.push(num[p]+a[p]);
	printf("%lld\n",pq.top());
    }
}