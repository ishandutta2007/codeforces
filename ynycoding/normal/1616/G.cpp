#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define ll long long
using std::vector;
const int N=150005;
int T, n, m, is[N], vis[N][2];
ll ans;
vector<int> e[N], g[N], rg[N], *re;
void dfs(int u, int d)
{
	if(vis[u][d]) return;
	vis[u][d]=1;
	for(int v:re[u]) dfs(v, d^1);
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; ++i) e[i].clear(), g[i].clear(), rg[i].clear(), vis[i][0]=vis[i][1]=is[i]=0;
		for(int i=1, x, y; i<=m; ++i)
		{
			scanf("%d%d", &x, &y);
			e[x].pb(y), e[y].pb(x);
			if(y==x+1) is[x]=1;
		}
		int l=1, r=n;
		while(is[l]) ++l;
		while(is[r-1]) --r;
		if(l==n) { printf("%lld\n", 1ll*n*(n-1)/2); continue; }
		int s=l+1;
		for(int u=1, pr=0; u<=n; ++u)
		{
			for(int v:e[u]) if(v<u-1&&v>=pr) rg[u].pb(v+1), g[v+1].pb(u);
			if(!is[u-1]) pr=u-1;
		}
		re=rg;
		dfs(s, 0);
		vis[s][0]=0;
		re=g;
		dfs(s, 0);
		int a0=0, a1=0, b0=0, b1=0, a2=0, b2=0;
		for(int i=1; i<=l+1; ++i) a0+=vis[i][0], a1+=vis[i][1], a2+=vis[i][0]&&vis[i][1];
		for(int i=r; i<=n; ++i) b0+=vis[i][0], b1+=vis[i][1], b2+=vis[i][0]&&vis[i][1];
		ans=1ll*a0*b0+1ll*a1*b1-1ll*a2*b2;
		if(r==l+1) ans-=1;
		for(int i=r; i<=n; ++i) ans+=(a1&&vis[i][0])||(a0&&vis[i][1]);
		for(int i=1; i<=l+1; ++i) ans+=(b1&&vis[i][0])||(b0&&vis[i][1]);
		ans+=((a0&&b0)||(a1&&b1));
		printf("%lld\n", ans);
	}
	return 0;
}