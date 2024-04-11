#include <cstdio>
#include <algorithm>
#define N 205
int MOD;
int n, m, col[N*N], fa[N*N];
int l[N<<1][N<<1], top, t;
char s[N][N];
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline void upt(int &x, int a) { x=mval(x+a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }
inline int inv(int x) { return qpow(x, MOD-2); }
int findfa(int x) { return x==fa[x]?x:fa[x]=findfa(fa[x]); }
inline bool merge(int x, int y)
{
	x=findfa(x), y=findfa(y);
	if(x==y) return 0;
	fa[x]=y;
	return 1;
}
inline int gid(int x, int y) { return (x-1)*(m+1)+y; }
inline void add(int x, int y, int x1, int y1)
{
	if(!x1||!y1||x1>n+1||y1>m+1||col[fa[gid(x, y)]]==col[fa[gid(x1, y1)]]) return;
	x=col[fa[gid(x, y)]], y=col[fa[gid(x1, y1)]];
	upt(l[x][x], 1), upt(l[y][y], 1), upt(l[x][y], MOD-1), upt(l[y][x], MOD-1);
}
inline int det(int n)
{
	int ret=1;
	for(int i=1; i<=n; ++i)
	{
		int cur=0;
		for(int j=i; j<=n; ++j) if(l[j][i]) { cur=j; break; }
		if(!cur) return 0;
		if(cur!=i) ret=MOD-ret;
		for(int j=i; j<=n; ++j) std::swap(l[i][j], l[cur][j]);
		int iv=inv(l[i][i]);
		ret=1ll*ret*l[i][i]%MOD;
		for(int j=i; j<=n; ++j) l[i][j]=1ll*l[i][j]*iv%MOD;
		for(int j=i+1; j<=n; ++j) for(int k=i+1; k<=n; ++k) upt(l[j][k], MOD-1ll*l[j][i]*l[i][k]%MOD);
	}
	return ret;
}
inline int solve(int t)
{
	std::fill(col+1, col+(n+1)*(m+1)+1, 0);
	for(int i=1; i<=top; ++i) std::fill(l[i]+1, l[i]+top+1, 0);
	top=0;
	for(int i=1; i<=n+1; ++i) for(int j=1; j<=m+1; ++j) if(((i+j+t)&1)&&(!col[findfa(gid(i, j))]))
	col[fa[gid(i, j)]]=++top;
	for(int i=1; i<=n+1; ++i) for(int j=1; j<=m+1; ++j) if((i+j+t)&1)
	{
		if(s[i-1][j]!='\\') add(i, j, i-1, j+1);
		if(s[i][j]!='/') add(i, j, i+1, j+1);
	}
	for(int i=1; i<top; ++i) for(int j=1; j<top; ++j) l[i][j]=l[i+1][j+1];
	return det(top-1);
}
int main()
{
	scanf("%d%d%d", &n, &m, &MOD);
	for(int i=1; i<=n+1; ++i) for(int j=1; j<=m+1; ++j) fa[gid(i, j)]=gid(i, j);
	for(int i=1; i<=n; ++i)
	{
		scanf("%s", s[i]+1);
		for(int j=1; j<=m; ++j)
		{
			if(s[i][j]=='\\'&&!merge(gid(i, j), gid(i+1, j+1))) return puts("0"), 0;
			if(s[i][j]=='/'&&!merge(gid(i+1, j), gid(i, j+1))) return puts("0"), 0;
		}
	}
	printf("%d\n", mval(solve(0)+solve(1)));
	return 0;
}