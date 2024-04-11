#include <cstdio>
#include <algorithm>
#define bc __builtin_popcount
const int N=1000005, K=20;
int n, m, k, a[N], pos[K], cur, b[N], cs[N], ps[N], mx=-1, ix, iy;
int f[1<<K], g[1<<K];
char s[K+1], t[K+1];
inline void upt(int &x, int a) { x=std::max(x, a); }
inline void dw(int &x, int a) { x=std::min(x, a); }
inline void swp(int x, int a, int b)
{
	int l=(x>>a)&1, r=(x>>b)&1;
	x^=(l<<a)^(r<<b)^(l<<b)^(r<<a);
}
inline int calc(void)
{
	int ret=0;
	for(int i=0; i<k; ++i) ret|=((s[i]-'0')<<pos[i]);
	return ret;
}
namespace iobuff{
	const int LEN=1000000;
	char in[LEN+5], out[LEN+5];
	char *pin=in, *pout=out, *ed=in, *eout=out+LEN;
	inline char gc(void)
	{
		return pin==ed&&(ed=(pin=in)+fread(in, 1, LEN, stdin), ed==in)?EOF:*pin++;
	}
	inline void pc(char c)
	{
		pout==eout&&(fwrite(out, 1, LEN, stdout), pout=out);
		(*pout++)=c;
	}
	inline void flush()
	{ fwrite(out, 1, pout-out, stdout), pout=out; }
	template<typename T> inline void scan(T &x)
	{
		static int f;
		static char c;
		c=gc(), f=1, x=0;
		while(c<'0'||c>'9') f=(c=='-'?-1:1), c=gc();
		while(c>='0'&&c<='9') x=10*x+c-'0', c=gc();
		x*=f;
	}
	template<typename T> inline void putint(T x, char div)
	{
		static char s[15];
		static int top;
		top=0;
		x<0?pc('-'), x=-x:0;
		while(x) s[top++]=x%10, x/=10;
		!top?pc('0'), 0:0;
		while(top--) pc(s[top]+'0');
		pc(div);
	}
}
using namespace iobuff;
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	scanf("%s%s", s, t);
	for(int i=1; i<=n; ++i)
	{
		scan(a[i]), scan(b[i]);
		--a[i], --b[i];
	}
	for(int i=0; i<k; ++i) pos[i]=i;
	for(int i=n; i; --i)
	{
		std::swap(pos[a[i]], pos[b[i]]);
		cs[i]=calc();
	}
	std::copy(t, t+k, s);
	for(int i=0; i<k; ++i) pos[i]=i;
	ps[n+1]=calc();
	for(int i=n; i; --i)
	{
		std::swap(pos[a[i]], pos[b[i]]);
		ps[i]=calc();
	}
	std::fill(f, f+(1<<k), 0x3f3f3f3f);
	for(int i=1; i<=n+1; ++i) upt(g[ps[i]], i), dw(f[cs[i]], i);
	for(int len=2; len<=(1<<k); len<<=1)
	{
		int mid=len>>1;
		for(int i=0; i<(1<<k); i+=len) for(int j=i; j<i+mid; ++j)
			upt(g[j], g[j+mid]), dw(f[j], f[j+mid]);
	}
	for(int s=0; s<(1<<k); ++s)
	{
		if(g[s]-f[s]>=m&&bc(s)>mx) mx=bc(s), ix=f[s], iy=g[s];
	}
	printf("%d\n%d %d\n", k-bc(cs[ix]^ps[iy]), ix, iy-1);
	return 0;
}