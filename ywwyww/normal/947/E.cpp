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
typedef long long ll;
typedef unsigned long long ull;
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
const int N=300000;
const int W=262144;
ll fp(ll a,ll b)
{
	ll s=1;
	for(;b;b>>=1,a=a*a%p)
		if(b&1)
			s=s*a%p;
	return s;
}
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
	for(int i=2;i<=n;i<<=1)
		for(int j=0;j<n;j+=i)
			for(int k=0;k<i/2;k++)
			{
				ll u=a[j+k];
				ll v=a[j+k+i/2]*w[W/i*k]%p;
				a[j+k]=(u+v)%p;
				a[j+k+i/2]=(u-v)%p;
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
	for(int i=1;i<W;i++)
		w[i]=w[i-1]*s%p;
}
void mul(ll *a,ll *b,ll *c,int n,int m,int l)
{
	static ll a1[N],a2[N];
	int k=1;
	while(k<=n+m)
		k<<=1;
	for(int i=0;i<=n;i++)
		a1[i]=a[i];
	for(int i=n+1;i<k;i++)
		a1[i]=0;
	for(int i=0;i<=m;i++)
		a2[i]=b[i];
	for(int i=m+1;i<k;i++)
		a2[i]=0;
	ntt(a1,k,1);
	ntt(a2,k,1);
	for(int i=0;i<k;i++)
		a1[i]=a1[i]*a2[i]%p;
	ntt(a1,k,-1);
	for(int i=0;i<=l;i++)
		c[i]=a1[i];
}
int n;
ll m;
ll f1[N],f2[N],f3[N],a[N];
ll fac[N],ifac[N],inv[N];
int main()
{
	init();
	open("cf947e");
	scanf("%d%I64d",&n,&m);
	inv[0]=inv[1]=fac[0]=fac[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<=n+1;i++)
	{
		inv[i]=-p/i*inv[p%i]%p;
		fac[i]=fac[i-1]*i%p;
		ifac[i]=ifac[i-1]*inv[i]%p;
	}
	for(int i=0;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(int i=0;i<=n;i++)
	{
		f1[i]=a[n-i]*fac[n-i]%p;
		f2[i]=ifac[i];
	}
	mul(f1,f2,f3,n,n,n);
	for(int i=0;i<=n;i++)
		a[i]=f3[n-i]*ifac[i]%p;
	for(int i=0;i<=n;i++)
		a[i]=a[i]*fp(inv[i+1],m)%p;
	for(int i=0;i<=n;i++)
	{
		f1[i]=a[n-i]*fac[n-i]%p;
		f2[i]=(i&1?-1:1)*f2[i];
	}
	mul(f1,f2,f3,n,n,n);
	for(int i=0;i<=n;i++)
		a[i]=f3[n-i]*ifac[i]%p;
	for(int i=0;i<=n;i++)
		a[i]=(a[i]+p)%p;
	for(int i=0;i<=n;i++)
		printf("%I64d ",a[i]);
	return 0;
}