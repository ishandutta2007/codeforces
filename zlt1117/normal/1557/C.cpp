//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
#define mk make_pair
#define iter set<int>::iterator
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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=2e5+5,mod=1e9+7;
int n,k;
int dp[maxn][2],fac[maxn],inv[maxn];
inline void init()
{
	FOR(i,0,k)dp[i][0]=dp[i][1]=0;
}
inline void input()
{
	n=gi(),k=gi();
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	FOR(i,2,n)fac[i]=1ll*i*fac[i-1]%mod,inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,n)inv[i]=1ll*inv[i-1]*inv[i]%mod;
}
inline void solve()
{
	dp[0][0]=1;
	int sum=0;
	FOR(i,0,n-1)if(i%2==0)sum=(sum+1ll*fac[n]*inv[i]%mod*inv[n-i])%mod;
	int temp=1;
	FOR(i,1,n)temp=temp*2%mod; 
	FOR(i,1,k)
	{
		dp[i][1]=(dp[i][1]+1ll*temp*dp[i-1][1])%mod;
		///case1:all1
		if(n%2==1)dp[i][0]=(dp[i][0]+dp[i-1][0])%mod;
		else dp[i][1]=(dp[i][1]+dp[i-1][0])%mod;
		dp[i][0]=(dp[i][0]+1ll*sum*dp[i-1][0])%mod;
	}
	printf("%d\n",(dp[k][0]+dp[k][1])%mod);
}
int main()
{
	int T=1;
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}