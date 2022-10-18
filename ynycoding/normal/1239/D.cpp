#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
using std::vector;
const int N=1000005;
int T, n, m, vis[N];
vector<int> e[N];
int low[N], dfn[N], in[N], cnt, stk[N], col[N], top, tot;
void tarjan(int u)
{
	low[u]=dfn[u]=++cnt;
	stk[++top]=u;
	in[u]=1;
	for(int v:e[u])
	{
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=std::min(low[u], low[v]);
		}
		else if(in[v]) low[u]=std::min(low[u], dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		++tot;
		while(stk[top+1]!=u)
		{
			col[stk[top]]=tot;
			in[stk[top]]=0;
			--top;
		}
	}
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		std::fill(stk+1, stk+n+1, 0);
		scanf("%d%d", &n, &m);
		cnt=0;
		for(int i=1; i<=n; ++i) e[i].clear(), vis[i]=dfn[i]=low[i]=0;
		tot=0;
		for(int i=1, x, y; i<=m; ++i) scanf("%d%d", &x, &y), e[x].pb(y);
		for(int i=1; i<=n; ++i) if(!dfn[i]) tarjan(i);
		for(int i=1; i<=n; ++i) if(col[i]==1) vis[i]=1;
		for(int i=1; i<=n; ++i) if(!vis[i])
		{
			puts("Yes");
			int c1=0;
			for(int j=1; j<=n; ++j) c1+=vis[j];
			printf("%d %d\n", c1, n-c1);
			for(int j=1; j<=n; ++j) if(vis[j]) printf("%d ", j);
			puts("");
			for(int j=1; j<=n; ++j) if(!vis[j]) printf("%d ", j);
			puts("");
			goto out;
		}
		puts("No");
		out:;
	}
	return 0;
}