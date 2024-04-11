#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
using std::vector;
const int N=505, M=N*N;
int n, m;
char s[N][N];
int a[N][N], f[M];
vector<int> e[M];
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
inline int gid(int x, int y) { return (x-1)*m+y; }
inline void add(int x, int y)
{
	e[x].pb(y);
	e[y].pb(x);
}
void dfs(int u)
{
	for(int v:e[u]) if(!f[v])
	{
		f[v]=5-f[u];
		dfs(v);
	}
	else if(f[v]+f[u]!=5) puts("NO"), exit(0);
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%s", s[i]+1);
	for(int x=1; x<=n; ++x) for(int y=1; y<=m; ++y) if(s[x][y]=='X')
	{
		int t=0;
		for(int i=0; i<4; ++i)
		{
			int x1=x+dx[i], y1=y+dy[i];
			if(s[x1][y1]!='.') continue;
			int u=gid(x1, y1);
			if(t) add(t, u), t=0;
			else t=u;
		}
		if(t) return puts("NO"), 0;
	}
	for(int x=1; x<=n; ++x) for(int y=1; y<=m; ++y) if(s[x][y]=='.'&&!f[gid(x, y)])
		f[gid(x, y)]=1, dfs(gid(x, y));
	for(int x=1; x<=n; ++x) for(int y=1; y<=m; ++y)
	{
		if(s[x][y]=='.')
			a[x][y]=f[gid(x, y)];
		else
		{
			for(int i=0; i<4; ++i)
			{
				int x1=x+dx[i], y1=y+dy[i];
				if(s[x1][y1]!='.') continue;
				a[x][y]+=f[gid(x1, y1)];
			}
		}
	}
	puts("YES");
	for(int i=1; i<=n; ++i, puts("")) for(int j=1; j<=m; ++j) printf("%d ", a[i][j]);
	return 0;
}