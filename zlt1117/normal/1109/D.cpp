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
inline void chkmax(int &x,int y){if(x<y)x=y;}
inline void chkmin(int &x,int y){if(x>y)x=y;}
const int maxn=2e6+5,mod=1e9+7;
int fac[maxn],inv[maxn],invf[maxn];
inline int qpow(int x,int k)
{
	if(k<0)return qpow(x,mod-1+k);
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
int n,m,a,b;
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi();a=gi(),b=gi();
	fac[0]=fac[1]=inv[0]=inv[1]=invf[0]=invf[1]=1;
	FOR(i,2,n+m)fac[i]=1ll*i*fac[i-1]%mod;
	FOR(i,2,n+m)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,n+m)invf[i]=1ll*invf[i-1]*inv[i]%mod;
}
inline void solve()
{
	int ans=0;
	FOR(i,1,n)
	{
		int sum=1ll*C(n-2,i-1)*C(m-1,i-1)%mod*fac[i-1]%mod;
		sum=1ll*sum*qpow(m,n-i-1)%mod*qpow(n,n-i-2)%mod*(i+1)%mod;
		ans=(ans+sum)%mod;
	}
	printf("%d\n",ans);
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