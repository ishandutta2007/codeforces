#include<bits/stdc++.h>
#define ll long long
#define LG 16
#define N 100100
#define MN 100000
using namespace std;

ll n,m,num[N],cnt[N],qzc[N],qzs[N];

namespace Get
{
    ll g[N][20];
    inline ll gcd(ll u,ll v)
    {
	for(;u&&v&&u!=v;)
	{
	    swap(u,v);
	    u%=v;
	}
	return max(u,v);
    }
    void work()
    {
	ll i,j,k,t,l;
	for(i=1;i<=n;i++) g[i][0]=num[i];
	for(i=1;i<=LG;i++)
	{
	    for(j=1;j+(1 << (i-1))<=n;j++)
	    {
		g[j][i]=gcd(g[j][i-1],g[j+(1 << (i-1))][i-1]);
	    }
	}
	for(i=1;i<=n;i++)
	{
	    for(j=l=i,t=num[i];j<=n;)
	    {
		t=gcd(t,num[j]);
		for(k=LG;k>=0;k--)
		{
		    if((j+(1 << k))>n+1) continue;
		    if(g[j][k]%t==0)
		    {
			j+=(1 << k);
		    }
		}
		cnt[t]+=j-l;
		l=j;
	    }
	}
    }
}

ll f(ll a,ll b,ll c,ll n)
{
    if(n<0) return 0;
    if(!a) return b/c*(n+1);
    if(a>=c || b>=c) return f(a%c,b%c,c,n)+a/c*n*(n+1)/2+b/c*(n+1);
    ll m=(a*n+b)/c;
    return m*n-f(c,c-b-1,a,m-1);
}

inline ll ask(ll a,ll b,ll c)
{
    if(c<0) return 0;
    return c/a+1+f(a,c%a,b,c/a);
}

inline ll solve(ll a,ll ca,ll b,ll cb,ll c)
{
    if(a*(ca-1)+b*(cb-1)<=c) return ca*cb;
    if(c<0) return 0;
//    cerr<<a<<" "<<ca<<" "<<b<<' '<<cb<<' '<<c<<" "<<ask(a,b,c)-ask(a,b,c-a*ca)-ask(a,b,c-b*cb)+ask(a,b,c-a*ca-b*cb)<<endl;
    return ask(a,b,c)-ask(a,b,c-a*ca)-ask(a,b,c-b*cb)+ask(a,b,c-a*ca-b*cb);
}

inline ll calc(ll u)
{
    ll i,j,l,r,t,res=0;
    for(i=1;i<=MN;i++)
    {
	if(!cnt[i]) continue;
	t=min(cnt[i],u/i);
	res+=cnt[i]*t-t*(t-1)/2;
    }
//    cout<<res<<endl;
    for(l=r=1;l<MN;l++)
    {
	if(!cnt[l]) continue;
	if(l<r) res+=cnt[l]*(qzc[r-1]-qzc[l]);
	for(;r<=MN&&qzs[r]-qzs[l]<=u;r++)
	{
	    if(l!=r && cnt[r])
	    {
//		cerr<<l<<" "<<r<<" "<<solve(l,cnt[l],r,cnt[r],u-(qzs[r-1]-qzs[l])-l-r)<<endl;
		res+=solve(l,cnt[l],r,cnt[r],u-(qzs[r-1]-qzs[l])-l-r);
	    }
	}
	if(r<=MN)
	{
//	    cerr<<l<<" "<<r<<endl;
	    if(l!=r && cnt[r])
	    {
//		cerr<<l<<" "<<r<<" "<<solve(l,cnt[l],r,cnt[r],u-(qzs[r-1]-qzs[l])-l-r)<<endl;
		res+=solve(l,cnt[l],r,cnt[r],u-(qzs[r-1]-qzs[l])-l-r);
	    }
	}
    }
    return res;
}

int main()
{
    ll i,j,l,r,mid;
    cin>>n;
    for(i=1;i<=n;i++)
    {
	scanf("%lld",&num[i]);
    }
    Get::work();
//    for(i=1;i<=20;i++) cout<<i<<' '<<cnt[i]<<endl;
    m=(n+1)*n/2;
    m=(m+1)*m/2;
    m=(m+1)/2;
    for(i=1;i<=MN;i++)
    {
	qzc[i]=qzc[i-1]+cnt[i];
	qzs[i]=qzs[i-1]+cnt[i]*i;
    }
//    cout<<calc(12)<<endl;return 0;
    for(l=1,r=qzs[MN]+1;l<r;)
    {
	mid=((l+r)>>1);
	if(calc(mid)<m) l=mid+1;
	else r=mid;
    }
    cout<<l;
}