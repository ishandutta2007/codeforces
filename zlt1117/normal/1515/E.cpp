//#pragma GCC optimize("Ofast")
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
const int maxn=405;
int dp[maxn][maxn],n,mod,fac[maxn],inv[maxn],pw[maxn];
///dp[i][k] in space i choose k computers
inline void init()
{

}
inline void input()
{
	n=gi(),mod=gi();
	fac[0]=fac[1]=inv[0]=inv[1]=pw[0]=1;
	FOR(i,1,n)pw[i]=2ll*pw[i-1]%mod;
	FOR(i,2,n)fac[i]=1ll*fac[i-1]*i%mod,inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,n)inv[i]=1ll*inv[i-1]*inv[i]%mod;
}
inline int C(int n,int m){return n<m?0:1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;}
inline void solve()
{
	int ans=0;
	FOR(i,1,n)
	{
		if(i!=1)dp[i][i-1]=pw[i-2];
		FOR(j,1,i-2)///last empty computer
		{
			int now=i-j-1;
			FOR(k,1,j)
			{
				dp[i][k+now]=(dp[i][k+now]+1ll*dp[j][k]*C(k+now,k)%mod*pw[now-1]%mod)%mod;
			}
		}
		if(i==n)continue;
		FOR(j,1,i-1)ans=1ll*dp[i][j]*pw[n-i-1]%mod*C(n-i+j,j)%mod+ans,ans%=mod;
		//cerr<<i<<" "<<ans<<endl;
	}
	ans=(ans+pw[n-1])%mod;
	//cerr<<ans<<endl;
	printf("%d\n",ans);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}