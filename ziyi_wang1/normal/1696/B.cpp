#include<cstdio>
#include<cstring>
#include<algorithm>
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
int a[100010];
int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		int cnt=0;
		for(int i=1;i<=n;++i)a[i]=read(),cnt+=a[i]!=0;
		if(cnt==0){printf("0\n");continue;}
		int cnt1=0;
		for(int i=1;i<=n;++i)
			if(a[i])
			{
				int r=i;
				while(r<n&&a[r+1])++r;
				cnt1=r-i+1;
				break;
			}
		if(cnt==cnt1)printf("1\n");
		else printf("2\n");
	}
	flush();
	return 0;
}