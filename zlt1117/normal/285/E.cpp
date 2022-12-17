//#pragma GCC optimize(4)
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
const int maxn=1005,mod=1e9+7;
ll dp[maxn][maxn][2][2];/// 
int inv[maxn],fac[maxn],n,m;
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
inline void getinv()
{
	inv[0]=inv[1]=fac[0]=fac[1]=1;
	FOR(i,2,maxn-1)fac[i]=1ll*fac[i-1]*i%mod,inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,maxn-1)inv[i]=1ll*inv[i-1]*inv[i]%mod;
}
inline int C(int n,int m)
{
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
inline void init()
{
	getinv();
}
inline void input()
{
	n=gi(),m=gi();
}
inline void solve()
{
	dp[1][0][0][0]=1;
	dp[1][1][1][0]=1;
	FOR(i,2,n)
	{
		dp[i][0][0][0]=1;
		FOR(j,1,i)
		{///next current
			dp[i][j][0][0]=(dp[i-1][j][0][0]+dp[i-1][j][0][1]+dp[i-1][j-1][0][0])%mod;
			dp[i][j][0][1]=(dp[i-1][j][1][0]+dp[i-1][j-1][1][0]+dp[i-1][j][1][1])%mod;
			dp[i][j][1][0]=(dp[i-1][j-1][0][0]+dp[i-1][j-1][0][1])%mod;
			dp[i][j][1][1]=(dp[i-1][j-1][1][1]+dp[i-1][j-1][1][0])%mod;
		}
	}
	ll ans=0;
	FOR(i,m,n)
	{
		ll sum=((i-m)%2==0)?1:-1;
		sum=sum*C(i,m)%mod;
		sum=(sum*(dp[n][i][0][0]+dp[n][i][0][1]))%mod;
		sum=sum*fac[n-i]%mod;
		ans=(ans+sum)%mod;
	}
	ans=(ans%mod+mod)%mod;///!!! 
	printf("%lld\n",ans);
}
int main()
{
	int T=1;
	//T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}