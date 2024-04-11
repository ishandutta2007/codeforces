#include <cstdio>
#include <random>
#include <algorithm>
#define x first
#define y second
#define ll int
#define pb push_back
using std::pair;
using std::vector;
const int N=500005;

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
using namespace iobuff;

int n, m;
vector<pair<int, int> > e[N];
int rt;
ll cdis;
void pdfs(int u, int fa, ll dis)
{
	if(dis>cdis) rt=u, cdis=dis;
	for(auto [v, w]:e[u]) if(v!=fa)
		pdfs(v, u, dis+w);
}
struct Qr{
	int rt, rw[N], dep[N], up[N], son[N], pa[N][25], id[N], rk[N], top;
	ll mx[N], sum[N], dis[N];
	void dfs(int u, int fa, int cw)
	{
		rw[u]=cw;
		dep[u]=dep[fa]+1;
		pa[u][0]=fa;
		dis[u]=dis[fa]+cw;
		for(int i=1; (1<<i)<=n; ++i) pa[u][i]=pa[pa[u][i-1]][i-1];
		for(auto [v, w]:e[u]) if(v!=fa)
		{
			dfs(v, u, w);
			if(mx[v]>mx[u]) mx[u]=mx[v], son[u]=v;
		}
		mx[u]+=cw;
	}
	void dfs1(int u, int tp, int fa)
	{
		if(tp==u) id[++top]=u;//, printf("%d %lld\n", u, mx[u]);
		up[u]=tp;
		if(son[u]) dfs1(son[u], tp, u);
		for(auto [v, w]:e[u]) if(v!=fa&&v!=son[u])
		{
			dfs1(v, v, u);
		}
	}
	inline int find(int u, int k)
	{
		for(int i=19; ~i; --i) if(rk[up[pa[u][i]]]>k)
			u=pa[u][i];
		return pa[u][0];
	}
	void init(int rt)
	{
		dfs(rt, 0, 0);
		dfs1(rt, rt, 0);
//		printf("rt %d\n", rt);
		std::sort(id+1, id+top+1, [&] (int x, int y) { return mx[x]>mx[y]; } );
		for(int i=1; i<=top; ++i) sum[i]=sum[i-1]+mx[id[i]], rk[id[i]]=i;
//		printf("%lld\n", sum[top]);
	}
	ll ask(int u, int k)
	{
		k=2*k-1;
		k=std::min(k, top);
		if(rk[up[u]]<=k) return sum[k];
		else
		{
			int v=find(u, k);
			if(!v) v=rt;
			ll s=sum[k]+mx[u]+dis[pa[u][0]]-dis[v];
			ll s1=s-mx[id[k]], s2=s-(mx[v]-rw[v]);
			return std::max(s1, s2);
		}
	}
}A, B;
int main()
{
	scan(n), scan(m);
	for(int i=1, x, y, w; i<n; ++i)
	{
		scan(x), scan(y), scan(w);
//		w=1;
		e[x].pb({y, w});
		e[y].pb({x, w});
	}
	pdfs(1, 0, 0);
	int rt1=rt;
	cdis=0;
	pdfs(rt, 0, 0);
	A.init(rt);
	B.init(rt1);
//	printf("rt %d\n", rt);
	for(int i=1, u, k, lst=0; i<=m; ++i)
	{
		scan(u), scan(k);
		u=(lst+u-1)%n+1, k=(lst+k-1)%n+1;
		putint(lst=std::max(A.ask(u, k), B.ask(u, k)), '\n');
	}
	flush();
	return 0;
}