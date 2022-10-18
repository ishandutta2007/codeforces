#include <cstdio>
#include <algorithm>
#define N 800005
int n, mx, x[N], y[N], ans[N], to[N], head[N], nxt[N], vis[N], ok[N], deg[N], top=1;
inline void add(int a, int b) { nxt[++top]=head[a], to[top]=b, head[a]=top; }
void dfs(int u)
{
	vis[u]=1;
	for(int &i=head[u]; i; i=nxt[i]) if(!ok[i>>1])
	{
		ans[i>>1]=i&1;
		ok[i>>1]=1;
		dfs(to[i]);
	}
}
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d%d", x+i, y+i), mx=std::max(mx, std::max(x[i], y[i]));
	for(int i=1; i<=n; ++i)
		add(x[i], mx+y[i]), add(mx+y[i], x[i]), ++deg[x[i]], ++deg[mx+y[i]];
	for(int i=1, pr=0; i<=2*mx; ++i)
		if(deg[i]&1) pr?add(pr, i), add(i, pr), pr=0:pr=i;
	for(int i=1; i<=2*mx; ++i) if(!vis[i]) dfs(i);
	for(int i=1; i<=n; ++i) putchar(ans[i]?'b':'r');
	return 0;
}