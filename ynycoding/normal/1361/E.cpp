#include <cstdio>
#include <vector>
#include <random>
#include <algorithm>
#define pb push_back
using std::vector;
std::mt19937 rnd(114);
const int N=200005;
int T, n, m, vis[N], in[N], is[N], sum[N], id[N];
vector<int> e[N];
bool pdfs(int u)
{
	++vis[u];
	in[u]=1;
	if(vis[u]>1) return 0;
	for(int v:e[u]) if(!in[v])
		if(!pdfs(v)) return 0;
	in[u]=0;
	return 1;
}
void dfs(int u)
{
	vis[u]=1;
	for(int v:e[u]) if(!vis[v])
	{
		dfs(v);
		sum[u]+=sum[v];
		id[u]^=id[v];
	}
	else
	{
		id[u]^=v;
		id[v]^=v;
		++sum[u];
		--sum[v];
	}
//	printf("sum %d %d\n", u, sum[u]);
}
void rdfs(int u)
{
	vis[u]=1;
	is[u]=sum[u]>=2;
	if(!is[u]) is[u]|=is[id[u]];
	for(int v:e[u]) if(!vis[v])
	{
		rdfs(v);
	}
//	printf("sum %d %d\n", u, sum[u]);
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; ++i) id[i]=sum[i]=0, e[i].clear();
		for(int i=1, x, y; i<=m; ++i) scanf("%d%d", &x, &y), e[x].pb(y);
		int rt=50, x=0;
		while(rt--)
		{
			x=rnd()%n+1;
			std::fill(vis+1, vis+n+1, 0);
			std::fill(in+1, in+n+1, 0);
			if(!pdfs(x)) x=0;
			else break;
		}
		if(!x) { puts("-1"); continue; }
//		printf("x %d\n", x);
		int tot=0;
		std::fill(vis+1, vis+n+1, 0);
		std::fill(sum+1, sum+n+1, 0);
		dfs(x);
		std::fill(vis+1, vis+n+1, 0);
		std::fill(is+1, is+n+1, 0);
		rdfs(x);
		for(int i=1; i<=n; ++i) tot+=!is[i];
		if(tot*5<n) { puts("-1"); continue; }
		for(int i=1; i<=n; ++i) if(!is[i]) printf("%d ", i);
		puts("");
	}
	return 0;
}