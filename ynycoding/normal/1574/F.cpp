#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
#define pb push_back
using std::vector;
const int N=300005, MOD=998244353;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline void inc(int &x, int a) { x=mval(x+a); }
int n, m, k, nxt[N], pr[N], is[N], vis[N], cnt[N];
int f[N];
vector<int> rs;
int dfs(int u, int lf, int rt)
{
	if(vis[u]||is[u]) return 0;
	int ret=1;
	vis[u]=1;
	if(rt&&nxt[u])
	{
		int t=dfs(nxt[u], 0, 1);
		if(!t) return 0;
		ret+=t;
	}
	if(lf&&pr[u])
	{
		int t=dfs(pr[u], 1, 0);
		if(!t) return 0;
		ret+=t;
	}
	return ret;
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1, k; i<=n; ++i)
	{
		scanf("%d", &k);
		int p=0;
		for(int j=1, x; j<=k; ++j)
		{
			scanf("%d", &x);
			if(p)
			{
				if(nxt[p]&&nxt[p]!=x) is[p]=1;
				if(pr[x]&&pr[x]!=p) is[x]=1;
				pr[x]=p, nxt[p]=x;
			}
			p=x;
		}
	}
	for(int i=1; i<=k; ++i) if(!vis[i])
	{
		++cnt[dfs(i, 1, 1)];
	}
	for(int i=1; i<=k; ++i) if(cnt[i]) rs.pb(i);
//	for(int x:rs) printf("add %d %d\n", x, cnt[x]);
	f[0]=1;
	for(int i=0; i<m; ++i) for(int x:rs) if(x+i<=m)
		inc(f[x+i], 1ll*f[i]*cnt[x]%MOD);
	printf("%d\n", f[m]);
	return 0;
}