#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
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
const int maxn=1e6+5,mod=1e9+7; 
int n,k,fac[maxn],inv[maxn];
inline void init()
{
	
}
inline int qpow(int x,int k)
{
	int ret=1;
	while(k)
	{
		if(k&1)ret=1ll*ret*x%mod;
		k>>=1,x=1ll*x*x%mod;
	}
	return ret;
}
inline int C(int n,int m){if(n<m)return 0;if(n<0||m<0)return 0;return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;}
inline void input()
{
	n=gi(),k=gi();
	fac[0]=inv[0]=fac[1]=inv[1]=1;
	FOR(i,2,k+2)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,k+2)fac[i]=1ll*fac[i-1]*i%mod,inv[i]=1ll*inv[i-1]*inv[i]%mod; 
}
inline void solve()
{
	if(n<=k+2)
	{
		int ans=0;
		FOR(i,1,n)ans+=qpow(i,k),ans%=mod;
		printf("%d\n",ans);
	}
	else
	{
		int ans=0;
		int now=0,now2=1;
		FOR(i,1,k+2)now2=1ll*now2*(n-i)%mod;
		FOR(i,1,k+2)
		{
			now=(now+qpow(i,k))%mod;
			int val=now;
			val=1ll*val*now2%mod*qpow(n-i,mod-2)%mod;///upper
			int temp=1ll*fac[i-1]%mod*fac[k+2-i]%mod;
			if((k+2-i)&1)temp=mod-temp;
			val=1ll*val*qpow(temp,mod-2)%mod;
			ans=(ans+val)%mod;
		}
		printf("%d\n",ans);
	}
}
int main()
{
	int T=1;
//	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}