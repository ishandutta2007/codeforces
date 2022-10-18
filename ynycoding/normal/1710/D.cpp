#include <cstdio>
#include <numeric>
#include <algorithm>
const int N=2005;
int T, n, fa[N];
char s[N][N];
inline int findfa(int x) { return x==fa[x]?x:fa[x]=findfa(fa[x]); }
inline void merge(int x, int y)
{
	printf("%d %d\n", x, y);
	fa[findfa(x)]=findfa(y);
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		std::iota(fa, fa+n+1, 0);
		for(int i=1; i<=n; ++i)
		{
			scanf("%s", s[i]+i);
			for(int j=i; j<=n; ++j) s[i][j]-='0';
		}
		for(int i=n; i; --i)
		{
			for(int j=i+1, pr=i; j<=n; ++j) if(s[i][j]&&findfa(i)!=findfa(j))
			{
				merge(i, j);
				for(int t=pr+1, ok=0; t<j; ++t) if(findfa(t)!=findfa(i))
				{
					merge(t, ok?i:j);
					ok=1;
				}
				pr=j;
			}
		}
	}
	return 0;
}