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
const int N=200010;
int a[N],b[N];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	int ans=0;
	for(int i=1;i<=n;i++)
		if(b[i])
			ans=max(i-b[i]+1,ans);
	ans+=n;
	int l=n;
	while(l>=2&&b[l]>=2&&b[l-1]==b[l]-1)
		l--;
	if(b[l]==1)
	{
		int s=0;
		for(int i=1;i<l;i++)
			if(b[i])
				s=max(s,i+n-l+1-b[i]+1);
		if(s==0)
			ans=l-1;
	}
	printf("%d\n",ans);
	return 0;
}