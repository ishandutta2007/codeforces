#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define C ch=getchar()
#define N 200100
#define M 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

ll n,m,a[N],b[N],c[N];
char ch;

inline ll lb(ll u){return u&(-u);}
inline void add(ll u,ll v){for(;u<=m;u+=lb(u)) c[u]+=v;}
inline ll ask(ll u){ll res=0;for(;u;u-=lb(u)) res+=c[u];return res;}

inline bool judge(ll u)
{
    memset(c,0,sizeof(c));
    ll i,j,t;
    for(i=1;i<=n;i++)
    {
	for(j=0;;j++)
	{
	    t=(a[i]+j*u)/b[i]+1;
	    if(t>=m) break;
	    add(t,1);
	    if(ask(t)>t) return 0;
	}
    }
    for(i=1;i<m;i++) if(ask(i)>i) return 0;
    return 1;
}

inline ll read()
{
    for(C;ch<'0';C);
    static ll res;
    res=ch-'0';
    for(C;ch>='0';res=res*10+ch-'0',C);
    return res;
}

int main()
{
    ll i,j,p,q,l,r,mid;
    cin>>n>>m;
    for(i=1;i<=n;i++) a[i]=read();
    for(i=1;i<=n;i++) b[i]=read();
    for(l=0,r=1e13;l<r;)
    {
	mid=((l+r)>>1);
	if(judge(mid)) r=mid;
	else l=mid+1;
    }
    if(l<1e13) cout<<l;
    else puts("-1");
}