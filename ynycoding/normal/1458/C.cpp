#include <cstdio>
#include <numeric>
#include <algorithm>
const int N=1005;
int T, n, m, a[N][N], b[N][N], d[4], p[4], rp[N];
char s[N*N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) scanf("%d", a[i]+j);
		scanf("%s", s+1);
		p[1]=1, p[2]=2, p[3]=3;
		d[1]=d[2]=d[3]=0;
		for(int i=1; i<=m; ++i)
		{
			switch(s[i])
			{
				case 'R':
					++d[p[2]];
					break;
				case 'L':
					--d[p[2]];
					break;
				case 'D':
					++d[p[1]];
					break;
				case 'U':
					--d[p[1]];
					break;
				case 'I':
					std::swap(p[2], p[3]);
					break;
				case 'C':
					std::swap(p[1], p[3]);
					break;
			}
		}
		for(int i=1; i<=3; ++i) rp[p[i]]=i;
		for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j)
		{
			int x=((i-1+d[1])%n+n)%n+1, y=((j-1+d[2])%n+n)%n+1, z=((a[i][j]+d[3]-1)%n+n)%n+1;
			b[p[1]==1?x:p[1]==2?y:z][p[2]==1?x:p[2]==2?y:z]=(p[3]==1?x:p[3]==2?y:z);
		}
		for(int i=1; i<=n; ++i, puts("")) for(int j=1; j<=n; ++j)
			printf("%d ", b[i][j]);
	}
	return 0;
}