//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
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
const int maxn=3e5+5,mod=998244353;
int a[maxn],n;
ll inv[maxn],fac[maxn];
ll ans;
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,2*n)a[i]=gi();
}
inline void solve()
{
	sort(a+1,a+2*n+1);
	FOR(i,n+1,2*n)ans+=a[i],ans%=mod;
	FOR(i,1,n)ans-=a[i],ans=(ans+mod)%mod;
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	FOR(i,2,2*n)fac[i]=(fac[i-1]*i)%mod,inv[i]=((mod-mod/i)*inv[mod%i])%mod;
	ans=(ans*fac[2*n])%mod;
	FOR(i,1,n)ans=(ans*inv[i])%mod,ans=(ans*inv[i])%mod;
	printf("%lld\n",ans);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}///