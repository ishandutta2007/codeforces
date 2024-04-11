#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
    int x=0,f=1;char ch=gc;
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
    return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=1e6+5,mod=998244353;
int n,a[maxn];
ll fac[maxn],inv[maxn],dp[maxn],pre[maxn];
inline void init()
{
	
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
	sort(a+1,a+n+1);
	inv[1]=inv[0]=fac[1]=fac[0]=1;
	FOR(i,2,n)fac[i]=(fac[i-1]*i)%mod,inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,n)inv[i]=(inv[i]*inv[i-1])%mod;
}
inline void solve()
{
	sort(a+1,a+n+1);
	if(a[n]<a[n-1]*2){printf("0\n");return;}///!!!
	int now=0;
	dp[0]=1,pre[0]=fac[n-1];//now=-1
	FOR(i,1,n)
	{
		while(2*a[now]<=a[i]&&now<=i)++now;--now;
		dp[i]=(dp[i]+inv[n-now-1]*pre[now]%mod)%mod;
		pre[i]=(pre[i-1]+fac[n-now-2]*dp[i]%mod)%mod;
	}
	printf("%lld\n",dp[n]);
}
int main()
{
	input();
	init();
	solve();
	return 0;
}
///