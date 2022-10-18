#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using std::min;
using std::max;
using std::vector;
using std::queue;
const int N=200005;

int n, m, k, vis[N];
int dx[6]={-1, 1, 0, 0, 0, 0};
int dy[6]={0, 0, -1, 1, 0, 0};
int dz[6]={0, 0, 0, 0, -1, 1};
int col[N], cd[N];
inline int gid(int x, int y, int z)
{
	return (x-1)*m*k+(y-1)*k+z;
}
bool chk(int x, int y, int z) { return x>=1&&x<=n&&y>=1&&y<=m&&z>=1&&z<=k; }
#define FAIL { puts("-1"); exit(0); }
void ins(int, int, int, int, int);
void del(int x, int y, int z)
{
	int u=gid(x, y, z), &sd=cd[u];
//	printf("del %d %d %d\n", x, y, z);
	for(int d=0; d<6; ++d) if(sd&(1<<d))
		sd^=1<<d, ins(x+dx[d], y+dy[d], z+dz[d], d, col[u]);
	col[u]=cd[u]=0;
}
void ins(int x, int y, int z, int d, int c)
{
//	printf("%d %d %d %d %d\n", x, y, z, d, c);
	if(!chk(x, y, z))
	{
		if(c) FAIL;
		return;
	}
	int u=gid(x, y, z);
	if(!vis[u])
	{
		vis[u]=1;
		col[u]=c, cd[u]|=1<<d;
		if(!c) ins(x+dx[d], y+dy[d], z+dz[d], d, c);
		return;
	}
	vis[u]=1;
	if(col[u]&&col[u]!=c) del(x, y, z), ins(x+dx[d], y+dy[d], z+dz[d], d, c);
//	else if(vis[u]&&col[u]&&!c) FAIL
	else if(!col[u])
	{
		ins(x+dx[d], y+dy[d], z+dz[d], d, c);
	}
	else if(col[u]==c) cd[u]|=1<<d;
}
int c;
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1; i<=m; ++i) for(int j=1; j<=k; ++j)
	{
		scanf("%d", &c);
		ins(1, i, j, 1, c);
	}
	for(int i=1; i<=m; ++i) for(int j=1; j<=k; ++j)
	{
		scanf("%d", &c);
		ins(n, i, j, 0, c);
	}
	for(int i=1; i<=n; ++i) for(int j=1; j<=k; ++j)
	{
		scanf("%d", &c);
		ins(i, 1, j, 3, c);
	}
	for(int i=1; i<=n; ++i) for(int j=1; j<=k; ++j)
	{
		scanf("%d", &c);
		ins(i, m, j, 2, c);
	}
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
	{
		scanf("%d", &c);
		ins(i, j, 1, 5, c);
	}
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
	{
		scanf("%d", &c);
		ins(i, j, k, 4, c);
	}
	for(int i=1; i<=n*m*k; ++i) printf("%d ", col[i]);
	return 0;
}