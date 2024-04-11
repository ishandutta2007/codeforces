#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#define IN inline
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
using namespace std;
inline int getint()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int mod=998244353;
const int maxn=2e5+5;
ll inv[maxn],fac[maxn],invf[maxn];
ll n,m,d[maxn],a,b;
ll pre[maxn];
inline ll qpow(ll x,ll k)
{
	ll ret=1;
	while(k)
	{
		if(k&1)ret=ret*x%mod;
		x=(x*x)%mod,k>>=1;
	}
	return ret;
}
int main()
{
	n=getint(),m=getint();
	FOR(i,1,n)d[i]=getint();
	inv[0]=inv[1]=1;
	fac[0]=fac[1]=invf[0]=invf[1]=1;
	FOR(i,2,n)fac[i]=(fac[i-1]*i)%mod,inv[i]=((mod-mod/i)*inv[mod%i])%mod,invf[i]=(invf[i-1]*inv[i])%mod;
	sort(d+1,d+n+1);
	FOR(i,1,n)pre[i]=pre[i-1]+d[i],pre[i]%=mod;
	ll temp=0;
	FOR(i,1,m)
	{
		a=getint(),b=getint();
		ll l=1,r=n,ret=0;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(d[mid]<b)ret=mid,l=mid+1;
			else r=mid-1;
		}
		ll sum=(pre[n]-pre[ret]+mod)%mod,ans=0;
		ll cnt=n-ret;
		if(cnt<a)printf("0\n");
		else
		{
			ans=(invf[cnt]*fac[a]%mod)*fac[cnt-a]%mod;
			ans=((ans*fac[cnt-1])%mod*invf[cnt-a-1])%mod;
			ans=(ans*invf[a])%mod;
			ans=(ans*sum)%mod;
			ans+=((pre[ret]*(cnt+1-a))%mod*inv[cnt+1])%mod; 
			ans%=mod;
			printf("%lld\n",ans%mod);
		}
	}
	return 0;
}///