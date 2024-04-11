#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#define pb push_back
#define N 200005
using std::vector;
int n, m, ex[N], sa[N], rk[N], lcpm[N], qt[N][5], rans[N], q;
char s[N], t[N], tmp[N];
int mx, id, hs[N], pw[N];
const int MOD=1000000007, base=233;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline void init(char *s, int n)
{
	pw[0]=1;
	for(int i=1; i<=n; ++i) pw[i]=1ll*base*pw[i-1]%MOD;
	for(int i=1; i<=n; ++i)
	{
		hs[i]=(1ll*hs[i-1]*base+s[i]-'a'+1)%MOD;
	}
}
bool check(int x, int y, int len)
{
	return mval(MOD+hs[x+len-1]-1ll*hs[x-1]*pw[len]%MOD)==mval(MOD+hs[y+len-1]-1ll*hs[y-1]*pw[len]%MOD);
}
inline int lcp(int x, int y)
{
	int l=0, r=n-std::max(x, y)+1;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(x, y, mid)) l=mid;
		else r=mid-1;
	}
	return l;
}
inline int _gmn(int a, int b)
{
	if(a>b) std::swap(a, b);
	if(a==-1) return b;
	if(b-a>=m)
	{
		int len=ex[a+1+m];
		if(len<m) return (s[a+len+1]>t[len+1])?a:b;
		len=lcpm[a+1];
//		if(a==3&&b==15) printf("fa %d %d\n", len, a+1);
		if(len<b-a-m) return (s[a+m+len+1]>s[a+len+1])?a:b;
		len=ex[b+1];
		if(len<m) return (s[b+len-m+1]<t[len+1])?a:b;
		return a;
	}
	else
	{
		int len=ex[a+1+m];
		if(len<b-a) return (s[a+len+1]>t[len+1])?a:b;
		len=ex[b-a+1];
		if(len<m-(b-a)) return (t[len+1]>t[(b-a)+len+1])?a:b;
		len=ex[m-(b-a)+1];
		if(len<b-a) return (t[len+1]<t[m-(b-a)+len+1])?a:b;
		return a;
	}
}
bool cmp(int a, int b) { return _gmn(a, b)==a; }
inline int gmn(int a, int b)
{
//	int ret=_gmn(a, b);
//	if(a==3&&b==15) printf("%d %d %d\n", a, b, ret);
	return a==-1?b:b==-1?a:rk[a]<rk[b]?a:b;
}
inline void exkmp(char *s, int n)
{
	for(int i=2; i<=n; ++i)
	{
		int t=(i>mx?0:std::min(mx-i+1, ex[i-id+1]));
		while(t+i<=n&&s[t+i]==s[t+1]) ++t;
		ex[i]=t;
		if(i+ex[i]-1>mx) mx=i+ex[i]-1, id=i;
	}
}
const int B=2320;
int blc, bel[N], mn[B][B], lim, tot;
inline void initblc(int x)
{
	int l=x*blc, r=std::min(n, blc*(x+1)-1);
	for(int i=l; i<=r; ++i) mn[i-l+1][i-l+1]=i;
	for(int len=2; len<=r-l+1; ++len) for(int a=1, b=len; b<=r-l+1; ++a, ++b)
		mn[a][b]=gmn(mn[a][b-1], mn[a+1][b]);
}
int lg[N], st[N][20];
vector<int> ev[B];
inline int ask(int x, int t, int l, int r)
{
	if(l>t||r<t) return -1;
	int d=t%x;
	l=(l-d+x-1)/x*x+d, r=(r-d)/x*x+d;
	int len=lg[(r-l)/x+1];
//	printf("%d %d %d %d %d %d\n", l, r, t, len, r-(1<<len)*x+x, r-(1<<len)*x+x+x*(1<<len)-1);
	return gmn(st[l][len], st[r-(1<<len)*x+x][len]);
}
inline void proc(void)
{
	for(int i=2; i<=n+1; i<<=1) ++lg[i];
	for(int i=1; i<=n+1; ++i) lg[i]+=lg[i-1];
	for(int t=1; t<=lim; ++t)
	{
		for(int i=0; i<=n; ++i) st[i][0]=i;
		for(int l=1; (1<<l)*t<=n+1; ++l) for(int i=0; i+((1<<l)-1)*t<=n; ++i)
			st[i][l]=gmn(st[i][l-1], st[i+(1<<(l-1))*t][l-1]);
		for(int x:ev[t])
		{
			int ret=-1;
			for(int i=qt[x][0]; i<=qt[x][0]+t-1&&i<=qt[x][1]; ++i) if(i%t>=qt[x][3]&&i%t<=qt[x][4])
				ret=gmn(ret, ask(t, i, qt[x][0], qt[x][1]));
			rans[x]=ret;
		}
	}
}
inline int asklr(int l, int r)
{
	if(l>r) return -1;
	return mn[l%blc+1][r%blc+1];
}
inline int qr(int l, int r, int k, int x, int y)
{
	int ret=-1;
	for(int cur=l/k*k; cur<=r; cur+=k)
		ret=gmn(ret, asklr(std::max(cur+x, l), std::min(cur+y, r)));
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
	scanf("%s%s%d", s+1, t+1, &q);
	n=strlen(s+1), m=strlen(t+1);
	memcpy(tmp, t, m+1);
	memcpy(tmp+m+1, s+1, n);
	exkmp(tmp, n+m);
	
	init(s, n);
	for(int i=1; i+m<=n; ++i) lcpm[i]=lcp(i, i+m);
	
	for(int i=0; i<=n; ++i) sa[i]=i;
	std::sort(sa, sa+n+1, cmp);
	for(int i=0; i<=n; ++i) rk[sa[i]]=i;
	
	blc=sqrt(n)*2+1;
	for(int i=0; i<=n; ++i) bel[i]=i/blc;
	lim=sqrt(n)/4;
	tot=bel[n];
	for(int i=0; i<=tot; ++i) initblc(i);
	
	for(int i=1, l, r, k, x, y; i<=q; ++i)
	{
		scan(qt[i][0]), scan(qt[i][1]), scan(qt[i][2]), scan(qt[i][3]), scan(qt[i][4]);
		rans[i]=-1;
		if(qt[i][2]<=lim) ev[qt[i][2]].pb(i);
	}
	proc();
	for(int t=0; t<=tot; ++t)
	{
		int tl=blc*t, tr=std::min(n, blc*(t+1)-1);
		initblc(t);
		for(int i=1; i<=q; ++i) if(qt[i][2]>lim)
		{
			int l=qt[i][0], r=qt[i][1], k=qt[i][2], x=qt[i][3], y=qt[i][4];
			if(!(tl>r||tr<l)) rans[i]=gmn(rans[i], qr(std::max(l, tl), std::min(r, tr), k, x, y));
		}
	}
	for(int i=1; i<=q; ++i)
	{
		putint(rans[i], ' ');
	}
	flush();
	return 0;
}