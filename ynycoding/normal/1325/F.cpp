#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#define pb push_back
#define ll long long
#define N 200005
using std::vector;
int n, m, dep[N], sz[N], f[N], blk, top, lim, l1, mx, idd;
vector<int> e[N], id[N];
inline void prin(int u,  int v) { if(dep[u]<dep[v]) std::swap(u, v); while(u!=v) printf("%d ", u), u=f[u]; printf("%d\n", v); }
void dfs(int u, int fa)
{
	dep[u]=dep[fa]+1, f[u]=fa, ++sz[dep[u]], id[dep[u]].pb(u), lim=std::max(lim, dep[u]);
	for(int v:e[u])
	{
		if(dep[v]) { if(abs(dep[v]-dep[u])+1>=blk) printf("2\n%d\n", abs(dep[v]-dep[u])+1), prin(u, v), exit(0);
		l1=std::max(l1, abs(dep[u]-dep[v])); continue; }
		dfs(v, u);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	blk=sqrt(n);
	if(blk*blk<n) ++blk;
	for(int i=1, x, y; i<=m; ++i) scanf("%d%d", &x, &y), e[x].pb(y), e[y].pb(x);
	l1=1;
	dfs(1, 0);
	++l1;
	top=blk;
	puts("1");
	for(int i=1; i<=l1; ++i)
	{
		int cur=0;
		for(int j=i; j<=lim; j+=l1) cur+=sz[j];
		if(cur>mx) mx=cur, idd=i;
	}
	for(int i=idd; i<=lim; i+=l1)
	{
		for(int j=0; j<sz[i]&&top; ++j) printf("%d ", id[i][j]), --top;
	}
	return 0;
}