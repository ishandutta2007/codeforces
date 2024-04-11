#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
using std::vector;
using std::pair;
const int N=300005;

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

int n, m, p[N], x[N], y[N], is[N], dep[N], id[N], ans;
int f[N];
vector<int> e[N];
vector<pair<int, int> > up[N];
void dfs(int u, int fa)
{
	dep[u]=dep[fa]+1;
	for(int v:e[u]) dfs(v, u);
}
inline void gmx(int &x, int a) { x=std::max(x, a); }
int stk[N], top;
void rdfs(int u)
{
	int sum=0;
	id[u]=++top, stk[top]=u;
	for(int v:e[u])
	{
		rdfs(v);
		gmx(f[u], f[v]);
		sum+=f[v];
	}
	gmx(f[u], sum);
	for(auto [v, t]:up[u]) if(id[v])
		gmx(f[stk[id[v]+1]], f[u]+1), is[t]=1;
	--top;
	id[u]=0;
}
int main()
{
	scan(n), scan(m);
	for(int i=2; i<=n; ++i) scan(p[i]), e[p[i]].pb(i);
	dfs(1, 0);
	for(int i=1; i<=m; ++i)
	{
		scan(x[i]), scan(y[i]);
		int x=::x[i], y=::y[i];
		if(dep[x]>dep[y]) std::swap(x, y);
		if(x==p[y]) return puts("-1"), 0;
		up[y].pb({x, i});
	}
	rdfs(1);
	ans=f[1];
	for(int i=1; i<=m; ++i) if(!is[i])
		gmx(ans, f[x[i]]+f[y[i]]+1);
	printf("%d\n", ans);
	return 0;
}