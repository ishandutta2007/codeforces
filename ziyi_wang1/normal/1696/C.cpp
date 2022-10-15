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
pair<int,long long>a[50050],b[50050];
int tpa,tpb;
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		tpa=tpb=0;
		for(int i=1,x;i<=n;++i)
		{
			x=read();
			int cnt=1;
			while(x%m==0)x/=m,cnt*=m;
			if(tpa&&a[tpa].first==x)a[tpa].second+=cnt;
			else a[++tpa]=make_pair(x,cnt);
		}
		int k=read();
		for(int i=1,x;i<=k;++i)
		{
			x=read();
			int cnt=1;
			while(x%m==0)x/=m,cnt*=m;
			if(tpa&&b[tpb].first==x)b[tpb].second+=cnt;
			else b[++tpb]=make_pair(x,cnt);
		}
		if(tpa!=tpb){printf("No\n");continue;}
		bool flag=0;
		for(int i=1;i<=tpa;++i)
			if(a[i].first!=b[i].first||a[i].second!=b[i].second)flag=1;
		if(flag)printf("No\n");
		else printf("Yes\n");
	}
	flush();
	return 0;
}