#include <cstdio>
#include <vector>
#define pb push_back
#define ll long long
#define N 500005
using std::vector;
int n, m, op[N], x[N], qx[N], y[N], fa[N], tp[N], tm[N], tg[N], cur, tid;
ll val[N], ans[N], adt[N];
vector<int> id[N], qr[N];
char s[100];
void merge(int x, int y)
{
	if(x==y) return;
	for(int v:id[x]) id[y].pb(v), val[v]+=adt[x]-adt[y], fa[v]=y, tp[v]=(tm[v]<tg[x]?tg[x]:tp[v]), tm[v]=cur;
	id[x].clear();
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
	scan(n), scan(m);
	for(int i=1; i<=n; ++i) id[i].pb(i), fa[i]=i;
	for(int i=1, a, b; i<=m; ++i)
	{
		cur=i;
		char c=gc();
		while(c<'A'||c>'Z') c=gc();
		s[0]=c;
		scan(a);
//		scanf("%s%d", s, &a);
		if(s[0]=='U')
		{
			scan(b);
//			scanf("%d", &b);
			op[i]=1;
			x[i]=a, y[i]=b;
		}
		if(s[0]=='M')
		{
			scan(b);
//			scanf("%d", &b);
			a=fa[a], b=fa[b];
			if(id[a].size()>id[b].size()) std::swap(a, b);
			merge(a, b);
		}
		if(s[0]=='A') op[i]=3, x[i]=a;
		if(s[0]=='Z') tg[fa[a]]=i;
		if(s[0]=='Q')
		{
			++tid;
			qx[tid]=a;
			qr[i].pb(tid);
			qr[tm[a]<tg[fa[a]]?tg[fa[a]]:tp[a]].pb(-tid);
		}
	}
	for(int i=1; i<=n; ++i) id[i].clear(), id[i].pb(i), fa[i]=i;
	for(int i=1; i<=m; ++i)
	{
		if(op[i]==1)
		{
			x[i]=fa[x[i]], y[i]=fa[y[i]];
			if(id[x[i]].size()>id[y[i]].size()) std::swap(x[i], y[i]);
			merge(x[i], y[i]);
		}
		if(op[i]==3) adt[fa[x[i]]]+=id[fa[x[i]]].size();
		for(int v:qr[i])
		{
			if(v>0) ans[v]+=val[qx[v]]+adt[fa[qx[v]]];
			else ans[-v]-=val[qx[-v]]+adt[fa[qx[-v]]];
		}
	}
	for(int i=1; i<=tid; ++i) putint(ans[i], '\n');//printf("%lld\n", ans[i]);
	flush();
	return 0;
}