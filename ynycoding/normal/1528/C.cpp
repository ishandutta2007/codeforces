#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define ll long long
using std::vector;
const int N=300005;
int T, n, l[N], r[N], f[N], in[N], out[N], cnt, ans;
vector<int> e[N], g[N];
int sum[N];
inline void gmx(int &x, int a) { x=std::max(x, a); }
inline void add(int p, int v) { while(p<=n) sum[p]+=v, p+=p&(-p); }
inline int ask(int p) { int ret=0; while(p) ret+=sum[p], p-=p&(-p); return ret; }
void pdfs(int u)
{
	in[u]=++cnt;
	for(int v:g[u]) pdfs(v);
	out[u]=cnt;
//	printf("in %d %d\n", u, in[u]);
}
void dfs(int u, int d)
{
	int t=ask(in[u]);
	if(t)
	{
		add(in[t], -t);
		add(out[t]+1, t);
	}
	else ++d;
	add(in[u], u);
	add(out[u]+1, -u);
	for(int v:e[u]) dfs(v, d);
	add(in[u], -u);
	add(out[u]+1, u);
	if(t)
	{
		add(in[t], t);
		add(out[t]+1, -t);
	}
	gmx(ans, d);
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		cnt=0;
		for(int i=1; i<=n; ++i) e[i].clear(), g[i].clear();
		std::fill(sum+1, sum+n+1, 0);
		ans=0;
		for(int i=2, x; i<=n; ++i) scanf("%d", &x), e[x].pb(i);
		for(int i=2, x; i<=n; ++i) scanf("%d", &x), g[x].pb(i);
		pdfs(1);
		dfs(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}