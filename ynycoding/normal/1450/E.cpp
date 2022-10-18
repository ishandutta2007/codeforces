#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define rep(_a, _b, _c) for(int (_a)=(_b); (_a)<=(_c); ++(_a))
#define pb push_back
#define N 205
using std::vector;
int n, m, g[N][N], f[N][N], fa[N], dis[N], col[N];
vector<int> e[N];
int findfa(int x)
{
	if(x==fa[x]) return x;
	int t=fa[x];
	fa[x]=findfa(fa[x]);
	dis[x]+=dis[t];
	return fa[x];
}
void dfs(int u)
{
	for(int v:e[u])
	{
		if(!col[v]) col[v]=3^col[u], dfs(v);
		else
		{
			if(col[u]==col[v]) puts("NO"), exit(0);
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) fa[i]=i;
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(i!=j) g[i][j]=0x3f3f3f3f;
	for(int i=1, x, y, z; i<=m; ++i)
	{
		scanf("%d%d%d", &x, &y, &z);
		e[x].pb(y), e[y].pb(x);
		int px=findfa(x), py=findfa(y);
		if(z==1)
		{
			if(px==py)
			{
				if(dis[y]!=dis[x]+1) return puts("NO"), 0;
			}
			else
			{
				dis[px]=dis[y]-1-dis[x], fa[px]=py;
			}
			if(g[x][y]==-1) return puts("NO"), 0;
			g[x][y]=1;
			g[y][x]=-1;
		}
		else
		{
			if(px==py)
			{
				if(abs(dis[x]-dis[y])!=1) return puts("NO"), 0;
			}
			else
			{
				g[x][y]=1;
				g[y][x]=1;
			}
		}
	}
	col[1]=1;
	dfs(1);
	rep(i, 1, n) rep(j, 1, n) f[i][j]=g[i][j];
	rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) f[i][j]=std::min(f[i][j], f[i][k]+f[k][j]);
	rep(i, 1, n) if(f[i][i]<0) return puts("NO"), 0;
	int ans=0, u=0;
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(ans<f[i][j]) ans=f[i][j], u=i;
	puts("YES");
	printf("%d\n", ans);
	for(int i=1; i<=n; ++i) printf("%d ", f[u][i]);
	return 0;
}