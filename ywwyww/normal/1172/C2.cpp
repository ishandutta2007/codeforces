/*
Author: yww
Language: C++
Mail: weeerrr720@qq.com
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<functional>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<bitset>
#include<assert.h>
#ifdef _WIN32
	#include<windows.h>
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
void open(const char *s){
#ifndef ONLINE_JUDGE
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
void open2(const char *s){
#ifdef DEBUG
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
template <class T>
int upmin(T &a, const T &b){return (b<a?a=b,1:0);}
template <class T>
int upmax(T &a, const T &b){return (b>a?a=b,1:0);}
namespace io
{
	const int SIZE=(1<<20)+1;
	char ibuf[SIZE],*iS,*iT;
	char obuf[SIZE],*oS=obuf,*oT=oS+SIZE-1;
	int getc()
	{
		(iS==iT?iS=ibuf,iT=ibuf+fread(ibuf,1,SIZE,stdin):0);
		return iS==iT?EOF:*(iS++);
	}
	int f;
	char c;
	template <class T>
	void get(T &x)
	{
		f=1;
		for(c=getc();(c<'0'||c>'9')&&c!='-';c=getc());
		(c=='-'?f=-1,c=getc():0);
		x=0;
		for(;c>='0'&&c<='9';c=getc())
			x=x*10+c-'0';
		x*=f;
	}
	void flush()
	{
		fwrite(obuf,1,oS-obuf,stdout);
		oS=obuf;
	}
	void putc(char x)
	{
		*(oS++)=x;
		if(oS==oT)
			flush();
	}
	int a[55],t;
	template <class T>
	void put(T x)
	{
		if(!x)
			putc('0');
		x<0?putc('-'),x=-x:0;
		while(x)
		{
			a[++t]=x%10;
			x/=10;
		}
		while(t)
			putc(a[t--]+'0');
	}
	void space()
	{
		putc(' ');
	}
	void enter()
	{
		putc('\n');
	}
	struct flusher
	{
		~flusher()
		{
			flush();
		}
	}
	io_flusher;
}
const int infi=0x3fffffff;
const ll infll=0x3fffffffffffffffll;
const ll p=998244353;
const int N=200010;
const int M=3010;
ll fp(ll a,ll b)
{
	a%=p;
	ll s=1;
	for(;b;b>>=1,a=a*a%p)
		if(b&1)
			s=s*a%p;
	return s;
}
int _inv[N],*inv=_inv+M;
int _inv1[N],*inv1=_inv1+M;
int _inv0[N],*inv0=_inv0+M;
void add(int &a,ll b)
{
	a=(a+b)%p;
}
int f[M][M];//ij1i-j0 
int n,m;
int a[N],w[N];
int w0,w1;
int main()
{
	open2("c");
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
		if(a[i])
			w1+=w[i];
		else
			w0+=w[i];
	for(int i=-3000;i<=3000;i++)
		inv[i]=fp(w0+w1+i,p-2);
	for(int i=-3000;i<=3000;i++)
		inv1[i]=fp(w1+i,p-2);
	for(int i=-3000;i<=3000;i++)
		inv0[i]=fp(w0+i,p-2);
	f[0][0]=1;
	for(int i=0;i<m;i++)
		for(int j=0;j<=i;j++)
			if(f[i][j])
			{
				ll v=(ll)(w1+j)*inv[j-(i-j)]%p;
				add(f[i+1][j+1],(ll)f[i][j]*v);
				add(f[i+1][j],(ll)f[i][j]*(1-v));
			}
	ll s1=1;
	ll ss1=0;
	for(int j=0;j<=m;j++)
	{
		ss1=(ss1+f[m][j]*s1)%p;
		s1=(s1+s1*inv1[j])%p;
	}
	ll s0=1,ss0=0;
	for(int j=0;j<=m&&j<=w0;j++)
	{
		ss0=(ss0+f[m][m-j]*s0)%p;
		s0=(s0-s0*inv0[-j])%p;
	}
	for(int i=1;i<=n;i++)
		if(a[i])
		{
			ll ans=w[i]*ss1%p;
			ans=(ans%p+p)%p;
			printf("%lld\n",ans);
		}
		else
		{
			ll ans=w[i]*ss0%p;
			ans=(ans%p+p)%p;
			printf("%lld\n",ans);
		}
	return 0;
}