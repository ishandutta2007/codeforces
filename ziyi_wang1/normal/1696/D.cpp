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
int T,n;
int a[300030];
struct segtree
{
	int mi[1000010];
	void build(int k,int l,int r)
	{
		mi[k]=0x3f3f3f3f;
		if(l==r)return;
		build(k<<1,l,(l+r)>>1);
		build(k<<1|1,((l+r)>>1)+1,r);
	}
	void upd(int k,int l,int r,int p,int w)
	{
		if(l==r)return mi[k]=w,void();
		if(p<=((l+r)>>1))upd(k<<1,l,(l+r)>>1,p,w);
		else upd(k<<1|1,((l+r)>>1)+1,r,p,w);
		mi[k]=min(mi[k<<1],mi[k<<1|1]);
	}
	int qry(int k,int l,int r,int ll,int rr)
	{
		if(l>rr||r<ll)return 0x3f3f3f3f;
		if(l>=ll&&r<=rr)return mi[k];
		return min(qry(k<<1,l,(l+r)>>1,ll,rr),qry(k<<1|1,((l+r)>>1)+1,r,ll,rr));
	}
}T1,T2;
int st1[300030],tp1;
int st2[300030],tp2;
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i)a[i]=read();
		T1.build(1,1,n);
		T2.build(1,1,n);
		st1[tp1=1]=st2[tp2=1]=1;
		T1.upd(1,1,n,1,0);
		T2.upd(1,1,n,1,0);
		int ans=0;
		// printf("%d ",0);
		for(int i=2;i<=n;++i)
		{
			while(tp1&&a[i]>a[st1[tp1]])T1.upd(1,1,n,st1[tp1],0x3f3f3f3f),--tp1;
			st1[++tp1]=i;
			while(tp2&&a[i]<a[st2[tp2]])T2.upd(1,1,n,st2[tp2],0x3f3f3f3f),--tp2;
			st2[++tp2]=i;
			int d;
			if(a[i]>a[i-1])d=T2.qry(1,1,n,st1[tp1-1]+1,i)+1;
			else d=T1.qry(1,1,n,st2[tp2-1]+1,i)+1;
			d=min(d,0x3f3f3f3f);
			T1.upd(1,1,n,i,d);
			T2.upd(1,1,n,i,d);
			if(i==n)ans=d;
			// printf("%d ",d);
		}
		// printf("\n");
		printf("%d\n",ans);
	}
	flush();
	return 0;
}