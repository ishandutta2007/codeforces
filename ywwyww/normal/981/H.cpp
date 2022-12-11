#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
//using namespace std;
using std::min;
using std::max;
using std::swap;
using std::sort;
using std::reverse;
using std::random_shuffle;
using std::lower_bound;
using std::upper_bound;
using std::unique;
using std::vector;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
void open(const char *s){
#ifndef ONLINE_JUDGE
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
int rd(){int s=0,c,b=0;while(((c=getchar())<'0'||c>'9')&&c!='-');if(c=='-'){c=getchar();b=1;}do{s=s*10+c-'0';}while((c=getchar())>='0'&&c<='9');return b?-s:s;}
void put(int x){if(!x){putchar('0');return;}static int c[20];int t=0;while(x){c[++t]=x%10;x/=10;}while(t)putchar(c[t--]+'0');}
int upmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
int upmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
const ll p=998244353;
const int N=100010;
ll fp(ll a,ll b)
{
	ll s=1;
	for(;b;b>>=1,a=a*a%p)
		if(b&1)
			s=s*a%p;
	return s;
}
namespace ntt
{
	const int N=300000;
	const int W=1<<18;
	ll plus(ll a,ll b){a+=b;return a>=p?a-p:a;}
	ll minus(ll a,ll b){a-=b;return a>=0?a:a+p;}
	ll w[N];
	int rev[N];
	void ntt(ll *a,int n,int t)
	{
		for(int i=1;i<n;i++)
		{
			rev[i]=(rev[i>>1]>>1)|(i&1?n>>1:0);
			if(rev[i]>i)
				swap(a[i],a[rev[i]]);
		}
		for(int i=0;i<n;i++)
			a[i]=plus(a[i],p);
		for(int i=2;i<=n;i<<=1)
			for(int j=0;j<n;j+=i)
				for(int k=0;k<i/2;k++)
				{
					ll u=a[j+k];
					ll v=a[j+k+i/2]*w[W/i*k]%p;
					a[j+k]=plus(u,v);
					a[j+k+i/2]=minus(u,v);
				}
		if(t==-1)
		{
			reverse(a+1,a+n);
			ll inv=fp(n,p-2);
			for(int i=0;i<n;i++)
				a[i]=a[i]*inv%p;
		}
	}
	void init()
	{
		ll s=fp(3,(p-1)/W);
		w[0]=1;
		for(int i=1;i<W/2;i++)
			w[i]=w[i-1]*s%p;
	}
	void mul(ll *a,ll *b,ll *c,int n,int m,int l)
	{
		static ll a1[N],a2[N];
		int k=1;
		while(k<=n+m)
			k<<=1;
		for(int i=0;i<k;i++)
			a1[i]=a2[i]=0;
		for(int i=0;i<=n;i++)
			a1[i]=a[i];
		for(int i=0;i<=m;i++)
			a2[i]=b[i];
		ntt(a1,k,1);
		ntt(a2,k,1);
		for(int i=0;i<k;i++)
			a1[i]=a1[i]*a2[i]%p;
		ntt(a1,k,-1);
		for(int i=0;i<=l;i++)
			c[i]=a1[i];
	}
	void mul2(ll *a,ll *b,ll *c,ll *d,ll *e,int n,int m,int l)
	{
		static ll a1[N],a2[N],a3[N],a4[N];
		int k=1;
		while(k<=n+m)
			k<<=1;
		for(int i=0;i<k;i++)
			a1[i]=a2[i]=a3[i]=a4[i]=0;
		for(int i=0;i<=n;i++)
		{
			a1[i]=a[i];
			a3[i]=c[i];
		}
		for(int i=0;i<=m;i++)
		{
			a2[i]=b[i];
			a4[i]=d[i];
		}
		ntt(a1,k,1);
		ntt(a2,k,1);
		ntt(a3,k,1);
		ntt(a4,k,1);
		for(int i=0;i<k;i++)
			a1[i]=a1[i]*a2[i]%p;
		for(int i=0;i<k;i++)
			a3[i]=a3[i]*a4[i]%p;
		ntt(a1,k,-1);
		ntt(a3,k,-1);
		for(int i=0;i<=l;i++)
			e[i]=(a1[i]+a3[i])%p;
	}
}
vector<int> g[N];
int s[N];
int n,k;
ll ans=0;
ll fac[N];
ll ifac[N];
void init()
{
	fac[0]=1;
	for(int i=1;i<=k;i++)
		fac[i]=fac[i-1]*i%p;
	ifac[k]=fp(fac[k],p-2);
	for(int i=k;i>=1;i--)
		ifac[i-1]=ifac[i]*i%p;
}
ll binom(int x,int y)
{
	return x>=y&&y>=0?fac[x]*ifac[y]%p*ifac[x-y]%p:0;
}
ll f1[N];
ll f2[N];
ll c[N];
ll d[N];
int l;
typedef std::pair<ll*,ll*> _;
_ solve(int l,int r)
{
	_ s;
	if(l==r)
	{
		s.first=new ll[2];
		s.second=new ll[2];
		s.first[0]=1;
		s.first[1]=c[l];
		s.second[0]=d[l];
		s.second[1]=d[l]*c[0]%p;
		return s;
	}
	int mid=(l+r)>>1;
	_ ls=solve(l,mid);
	_ rs=solve(mid+1,r);
	s.first=new ll[r-l+2];
	s.second=new ll[r-l+2];
	ntt::mul(ls.first,rs.first,s.first,mid-l+1,r-mid,r-l+1);
	ntt::mul2(ls.second,rs.first,ls.first,rs.second,s.second,mid-l+1,r-mid,r-l+1);
	return s;
}
void dfs(int x,int fa)
{
	s[x]=1;
	for(auto v:g[x])
		if(v!=fa)
		{
			dfs(v,x);
			s[x]+=s[v];
			ans=(ans+f2[x]*f2[v])%p;
			f2[x]=(f2[x]+f2[v])%p;
		}
	if(s[x]==1)
	{
		f1[x]=f2[x]=1;
		return;
	}
	l=0;
	for(auto v:g[x])
		if(v!=fa)
		{
			c[++l]=s[v];
			d[l]=f2[v];
		}
	c[0]=n-s[x];
	_ e=solve(1,l);
	for(int i=0;i<=l&&i<=k;i++)
	{
		f1[x]=(f1[x]+e.first[i]*binom(k,i)%p*fac[i])%p;
		ans=(ans+e.second[i]*binom(k,i)%p*fac[i])%p;
	}
	f2[x]=(f2[x]+f1[x])%p;
}
int main()
{
	ntt::init();
	open("cf981h");
	scanf("%d%d",&n,&k);
	if(k==1)
	{
		printf("%I64d\n",(ll)n*(n-1)/2%p);
		return 0;
	}
	init();
	int x,y;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	printf("%I64d\n",ans);
	return 0;
}