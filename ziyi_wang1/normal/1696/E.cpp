#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
namespace io
{
	const int N=1<<20;
	char buf[N],*t1=buf,*t2=buf;
	#ifdef cjy 
	#define getc() getchar()
	#else
	#define getc() t1==t2&&(t2=(t1=buf)+fread(buf,1,N,stdin),t1==t2)?EOF:*t1++
	#endif
	inline int read()
	{
		static int an,f;an=0,f=1;
		static char ch;ch=getc();
		while(ch<48||ch>57)ch=='-'?f=-1:0,ch=getc();
		while(ch>=48&&ch<=57)an=(an<<3)+(an<<1)+(ch^48),ch=getc();
		return an*f;
	}
	char buff[N],*T=buff;
	inline void flush(){fwrite(buff,1,T-buff,stdout);T=buff;}
	inline void putc(char ch){if(T==buff+N)flush();*T++=ch;}
	template<typename T>
	inline void print(T x)
	{
		if(!x){putc('0');return;}
		if(x<0)putc('-'),x=-x;
		static int st[30],tp;
		while(x)st[++tp]=x%10,x/=10;
		while(tp)putc(st[tp--]^48);
	}
}
using io::read;
using io::putc;
using io::flush;
using io::print;
const int mod=1000000007;
int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
int n;
int a[200020];
int fac[400020],ifac[400020];
int C(int a,int b)
{
	return 1ll*fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}
int dp[20][20];
int main()
{
	n=read();
	for(int i=0;i<=n;++i)a[i]=read();
	fac[0]=1;
	for(int i=1;i<=400000;++i)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[400000]=kpow(fac[400000],mod-2);
	for(int i=400000;i;--i)ifac[i-1]=1ll*ifac[i]*i%mod;
	int ans=0;
	for(int i=0;i<=n;++i)(ans+=C(a[i]+i,i+1))>=mod?ans-=mod:0;
	printf("%d\n",ans);
	flush();
	return 0;
}