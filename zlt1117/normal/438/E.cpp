//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define se second
#define sz(x) (int)(x.size())
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
namespace Poly
{
	const int mod=998244353,G=3;
	typedef vector<int> poly;
	vector<int>rev;
	inline poly get(int x){return poly(1,x);} 
	inline int qpow(int x,int k)
	{
		int ret=1;
		while(k)
		{
			if(k&1)ret=1ll*x*ret%mod;
			x=1ll*x*x%mod,k>>=1;
		}
		return ret;
	}
	int getbit(int len)
	{
		int bit=0;
		while((1<<bit)<len)bit++;
		return bit;
	}
	inline void calcrev(int len)
	{
		int bit=getbit(len);
		rev.resize(len);
		FOR(i,0,len-1)rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	}
	inline void dft(poly &a)
	{
		int len=sz(a);
		FOR(i,0,len-1)if(i<rev[i])swap(a[i],a[rev[i]]);
		for(int l=1;l<len;l<<=1)
		{
			int wn=qpow(G,(mod-1)/(l<<1));
			for(int i=0;i<len;i+=l<<1)
			{
				for(int j=0,w=1;j<l;++j,w=1ll*w*wn%mod)
				{
					int v1=a[i+j],v2=1ll*a[i+j+l]*w%mod;
					a[i+j]=(v1+v2)%mod;a[i+j+l]=(v1-v2+mod)%mod;
				}
			}
		}
	}
	inline void idft(poly &a)
	{
		reverse(a.begin()+1,a.end());
		dft(a);
		int inv=qpow(sz(a),mod-2);
		FOR(i,0,sz(a)-1)a[i]=1ll*a[i]*inv%mod;
	}
	inline poly modxk(poly a,int k)
	{
		k=min(sz(a),k);
		return poly(a.begin(),a.begin()+k);
	}
	inline poly mulxk(poly a,int k)
	{
		poly b=a;
		b.insert(b.begin(),k,0);
		return b;
	}
	inline poly divxk(poly a,int k)
	{
		if(sz(a)<=k)return poly();
		else return poly(a.begin()+k,a.end());
	}
	inline poly operator + (poly a,poly b)
	{
		if(sz(a)<sz(b))swap(a,b);
		FOR(i,0,sz(b)-1)a[i]=(a[i]+b[i])%mod;
		return a;
	}
	inline poly operator - (poly a,poly b)
	{
		int len=max(sz(a),sz(b));
		a.resize(len),b.resize(len);
		FOR(i,0,len-1)a[i]=(a[i]-b[i]+mod)%mod;
		return a;
	}
	inline poly operator * (poly a,poly b)
	{
		int len=sz(a)+sz(b);
		len=1<<getbit(len);
		calcrev(len);
		a.resize(len),b.resize(len);
		dft(a),dft(b);
		FOR(i,0,len-1)a[i]=1ll*a[i]*b[i]%mod;
		idft(a);
		a.resize(len);
		return a; 
	}
	inline poly Inv(poly a,int m)
	{
		poly ret=get(qpow(a[0],mod-2));
		int k=1;
		while(k<m)
		{
			k<<=1,calcrev(k<<1);
			poly f=modxk(ret,k),g=modxk(a,k);
			f.resize(k<<1),g.resize(k<<1);
			dft(f),dft(g);
			ret.resize(k<<1);
			FOR(i,0,(k<<1)-1)ret[i]=1ll*f[i]*(2-1ll*f[i]*g[i]%mod)%mod;
			FOR(i,0,(k<<1)-1)if(ret[i]<0)ret[i]+=mod;
			idft(ret);ret=modxk(ret,k);
		}
		return modxk(ret,m);
	}
	inline poly sqrt(poly a,int m)
	{
		poly ret=get(1);
		int k=1;
		while(k<m)
		{
			k<<=1;
			ret=modxk(ret+modxk(modxk(a,k)*Inv(ret,k),k),k);
			FOR(i,0,sz(ret)-1)ret[i]=1ll*ret[i]*(mod+1)/2%mod; 
		}
		return modxk(ret,m);
	}
}
using namespace Poly;
const int maxn=1e5+5,maxv=1e5;
poly g,f;
int n,m,c[maxn];
inline void init()
{
	
}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)c[i]=gi();
}
inline void solve()
{
	g.resize(maxv+1);
	FOR(i,1,n)g[c[i]]=1;
	FOR(i,0,sz(g)-1)g[i]=4ll*g[i]%mod;
	f=Inv(get(1)+sqrt(get(1)-g,m+1),m+1);
	FOR(i,0,sz(f)-1)f[i]=f[i]*2%mod;
	FOR(i,1,m)printf("%d\n",f[i]);
}
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
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