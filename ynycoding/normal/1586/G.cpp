#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define x first
#define y second
using std::pair;
using std::vector;
const int N=400005, MOD=1000000007;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline void inc(int &x, int a) { x=mval(x+a); }
int n, t, in[N], f[N], g[N], a[N], b[N], id[N], sum[N];
int mx[N];
vector<int> qid[N];
inline void add(int p, int x) { while(p<=2*n) inc(sum[p], x), p+=p&(-p); }
inline int ask(int p) { int ret=0; while(p) inc(ret, sum[p]), p-=p&(-p); return ret; }
inline void add1(int p, int x) { while(p<=2*n) mx[p]=std::max(mx[p], x), p+=p&(-p); }
inline int ask1(int p) { int ret=0; while(p) ret=std::max(ret, mx[p]), p-=p&(-p); return ret; }
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d%d", a+i, b+i), id[b[i]]=i;
	scanf("%d", &t);
	for(int i=1, x; i<=t; ++i) scanf("%d", &x), in[x]=1;
	for(int i=1; i<=2*n; ++i) if(in[id[i]])
	{
		int u=id[i];
		int t=id[ask1(2*n-a[u]+1)];
		qid[t].pb(u);
		add1(2*n-a[u]+1, b[u]);
	}
	int t=id[ask1(2*n)];
	a[n+1]=1;
	qid[t].pb(n+1);
	for(int i=1; i<=2*n; ++i) if(id[i])
	{
		int u=id[i];
		f[u]=mval(1+ask(2*n-a[u]+1));
		if(in[u])
		{
			inc(g[u], 1);
			for(int x:qid[u]) g[x]=mval(ask(2*n-a[x]+1)+g[u]);
		}
		add(2*n-a[u]+1, f[u]);
	}
	printf("%d\n", g[n+1]);
	return 0;
}