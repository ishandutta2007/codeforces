#include <cstdio>
#include <algorithm>
#define i128 __int128
const int N=1005;

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
		putchar(c);
//		pout==eout&&(fwrite(out, 1, LEN, stdout), pout=out);
//		(*pout++)=c;
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
		static char s[100];
		static int top;
		top=0;
		x<0?pc('-'), x=-x:0;
		while(x) s[top++]=x%10, x/=10;
		!top?pc('0'), 0:0;
		while(top--) pc(s[top]+'0');
		pc(div);
	}
}
using iobuff::scan;
using iobuff::putint;
using iobuff::flush;
using iobuff::pc;

int T, n, m, in[N], in1[N];
i128 x[N], y[N], to[N][N], to1[N][N], *a;
inline i128 gcd(i128 x, i128 y) { while(y) x%=y, std::swap(x, y); return x; }
struct seg{
	#define ls (u<<1)
	#define rs (u<<1|1)
	i128 val[N<<2];
	inline void upt(int u)
	{
		if(val[ls]&&val[rs]) val[u]=gcd(val[ls], val[rs]);
		else val[u]=val[ls]|val[rs];
	}
	void build(int u, int l, int r)
	{
		if(l==r)
		{
			val[u]=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(ls, l, mid), build(rs, mid+1, r);
		upt(u);
	}
	void del(int u, int l, int r, int p)
	{
		if(l==r) { val[u]=0; return; }
		int mid=(l+r)>>1;
		if(p<=mid) del(ls, l, mid, p);
		else del(rs, mid+1, r, p);
		upt(u);
	}
}A[N], B[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scan(n), scan(m);
		for(int i=1; i<=n; ++i) scan(x[i]), in[i]=1;
		for(int i=1; i<=m; ++i) scan(y[i]), in1[i]=1;
		for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
		{
			i128 v=gcd(x[i], y[j]);
			to[i][j]=x[i]/v;
			to1[j][i]=y[j]/v;
		}
		for(int i=1; i<=n; ++i) a=to[i], A[i].build(1, 1, m);
		for(int i=1; i<=m; ++i) a=to1[i], B[i].build(1, 1, n);
		while(1)
		{
			int ok=0;
			for(int i=1; i<=n; ++i) if(in[i]&&A[i].val[1]>1)
			{
				in[i]=0;
				ok=1;
//				printf("del %d\n", i);
				for(int j=1; j<=m; ++j) B[j].del(1, 1, n, i);
			}
			for(int i=1; i<=m; ++i) if(in1[i]&&B[i].val[1]>1)
			{
//				printf("del1 %d\n", i);
				in1[i]=0;
				ok=1;
				for(int j=1; j<=n; ++j) A[j].del(1, 1, m, i);
			}
			if(!ok) break;
		}
		int rsa=0, rsb=0;
		for(int i=1; i<=n; ++i) rsa+=in[i];
		for(int i=1; i<=m; ++i) rsb+=in1[i];
//		printf("s %d %d %d %d\n", n, m, rsa, rsb);
		if(!rsa||!rsb) { puts("NO"); continue; }
		printf("YES\n%d %d\n", rsa, rsb);
		for(int i=1; i<=n; ++i) if(in[i]) putint(x[i], ' ');
		pc('\n');
		for(int i=1; i<=m; ++i) if(in1[i]) putint(y[i], ' ');
		pc('\n');
	}
	return 0;
}