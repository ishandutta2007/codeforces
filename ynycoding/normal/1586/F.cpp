#include <cstdio>
#include <algorithm>
const int N=1005;
int n, k, e[N][N], pw, mx;
int d[N][N];
int main()
{
	scanf("%d%d", &n, &k);
	pw=1;
	while(pw<n) ++mx, pw=k*pw;
	--mx;
	for(int i=0; i<n; ++i)
	{
		int x=i, tp=0;
		while(x) d[i][tp++]=x%k, x/=k;
	}
	for(int i=1; i<n; ++i)
	{
		for(int j=0; j<i; ++j)
		{
			int t=0;
			while(d[i][t]<=d[j][t]) ++t;
//			printf("fa %d %d %d %d %d\n", i, j, t, d[i][t], d[j][t]);
			e[j+1][i+1]=t+1;
		}
	}
	printf("%d\n", mx+1);
	for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) printf("%d ", e[i][j]);
	return 0;
}