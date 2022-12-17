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
const int maxn=1e6+5,mod=1e9+7;
int fac[maxn],inv[maxn],invf[maxn],n,m,k;
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
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi(),k=gi();
}
inline void solve()
{
	int ans=0;
	FOR(i,0,m)ans=(ans+1ll*C(n-i-1,m-i)*qpow(inv[2],n-i)%mod*i%mod*k)%mod;
	if(n==m)ans=1ll*n*k%mod;
	printf("%d\n",ans);
}
int main()
{
	fac[0]=fac[1]=inv[0]=inv[1]=invf[0]=invf[1]=1;
	FOR(i,2,maxn-1)fac[i]=1ll*i*fac[i-1]%mod;
	FOR(i,2,maxn-1)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,maxn-1)invf[i]=1ll*invf[i-1]*inv[i]%mod;
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