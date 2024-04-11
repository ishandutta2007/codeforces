#include <cstdio>
#include <algorithm>
#define N 500005
int n, m, head[N], nxt[N], to[N], vis[N], dir[N], deg[N], top=1, cur;
inline void add(int a, int b) { nxt[++top]=head[a], to[top]=b, head[a]=top; }
void dfs(int u)
{
	for(int &i=head[u]; i; i=nxt[i]) if(!vis[i])
	{
		int v=to[i];
		int t=i;
		vis[i]=vis[i^1]=1;
		dfs(v);
		dir[t>>1]=cur^(t&1);
		t>>=1;
		cur^=1;
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1, a, b; i<=m; ++i) scanf("%d%d", &a, &b), add(a, b), add(b, a), ++deg[a], ++deg[b];
	for(int i=1, pr=0; i<=n; ++i) if(deg[i]&1)
	{
		if(pr) add(pr, i), add(i, pr), pr=0;
		else pr=i;
	}
	if((top>>1)&1) add(1, 1), add(1, 1);
	dfs(1);
	printf("%d\n", top>>1);
	for(int i=1; i<=top>>1; ++i) printf("%d %d\n", to[(i<<1)|dir[i]], to[(i<<1)|(dir[i]^1)]);
	return 0;
}