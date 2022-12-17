#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define pb push_back
#define sz(x) (int)(x.size())
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=2e5+5,mod=998244353;
int n,k,a[maxn];
int aa,b;
ll inv[maxn],fac[maxn];
inline void init()
{

}
inline void input()
{
	n=gi(),k=gi();
	if(n==1){printf("0\n");exit(0);}
	FOR(i,1,n)a[i]=gi();a[n+1]=a[1];
	FOR(i,1,n){if(a[i]==a[i+1])aa++;else b++;}
	inv[0]=fac[0]=inv[1]=fac[1]=1;
	FOR(i,2,200000)fac[i]=fac[i-1]*i%mod,inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,200000)inv[i]=inv[i-1]*inv[i]%mod;
}
inline ll C(int x,int y){if(x<y)return 0;return (fac[x]*inv[y]%mod)*inv[x-y]%mod;}
inline ll qpow(ll x,ll k)
{
	ll ret=1;
	while(k)
	{
		if(k&1)ret=(ret*x)%mod;
		x=(x*x)%mod,k>>=1;
	}
	return ret;
}
inline void solve()
{
	ll ans=0;
	FOR(i,1,b)
	{
		ll sum=C(b,b-i)*qpow(k-2,b-i)%mod;
		ll now=0;
		if(i%2==0)now=qpow(2,i)-C(i,i/2);
		else now=qpow(2,i);
		now=(now+mod)%mod;
		sum=(sum*now)%mod;
		ans+=sum*inv[2]%mod;
		ans%=mod;	
	} 
	ans=(ans*qpow(k,aa))%mod;
	printf("%lld\n",ans);
}
int main()
{
//	T=gi();
//	while(T--)
//	{
		init();
		input();
		solve();
//	}
	return 0;
}