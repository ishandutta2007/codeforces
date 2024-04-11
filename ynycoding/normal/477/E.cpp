#include <cstdio>
#include <cmath>
#include <algorithm>
#define N 400005
using std::min;
int n, q, a[N], mn[3][N][25], lg[N];
inline void init(void)
{
	for(int i=2; i<=n; i<<=1) ++lg[i];
	for(int i=1; i<=n; ++i) lg[i]+=lg[i-1];
	for(int i=1; i<=n; ++i) mn[0][i][0]=a[i], mn[1][i][0]=a[i]+2*i, mn[2][i][0]=a[i]-2*i;
	for(int l=1; (1<<l)<=n; ++l) for(int i=1; i+(1<<l)-1<=n; ++i)
	{
		for(int t=0; t<3; ++t) mn[t][i][l]=min(mn[t][i][l-1], mn[t][i+(1<<(l-1))][l-1]);
	}
}
inline int ask(int t, int l, int r)
{
	if(l>r) std::swap(l, r);
	int len=lg[r-l+1];
	return min(mn[t][l][len], mn[t][r-(1<<len)+1][len]);
}
inline int findl(int p, int x)
{
	int l=1, r=p;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(ask(0, mid, p)>=x) r=mid;
		else l=mid+1;
	}
	return l;
}
inline int findr(int p, int x)
{
	int l=p, r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(ask(0, p, mid)>=x) l=mid;
		else r=mid-1;
	}
	return l;
}
inline int solve(int r1, int c1, int r2, int c2)
{
	c1=min(c1, ask(0, r1, r2));
	if(c1<=c2)
	{
		int l=findl(r2, c2), r=findr(r2, c2);
		int ret=abs(r2-r1)+abs(c2-c1)-1;
		if(r2<=r1)
		{
			ret=min(ret, abs(r2-r1)+ask(0, r2, min(r1, r))-c2);
			if(r>=r1)
			{
				ret=min(ret, ask(1, r1, r)-r1-r2-c2);
				if(r<n) ret=min(ret, 2*(r+1)-r1-r2+c2-a[r+1]);
			}
			else if(r<n) ret=min(ret, r1-r2+c2-a[r+1]);
			ret=min(ret, r1+r2+ask(2, l, r2)-c2);
			if(l>1) ret=min(ret, r1+r2-2*(l-1)+c2-a[l-1]);
		}
		else
		{
			ret=min(ret, abs(r2-r1)+ask(0, std::max(l, r1), r2)-c2);
			if(l<=r1)
			{
				ret=min(ret, r1+r2+ask(2, l, r1)-c2);
				if(l>1) ret=min(ret, r1+r2-2*(l-1)+c2-a[l-1]);
			}
			else if(l>1) ret=min(ret, r2-r1+c2-a[l-1]);
			ret=min(ret, ask(1, r2, r)-r1-r2-c2);
			if(r<n) ret=min(ret, 2*(r+1)-r1-r2+c2-a[r+1]);
		}
		return ret+1;
	}
	int l=findl(r2, c2), r=findr(r2, c2);
	int ret=abs(r2-r1)+abs(c2-c1);
	if(r2<=r1)
	{
		if(r>=r1)
		{
			ret=min(ret, ask(1, r1, r)-r1-r2-c2);
			if(r<n) ret=min(ret, 2*(r+1)-r1-r2+c2-a[r+1]);
		}
		else if(r<n) ret=min(ret, r1-r2+c2-a[r+1]);
		ret=min(ret, r1+r2+ask(2, l, r2)-c2);
		if(l>1) ret=min(ret, r1+r2-2*(l-1)+c2-a[l-1]);
	}
	else
	{
		if(l<=r1)
		{
			ret=min(ret, r1+r2+ask(2, l, r1)-c2);
			if(l>1) ret=min(ret, r1+r2-2*(l-1)+c2-a[l-1]);
		}
		else if(l>1) ret=min(ret, r2-r1+c2-a[l-1]);
		ret=min(ret, ask(1, r2, r)-r1-r2-c2);
		if(r<n) ret=min(ret, 2*(r+1)-r1-r2+c2-a[r+1]);
	}
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
	scan(n);
	for(int i=1; i<=n; ++i) scan(a[i]);
	init();
	scan(q);
	for(int i=1, r1, c1, r2, c2; i<=q; ++i)
	{
		scan(r1), scan(c1), scan(r2), scan(c2);
		putint(min(solve(r1, c1, r2, c2), min(1+solve(r1, 0, r2, c2), 1+solve(r1, a[r1], r2, c2))), '\n');
	}
	flush();
	return 0;
}