#include <cstdio>
#include <algorithm>
#define MAXN 55
int n, m, a[MAXN][MAXN], b[MAXN][MAXN], tag[MAXN][MAXN], ans;
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) scanf("%d", &a[i][j]);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
	{
		if(b[i][j]^a[i][j]) if(a[i][j]==1&&a[i+1][j]==1&&a[i][j+1]==1&&a[i+1][j+1]==1&&i<n&&j<m)
		b[i][j]=b[i+1][j]=b[i][j+1]=b[i+1][j+1]=1, ++ans, tag[i][j]=1;
		else if(a[i][j]==1&&a[i+1][j]==1&&a[i][j-1]==1&&a[i+1][j-1]==1&&i<n&&j>1) b[i][j]=b[i][j-1]=b[i+1][j]=b[i+1][j-1]=1, ++ans, tag[i][j-1]=1;
		else if(a[i][j]==1&&a[i-1][j]==1&&a[i][j+1]==1&&a[i-1][j+1]==1&&i>1&&j<m) b[i][j]=b[i-1][j]=b[i][j+1]=b[i-1][j+1]=1, ++ans, tag[i-1][j]=1;
		else if(a[i][j]==1&&a[i-1][j]==1&&a[i][j-1]==1&&a[i-1][j-1]==1&&i>1&&j>1) b[i][j]=b[i-1][j]=b[i][j-1]=b[i-1][j-1]=1, ++ans, tag[i-1][j-1]=1;
	}
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if(a[i][j]^b[i][j]) { return puts("-1"); }
	printf("%d\n", ans);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if(tag[i][j]) printf("%d %d\n", i, j);
	return 0;
}