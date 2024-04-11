#include <cstdio>
#include <algorithm>
#define N 5005
int n, m, f[N][N], ans;
char s[N], t[N];
int main()
{
	scanf("%d%d", &n, &m);
	scanf("%s%s", s+1, t+1);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
	{
		if(s[i]==t[j]) f[i][j]=f[i-1][j-1]+2;
		f[i][j]=std::max(f[i][j], f[i-1][j]-1);
		f[i][j]=std::max(f[i][j], f[i][j-1]-1);
		ans=std::max(ans, f[i][j]);
	}
	printf("%d\n", ans);
	return 0;
}