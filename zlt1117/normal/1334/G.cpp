#pragma GCC optimize("Ofast")
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
const int mod=998244353;
namespace Poly
{
	const int G=3;
	typedef vector<int> poly;
	vector<int>rev;
	inline int qpow(int x,int k)
	{
		int ret=1;
		while(k)
		{
			if(k&1)ret=1ll*x*ret%mod;
			k>>=1,x=1ll*x*x%mod;
		}
		return ret;
	}
	inline int getbit(int len)
	{
		int bit=0;
		while(1<<bit<len)bit++;
		return bit;
	}
	inline void calcrev(int len)
	{
		rev.resize(len);
		int bit=getbit(len);
		FOR(i,0,len-1)rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	}
	inline void dft(poly &a)
	{
		int n=sz(a);
		FOR(i,0,n-1)if(i<rev[i])swap(a[i],a[rev[i]]);
		for(int l=1;l<n;l<<=1)
		{
			int wn=qpow(G,(mod-1)/(l<<1));
			for(int i=0;i<n;i+=l<<1)
			{
				int w=1;
				for(int j=0;j<l;++j,w=1ll*w*wn%mod)
				{
					int v1=a[i+j],v2=1ll*a[i+j+l]*w%mod;
					a[i+j]=(v1+v2)%mod;
					a[i+j+l]=(v1-v2+mod)%mod;
				}
			}
		}
	}
	inline void idft(poly &a)
	{
		int n=sz(a);
		reverse(a.begin()+1,a.end());
		dft(a);
		int inv=qpow(n,mod-2);
		FOR(i,0,n-1)a[i]=1ll*a[i]*inv%mod;
	}
	inline poly operator * (poly a,poly b)
	{
		int len=sz(a)+sz(b),l=len;
		len=1<<getbit(len);calcrev(len);
		a.resize(len),b.resize(len);
		dft(a),dft(b);
		FOR(i,0,len-1)a[i]=1ll*a[i]*b[i]%mod;
		idft(a);
		a.resize(l-1);
		return a;
	}
	inline poly operator + (poly a,poly b)
	{
		if(sz(a)>sz(b))swap(a,b);
		FOR(i,0,sz(a)-1)b[i]=(b[i]+a[i])%mod;
		return b;
	}
	inline poly operator - (poly a,poly b)
	{
		FOR(i,0,sz(b)-1)b[i]=(mod-b[i])%mod;
		return a+b;
	}
}
using namespace Poly;
const int maxn=2e5+5;
int m,n;
char ss[maxn],tt[maxn];
int val[maxn],s[maxn],t[maxn]; 
inline void init()
{
	srand(time(0));
	FOR(i,1,26)val[i]=i;
	random_shuffle(val+1,val+27);
}
int p[maxn],pre[maxn],id[maxn];
inline void input()
{
	FOR(i,1,26)p[i]=gi();
	scanf("%s",tt);scanf("%s",ss);
	m=strlen(tt),n=strlen(ss);
	FOR(i,0,n-1)s[i]=ss[i]-'a'+1;
	FOR(i,0,m-1)t[i]=tt[i]-'a'+1;
	FOR(i,1,26)id[i]=i;
}
inline void solve()
{
	poly v1(n),v2(n),ans;
	reverse(t,t+m);
	FOR(i,0,n-1)pre[i]=1ll*val[s[i]]*val[s[i]]%mod*s[i]%mod*s[i]%mod;
	FOR(i,1,n-1)pre[i]=(pre[i-1]+pre[i])%mod;
	FOR(i,0,n-1)v1[i]=1ll*(mod-2ll)*val[s[i]]%mod*val[s[i]]%mod*s[i]%mod;FOR(i,0,m-1)v2[i]=p[t[i]];ans=ans+v1*v2;
	v1.clear(),v2.clear();v1.resize(n),v2.resize(m);
	FOR(i,0,n-1)v1[i]=1ll*val[s[i]]*val[s[i]]%mod;FOR(i,0,m-1)v2[i]=1ll*p[t[i]]*p[t[i]]%mod;ans=ans+v1*v2;
	v1.clear(),v2.clear();v1.resize(n),v2.resize(m);
	FOR(i,0,n-1)v1[i]=1ll*(mod-2ll)*val[s[i]]*s[i]%mod*s[i]%mod;FOR(i,0,m-1)v2[i]=val[t[i]]%mod;ans=ans+v1*v2;
	v1.clear(),v2.clear();v1.resize(n),v2.resize(m);
	FOR(i,0,n-1)v1[i]=4ll*val[s[i]]*s[i]%mod;FOR(i,0,m-1)v2[i]=1ll*p[t[i]]*val[t[i]]%mod;ans=ans+v1*v2;
	v1.clear(),v2.clear();v1.resize(n),v2.resize(m);
	FOR(i,0,n-1)v1[i]=1ll*(mod-2ll)*val[s[i]]%mod;FOR(i,0,m-1)v2[i]=1ll*p[t[i]]*val[t[i]]%mod*p[t[i]]%mod;ans=ans+v1*v2;
	v1.clear(),v2.clear();v1.resize(n),v2.resize(m);
	FOR(i,0,n-1)v1[i]=1ll*s[i]*s[i]%mod;FOR(i,0,m-1)v2[i]=1ll*val[t[i]]*val[t[i]]%mod;ans=ans+v1*v2;
	v1.clear(),v2.clear();v1.resize(n),v2.resize(m);
	FOR(i,0,n-1)v1[i]=1ll*(mod-2ll)*s[i]%mod;FOR(i,0,m-1)v2[i]=1ll*p[t[i]]*val[t[i]]%mod*val[t[i]]%mod;ans=ans+v1*v2;
	v1.clear(),v2.clear();v1.resize(n),v2.resize(m);
	ll value=0;FOR(i,0,m-1)value=(value+1ll*p[t[i]]*val[t[i]]%mod*p[t[i]]%mod*val[t[i]])%mod;
	FOR(i,m-1,n-1)
	{
		ll now=(value+ans[i])%mod;
		now=(now+pre[i])%mod;
		if(i!=m-1)now=(now+mod-pre[i-m])%mod;
		if(now==0)putchar('1');
		else putchar('0');
	}
	puts("");
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
/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
a
a
*/