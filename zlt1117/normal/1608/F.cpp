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
const int maxn=2005,maxk=25,mod=998244353;
int dp[2][maxn*2][maxn],pre[2][maxn*2][maxn],now,last;
int fac[maxn],inv[maxn],invf[maxn],n,b[maxn],l[maxn],r[maxn],k;
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
inline int C(int n,int m)
{
	if(n<0||m<0||n<m)return 0;
	return 1ll*fac[n]*invf[m]%mod*invf[n-m]%mod;
}
inline void input()
{
	n=gi();k=gi();FOR(i,1,n)b[i]=gi();
	FOR(i,1,n)l[i]=max(0,b[i]-k),r[i]=min(n,b[i]+k);
	fac[0]=fac[1]=inv[0]=inv[1]=invf[0]=invf[1]=1;
	FOR(i,2,n)fac[i]=1ll*i*fac[i-1]%mod;
	FOR(i,2,n)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,n)invf[i]=1ll*invf[i-1]*inv[i]%mod;
}
inline void solve()
{
	dp[now][0][0]=1;pre[now][0][0]=1;
	FOR(i,1,n)
	{
		now=now^1,last=now^1;
		for(int j=i;j>=0;--j)
		{
			FOR(k,l[i],r[i])
			{
				///dp[i][j+k][k]
				int &nval=dp[now][j+k][k];
				nval=(nval+1ll*(j+k)*dp[last][j+k][k])%mod;
				if(j+k)nval=(nval+dp[last][j+k-1][k])%mod;
				if(j+k&&k)///must become k-1 and lower
				{
					///-1 because a_i=mex
					int val=pre[last][j+k-1][k-1];
					if(k-1>=r[i-1])val=pre[last][j+k-1][r[i-1]];
					//val=0;
					//FOR(kk,l[i-1],min(k-1,r[i-1]))val=(val+1ll*dp[last][j+k-1][kk]*fac[j+k-kk-1])%mod;
					nval=(nval+1ll*val*invf[j])%mod;
				}
				pre[now][j+k][k]=1ll*dp[now][j+k][k]*fac[j]%mod;
				if(k)pre[now][j+k][k]=(pre[now][j+k][k]+pre[now][j+k][k-1])%mod;
			}
		}
		FOR(j,0,i-1)FOR(k,l[i-1],r[i-1])dp[last][j+k][k]=pre[last][j+k][k]=0;
	}
	int ans=0;
	FOR(j,0,n)FOR(k,l[n],r[n])
	{
		int val=dp[now][j+k][k];
		ans=(ans+1ll*fac[n-k]*invf[n-k-j]%mod*val)%mod;
	}
	printf("%d\n",ans);
}
int main()
{
	input();
	solve();
	return 0;
}