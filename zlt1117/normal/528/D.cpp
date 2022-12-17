#pragma GCC optimize(2)
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
const int maxn=3e5+5;
namespace Poly
{
	typedef vector<int> poly;
	const int mod=998244353,g=3;
	vector<int>rev,roots;
	inline void prep()
	{
		roots.pb(0),roots.pb(1);
	}
	inline int qpow(int x,int k)
	{
		int ret=1;
		while(k)
		{
			if(k&1)ret=1ll*ret*x%mod;
			x=1ll*x*x%mod,k>>=1;
		}
		return ret;
	}
	inline int getlen(int x)
	{
		int bit=0;
		while((1<<bit)<x)bit++;
		return 1<<bit;
	}
	inline void calcrev(int x)
	{
		if(sz(rev)==x)return ;
		int bit=0;while(1<<bit<x)bit++;x=1<<bit;
		rev.resize(x);
		FOR(i,0,x-1)rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
		if(sz(roots)<x)
		{
			int l=sz(roots);roots.resize(x);
			for(;l<x;l<<=1)
			{
				int w=1,wn=qpow(g,(mod-1)/(2*l));
				for(int j=0;j<l;++j)
				{
					roots[l+j]=w;
					w=1ll*w*wn%mod;
				}	
			}	
		}	
	}
	inline void dft(poly &a)
	{
		int len=getlen(sz(a));
		FOR(i,0,len-1)if(i<rev[i])swap(a[i],a[rev[i]]);
		for(int l=1;l<len;l<<=1)
		{
			for(int i=0;i<len;i+=l<<1)
			{
				for(int j=0;j<l;++j)
				{
					int v1=a[i+j],v2=1ll*a[i+j+l]*roots[j+l]%mod;
					a[i+j]=v1+v2,a[i+j+l]=v1-v2;
					if(a[i+j]>=mod)a[i+j]-=mod;
					if(a[i+j+l]<0)a[i+j+l]+=mod;
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
	inline poly operator + (poly a,poly b)
	{
		int len=max(sz(a),sz(b));
		a.resize(len),b.resize(len);
		FOR(i,0,len-1)a[i]=a[i]+b[i],a[i]-=(a[i]>=mod)?mod:0;
		return a;
	}
	inline poly operator - (poly a,poly b)
	{
		int len=max(sz(a),sz(b));
		a.resize(len),b.resize(len);
		FOR(i,0,len-1)a[i]=a[i]-b[i],a[i]+=(a[i]<0)?mod:0;
		return a;
	}
	inline poly operator * (poly a,poly b)
	{
		int len=sz(a)+sz(b);
		len=getlen(len);a.resize(len),b.resize(len);
		calcrev(len);
		dft(a),dft(b);
		FOR(i,0,len-1)a[i]=1ll*a[i]*b[i]%mod;
		idft(a);a.resize(len);return a;
	}
}
using namespace Poly;
char s[maxn],t[maxn];
int n,m,k,cnt[maxn];
inline void init()
{
	prep();
}
inline void input()
{
	n=gi(),m=gi(),k=gi();
	scanf("%s%s",s,t);
}
bool vis[maxn];
inline void solve1(char x)
{	
	memset(vis,0,sizeof(vis));
	poly v1,v2;
	v1.resize(n),v2.resize(m);
	reverse(t,t+m);
	FOR(i,0,n-1)v1[i]=s[i]==x?1:2;
	FOR(i,0,m-1)v2[i]=t[i]==x?1:0;
	set<int>s;FOR(i,0,n-1)if(v1[i]==1)s.insert(i);
	FOR(i,0,n-1)
	{
		auto it=s.lower_bound(i);
		if(it!=s.end()&&(*it)-i<=k)v1[i]=1;
		if(it!=s.begin()){it--;if(i-(*it)<=k)v1[i]=1;}
	}
	reverse(t,t+m);
	poly v3=v1;FOR(i,0,n-1)v3[i]=1ll*v1[i]*v1[i]*v1[i]%mod;
	poly v4=v2;FOR(i,0,m-1)v4[i]=1ll*v2[i]*v2[i]*v2[i]%mod;
	poly ans=v1*v4+v2*v3;
	poly sum;
	poly v5=v1;FOR(i,0,n-1)v5[i]=1ll*v1[i]*v1[i]*2%mod;
	poly v6=v2;FOR(i,0,m-1)v6[i]=1ll*v2[i]*v2[i]%mod;
	sum=v5*v6;
	ans=ans-sum;
	FOR(i,m-1,n-1)cnt[i-m+1]+=ans[i]==0;
}
inline void solve()
{
	int ans=0;
	solve1('A'),solve1('C'),solve1('G'),solve1('T');
	FOR(i,0,n-m+1)ans+=cnt[i]==4;
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