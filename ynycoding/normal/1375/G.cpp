#include <cstdio>
#include <algorithm>
#define N 200005
int n, w;
int head[N], to[N<<1], nxt[N<<1], top;
inline void add(int x, int y) { nxt[++top]=head[x], head[x]=top, to[top]=y; }
inline void dfs(int u, int fa, int col)
{
	w+=col;
	for(int i=head[u]; i; i=nxt[i]) if(to[i]!=fa) dfs(to[i], u, col^1);
}
int main()
{
	scanf("%d", &n);
	for(int i=1, x, y; i<n; ++i) scanf("%d%d", &x, &y), add(x, y), add(y, x);
	dfs(1, 0, 0);
	printf("%d\n", std::min(w-1, n-w-1));
	return 0;
}