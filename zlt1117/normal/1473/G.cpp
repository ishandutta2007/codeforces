#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define A(x) ((x)%mod)
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=2e5+5,mod=998244353,g=3;
int fac[maxn],inv[maxn],n,a[maxn],b[maxn];
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
namespace Poly
{
	typedef vector<int> poly;
	vector<int>rev;
	inline int getlen(int len)
	{
		int bit=0;
		while(1<<bit<len)bit++;
		return 1<<bit;
	}
	inline void calcrev(int len)
	{
		rev.resize(len);
		int bit=0;
		while(1<<bit<len)bit++;
		FOR(i,0,len-1)rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	}
	inline poly dft(poly &a)
	{
		int n=sz(a);
		FOR(i,0,n-1)if(i<rev[i])swap(a[i],a[rev[i]]);
		for(int l=1;l<n;l<<=1)
		{
			int wn=qpow(g,(mod-1)/(l<<1));
			for(int i=0;i<n;i+=l<<1)
			{
				for(int j=0,w=1;j<l;++j,w=1ll*w*wn%mod)
				{
					int v1=a[i+j],v2=1ll*a[i+j+l]*w%mod;
					a[i+j]=(v1+v2)%mod;
					a[i+j+l]=(v1-v2+mod)%mod;
				}
			}
		}
		return a;
	}
	inline poly idft(poly &a)
	{
		reverse(a.begin()+1,a.end());
		dft(a);int inv=qpow(sz(a),mod-2);
		FOR(i,0,sz(a)-1)a[i]=1ll*a[i]*inv%mod;
		return a;
	}
	inline poly mul(poly a,poly b)
	{
		int len=sz(a)+sz(b);
		len=getlen(len);calcrev(len);
		a.resize(len),b.resize(len);
		dft(a),dft(b);
		FOR(i,0,len-1)a[i]=1ll*a[i]*b[i]%mod;
		idft(a);a.resize(len);
		return a;
	}
}
using namespace Poly;
inline void init()
{
	inv[0]=inv[1]=fac[0]=fac[1]=1;
	FOR(i,2,maxn-1)fac[i]=1ll*fac[i-1]*i%mod,inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,maxn-1)inv[i]=1ll*inv[i-1]*inv[i]%mod;
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi(),b[i]=gi();
}
int dp[maxn];
inline void solve()
{
	dp[1]=1;int now=1;
	FOR(i,1,n)
	{
		int len=a[i]-b[i]<0?now:now+a[i]-b[i];
		now+=a[i]-b[i];
 		vector<int>f(dp,dp+len+1);
		vector<int>g(2*len+1);
		int lim=len;
		FOR(j,0,2*len)
		{
			if(b[i]+(j-lim)>=0&&a[i]-(j-lim)>=0)
			{
				int temp=1ll*fac[b[i]+(j-lim)]*fac[a[i]-(j-lim)]%mod;
				g[j]=qpow(temp,mod-2);
			}
		}
		vector<int>ans=mul(f,g);
		FOR(j,1,len)dp[j]=0;
		FOR(j,1,now)dp[j]=1ll*ans[j+lim]*fac[a[i]+b[i]]%mod;
	}
	int ans=0;
	FOR(i,1,now)ans+=dp[i],ans%=mod;
	printf("%d\n",ans);
}
int main()
{
 	int T=1;
//	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}