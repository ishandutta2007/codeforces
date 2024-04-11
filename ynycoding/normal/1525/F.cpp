#include <cstdio>
#include <algorithm>
#define ll long long
const int N=105;
int n, m, k, e[N][N], to[N], vis[N], vq[N], ok[N], idx, ans;
int pr[N][N], x[N], y[N];
ll f[N][N];
bool dfs(int u)
{
	vis[u]=1;
	for(int v=n+1; v<=2*n; ++v) if(e[u][v]&&!vis[v])
	{
		vis[v]=1;
		if(!to[v]||dfs(to[v]))
		{
			to[v]=u, to[u]=v;
			return 1;
		}
	}
	return 0;
}
void dfs1(int u)
{
	vis[u]=1;
	for(int v=n+1; v<=2*n; ++v) if(e[u][v]&&!vis[v])
	{
		vis[v]=1;
		if(to[v]) dfs1(to[v]);
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1, x, y; i<=m; ++i) scanf("%d%d", &x, &y), e[x][y+n]=1;
	for(int i=1; i<=k; ++i) scanf("%d%d", x+i, y+i);
	for(int u=1; u<=n; ++u) if(!to[u])
	{
		std::fill(vis+1, vis+2*n+1, 0);
		dfs(u);
	}
	std::fill(vis+1, vis+2*n+1, 0);
	for(int u=1; u<=n; ++u) if(!to[u]&&!vis[u]) dfs1(u);
	ans=0;
	for(int u=1; u<=n; ++u) if(!vis[u]) vq[++ans]=u;
	for(int u=n+1; u<=2*n; ++u) if(vis[u]) vq[++ans]=u;
	if(k<n-ans)
	{
		printf("%d\n", k);
		for(int i=1; i<=k; ++i) printf("0 ");
		return 0;
	}
	for(int i=0; i<=n; ++i) for(int j=0; j<=n; ++j) f[i][j]=-0x3f3f3f3f;
	f[0][0]=0;
	for(int i=1; i<=k; ++i) for(int j=0; j<=n; ++j) for(int k=0; k<=n; ++k) if(i<n-ans+j+k)
	{
		if(f[i-1][j]+std::max(0ll, x[i]-1ll*k*y[i])>f[i][j+k])
		{
			f[i][j+k]=f[i-1][j]+std::max(0ll, x[i]-1ll*k*y[i]);
			pr[i][j+k]=k;
		}
	}
	printf("%d\n", k+(k+ans-n+1));
	for(int i=k, y=k+ans-n+1; i; --i)
	{
		ok[i]=pr[i][y];
		y-=pr[i][y];
	}
	for(int i=1; i<=k; ++i)
	{
		for(int j=1; j<=ok[i]; ++j) printf("%d ", (vq[++idx]>n?-(vq[idx]-n):vq[idx]));
		printf("0 ");
	}
	return 0;
}