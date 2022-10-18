#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define pb push_back
using std::vector;
const int N=200005;
int T, n, is[N], tot, mx;
vector<int> e[N];
void dfs(int u, int fa)
{
	is[u]=0;
	for(int v:e[u]) if(v!=fa)
	{
		dfs(v, u);
		is[u]|=is[v]^1;
	}
	tot-=2*is[u];
//	printf("is %d %d\n", u, is[u]);
//	if(fa&&e[u].size()==1) ++tot;
}
//void dfs1(int u, int fa, int d)
//{
//	int tot=0;
//	for(int v:e[u]) if(v!=fa) tot+=is[v];
//	for(int v:e[u]) if(v!=fa)
//		dfs1(v, u, d+tot-is[v]);
//	if(fa&&e[u].size()==1) mx=std::max(mx, d);
//}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) e[i].clear();
		for(int i=1, x, y; i<n; ++i) scanf("%d%d", &x, &y), e[x].pb(y), e[y].pb(x);
		tot=n;
		dfs(1, 0);
		printf("%d\n", tot+1-(!is[1]));
	}
	return 0;
}