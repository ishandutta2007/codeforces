//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define int ll
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=1e5+5,mod=1e9+7;
int dp[maxn],sum,n,k;
inline int qpow(int x,int k)
{
	int ret=1;
	while(k)
	{
		if(k&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,k>>=1;
	}
	return ret;
}
int fac[maxn],inv[maxn];
inline void init()
{
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	FOR(i,2,maxn-1)fac[i]=1ll*fac[i-1]*i%mod,inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,maxn-1)inv[i]=1ll*inv[i-1]*inv[i]%mod;
}
inline int C(int n,int m){return m<0||n<0||n<m?0:1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;}
inline void input()
{
	n=gi(),k=gi();
}
inline void solve()
{
	int ans=0;
	FOR(i,1,n)dp[i]=C(n-k*(i-1)+i-1,i),dp[i]=dp[i]*fac[i]%mod*fac[n-i]%mod;
	FOR(i,1,n)
	{
		dp[i]=(dp[i]-dp[i+1]+mod)%mod;
		ans+=dp[i]*i%mod;
		ans%=mod;
	}
	ans=ans*inv[n]%mod;ans=(ans+1)%mod;
	printf("%lld\n",ans);
}
signed main()
{
	int T=1;
	T=gi();
	init();
	while(T--)
	{
		input();
		solve();
	}
	return 0;
}