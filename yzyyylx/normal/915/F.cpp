#include<bits/stdc++.h>
#define ll long long
#define N 1001000
using namespace std;

ll n,ans,num[N],pos[N],fa[N],size[N];
vector<ll>to[N];

inline bool cmp(ll u,ll v){return num[u]<num[v];}
ll ff(ll u){return u==fa[u]?u:fa[u]=ff(fa[u]);}
inline ll calc()
{
    ll i,j,k,t,res=0;
    for(i=1;i<=n;i++) fa[i]=i,size[i]=1;
    for(j=1;j<=n;j++)
    {
	i=pos[j];
	for(k=0;k<to[i].size();k++)
	{
	    t=ff(to[i][k]);
	    if(t==ff(i) || num[t]>num[i]) continue;
	    res+=size[ff(i)]*size[t]*num[ff(i)];
	    size[ff(i)]+=size[t];
	    fa[t]=ff(i);
	}
    }
    return res;
}

inline ll Calc()
{
    ll i,j,k,t,res=0;
    for(i=1;i<=n;i++) fa[i]=i,size[i]=1;
    for(j=1;j<=n;j++)
    {
	i=pos[j];
	for(k=0;k<to[i].size();k++)
	{
	    t=ff(to[i][k]);
	    if(t==ff(i) || num[t]<num[i]) continue;
	    res+=size[ff(i)]*size[t]*num[ff(i)];
	    size[ff(i)]+=size[t];
	    fa[t]=ff(i);
	}
    }
    return res;
}

int main()
{
    ll i,j,p,q;
    cin>>n;
    for(i=1;i<=n;i++) scanf("%lld",&num[i]),pos[i]=i;
    for(i=1;i<n;i++)
    {
	scanf("%lld%lld",&p,&q);
	to[p].push_back(q);
	to[q].push_back(p);
    }
    sort(pos+1,pos+n+1,cmp);
//    for(i=1;i<=n;i++) cout<<pos[i]<<"  ";puts("");
    ans+=calc();
    reverse(pos+1,pos+n+1);
    ans-=Calc();
    cout<<ans;
}