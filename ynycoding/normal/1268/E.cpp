#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
using std::vector;
const int N=500005;
int n, m, dep[N], f[N], vis[N], pa[N], x[N], y[N], ok[N], g[N], q[N], tp;
vector<int> e[N];
void proc(void)
{
	int mn=0x3f3f3f3f, id=0, mx=0, idx=0;
	for(int i=1; i<=tp; ++i)
	{
		if(mn>q[i]) mn=q[i], idx=i;
		if(mx<q[i]) mx=q[i], id=i;
	}
	bool ok0=0, ok1=0;
	int x=id;
	while(1)
	{
		int y=(x==tp)?1:x+1;
		if(y==idx) { ok0=1; break; }
		if(q[y]>q[x]) break;
		x=y;
	}
	x=id;
	while(1)
	{
		int y=(x==1)?tp:x-1;
		if(y==idx) { ok1=1; break; }
		if(q[y]>q[x]) break;
		x=y;
	}
	if(ok0&&ok1) ok[q[idx]]=q[id];
}
void dfs(int u, int fa, int deep)
{
	pa[u]=fa;
	dep[u]=deep+1;
	for(int i:e[u]) if(!vis[i])
	{
		vis[i]=1;
		int v=x[i]^y[i]^u;
		if(dep[v])
		{
			q[tp=1]=i;
			int t=dep[u]>dep[v]?u:v;
			int s=dep[u]>dep[v]?v:u;
			while(t!=s)
			{
				q[++tp]=pa[t];
				t=x[pa[t]]^y[pa[t]]^t;
			}
			proc();
		}
		else dfs(v, i, dep[u]);
	}
}
inline void insert(int id)
{
	int u=x[id], v=y[id];
	int x=f[u]+f[v]-(ok[id]?g[ok[id]]:0);
	f[u]=f[v]=x;
	g[id]=x;
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1, a, b; i<=m; ++i) scanf("%d%d", &a, &b), x[i]=a, y[i]=b, e[a].pb(i), e[b].pb(i);
	std::fill(f+1, f+n+1, 1);
	dfs(1, 0, 0);
	for(int i=m; i; --i) insert(i);
	for(int i=1; i<=n; ++i) printf("%d ", f[i]-1);
	return 0;
}