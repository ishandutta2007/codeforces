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
const int maxn=5e5+5;
int m,n;
char s[maxn],t[maxn];
int val[maxn]; 
inline void init()
{
	srand(time(0));
	FOR(i,1,26)val[i]=i;
	random_shuffle(val+1,val+27);
}
inline void input()
{
	n=gi();
	scanf("%s",s);
	FOR(i,0,n-1)t[i]=s[i];
}
bool vis[maxn]; 
inline void solve()
{
	poly v1(n),v2(n),v3(n),v4(n),v5(n),v6(n);
	reverse(s,s+n);
	FOR(i,0,n-1)s[i]=s[i]=='?'?0:val[(int)(s[i]-'A'+1)];
	FOR(i,0,n-1)t[i]=t[i]=='?'?0:val[(int)(t[i]-'A'+1)];
	FOR(i,0,n-1)v1[i]=s[i]*s[i]*s[i];
	FOR(i,0,n-1)v2[i]=t[i];
	FOR(i,0,n-1)v3[i]=s[i]*s[i];
	FOR(i,0,n-1)v4[i]=t[i]*t[i];
	FOR(i,0,n-1)v5[i]=s[i];
	FOR(i,0,n-1)v6[i]=t[i]*t[i]*t[i];
	poly ans=v1*v2;
	ans=ans-poly{2}*v3*v4;
	ans=ans+v5*v6;
	vector<int>now;
	FOR(i,1,n)vis[i]=0;
	FOR(i,n,2*n-1)if(ans[i]==0)vis[i-n+2]=1;
	FOR(i,1,n)
	{
		int j=i+1;
		bool ok=1;
		while(j<=n)
		{
			if(!vis[j])
			{
				ok=0;
				break;
			}
			j+=i;
		}
		if(ok)now.pb(i);
	}
	printf("%d\n",sz(now));
	for(int x:now)printf("%d ",x);
	puts("");
}
int main()
{
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