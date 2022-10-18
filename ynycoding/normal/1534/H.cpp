#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
using std::vector;
const int N=100005;
int n, rt, ans, f[N], fo[N], q[N], qo[N], pa[N], rp[N];
vector<int> e[N], id[N];
bool cmp(int a, int b) { return f[a]>f[b]; }
void dfs(int u, int fa)
{
	pa[u]=fa;
	q[u]=u;
	for(int v:e[u]) if(v!=fa)
	{
		dfs(v, u);
		f[u]=std::max(f[v], f[u]);
	}
	for(int v:e[u]) if(v!=fa)
		id[u].pb(v);
	if(id[u].empty()) return;
	std::sort(id[u].begin(), id[u].end(), cmp);
	q[u]=q[*id[u].begin()];
	int cnt=0;
	for(int v:id[u])
	{
		f[u]=std::max(f[u], cnt+f[v]);
		++cnt;
	}
}
void dfs1(int u, int fa)
{
	if(fa)
	{
		int tmp=f[fa];
		f[fa]=fo[u];
		id[u].insert(std::lower_bound(id[u].begin(), id[u].end(), fa, cmp), fa);
		f[fa]=tmp;
	}
	int cnt=0, mx=-1, mx1=-1, mid=-1, mid1=-1;
	for(int v:id[u])
	{
		int val=v==fa?fo[u]:f[v];
		val+=cnt;
		if(val>mx) mx1=mx, mid1=mid, mx=val, mid=cnt;
		else if(val>mx1) mx1=val, mid1=cnt;
		++cnt;
	}
	mx=std::max(0, mx), mx1=std::max(0, mx1);
	int q1=id[u][0]==fa?qo[u]:q[id[u][0]];
	int q2=(id[u].size()==1?u:id[u][1]==fa?qo[u]:q[id[u][1]]);
	cnt=0;
	for(int v:id[u])
	{
		if(v==fa) { ++cnt; continue; }
		fo[v]=(mid==cnt?mx1-(mid1>cnt):mx-(mid>cnt));
		qo[v]=cnt?q1:q2;
		++cnt;
	}
	for(int v:e[u]) if(v!=fa) dfs1(v, u);
}
void pdfs(int u, int fa)
{
	rp[u]=fa;
	for(int v:e[u]) if(v!=fa)
		pdfs(v, u);
}
int x, a, b;
int fix(int u)
{
	int cnt=0;
	for(int v:id[u]) if(v!=rp[u])
	{
		if(cnt)
		{
			printf("? %d\n", (v==pa[u]?qo[u]:q[v]));
			fflush(stdout);
			scanf("%d", &x);
			if(x!=u) return fix(x);
		}
		++cnt;
	}
	return u;
}
int main()
{
	scanf("%d", &n);
	if(n==1) return puts("0\n! 1 1"), 0;
	for(int i=1, x, y; i<n; ++i) scanf("%d%d", &x, &y), e[x].pb(y), e[y].pb(x);
	dfs(1, 0);
	dfs1(1, 0);
	for(int u=1; u<=n; ++u)
	{
		int cnt=0, mx=0;
		for(int v:id[u])
		{
			int val=v==pa[u]?fo[u]:f[v];
			ans=std::max(ans, mx+cnt+val+1);
			mx=std::max(mx, val);
			++cnt;
		}
	}
	printf("%d\n", ans);
	fflush(stdout);
	scanf("%d", &rt);
	pdfs(rt, 0);
	for(int v:id[rt])
	{
		printf("? %d\n", (v==pa[rt]?qo[rt]:q[v]));
		fflush(stdout);
		scanf("%d", &x);
		if(x!=rt) (a?b:a)=fix(x);
		if(b) break;
	}
	if(!a) a=rt;
	if(!b) b=rt;
	printf("! %d %d\n", a, b);
	return 0;
}