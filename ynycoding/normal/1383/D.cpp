#include <cstdio>
#include <algorithm>
const int N=255;
int n, m, a[N][N], b[N][N], X[N], Y[N], cx, cy, px, py;
int x[N*N], y[N*N], in[N][N], q[N*N][2], top;
int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};
inline void upt(int x, int y)
{
	if(!in[x][y]&&!b[x][y]&&x&&y&&x<=n&&y<=m)
	{
		int r=0, c=0;
		r=b[x][y-1]|b[x][y+1];
		c=b[x-1][y]|b[x+1][y];
		if(r&&c)
		{
			q[++top][0]=x, q[top][1]=y;
			in[x][y]=1;
		}
	}
}
inline void rupt(int x, int y)
{
	for(int d:{0, 1, 2, 3}) upt(x+dx[d], y+dy[d]);
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
	{
		scanf("%d", a[i]+j);
		x[a[i][j]]=i, y[a[i][j]]=j;
		X[i]=std::max(X[i], a[i][j]);
		Y[j]=std::max(Y[j], a[i][j]);
	}
	for(int v=n*m; v; --v)
	{
		int x=::x[v], y=::y[v];
		if(X[x]==v&&Y[y]==v)
		{
			cx=px+1, cy=py+1;
			px=cx, py=cy;
			b[cx][cy]=v;
			rupt(cx, cy);
		}
		else if(X[x]==v)
		{
			b[++px][py]=v;
			rupt(px, py);
		}
		else if(Y[y]==v)
		{
			b[px][++py]=v;
			rupt(px, py);
		}
		else
		{
//			printf("now %d %d %d\n", v, X[x], Y[y]);
			while(top&&b[q[top][0]][q[top][1]]) --top;
			if(!top) return puts("-1"), 0;
			x=q[top][0], y=q[top][1];
			b[x][y]=v;
			rupt(x, y);
		}
//	for(int i=1; i<=n; ++i, puts("")) for(int j=1; j<=m; ++j) printf("%d ", b[i][j]);
//	puts("");
	}
	for(int i=1; i<=n; ++i, puts("")) for(int j=1; j<=m; ++j) printf("%d ", b[i][j]);
	return 0;
}