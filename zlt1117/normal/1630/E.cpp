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
const int maxn=1e6+5,mod=998244353;
int n,a[maxn],cnt[maxn],fac[maxn],inv[maxn],invf[maxn];
int ans1[maxn],ans2[maxn];
inline void init()
{
	FOR(i,1,n)ans1[i]=ans2[i]=cnt[i]=0;
}
inline void input()
{
	n=gi();
	FOR(i,1,n)
	{
		a[i]=gi();
		cnt[a[i]]++;
	}
}
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
inline void solve()
{
	int S=0;
	FOR(i,1,n)S=__gcd(S,cnt[i]);
	int answ1=0,answ2=0;
	fac[0]=fac[1]=inv[0]=inv[1]=invf[0]=invf[1]=1;
	FOR(i,2,n)fac[i]=1ll*i*fac[i-1]%mod;
	FOR(i,2,n)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,n)invf[i]=1ll*invf[i-1]*inv[i]%mod;
	vector<int>c;
	FOR(i,1,n)if(cnt[i]!=0)c.pb(cnt[i]);
	if(sz(c)==1)return puts("1"),void();
	FOR(i,1,n)
	{
		int x=i,s=n/x;
		if(S%s!=0||n%i)continue;
		int sum=1,res=x,ans1=0,ans2=0;
		for(int x:c)sum=1ll*sum*C(res,x/s)%mod,res-=x/s;
		ans1=(ans1+sum)%mod; 
		FOR(i,0,sz(c)-1)
		{
			if(c[i]<2)continue;
			int now=1ll*sum*qpow(C(x,c[i]/s),mod-2)%mod*C(x-2,c[i]/s-2)%mod;
			ans2=(ans2+1ll*now*n)%mod;
		}
		::ans1[i]=ans1,::ans2[i]=(1ll*n*ans1%mod+mod-ans2%mod)%mod;
	}
	FOR(i,1,n)answ1=(answ1+ans1[__gcd(n,i)])%mod,answ2=(answ2+ans2[__gcd(n,i)])%mod;
	answ1=1ll*answ1*qpow(n,mod-2)%mod,answ2=1ll*answ2*qpow(n,mod-2)%mod;
	int ans=1ll*answ2*qpow(answ1,mod-2)%mod;
	printf("%d\n",ans);
}
int main()
{
	int T=gi();
	while(T--)
	{
		init(); 
		input();
		solve();
	}
	return 0;
}