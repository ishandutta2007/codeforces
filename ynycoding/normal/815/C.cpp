#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define ll long long
#define N 5005
using std::vector;
int n, b, c[N], d[N], sz[N];
ll f[N][2][N], t1[N], t2[N];
vector<int> e[N];
void dfs(int u, int fa)
{
	sz[u]=1;
	f[u][1][0]=c[u];
	f[u][0][1]=c[u];
	f[u][1][1]=c[u];
	for(int v:e[u]) if(v!=fa)
	{
		dfs(v, u);
		std::fill(t1, t1+sz[u]+sz[v]+1, 0x3f3f3f3f3f3f);
		std::fill(t2, t2+sz[u]+sz[v]+1, 0x3f3f3f3f3f3f);
		for(int i=0; i<=sz[u]; ++i) for(int j=0; j<=sz[v]; ++j)
		{
			t1[i+j]=std::min(t1[i+j], f[u][0][i]+f[v][0][j]);
			t2[i+j]=std::min(t2[i+j], f[u][1][i]+std::min(f[v][0][j], f[v][1][j]-d[v]));
		}
		sz[u]+=sz[v];
		for(int i=0; i<=sz[u]; ++i) f[u][0][i]=t1[i], f[u][1][i]=t2[i];
	}
}
int main()
{
	scanf("%d%d", &n, &b);
	scanf("%d%d", c+1, d+1);
	c[1]-=d[1];
	for(int i=2, x; i<=n; ++i) scanf("%d%d%d", c+i, d+i, &x), e[x].pb(i);
	dfs(1, 0);
	int ans=0;
	while(ans<n&&std::min(f[1][0][ans+1], f[1][1][ans+1])<=b) ++ans;
	printf("%d\n", ans);
	return 0;
}