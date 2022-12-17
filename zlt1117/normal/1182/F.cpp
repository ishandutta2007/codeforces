//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define gc getchar()
#define int ll
#define mk make_pair
//#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
int a,b,p,q;
inline ll calc(ll n,ll a,ll b,ll c)
{
	if(!a)return (n+1)*(b/c);
	if(a>=c||b>=c)return n*(n+1)/2*(a/c)+(b/c)*(n+1)+calc(n,a%c,b%c,c);
	ll m=(a*n+b)/c;
	return n*m-calc(m-1,c,c-b-1,a);
}
inline void init()
{
	
}
inline void input()
{
	a=gi(),b=gi(),p=gi(),q=gi();
}
inline int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	int g=exgcd(b,a%b,x,y);
	int t=x;x=y;y=t-(a/b)*y;
	return g;
}
inline bool check(ll l,ll r)
{
	ll ret=calc(b,2*p,2*q-l,2*q);
	if(a)ret-=calc(a-1,2*p,2*q-l,2*q);
	ret-=calc(b,2*p,2*q-r-1,2*q);
	if(a)ret+=calc(a-1,2*p,2*q-r-1,2*q);
	return ret>0;
}
inline void solve()
{
	ll P=2*p,Q=2*q;
	ll l=0,r=q,ans=q;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(check(q-mid,q+mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	ll x=0,y=0;
	ll g=exgcd(P,Q,x,y);
	P/=g,Q/=g;
	ll t=ans,t2=x;
	ll answer=1e9;
	if((q+ans)%g==0)
	{
		ans=q+ans;
		x=ans/g*x,y=ans/g*y;
		x%=Q;x=(x%Q-Q)%Q;
		l=0,r=1e9,ans=1e9;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(x+Q*mid>=a)ans=mid,r=mid-1;
			else l=mid+1;
		}
		x+=ans*Q;
		answer=min(answer,x);
	}
	ans=t,x=t2;
	if((q-ans)%g==0)
	{
		ans=q-ans;
		x=ans/g*x,y=ans/g*y;
		x%=Q;x=(x%Q-Q)%Q;
		l=0,r=1e9,ans=1e9;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(x+Q*mid>=a)ans=mid,r=mid-1;
			else l=mid+1;
		}
		x+=ans*Q;
		answer=min(answer,x);
	}
	printf("%lld\n",answer);
}
signed main()
{
	int T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}