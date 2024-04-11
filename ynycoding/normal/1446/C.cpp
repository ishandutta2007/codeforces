#include <cstdio>
#include <algorithm>
#define N 200005
#define B 33
#define D 31
int n, a[N], to[N], rt;
#define ls ch[u][0]
#define rs ch[u][1]
int ch[N*B][2], id[N*B], f[N*B], top;
inline void insert(int &u, int d, int x, int t)
{
	if(!u) u=++top;
	if(d<0) { id[u]=t; return; }
	if(x&(1<<d)) insert(rs, d-1, x, t);
	else insert(ls, d-1, x, t);
}
void dfs(int u, int d)
{
	if(!u) return;
	if(d<0) { f[u]=1; return; }
	dfs(ls, d-1), dfs(rs, d-1);
	f[u]=std::max((ls!=0)+f[rs], (rs!=0)+f[ls]);
}
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), insert(rt, D, a[i], i);
	dfs(rt, D);
	printf("%d\n", n-f[rt]);
	return 0;
}