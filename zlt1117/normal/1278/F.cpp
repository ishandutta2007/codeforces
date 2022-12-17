#pragma GCC optimize("Ofast")
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
#define db double
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
const int mod=998244353,maxn=5005;
int n,m,k;
inline int qpow(int x,int k)
{
	int ret=1;
	while(k)
	{
		if(k&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;k>>=1;
	}
	return ret;
}
int s[maxn][maxn],inv[maxn],fac[maxn],invf[maxn];
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi(),k=gi();
	fac[0]=inv[0]=fac[1]=inv[1]=invf[1]=invf[0]=1;
	FOR(i,2,min(n,k))inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,min(n,k))fac[i]=1ll*fac[i-1]*i%mod,invf[i]=1ll*invf[i-1]*inv[i]%mod; 
}
inline void solve()
{
	int p=qpow(m,mod-2);
	s[0][0]=1;
	FOR(i,1,k)
	{
		FOR(j,1,k)
		{
			s[i][j]=(s[i-1][j-1]+1ll*s[i-1][j]*j%mod)%mod;
		}
	}
	int ans=0,now=1;
	FOR(j,0,k)
	{
		ans=(ans+1ll*s[k][j]*now%mod*qpow(p,j)%mod)%mod;
		now=1ll*now*(n-j)%mod;
	}
	printf("%d\n",ans);
}
int main()
{
	int T=1;
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}