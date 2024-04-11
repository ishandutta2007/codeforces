#include <cstdio>
#define MAXN 502
int n, m[MAXN][MAXN], ans;
char s[MAXN];
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%s", s);
		for(int j=1; j<=n; ++j) m[i][j]=(s[j-1]=='X'?1:2);
	}
	for(int i=2; i<n; ++i)
		for(int j=2; j<n; ++j)
			if(m[i+1][j+1]+m[i+1][j-1]+m[i][j]+m[i-1][j-1]+m[i-1][j+1]==5)
		++ans;
	printf("%d", ans);
	return 0;
}