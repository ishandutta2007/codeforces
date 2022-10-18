#include <cstdio>
#include <algorithm>
#define ll long long
const int N=4005;
int n, m, sz[N];
ll f[N][N], g[N], a[N];
int stk[N], top, ch[N][2], rt;
#define ls ch[u][0]
#define rs ch[u][1]
void dfs(int u)
{
	sz[u]=1;
	if(ls) dfs(ls), sz[u]+=sz[ls];
	if(rs) dfs(rs), sz[u]+=sz[rs];
}
void rdfs(int u)
{
	if(ls) rdfs(ls);
	if(rs) rdfs(rs);
	std::fill(g, g+sz[u]+1, -0x3f3f3f3f3f3f3f);
	for(int i=0; i<=sz[ls]; ++i) for(int j=0; j<=sz[rs]; ++j)
		g[i+j]=std::max(g[i+j], f[ls][i]+f[rs][j]-2ll*i*j*a[u]);
	for(int i=sz[u]; i; --i) g[i]=std::max(g[i], g[i-1]+(m-2*(i-1)-1)*a[u]);
	std::copy(g, g+sz[u]+1, f[u]);
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%lld", a+i);
	for(int i=1; i<=n; ++i)
	{
		while(top&&a[i]<=a[stk[top]])
		{
			ch[i][0]=stk[top];
			--top;
		}
		ch[stk[top]][1]=i;
		stk[++top]=i;
	}
	rt=stk[1];
	dfs(rt);
	rdfs(rt);
	printf("%lld\n", f[rt][m]);
	return 0;
}