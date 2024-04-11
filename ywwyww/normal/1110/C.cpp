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
int ans[30];

void solve()
{
	int n;
	scanf("%d",&n);
	int s1=0,s2=0;
	while(n)
	{
		s1++;
		s2+=n&1;
		n>>=1;
	}
	if(s1==s2)
		printf("%d\n",ans[s1]);
	else
		printf("%d\n",(1<<s1)-1);
}
int main()
{
	ans[2]=1;
	ans[3]=1;
	ans[4]=5;
	ans[5]=1;
	ans[6]=21;
	ans[7]=1;
	ans[8]=85;
	ans[9]=73;
	ans[10]=341;
	ans[11]=89;
	ans[12]=1365;
	ans[13]=1;
	ans[14]=5461;
	ans[15]=4681;
	ans[16]=21845;
	ans[17]=1;
	ans[18]=87381;
	ans[19]=1;
	ans[20]=349525;
	ans[21]=299593;
	ans[22]=1398101;
	ans[23]=178481;
	ans[24]=5592405;
	ans[25]=1082401;
	int q;
	scanf("%d",&q);
	while(q--)
		solve();
	return 0;
}