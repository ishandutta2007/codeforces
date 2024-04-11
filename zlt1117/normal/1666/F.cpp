#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define gc getchar()
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
const int maxn=5005,mod=998244353;
int dp[maxn][maxn];
int n,a[maxn],cnt[maxn],fac[maxn],invf[maxn];
inline void init()
{
	FOR(i,0,n)cnt[i]=0;
	FOR(i,0,n)FOR(j,0,n)dp[i][j]=0;
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi(),cnt[a[i]]++;
	FOR(i,1,n)cnt[i]+=cnt[i-1];
	fac[0]=1;
	FOR(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
	invf[0]=invf[1]=1;
	FOR(i,2,n)invf[i]=1ll*(mod-mod/i)*invf[mod%i]%mod;
	FOR(i,2,n)invf[i]=1ll*invf[i-1]*invf[i]%mod;
}
inline void solve()
{
	if(n==2)
	{
		if(a[1]==a[2])puts("0");
		else puts("1");
		return ;
	}
	FOR(i,1,n)dp[1][i]=1ll*cnt[i-1]*(cnt[i-1]-1)%mod*(cnt[i]-cnt[i-1])%mod;
	FOR(i,1,n)dp[1][i]=(dp[1][i-1]+dp[1][i])%mod;
	FOR(i,2,n/2)
	{
		FOR(j,1,n)if(cnt[j-1]>=i*2-1)dp[i][j]=1ll*dp[i-1][j-1]*(cnt[j]-cnt[j-1])%mod;
		FOR(j,1,n)if(i!=n/2)dp[i][j]=1ll*dp[i][j]*(cnt[j-1]-i*2+1)%mod;
		FOR(j,1,n)dp[i][j]=(dp[i][j-1]+dp[i][j])%mod;
	}
	int ans=dp[n/2][n];
	FOR(i,1,n)ans=1ll*ans*invf[cnt[i]-cnt[i-1]]%mod;
	printf("%d\n",ans);
}
int main()
{
//	freopen("F.in","r",stdin);
	int T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}