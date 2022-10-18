#include <cstdio>
#define MAXN 1001
int n, m, mp[MAXN][MAXN], now[MAXN][MAXN];
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=m; ++j)
		{
			char c=getchar();
			while(c=='\n'||c=='\r') c=getchar();
			if(c=='#') now[i][j]=mp[i][j]=1;
		}
	}
	for(int i=1; i<=n-2; ++i)
	{
		for(int j=1; j<=m-2; ++j)
		{
			if(mp[i][j])
			{
				if(mp[i+1][j]&&mp[i+2][j]&&mp[i][j+1]&&mp[i][j+2]&&mp[i+2][j+1]&&mp[i+2][j+2]&&mp[i+1][j+2])
				{
					for(int a=1; a<=3; ++a)
					{
						for(int b=1; b<=3; ++b)
						{
							if(a==b&&a==2) continue;
							now[i+a-1][j+b-1]=0;
						}
					}
				}
			}
		}
	}
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if(now[i][j]) return puts("NO"), 0;
	puts("YES");
	return 0;
}