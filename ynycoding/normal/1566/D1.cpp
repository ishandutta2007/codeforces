#include <cstdio>
#include <map>
#include <algorithm>
const int N=305;
int T, n, m, a[N*N], ra[N*N], fl[N][N], is[N][N], id[N*N], ans;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n*m; ++i) scanf("%d", a+i), id[i]=i;
		std::sort(id+1, id+n*m+1, [] (int x, int y) { return a[x]==a[y]?x<y:a[x]<a[y]; });
		int t=0;
		for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
		{
			is[i][j]=id[++t];
		}
		ans=0;
		for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) for(int k=1; k<j; ++k)
			ans+=a[is[i][k]]!=a[is[i][j]]&&is[i][k]<is[i][j];
		printf("%d\n", ans);
	}
	return 0;
}