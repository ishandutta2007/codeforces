#include<bits/stdc++.h>
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 510
using namespace std;

ll m,n,K,x[N],y[N];
struct Cz
{
    ll type,pos;
    P lr;
    bool operator < (const Cz &u) const {return pos<u.pos;}
}cz[N<<1];
multiset<P>se;
multiset<P>::iterator it;

inline bool cmp1(const Cz &u,const Cz &v)
{
    if(u.pos!=v.pos) return u.pos<v.pos;
    return u.type<v.type;
}

inline bool cmp2(const Cz &u,const Cz &v)
{
    if(u.pos!=v.pos) return u.pos>v.pos;
    return u.type<v.type;
}

inline ll check(ll u,ll v,ll w)
{
    ll i,j,r;
    se.clear();
    if(cz[1].pos!=w) return w;
    for(i=1;i<=v;i=j)
    {
	for(j=i;j<=v&&cz[j].pos==cz[i].pos;j++)
	{
	    if(cz[j].type) se.insert(cz[j].lr);
	    else se.erase(se.find(cz[j].lr));
	}
	r=1;
	for(it=se.begin();it!=se.end();it++)
	{
	    if((*it).fi>r) return cz[i].pos;
	    r=max(r,(*it).se+1);
	}
	if(r<=u) return cz[i].pos;
    }
}

inline bool judge(ll u)
{
    ll i,j,p,q,a,b,c,d,L,R,U,D,t=0;
    for(i=1;i<=K;i++)
    {
	a=max(1ll,y[i]-u),b=min(n,y[i]+u);
	c=max(1ll,x[i]-u),d=min(m,x[i]+u);
	cz[++t].type=1,cz[t].pos=a,cz[t].lr=mp(c,d);
	cz[++t].type=0,cz[t].pos=b+1,cz[t].lr=mp(c,d);
    }
    sort(cz+1,cz+t+1);
//    for(i=1;i<=t;i++) cout<<" "<<cz[i].pos<<" "<<cz[i].type<<' '<<cz[i].lr.fi<<" "<<cz[i].lr.se<<endl;
    U=check(m,t,1);
    for(i=1;i<=t;i++)
    {
	cz[i].pos--;
	cz[i].type^=1;
    }
    reverse(cz+1,cz+t+1);
    D=check(m,t,n);

    t=0;
    for(i=1;i<=K;i++)
    {
	a=max(1ll,y[i]-u),b=min(n,y[i]+u);
	c=max(1ll,x[i]-u),d=min(m,x[i]+u);
	cz[++t].type=1,cz[t].pos=c,cz[t].lr=mp(a,b);
	cz[++t].type=0,cz[t].pos=d+1,cz[t].lr=mp(a,b);
    }
    sort(cz+1,cz+t+1);
    L=check(n,t,1);
    for(i=1;i<=t;i++)
    {
	cz[i].pos--;
	cz[i].type^=1;
    }
    reverse(cz+1,cz+t+1);
    R=check(n,t,m);

//    cout<<U<<" "<<D<<" "<<L<<" "<<R<<endl;
    return (max(R-L,D-U)+1)/2<=u;
}

int main()
{
    ll i,j,l,r,mid;
    cin>>m>>n>>K;
    for(i=1;i<=K;i++)
    {
	scanf("%lld%lld",&x[i],&y[i]);
    }
//    cout<<judge(0);return 0;
    for(l=0,r=1e9;l<r;)
    {
	mid=((l+r)>>1);
//	cerr<<l<<' '<<r<<" "<<mid<<endl;
	if(judge(mid)) r=mid;
	else l=mid+1;
    }
    cout<<l;
}