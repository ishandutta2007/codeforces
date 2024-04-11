#include <cstdio>
#include <cmath>
#include <algorithm>
#define N 1000005
int n, m, a[N], blc, c0, mx, ans[N], tag;
int op[N], ql[N], sz[N], qr[N], qx[N], fa[N], rt[N], val[N];

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

int findfa(int x) { return x==fa[x]?x:fa[x]=findfa(fa[x]); }
inline void merge(int x, int y)
{
	if(!rt[y]) { rt[y]=rt[x], val[rt[x]]=y; }
	else fa[rt[x]]=rt[y];
	sz[y]+=sz[x];
	sz[x]=rt[x]=0;
}
inline void clr(int l, int r)
{
	mx=0;
	for(int i=l; i<=r; ++i) if(a[i])
	{
		a[i]=val[findfa(i)];
		rt[a[i]]=sz[a[i]]=0;
		a[i]-=tag;
		mx=std::max(a[i], mx);
	}
	tag=0;
}
inline void init(int l, int r)
{
//	mx-=tag;
//	tag=0;
//	mx=c0=tag=0;
//	for(int i=l; i<=r; ++i) mx=std::max(mx, a[i]), c0+=(a[i]==0);
	for(int i=l; i<=r; ++i) if(a[i])
	{
		if(!rt[a[i]]) rt[a[i]]=i, fa[i]=i, val[i]=a[i], sz[a[i]]=1;
		else fa[i]=rt[a[i]], ++sz[a[i]];
	}
}
inline void proc(int x)
{
	int l=blc*(x-1)+1, r=std::min(n, blc*x);
	mx=0;
	for(int i=l; i<=r; ++i) mx=std::max(mx, a[i]);
	init(l, r);
	for(int i=1; i<=m; ++i)
	{
		if(ql[i]<=l&&r<=qr[i])
		{
			if(op[i]==1)
			{
				int t=qx[i];
				if(t==0) continue;
				if(mx>2*t)
				{
					for(int j=tag+1; j<=t+tag; ++j) merge(j, j+t);
					mx-=t;
					tag+=t;
				}
				else if(mx>t)
				{
					for(int j=t+tag+1; j<=mx+tag; ++j) merge(j, j-t);
					mx=t;
				}
			}
			else
			{
				ans[i]+=(qx[i]?qx[i]>mx?0:sz[qx[i]+tag]:c0);
			}
		}
		else if(!(ql[i]>r||qr[i]<l))
		{
			if(op[i]==2)
			{
				for(int j=std::max(l, ql[i]); j<=std::min(r, qr[i]); ++j)
				{
					ans[i]+=(val[findfa(j)]-tag==qx[i]);
				}
				continue;
			}
			clr(l, r);
			if(op[i]==1) for(int j=std::max(l, ql[i]); j<=std::min(r, qr[i]); ++j)
			{
				if(a[j]>qx[i]) a[j]-=qx[i];
			}
			init(l, r);
		}
	}
	clr(l, r);
}
int main()
{
	scan(n), scan(m);
	blc=sqrt(n)+1;
//	blc=1;	
	for(int i=1; i<=n; ++i) scan(a[i]);
//	m=1;
	for(int i=1; i<=m; ++i) scan(op[i]), scan(ql[i]), scan(qr[i]), scan(qx[i]);
	for(int i=1; (i-1)*blc<n; ++i) proc(i);
	for(int i=1; i<=m; ++i)
		if(op[i]==2) putint(ans[i], '\n');
	flush();
	return 0;
}